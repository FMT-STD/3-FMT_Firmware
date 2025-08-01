#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re
import os
from datetime import datetime
from collections import defaultdict, OrderedDict

def parse_map_file_for_ram(map_file_path):
    """专门解析MAP文件中的RAM相关信息"""
    
    if not os.path.exists(map_file_path):
        print(f"错误: MAP文件不存在: {map_file_path}")
        return None
    
    print(f"正在深度分析RAM占用: {map_file_path}")
    
    # 存储RAM相关的所有数据
    ram_data = {
        'data_section': {},  # .data段 (初始化数据)
        'bss_section': {},   # .bss段 (未初始化数据)
        'heap_info': {},     # 堆信息
        'stack_info': {},    # 栈信息
        'memory_regions': {},# 内存区域信息
        'symbols': {},       # 符号表
        'section_details': {}# 段详细信息
    }
    
    try:
        with open(map_file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
            
        # 1. 解析内存配置信息
        memory_config_pattern = r'Memory Configuration\s*\n\s*Name\s+Origin\s+Length\s+Attributes\s*\n(.*?)(?=\n\n|\nLinker script)'
        memory_config_match = re.search(memory_config_pattern, content, re.DOTALL)
        if memory_config_match:
            memory_lines = memory_config_match.group(1).strip().split('\n')
            for line in memory_lines:
                line = line.strip()
                if line and not line.startswith('*'):
                    parts = line.split()
                    if len(parts) >= 3:
                        name = parts[0]
                        origin = parts[1]
                        length = parts[2]
                        ram_data['memory_regions'][name] = {
                            'origin': origin,
                            'length': length,
                            'size_bytes': 0
                        }
                        # 转换长度为字节
                        if 'K' in length:
                            ram_data['memory_regions'][name]['size_bytes'] = int(length.replace('K', '')) * 1024
                        elif 'M' in length:
                            ram_data['memory_regions'][name]['size_bytes'] = int(length.replace('M', '')) * 1024 * 1024
        
        # 2. 解析段分配信息
        section_pattern = r'\n(\.[a-zA-Z_][a-zA-Z0-9_]*)\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)(?:\s+(.+?))?\n'
        sections = re.findall(section_pattern, content)
        
        for section_name, address, size, location in sections:
            size_int = int(size, 16)
            if size_int > 0:
                ram_data['section_details'][section_name] = {
                    'address': address,
                    'size': size_int,
                    'location': location.strip() if location else ''
                }
        
        # 3. 详细解析.data和.bss段
        # .data段解析
        data_pattern = r'\.data\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+).*?\n(.*?)(?=\n\.[a-zA-Z]|\n\n|$)'
        data_match = re.search(data_pattern, content, re.DOTALL)
        if data_match:
            data_content = data_match.group(3)
            # 解析.data段中的符号
            symbol_pattern = r'\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(.+?)$'
            for line in data_content.split('\n'):
                line = line.strip()
                if line:
                    symbol_match = re.match(symbol_pattern, line)
                    if symbol_match:
                        addr, size, symbol = symbol_match.groups()
                        size_int = int(size, 16)
                        if size_int > 0:
                            # 提取文件名
                            file_name = 'unknown'
                            if '(' in symbol and ')' in symbol:
                                file_part = symbol.split('(')[-1].split(')')[0]
                                if file_part:
                                    file_name = file_part
                            
                            if file_name not in ram_data['data_section']:
                                ram_data['data_section'][file_name] = 0
                            ram_data['data_section'][file_name] += size_int
        
        # .bss段解析
        bss_pattern = r'\.bss\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+).*?\n(.*?)(?=\n\.[a-zA-Z]|\n\n|$)'
        bss_match = re.search(bss_pattern, content, re.DOTALL)
        if bss_match:
            bss_content = bss_match.group(3)
            # 解析.bss段中的符号
            for line in bss_content.split('\n'):
                line = line.strip()
                if line:
                    symbol_match = re.match(symbol_pattern, line)
                    if symbol_match:
                        addr, size, symbol = symbol_match.groups()
                        size_int = int(size, 16)
                        if size_int > 0:
                            # 提取文件名
                            file_name = 'unknown'
                            if '(' in symbol and ')' in symbol:
                                file_part = symbol.split('(')[-1].split(')')[0]
                                if file_part:
                                    file_name = file_part
                            
                            if file_name not in ram_data['bss_section']:
                                ram_data['bss_section'][file_name] = 0
                            ram_data['bss_section'][file_name] += size_int
        
        # 4. 查找所有RAM相关的符号
        all_symbols_pattern = r'\s+(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+([^\n]+)'
        all_symbols = re.findall(all_symbols_pattern, content)
        
        for addr, size, symbol_info in all_symbols:
            size_int = int(size, 16)
            if size_int > 0:
                # 检查是否在RAM区域
                addr_int = int(addr, 16)
                if 0x20000000 <= addr_int <= 0x2003FFFF:  # STM32F4 RAM地址范围
                    ram_data['symbols'][symbol_info] = {
                        'address': addr,
                        'size': size_int,
                        'address_int': addr_int
                    }
        
        # 5. 查找堆栈信息
        heap_pattern = r'_heap_start.*?=\s+(0x[0-9a-fA-F]+)|__heap_start.*?=\s+(0x[0-9a-fA-F]+)'
        stack_pattern = r'_stack.*?=\s+(0x[0-9a-fA-F]+)|__stack.*?=\s+(0x[0-9a-fA-F]+)'
        
        heap_matches = re.findall(heap_pattern, content)
        stack_matches = re.findall(stack_pattern, content)
        
        if heap_matches:
            ram_data['heap_info']['found'] = True
            ram_data['heap_info']['addresses'] = [m for m in heap_matches[0] if m]
        
        if stack_matches:
            ram_data['stack_info']['found'] = True
            ram_data['stack_info']['addresses'] = [m for m in stack_matches[0] if m]
        
        return ram_data
        
    except Exception as e:
        print(f"解析MAP文件时出错: {e}")
        return None

def generate_ram_analysis_report(ram_data, output_file):
    """生成RAM专用分析报告"""
    
    if not ram_data:
        print("错误: 没有RAM数据可分析")
        return False
    
    # 计算总RAM使用量
    total_data = sum(ram_data['data_section'].values())
    total_bss = sum(ram_data['bss_section'].values())
    total_ram = total_data + total_bss
    
    # 合并所有RAM使用数据
    combined_ram = defaultdict(int)
    for file_name, size in ram_data['data_section'].items():
        combined_ram[file_name] += size
    for file_name, size in ram_data['bss_section'].items():
        combined_ram[file_name] += size
    
    # 按大小排序
    sorted_ram = sorted(combined_ram.items(), key=lambda x: x[1], reverse=True)
    
    try:
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write("# FMT Firmware RAM占用深度分析报告\n\n")
            f.write(f"**分析时间**: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n")
            f.write("**⚠️ RAM空间不足问题专项分析 ⚠️**\n\n")
            
            # RAM总览
            f.write("## 🎯 RAM使用总览\n\n")
            f.write("| 内存类型 | 大小 (bytes) | 大小 (KB) | 百分比 |\n")
            f.write("|---------|-------------|-----------|--------|\n")
            f.write(f"| **RAM总计** | {total_ram:,} | {total_ram/1024:.1f} | 100.0% |\n")
            f.write(f"| .data段 (初始化数据) | {total_data:,} | {total_data/1024:.1f} | {total_data/total_ram*100:.1f}% |\n")
            f.write(f"| .bss段 (未初始化数据) | {total_bss:,} | {total_bss/1024:.1f} | {total_bss/total_ram*100:.1f}% |\n\n")
            
            # 内存区域信息
            if ram_data['memory_regions']:
                f.write("## 💾 内存配置信息\n\n")
                f.write("| 内存区域 | 起始地址 | 大小 | 大小(KB) |\n")
                f.write("|---------|---------|------|----------|\n")
                for name, info in ram_data['memory_regions'].items():
                    if 'RAM' in name.upper() or 'SRAM' in name.upper():
                        f.write(f"| {name} | {info['origin']} | {info['length']} | {info['size_bytes']/1024:.1f}KB |\n")
                f.write("\n")
            
            # RAM使用可视化
            f.write("## 📊 RAM使用分布可视化\n\n")
            f.write("```\n")
            f.write("RAM使用分布:\n")
            total_blocks = 50
            data_blocks = int((total_data / total_ram) * total_blocks)
            bss_blocks = total_blocks - data_blocks
            f.write(f".data段: {'█' * data_blocks}{' ' * (25-data_blocks)} {total_data/1024:.1f}KB\n")
            f.write(f".bss段:  {'█' * bss_blocks}{' ' * (25-bss_blocks)} {total_bss/1024:.1f}KB\n")
            f.write("```\n\n")
            
            # Top 50 RAM占用文件
            f.write("## 🔝 Top 50 RAM占用文件排行榜\n\n")
            f.write("| 排名 | 文件名 | RAM占用 (bytes) | RAM占用 (KB) | 占总RAM比例 |\n")
            f.write("|------|--------|----------------|--------------|------------|\n")
            
            for i, (file_name, size) in enumerate(sorted_ram[:50], 1):
                percentage = (size / total_ram) * 100
                f.write(f"| {i} | `{file_name}` | {size:,} | {size/1024:.2f} | {percentage:.2f}% |\n")
            
            f.write("\n")
            
            # .data段详细分析
            if ram_data['data_section']:
                f.write("## 📋 .data段 (初始化数据) 详细分析\n\n")
                f.write("| 排名 | 文件名 | 大小 (bytes) | 大小 (KB) | 占.data段比例 |\n")
                f.write("|------|--------|-------------|-----------|-------------|\n")
                
                sorted_data = sorted(ram_data['data_section'].items(), key=lambda x: x[1], reverse=True)
                for i, (file_name, size) in enumerate(sorted_data[:30], 1):
                    percentage = (size / total_data) * 100 if total_data > 0 else 0
                    f.write(f"| {i} | `{file_name}` | {size:,} | {size/1024:.2f} | {percentage:.2f}% |\n")
                f.write("\n")
            
            # .bss段详细分析  
            if ram_data['bss_section']:
                f.write("## 📋 .bss段 (未初始化数据) 详细分析\n\n")
                f.write("| 排名 | 文件名 | 大小 (bytes) | 大小 (KB) | 占.bss段比例 |\n")
                f.write("|------|--------|-------------|-----------|-------------|\n")
                
                sorted_bss = sorted(ram_data['bss_section'].items(), key=lambda x: x[1], reverse=True)
                for i, (file_name, size) in enumerate(sorted_bss[:30], 1):
                    percentage = (size / total_bss) * 100 if total_bss > 0 else 0
                    f.write(f"| {i} | `{file_name}` | {size:,} | {size/1024:.2f} | {percentage:.2f}% |\n")
                f.write("\n")
            
            # RAM符号分析 (大于1KB的符号)
            large_symbols = [(name, info) for name, info in ram_data['symbols'].items() if info['size'] > 1024]
            if large_symbols:
                f.write("## 🎯 大内存符号分析 (>1KB)\n\n")
                f.write("| 符号名称 | 地址 | 大小 (bytes) | 大小 (KB) |\n")
                f.write("|---------|------|-------------|----------|\n")
                
                large_symbols.sort(key=lambda x: x[1]['size'], reverse=True)
                for name, info in large_symbols[:20]:
                    f.write(f"| `{name}` | {info['address']} | {info['size']:,} | {info['size']/1024:.2f} |\n")
                f.write("\n")
            
            # 模块分类分析
            f.write("## 📦 模块分类RAM占用分析\n\n")
            
            # 分类统计
            categories = {
                'RT-Thread内核': [],
                'FMT应用模块': [],
                '驱动模块': [],
                '算法模块': [],
                '库文件': [],
                '其他': []
            }
            
            for file_name, size in sorted_ram:
                if any(keyword in file_name.lower() for keyword in ['thread', 'rt_', 'dfs', 'finsh', 'device', 'timer', 'mem', 'ipc']):
                    categories['RT-Thread内核'].append((file_name, size))
                elif any(keyword in file_name.lower() for keyword in ['drv_', 'stm32', 'spi', 'i2c', 'usart', 'gpio', 'adc']):
                    categories['驱动模块'].append((file_name, size))
                elif any(keyword in file_name.lower() for keyword in ['ins', 'fms', 'control', 'plant', 'kalman', 'pid']):
                    categories['算法模块'].append((file_name, size))
                elif any(keyword in file_name.lower() for keyword in ['mavlink', 'toml', 'fatfs', 'ff.o', 'printf']):
                    categories['库文件'].append((file_name, size))
                elif any(keyword in file_name.lower() for keyword in ['fmt', 'sensor', 'calibration', 'param', 'log']):
                    categories['FMT应用模块'].append((file_name, size))
                else:
                    categories['其他'].append((file_name, size))
            
            for category, files in categories.items():
                if files:
                    total_category = sum(size for _, size in files)
                    f.write(f"### {category}\n")
                    f.write(f"**总计**: {total_category/1024:.1f}KB ({total_category/total_ram*100:.1f}%)\n\n")
                    f.write("| 文件名 | RAM占用 (KB) |\n")
                    f.write("|--------|---------------|\n")
                    for file_name, size in files[:10]:  # 只显示前10个
                        f.write(f"| `{file_name}` | {size/1024:.2f} |\n")
                    f.write("\n")
            
            # 关键优化建议
            f.write("## 🚨 RAM空间不足 - 关键优化建议\n\n")
            
            # 找出最大的几个RAM占用者
            top_ram_users = sorted_ram[:10]
            
            f.write("### 🎯 立即优化目标\n\n")
            for i, (file_name, size) in enumerate(top_ram_users[:5], 1):
                f.write(f"**{i}. {file_name}** - {size/1024:.2f}KB ({size/total_ram*100:.1f}%)\n")
                
                # 针对性建议
                if 'calibration' in file_name.lower():
                    f.write("   - 检查校准数据表是否过大\n")
                    f.write("   - 考虑将校准数据存储到Flash而非RAM\n")
                    f.write("   - 使用更紧凑的数据结构\n")
                elif 'ins' in file_name.lower():
                    f.write("   - 检查INS算法中的缓冲区大小\n")
                    f.write("   - 减少状态变量的数量\n")
                    f.write("   - 优化矩阵运算的临时变量\n")
                elif 'ff.o' in file_name or 'fatfs' in file_name.lower():
                    f.write("   - 减小FAT文件系统的缓冲区\n")
                    f.write("   - 配置更小的扇区缓存\n")
                elif 'mavlink' in file_name.lower():
                    f.write("   - 减少MAVLink消息缓冲区大小\n")
                    f.write("   - 优化消息队列深度\n")
                else:
                    f.write("   - 检查全局变量和静态数组\n")
                    f.write("   - 考虑使用动态分配\n")
                f.write("\n")
            
            f.write("### 🔧 通用优化策略\n\n")
            f.write("1. **减少静态数组大小**\n")
            f.write("   - 检查所有大于1KB的数组\n")
            f.write("   - 使用动态分配替代静态分配\n")
            f.write("   - 采用内存池管理策略\n\n")
            
            f.write("2. **优化数据结构**\n")
            f.write("   - 使用位域减少结构体大小\n")
            f.write("   - 合并相关的全局变量\n")
            f.write("   - 移除未使用的变量\n\n")
            
            f.write("3. **配置优化**\n")
            f.write("   - 减小RT-Thread堆大小\n")
            f.write("   - 调整任务栈大小\n")
            f.write("   - 优化缓冲区配置\n\n")
            
            f.write("4. **编译优化**\n")
            f.write("   - 使用`-Os`优化代码大小\n")
            f.write("   - 启用链接时优化(LTO)\n")
            f.write("   - 移除调试信息\n\n")
            
            # 紧急修复方案
            f.write("### 🆘 紧急修复方案\n\n")
            if total_ram > 200*1024:  # 如果RAM使用超过200KB
                f.write("**当前RAM使用过高，建议紧急措施:**\n\n")
                f.write("1. **立即禁用非关键功能**\n")
                f.write("   - 暂时禁用日志系统\n")
                f.write("   - 减少MAVLink消息类型\n")
                f.write("   - 简化校准流程\n\n")
                
                f.write("2. **临时减小缓冲区**\n")
                f.write("   - 将所有缓冲区大小减半\n")
                f.write("   - 减少任务栈大小\n")
                f.write("   - 降低消息队列深度\n\n")
            
            # STM32F427 RAM信息
            f.write("### 📋 目标平台信息\n\n")
            f.write("- **芯片**: STM32F427VIT6\n")
            f.write("- **总RAM**: 256KB (SRAM1: 192KB + SRAM2: 64KB)\n")
            f.write(f"- **当前使用**: {total_ram/1024:.1f}KB ({total_ram/(256*1024)*100:.1f}%)\n")
            f.write(f"- **剩余空间**: {(256*1024-total_ram)/1024:.1f}KB\n")
            
            if total_ram > 200*1024:
                f.write("- **⚠️ 警告**: RAM使用率过高！\n")
            elif total_ram > 230*1024:
                f.write("- **🚨 危险**: RAM几乎耗尽！\n")
            
            f.write("\n---\n")
            f.write("*此报告专门针对RAM空间不足问题生成，建议优先处理Top 10文件*\n")
        
        print(f"RAM分析报告已生成: {output_file}")
        return True
        
    except Exception as e:
        print(f"生成报告时出错: {e}")
        return False

def main():
    map_file = "target/pixhawk/fmu-v2/build/fmt_pixhawk-fmuv2.map"
    output_file = "ram_analysis_report.md"
    
    # 解析MAP文件
    ram_data = parse_map_file_for_ram(map_file)
    
    if ram_data:
        # 生成RAM专用分析报告
        success = generate_ram_analysis_report(ram_data, output_file)
        if success:
            # 输出关键信息
            total_data = sum(ram_data['data_section'].values())
            total_bss = sum(ram_data['bss_section'].values())
            total_ram = total_data + total_bss
            
            print(f"\n🎯 RAM分析完成!")
            print(f"RAM总计: {total_ram/1024:.1f}KB")
            print(f".data段: {total_data/1024:.1f}KB")
            print(f".bss段: {total_bss/1024:.1f}KB")
            print(f"使用率: {total_ram/(256*1024)*100:.1f}%")
            
            if total_ram > 200*1024:
                print("⚠️  警告: RAM使用率过高!")
            
            # 显示Top 5 RAM占用文件
            combined_ram = {}
            for file_name, size in ram_data['data_section'].items():
                combined_ram[file_name] = combined_ram.get(file_name, 0) + size
            for file_name, size in ram_data['bss_section'].items():
                combined_ram[file_name] = combined_ram.get(file_name, 0) + size
            
            sorted_ram = sorted(combined_ram.items(), key=lambda x: x[1], reverse=True)
            print("\n🔝 Top 5 RAM占用文件:")
            for i, (file_name, size) in enumerate(sorted_ram[:5], 1):
                print(f"{i}. {file_name}: {size/1024:.2f}KB")
        else:
            print("报告生成失败!")
    else:
        print("MAP文件解析失败!")

if __name__ == "__main__":
    main()
