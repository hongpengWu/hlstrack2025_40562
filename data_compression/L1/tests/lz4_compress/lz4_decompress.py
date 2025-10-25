"""
LZ4 解压缩程序
用于解压 sample.txt.encoded 文件
"""

import sys
import os

def install_lz4_package():
    try:
        import pip
        pip.main(['install', 'lz4'])
        print("LZ4 包安装成功")
        return True
    except Exception as e:
        print(f"安装 LZ4 包失败: {e}")
        return False

def decompress_lz4_file(input_file, output_file):
    try:
        try:
            import lz4
        except ImportError:
            print("未找到 lz4 包，正在安装...")
            if not install_lz4_package():
                return False
            import lz4
        print(f"正在读取文件: {input_file}")
        with open(input_file, 'rb') as f:
            compressed_data = f.read()
        
        print(f"压缩文件大小: {len(compressed_data)} 字节")

        print("正在解压...")
        try:
            decompressed_data = lz4.frame.decompress(compressed_data)
        except AttributeError:
            try:
                import lz4.block
                decompressed_data = lz4.block.decompress(compressed_data)
            except AttributeError:
                print("错误: 无法找到合适的 lz4 解压缩函数")
                print("请尝试安装不同版本的 lz4 包: pip install lz4==3.1.3")
                return False
        
        print(f"解压后大小: {len(decompressed_data)} 字节")
        
        print(f"正在写入解压文件: {output_file}")
        with open(output_file, 'wb') as f:
            f.write(decompressed_data)
        
        print(f"解压成功！文件已保存到: {output_file}")
        return True
        
    except Exception as e:
        print(f"解压失败: {e}")
        return False

def main():
    input_file = "sample.txt.encoded"
    output_file = "sample.txt.decoded"
    
    if not os.path.exists(input_file):
        print(f"错误: 找不到文件 {input_file}")
        return 1
    
    print(f"LZ4 解压缩程序")
    print(f"输入文件: {input_file}")
    print(f"输出文件: {output_file}")
    print("-" * 50)
    
    if decompress_lz4_file(input_file, output_file):
        print("\n解压完成！")
        return 0
    else:
        print("\n解压失败！")
        return 1

if __name__ == "__main__":
    sys.exit(main())
