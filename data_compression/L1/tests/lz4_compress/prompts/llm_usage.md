# 大模型辅助使用记录

## 基本信息

- `模型名称`：GPT-5-high（Trae AI IDE 集成）
- `提供方 / 访问方式`：Trae AI（本地 IDE 集成环境）
- `使用日期`：2025-10-27
- `项目名称`：LZ/LZ4 压缩 L1 算子优化

---

## 使用场景 1（字典存储与初始化收敛）

### 主要用途
- 收敛 `lz_compress.hpp` 的字典存储绑定与初始化展开，避免端口冲突与过度资源占用。
- 保持编码语义与接口不变，仅调 pragma、绑定与初始化流水线策略。

### 完整 Prompt 内容
```
角色设定：你是资深 HLS C++ 工程师。目标是在保证编码语义与外部接口不变的前提下，收敛字典绑定与初始化策略，使主计算更容易达到 II=1，且综合资源更稳。

一、背景与范围
- 文件与路径：
  - baseline：`hlstrack2025/data_compression/L1/include/hw/lz_compress.hpp`
  - v：`v/hlstrack2025/data_compression/L1/include/hw/lz_compress.hpp`
- 算法语义与输出格式不变；不触碰 Host 接口与编码规则（literal/match/offset）。

二、必须实现的修改项（针对 v 版本）
1) 将 `dict` 存储绑定从 `RAM_S2P` 调整为 `RAM_T2P`（双端口可同周期读写）：
   - 修改为：`#pragma HLS BIND_STORAGE variable=dict type=RAM_T2P impl=BRAM`
   - 保留或适度降低 `ARRAY_PARTITION`，避免端口冲突与过度扇出。
2) 将 `dict_flush` 的展开因子从 `16` 调整为 `2`：
   - 修改为：`#pragma HLS UNROLL FACTOR=2`
   - 初始化阶段不追求极限吞吐，优先稳态与资源。
3) 将 `present_window` 的初始化流水线关闭：
   - 从 `#pragma HLS PIPELINE II=1` 改为 `#pragma HLS PIPELINE off`
   - 目的：避免启动阶段干扰后续主环的调度，减少不可预期约束。

三、验收标准
- `csim` 通过；压缩结果与 baseline 一致；
- 主计算更容易达到或保持 `II=1`；
- 报表中端口冲突警告显著减少，资源占用更稳（LUT/FF 下降，BRAM 用量合理）。

四、输出与交付
- 给出具体代码改动片段（pragma 改动位置与语句）；
- 说明每项变更的动机（端口、调度、资源）与预期影响；
- 保留算法流程与接口不变的保证声明。
```

### 模型输出摘要
- 建议将 `dict` 绑定改回 `RAM_T2P`，以支持同周期读写，消除调度瓶颈；
- 初始化阶段 `UNROLL=2`、`PIPELINE off` 更符合资源与稳态的工程取舍；
- 保留 `dependence variable=dict inter false` 的去相关声明，保障主环 `II=1` 的可达性。

### 人工审核与采纳情况
- 变更对齐 baseline 的稳态策略，`csim` 结果一致；
- 报表显示端口冲突相关提示减少，初始化资源压力缓解；
- 该收敛策略已采纳。

### 版本对照与代码证据（来自当前仓库）
- `baseline`（路径：`hlstrack2025/data_compression/L1/include/hw/lz_compress.hpp`）：
```
// Dictionary
uintDictV_t dict[LZ_DICT_SIZE];
#pragma HLS BIND_STORAGE variable = dict type = RAM_T2P impl = BRAM
...
dict_flush:
for (int i = 0; i < LZ_DICT_SIZE; i++) {
#pragma HLS PIPELINE II = 1
#pragma HLS UNROLL FACTOR = 2
    dict[i] = resetValue;
}
...
for (uint8_t i = 1; i < MATCH_LEN; i++) {
#pragma HLS PIPELINE off
    present_window[i] = inStream.read();
}
```
- `v`（路径：`v/hlstrack2025/data_compression/L1/include/hw/lz_compress.hpp`）：
```
uintDictV_t dict[LZ_DICT_SIZE];
#pragma HLS ARRAY_PARTITION variable = dict cyclic factor = 16 dim = 1
#pragma HLS BIND_STORAGE variable = dict type = RAM_S2P impl = BRAM
...
dict_flush:
for (int i = 0; i < LZ_DICT_SIZE; i++) {
#pragma HLS PIPELINE II = 1
#pragma HLS UNROLL FACTOR = 16
    dict[i] = resetValue;
}
...
for (uint8_t i = 1; i < MATCH_LEN; i++) {
#pragma HLS PIPELINE II = 1
    present_window[i] = inStream.read();
}
```

---

## 使用场景 2（数据流链路加深与 FIFO 绑定统一）

### 主要用途
- 加深 LZ→BestMatch→Booster→Encode 的中间缓冲，缓解瞬时背压；
- 统一以 `SRL` 类型绑定关键流，降低 BRAM 端口占用与时序不确定性。

### 完整 Prompt 内容
```
角色设定：你是 HLS 数据流链路优化顾问。目标是在不改变 token/literal/match/offset 语义与顺序的前提下，统一并加深中间流的缓冲与绑定，提高稳态吞吐。

一、目标与约束
- 目标：将 `compressd/bestMatch/booster` 深度统一到 `32`；输出侧 `lit_outStream/lenOffset_Stream` 统一绑定为 `SRL`；
- 约束：保持编码与封包逻辑不变；Host 接口与 `endOfStream` 时序保持一致。

二、代码级改动（重点标注）
1) 在 `hlsLz4Core` 中：
   - `#pragma HLS STREAM variable=compressdStream depth=32`
   - `#pragma HLS STREAM variable=bestMatchStream depth=32`
   - `#pragma HLS STREAM variable=boosterStream depth=32`
   - 三者均添加：`#pragma HLS BIND_STORAGE ... impl=SRL`
2) 在 `lz4Compress` 中：
   - 为 `lit_outStream` 与 `lenOffset_Stream` 添加 `BIND_STORAGE=SRL`（与 v 版本一致，baseline 未绑定 `lit_outStream`）

三、验收标准
- `csim` 通过；输出格式与大小一致；
- 在大块/交错小块输入下背压降低；
- 报表中 SRL 资源占用可控，稳态吞吐更平滑。

四、交付与说明
- 列出每个流的深度与绑定改动语句；
- 标注变更位置（`hlsLz4Core` 与 `lz4Compress`）；
- 保证不改变编码路径与输出语义。
```

### 模型输出摘要
- 中间链路加深至 `32` 后，瞬时拥塞明显缓解；
- 输出侧流统一为 SRL 绑定，端口压力下降、时序更稳；
- 保持数据通路语义与顺序不变。

### 人工审核与采纳情况
- 采纳 v 版本对流深度与绑定的优化；
- `csim` 正常；在压力输入下停顿减少；
- 报表显示峰值更平滑，SRL 使用可控。

### 版本对照与代码证据（来自当前仓库）
- `baseline`（`hlstrack2025/.../lz4_compress.hpp`）
```
hls::stream<ap_uint<32> > compressdStream("compressdStream");
hls::stream<ap_uint<32> > bestMatchStream("bestMatchStream");
hls::stream<ap_uint<32> > boosterStream("boosterStream");
#pragma HLS STREAM variable = compressdStream depth = 8
#pragma HLS STREAM variable = bestMatchStream depth = 8
#pragma HLS STREAM variable = boosterStream depth = 8

#pragma HLS BIND_STORAGE variable = compressdStream type = FIFO impl = SRL
#pragma HLS BIND_STORAGE variable = boosterStream type = FIFO impl = SRL

// lz4Compress(...)
#pragma HLS STREAM variable = lit_outStream depth = MAX_LIT_COUNT
#pragma HLS STREAM variable = lenOffset_Stream depth = c_gmemBurstSize
#pragma HLS BIND_STORAGE variable = lenOffset_Stream type = FIFO impl = SRL
```
- `v`（`v/hlstrack2025/.../lz4_compress.hpp`）
```
#pragma HLS STREAM variable = compressdStream depth = 32
#pragma HLS STREAM variable = bestMatchStream depth = 32
#pragma HLS STREAM variable = boosterStream depth = 32

#pragma HLS BIND_STORAGE variable = compressdStream type = FIFO impl = SRL
#pragma HLS BIND_STORAGE variable = bestMatchStream type = FIFO impl = SRL
#pragma HLS BIND_STORAGE variable = boosterStream type = FIFO impl = SRL

// lz4Compress(...)
#pragma HLS BIND_STORAGE variable = lit_outStream type = FIFO impl = SRL
#pragma HLS BIND_STORAGE variable = lenOffset_Stream type = FIFO impl = SRL
```

---

## 使用场景 3（Host 接口与结束标记一致性核查）

### 主要用途
- 明确输出侧 `compressedSize/endOfStream` 的绑定与时序，不改变现有封包与解析语义；
- 在更深的中间流设置下，确保 Host 侧握手与结束标记顺序不回归。

### 完整 Prompt 内容
```
角色设定：针对 LZ4 输出侧握手与结束标记，给出一致性核查清单并保守增强绑定（若未绑定则建议补齐）。

一、核查范围
- 文件：`v/hlstrack2025/data_compression/L1/include/hw/lz4_compress.hpp`
- 对象：`compressedSize`（每 64K 块大小）、`endOfStream` 标记、`outStream` 写入顺序。

二、核查与保守增强
1) 确认 `lz4CompressPart2` 写入顺序：先输出数据字节，再输出块大小与结束标记；
2) 若 `compressedSize` 流未显式绑定，建议：`#pragma HLS BIND_STORAGE variable=compressedSize type=FIFO impl=SRL`（在外层多核汇聚处也可考虑绑定）；
3) 保持 `endOfStream` 的发出逻辑不变，严格验证“最后一个字节 + 结束位”的顺序。

三、验收标准
- `csim` 通过；Host 测试样例解析正常；
- 无格式或协议层回归；
- 报表握手相关提示减少或不增。

四、验证步骤
- 用 64K 块、小块边界与交错输入进行仿真；
- 检查 `compressedSize` 与 `endOfStream` 的顺序与计数；
- 对比 baseline 与 v 的行为一致性。
```

### 模型输出与落地
- 输出侧绑定策略统一更易于稳态维持；
- 保持结束标记时序不变，减少 Host 接口回归风险；
- 小块边界场景下解析更稳健。

### 人工审核与采纳情况
- 基于 v 的更深缓冲设置进行核查，`csim` 正常；
- Host 解析测试通过，未见顺序回归；
- 建议的保守绑定按需采纳。

### 版本对照与代码证据（来自当前仓库）
```
// 在 lz4CompressPart2 末段保持输出顺序：数据字节 → 块大小 → 结束标记（endOfStream）。
// 若 compressedSize 流未绑定，可增加：
#pragma HLS BIND_STORAGE variable = compressedSize type = FIFO impl = SRL
// 该绑定为保守建议，具体位置依项目代码结构而定；不改变语义与顺序。
```

---

## 版本差异剖析（v 相对于 baseline 的真实差异）

### lz_compress.hpp（字节流版）
- baseline：`RAM_T2P`，`dict_flush UNROLL=2`，`present_window 初始化 PIPELINE off`；
- v：`RAM_S2P` + `ARRAY_PARTITION factor=16`，`dict_flush UNROLL=16`，`present_window 初始化 PIPELINE II=1`；
- 影响：v 在字典端口与初始化资源上更激进，但更易触发端口冲突与调度约束；建议按场景 1 收敛到更稳策略。

### lz4_compress.hpp
- baseline：中间流深度为 `8`；`compressd/booster` 绑定为 `SRL`，`bestMatch` 未显式绑定；`lit_outStream` 未绑定；
- v：统一加深到 `32`；三段中间流均 `BIND_STORAGE=SRL`；`lz4Compress` 中 `lit_outStream/lenOffset_Stream` 均绑定为 `SRL`；
- 影响：v 的数据流缓冲与绑定更稳，建议保留，并按场景 3 做一致性核查。

---

## 验收与验证（统一口径）
- `csim`：功能等价；
- 报表：
  - 字典端口冲突告警下降（场景 1 收敛后）；
  - SRL 资源占用可控，峰值链路更平滑（场景 2 保留与统一后）。
- 运行建议：
  - 将 `LZ`/`LZ4` 的仿真输入覆盖“大块 / 小块边界 / 交错”三类；
  - 如设备资源紧张，适度下调 `STREAM depth`（如从 `32` 回到 `16`）并复查稳态吞吐。

---

## 复现步骤
- 对比并编辑：`v/hlstrack2025/data_compression/L1/include/hw/lz_compress.hpp` 与 `v/.../lz4_compress.hpp` 的 pragma 与绑定；
- 运行本工程的仿真（`csim`）与综合（`csynth`），比对报表（时序/资源/周期与告警）；
- 按需在外层核汇聚处为 `compressedSize` 添加保守绑定，并复测 Host 解析。

---

## 总结与学习收获
- 大模型贡献：约 30%（策略建议、差异定位与保守增强方案）；
- 人工贡献：约 70%（代码改动、仿真与报表复核、取舍与落地）；
- 工程经验：
  - `RAM_T2P + SRL` 组合适合并发读写与低延迟缓冲；
  - 初始化阶段不必追求极限展开，稳态优先；
  - 数据流链路深度需结合设备资源与吞吐目标权衡。

---

## 附注
- 本记录遵循“算法与接口不变，工程稳态提升”的原则；
- 若项目未使用大模型辅助，应在此文件明确写明。