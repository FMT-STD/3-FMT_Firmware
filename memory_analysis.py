#!/usr/bin/env python3
"""
Memory Analysis Script for FMT Firmware MAP file
"""

import re
import os
from collections import defaultdict

def analyze_map_file(map_file_path):
    """分析MAP文件并提取内存使用信息"""
    
    # 存储分析结果
    section_sizes = defaultdict(int)
    object_sizes = defaultdict(int)
    total_sizes = {'text': 0, 'data': 0, 'bss': 0, 'rodata': 0}
    
    with open(map_file_path, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()
    
    # 分析每一行
    for line in lines:
        line = line.strip()
        
        # 匹配内存段信息
        # 格式: .text.function_name 0x00000000 0x123 object_file.o
        section_match = re.match(r'^\s*(\.\w+(?:\.\w+)*)\s+0x[0-9a-fA-F]+\s+0x([0-9a-fA-F]+)\s+(.+\.o)$', line)
        if section_match:
            section_name = section_match.group(1)
            size = int(section_match.group(2), 16)
            object_file = section_match.group(3)
            
            # 提取主要段类型
            main_section = section_name.split('.')[1] if '.' in section_name else section_name
            if main_section in ['text', 'data', 'bss', 'rodata']:
                total_sizes[main_section] += size
                object_sizes[object_file] += size
                section_sizes[section_name] += size
    
    return total_sizes, object_sizes, section_sizes

def create_analysis_report(map_file_path, output_file):
    """创建内存分析报告"""
    
    total_sizes, object_sizes, section_sizes = analyze_map_file(map_file_path)
    
    # 计算总内存使用
    total_flash = total_sizes['text'] + total_sizes['data'] + total_sizes['rodata']
    total_ram = total_sizes['data'] + total_sizes['bss']
    
    # 排序
    sorted_objects = sorted(object_sizes.items(), key=lambda x: x[1], reverse=True)
    
    # 生成Markdown报告
    report = f"""# FMT Firmware 内存占用分析报告

## 总体内存使用情况

| 内存类型 | 大小 (bytes) | 大小 (KB) | 百分比 |
|---------|-------------|-----------|--------|
| **Flash总计** | {total_flash:,} | {total_flash/1024:.1f} | 100% |
| - .text (代码段) | {total_sizes['text']:,} | {total_sizes['text']/1024:.1f} | {total_sizes['text']/total_flash*100:.1f}% |
| - .rodata (只读数据) | {total_sizes['rodata']:,} | {total_sizes['rodata']/1024:.1f} | {total_sizes['rodata']/total_flash*100:.1f}% |
| - .data (初始化数据) | {total_sizes['data']:,} | {total_sizes['data']/1024:.1f} | {total_sizes['data']/total_flash*100:.1f}% |
| **RAM总计** | {total_ram:,} | {total_ram/1024:.1f} | 100% |
| - .data (初始化数据) | {total_sizes['data']:,} | {total_sizes['data']/1024:.1f} | {total_sizes['data']/total_ram*100:.1f}% |
| - .bss (未初始化数据) | {total_sizes['bss']:,} | {total_sizes['bss']/1024:.1f} | {total_sizes['bss']/total_ram*100:.1f}% |

## 内存占用可视化

### Flash使用分布
```
Text段:   {'█' * int(total_sizes['text']/total_flash*50)} {total_sizes['text']/1024:.1f}KB
RoData段: {'█' * int(total_sizes['rodata']/total_flash*50)} {total_sizes['rodata']/1024:.1f}KB  
Data段:   {'█' * int(total_sizes['data']/total_flash*50)} {total_sizes['data']/1024:.1f}KB
```

### RAM使用分布
```
Data段: {'█' * int(total_sizes['data']/total_ram*50 if total_ram > 0 else 0)} {total_sizes['data']/1024:.1f}KB
BSS段:  {'█' * int(total_sizes['bss']/total_ram*50 if total_ram > 0 else 0)} {total_sizes['bss']/1024:.1f}KB
```

## Top 30 内存占用最大的目标文件

| 排名 | 文件名 | 大小 (bytes) | 大小 (KB) | 百分比 |
|------|--------|-------------|-----------|--------|
"""
    
    for i, (obj_file, size) in enumerate(sorted_objects[:30], 1):
        # 简化文件路径显示
        short_name = obj_file.split('/')[-1] if '/' in obj_file else obj_file
        percentage = size / total_flash * 100 if total_flash > 0 else 0
        report += f"| {i} | `{short_name}` | {size:,} | {size/1024:.1f} | {percentage:.2f}% |\n"
    
    report += f"""

## 模块分类分析

### 内核模块 (RT-Thread)
| 模块 | 大小 (KB) |
|------|-----------|
"""
    
    # 分析内核模块
    kernel_total = 0
    for obj_file, size in sorted_objects:
        if 'kernel/' in obj_file:
            short_name = obj_file.split('/')[-1]
            report += f"| `{short_name}` | {size/1024:.1f} |\n"
            kernel_total += size
    
    report += f"""| **内核总计** | **{kernel_total/1024:.1f}** |

### FMT应用模块
| 模块 | 大小 (KB) |
|------|-----------|
"""
    
    # 分析FMT模块
    fmt_total = 0
    for obj_file, size in sorted_objects:
        if 'fmt/' in obj_file and 'kernel/' not in obj_file:
            short_name = obj_file.split('/')[-1]
            report += f"| `{short_name}` | {size/1024:.1f} |\n"
            fmt_total += size
    
    report += f"""| **FMT模块总计** | **{fmt_total/1024:.1f}** |

### 库文件
| 模块 | 大小 (KB) |
|------|-----------|
"""
    
    # 分析库文件
    lib_total = 0
    for obj_file, size in sorted_objects:
        if any(lib in obj_file for lib in ['lib', 'STM32', 'libraries']):
            short_name = obj_file.split('/')[-1]
            report += f"| `{short_name}` | {size/1024:.1f} |\n"
            lib_total += size
    
    report += f"""| **库文件总计** | **{lib_total/1024:.1f}** |

## 优化建议

### 1. 代码优化
- **最大的模块**: {sorted_objects[0][0].split('/')[-1]} ({sorted_objects[0][1]/1024:.1f}KB)
- **建议**: 检查是否有未使用的函数可以移除
- **编译优化**: 确保使用 `-Os` 或 `-O2` 优化级别

### 2. 库优化
- 总库文件占用: {lib_total/1024:.1f}KB ({lib_total/total_flash*100:.1f}%)
- **建议**: 检查是否有未使用的库函数被链接进来
- **工具**: 使用 `--gc-sections` 链接选项移除未使用的段

### 3. 数据优化
- BSS段占用: {total_sizes['bss']/1024:.1f}KB
- **建议**: 检查大的全局数组和静态变量
- **优化**: 考虑使用动态分配或减小数组大小

### 4. 目标设备限制
- **STM32F427/437**: Flash: 1MB, RAM: 256KB
- **当前Flash使用**: {total_flash/1024:.1f}KB ({total_flash/(1024*1024)*100:.1f}%)
- **当前RAM使用**: {total_ram/1024:.1f}KB ({total_ram/(256*1024)*100:.1f}%)

### 5. 立即优化项
"""
    
    # 找出可能的优化点
    large_objects = [obj for obj, size in sorted_objects[:10] if size > 10240]  # >10KB
    for obj in large_objects:
        report += f"- 检查 `{obj.split('/')[-1]}` 是否有优化空间\n"
    
    report += f"""
## 技术说明

- **分析时间**: {__import__('datetime').datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
- **分析工具**: Python MAP文件解析器
- **数据来源**: `fmt_pixhawk-fmuv2.map`
- **目标平台**: Pixhawk FMUv2 (STM32F427)

---
*此报告由自动化工具生成，建议结合实际代码审查进行优化决策*
"""
    
    # 写入文件
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(report)
    
    return total_sizes, sorted_objects

if __name__ == "__main__":
    map_file = "target/pixhawk/fmu-v2/build/fmt_pixhawk-fmuv2.map"
    output_file = "memory_analysis_report.md"
    
    if os.path.exists(map_file):
        print(f"正在分析MAP文件: {map_file}")
        total_sizes, sorted_objects = create_analysis_report(map_file, output_file)
        print(f"分析完成! 报告已保存到: {output_file}")
        
        # 输出简要信息
        total_flash = total_sizes['text'] + total_sizes['data'] + total_sizes['rodata']
        total_ram = total_sizes['data'] + total_sizes['bss']
        
        print(f"\n=== 内存使用摘要 ===")
        print(f"Flash总计: {total_flash/1024:.1f}KB")
        print(f"RAM总计: {total_ram/1024:.1f}KB")
        print(f"最大单个模块: {sorted_objects[0][0].split('/')[-1]} ({sorted_objects[0][1]/1024:.1f}KB)")
    else:
        print(f"错误: 找不到MAP文件 {map_file}")
