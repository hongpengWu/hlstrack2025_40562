# 2025年第八届全国大学生嵌入式芯片与系统设计竞赛——AMD命题式基础赛道
# 全国一等奖作品
# 初赛详情：
- sha256:T_exec = 6109ns，得分73.09
- lz:T_exec = 19923ns，得分68.53
- Cholesky:T_exec = 6221ns，得分94.3
## 归一化得分78.9（未x1.1）

# 决赛详情：
## 决赛选题为选项三
## 作品简介：
  基于经典论文的Unscented Kalman FIlter数学原理进行HLS代码构造。通过测试，验证了功能和相同数量级的精度；在性能，资源利用，延迟上对比官网算子更有优势；最后导出为IP核并嵌入到目标跟踪系统的PL端，与纯软件的目标跟踪系统进行直观对比，验证可行性。
Unscented Kalman Filter论文出处：https://citeseerx.ist.psu.edu/document?repid=rep1&type=pdf&doi=a665183562768e29d87ce3073fbcde564ae00768
Matlab代码出处：https://github.com/JJHu1993/sr-ukf
路演PPT，Jupyter文件，硬件文件均在“决赛”文件夹内，欢迎大家下载
