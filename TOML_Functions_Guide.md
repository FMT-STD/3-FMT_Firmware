# TOML函数使用指南

## 概述

本文档详细介绍了FMT固件中使用的TOML解析函数，包括函数签名、参数说明、返回值和使用示例。

## 函数列表

### 1. `toml_key_in(table, index)`

**功能**：获取表格中第index个键的名称

**函数签名**：
```c
const char* toml_key_in(toml_table_t* table, int index);
```

**参数**：
- `table`：TOML表格指针
- `index`：键的索引（从0开始）

**返回值**：
- **成功**：键名字符串指针
- **失败**：NULL（当index超出范围时）

**使用示例**：
```c
toml_table_t* root_tab = /* 根表格 */;
const char* key;

// 遍历所有键
for (int i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
    printf("键 %d: %s\n", i, key);
}
```

**示例输出**：
```
键 0: target
键 1: console
键 2: mavproxy
键 3: pilot-cmd
```

### 2. `toml_table_in(table, key)`

**功能**：获取表格中指定键对应的子表格

**函数签名**：
```c
toml_table_t* toml_table_in(toml_table_t* table, const char* key);
```

**参数**：
- `table`：父表格指针
- `key`：键名字符串

**返回值**：
- **成功**：子表格指针
- **失败**：NULL（键不存在或不是表格）

**使用示例**：
```c
toml_table_t* root_tab = /* 根表格 */;
toml_table_t* console_tab;
toml_table_t* mavproxy_tab;

// 获取console子表格
console_tab = toml_table_in(root_tab, "console");
if (console_tab != NULL) {
    printf("找到console表格\n");
}

// 获取mavproxy子表格
mavproxy_tab = toml_table_in(root_tab, "mavproxy");
if (mavproxy_tab != NULL) {
    printf("找到mavproxy表格\n");
}

// 尝试获取不存在的表格
toml_table_t* nonexistent = toml_table_in(root_tab, "nonexistent");
if (nonexistent == NULL) {
    printf("nonexistent表格不存在\n");
}
```

### 3. `toml_raw_in(table, key)`

**功能**：获取表格中指定键对应的原始值

**函数签名**：
```c
const char* toml_raw_in(toml_table_t* table, const char* key);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串

**返回值**：
- **成功**：原始值字符串指针
- **失败**：NULL（键不存在）

**使用示例**：
```c
toml_table_t* root_tab = /* 根表格 */;
toml_table_t* console_tab = toml_table_in(root_tab, "console");

// 获取顶级键值对
const char* target_value = toml_raw_in(root_tab, "target");
if (target_value != NULL) {
    printf("target = %s\n", target_value);
}

// 获取console表格中的值
const char* console_type = toml_raw_in(console_tab, "type");
const char* console_name = toml_raw_in(console_tab, "name");
const char* console_baudrate = toml_raw_in(console_tab, "baudrate");

if (console_type != NULL) {
    printf("console.type = %s\n", console_type);
}
if (console_name != NULL) {
    printf("console.name = %s\n", console_name);
}
if (console_baudrate != NULL) {
    printf("console.baudrate = %s\n", console_baudrate);
}
```

### 4. `toml_string_in(table, key, &strval)`

**功能**：获取表格中指定键的字符串值

**函数签名**：
```c
int toml_string_in(toml_table_t* table, const char* key, char** strval);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串
- `strval`：输出字符串指针的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_table_t* device_tab = /* device表格 */;
char* device_type;
char* device_name;

// 获取设备类型
if (toml_string_in(device_tab, "type", &device_type) == 0) {
    printf("设备类型: %s\n", device_type);
    rt_free(device_type);  // 需要手动释放内存
}

// 获取设备名称
if (toml_string_in(device_tab, "name", &device_name) == 0) {
    printf("设备名称: %s\n", device_name);
    rt_free(device_name);  // 需要手动释放内存
}
```

### 5. `toml_int_in(table, key, &ival)`

**功能**：获取表格中指定键的整数值

**函数签名**：
```c
int toml_int_in(toml_table_t* table, const char* key, int64_t* ival);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串
- `ival`：输出整数值的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_table_t* device_tab = /* device表格 */;
int64_t channel_num;
int64_t sample_time;

// 获取通道数量
if (toml_int_in(device_tab, "channel-num", &channel_num) == 0) {
    printf("通道数量: %ld\n", channel_num);
}

// 获取采样时间
if (toml_int_in(device_tab, "sample-time", &sample_time) == 0) {
    printf("采样时间: %ld\n", sample_time);
}
```

### 6. `toml_double_in(table, key, &dval)`

**功能**：获取表格中指定键的浮点数值

**函数签名**：
```c
int toml_double_in(toml_table_t* table, const char* key, double* dval);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串
- `dval`：输出浮点数值的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_table_t* device_tab = /* device表格 */;
double sample_time;

// 获取采样时间
if (toml_double_in(device_tab, "sample-time", &sample_time) == 0) {
    printf("采样时间: %f\n", sample_time);
}
```

### 7. `toml_array_in(table, key)`

**功能**：获取表格中指定键对应的数组

**函数签名**：
```c
toml_array_t* toml_array_in(toml_table_t* table, const char* key);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串

**返回值**：
- **成功**：数组指针
- **失败**：NULL（键不存在或不是数组）

**使用示例**：
```c
toml_table_t* pilot_cmd_tab = /* pilot-cmd表格 */;
toml_array_t* stick_channel_arr;

// 获取摇杆通道数组
stick_channel_arr = toml_array_in(pilot_cmd_tab, "stick-channel");
if (stick_channel_arr != NULL) {
    printf("找到摇杆通道数组\n");
    // 进一步处理数组内容
}
```

### 8. `toml_array_value_in(table, key, &arr)`

**功能**：获取表格中指定键的值数组

**函数签名**：
```c
int toml_array_value_in(toml_table_t* table, const char* key, toml_array_t** arr);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串
- `arr`：输出数组指针的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_table_t* pilot_cmd_tab = /* pilot-cmd表格 */;
toml_array_t* stick_channel_arr;

// 获取摇杆通道数组
if (toml_array_value_in(pilot_cmd_tab, "stick-channel", &stick_channel_arr) == 0) {
    printf("成功获取摇杆通道数组\n");
    // 处理数组内容
}
```

### 9. `toml_array_table_in(table, key, &arr)`

**功能**：获取表格中指定键的表格数组

**函数签名**：
```c
int toml_array_table_in(toml_table_t* table, const char* key, toml_array_t** arr);
```

**参数**：
- `table`：表格指针
- `key`：键名字符串
- `arr`：输出表格数组指针的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_table_t* pilot_cmd_tab = /* pilot-cmd表格 */;
toml_array_t* mode_arr;

// 获取模式数组
if (toml_array_table_in(pilot_cmd_tab, "mode", &mode_arr) == 0) {
    printf("成功获取模式数组\n");
    // 处理表格数组内容
}
```

### 10. `toml_array_nelem(arr)`

**功能**：获取数组的元素数量

**函数签名**：
```c
int toml_array_nelem(toml_array_t* arr);
```

**参数**：
- `arr`：数组指针

**返回值**：
- 数组元素数量

**使用示例**：
```c
toml_array_t* stick_channel_arr = /* 摇杆通道数组 */;
int elem_count = toml_array_nelem(stick_channel_arr);
printf("数组元素数量: %d\n", elem_count);
```

### 11. `toml_array_at(arr, index)`

**功能**：获取数组中指定索引的元素

**函数签名**：
```c
toml_table_t* toml_array_at(toml_array_t* arr, int index);
```

**参数**：
- `arr`：数组指针
- `index`：元素索引

**返回值**：
- **成功**：表格指针（对于表格数组）
- **失败**：NULL（索引超出范围）

**使用示例**：
```c
toml_array_t* mode_arr = /* 模式数组 */;
int mode_count = toml_array_nelem(mode_arr);

for (int i = 0; i < mode_count; i++) {
    toml_table_t* mode_tab = toml_array_at(mode_arr, i);
    if (mode_tab != NULL) {
        printf("处理模式 %d\n", i);
        // 处理单个模式表格
    }
}
```

### 12. `toml_int_at(arr, index, &ival)`

**功能**：获取数组中指定索引的整数值

**函数签名**：
```c
int toml_int_at(toml_array_t* arr, int index, int64_t* ival);
```

**参数**：
- `arr`：数组指针
- `index`：元素索引
- `ival`：输出整数值的地址

**返回值**：
- **成功**：0
- **失败**：非0值

**使用示例**：
```c
toml_array_t* stick_channel_arr = /* 摇杆通道数组 */;
int64_t channel_val;

// 获取第一个通道值
if (toml_int_at(stick_channel_arr, 0, &channel_val) == 0) {
    printf("第一个通道: %ld\n", channel_val);
}

// 获取第二个通道值
if (toml_int_at(stick_channel_arr, 1, &channel_val) == 0) {
    printf("第二个通道: %ld\n", channel_val);
}
```

## 完整示例

### TOML配置文件示例
```toml
target = "Amov-ICF5"

[console]
type = "serial"
name = "serial0"
baudrate = 57600

[console.devices]
type = "mavlink"
name = "mav_console"

[mavproxy]
chan = 0
type = "serial"

[pilot-cmd]
stick-channel = [4,3,1,2]

[pilot-cmd.device]
type = "rc"
name = "rc"
protocol = "auto"
channel-num = 8
sample-time = 0.05
range = [1000,2000]

[[pilot-cmd.mode]]
mode = 5
channel = 5
range = [1000,1300]

[[pilot-cmd.mode]]
mode = 4
channel = 5
range = [1400,1600]

[[pilot-cmd.command]]
type = 1
cmd = 1002
channel = 6
range = [1800,2000]
```

### 完整解析示例
```c
#include <firmament.h>
#include "module/toml/toml.h"

void parse_toml_config(toml_table_t* root_tab) {
    int i;
    const char* key;
    toml_table_t* sub_tab;
    toml_array_t* arr;
    int64_t ival;
    char* strval;
    
    printf("=== TOML配置解析示例 ===\n");
    
    // 1. 遍历所有顶级键
    printf("\n1. 遍历顶级键:\n");
    for (i = 0; 0 != (key = toml_key_in(root_tab, i)); i++) {
        printf("  键 %d: %s\n", i, key);
    }
    
    // 2. 获取顶级键值对
    printf("\n2. 顶级键值对:\n");
    const char* target_value = toml_raw_in(root_tab, "target");
    if (target_value != NULL) {
        printf("  target = %s\n", target_value);
    }
    
    // 3. 处理console表格
    printf("\n3. Console配置:\n");
    toml_table_t* console_tab = toml_table_in(root_tab, "console");
    if (console_tab != NULL) {
        if (toml_string_in(console_tab, "type", &strval) == 0) {
            printf("  console.type = %s\n", strval);
            rt_free(strval);
        }
        
        if (toml_string_in(console_tab, "name", &strval) == 0) {
            printf("  console.name = %s\n", strval);
            rt_free(strval);
        }
        
        if (toml_int_in(console_tab, "baudrate", &ival) == 0) {
            printf("  console.baudrate = %ld\n", ival);
        }
    }
    
    // 4. 处理pilot-cmd表格
    printf("\n4. Pilot-CMD配置:\n");
    toml_table_t* pilot_cmd_tab = toml_table_in(root_tab, "pilot-cmd");
    if (pilot_cmd_tab != NULL) {
        // 处理stick-channel数组
        if (toml_array_value_in(pilot_cmd_tab, "stick-channel", &arr) == 0) {
            printf("  摇杆通道映射: [");
            int elem_count = toml_array_nelem(arr);
            for (int j = 0; j < elem_count; j++) {
                if (toml_int_at(arr, j, &ival) == 0) {
                    printf("%ld", ival);
                    if (j < elem_count - 1) printf(", ");
                }
            }
            printf("]\n");
        }
        
        // 处理device子表格
        toml_table_t* device_tab = toml_table_in(pilot_cmd_tab, "device");
        if (device_tab != NULL) {
            if (toml_string_in(device_tab, "type", &strval) == 0) {
                printf("  device.type = %s\n", strval);
                rt_free(strval);
            }
            
            if (toml_string_in(device_tab, "name", &strval) == 0) {
                printf("  device.name = %s\n", strval);
                rt_free(strval);
            }
            
            if (toml_string_in(device_tab, "protocol", &strval) == 0) {
                printf("  device.protocol = %s\n", strval);
                rt_free(strval);
            }
            
            if (toml_int_in(device_tab, "channel-num", &ival) == 0) {
                printf("  device.channel-num = %ld\n", ival);
            }
        }
        
        // 处理mode数组
        if (toml_array_table_in(pilot_cmd_tab, "mode", &arr) == 0) {
            int mode_count = toml_array_nelem(arr);
            printf("  飞行模式配置 (%d个):\n", mode_count);
            
            for (int j = 0; j < mode_count; j++) {
                toml_table_t* mode_tab = toml_array_at(arr, j);
                if (mode_tab != NULL) {
                    if (toml_int_in(mode_tab, "mode", &ival) == 0) {
                        printf("    模式 %d: mode=%ld\n", j, ival);
                    }
                    
                    if (toml_int_in(mode_tab, "channel", &ival) == 0) {
                        printf("      通道: %ld\n", ival);
                    }
                }
            }
        }
        
        // 处理command数组
        if (toml_array_table_in(pilot_cmd_tab, "command", &arr) == 0) {
            int cmd_count = toml_array_nelem(arr);
            printf("  命令配置 (%d个):\n", cmd_count);
            
            for (int j = 0; j < cmd_count; j++) {
                toml_table_t* cmd_tab = toml_array_at(arr, j);
                if (cmd_tab != NULL) {
                    if (toml_int_in(cmd_tab, "type", &ival) == 0) {
                        printf("    命令 %d: type=%ld\n", j, ival);
                    }
                    
                    if (toml_int_in(cmd_tab, "cmd", &ival) == 0) {
                        printf("      命令ID: %ld\n", ival);
                    }
                }
            }
        }
    }
    
    printf("\n=== 解析完成 ===\n");
}
```

## 注意事项

1. **内存管理**：使用 `toml_string_in()` 获取的字符串需要手动释放内存
2. **错误检查**：所有函数调用都应该检查返回值
3. **类型安全**：确保获取的值类型与预期一致
4. **数组边界**：访问数组元素前检查索引范围
5. **NULL检查**：使用指针前检查是否为NULL

## 总结

这些TOML函数提供了完整的配置文件解析功能，支持：
- 表格和子表格的访问
- 键值对的读取
- 数组的处理
- 多种数据类型的支持

通过合理组合这些函数，可以实现复杂配置文件的解析和处理。 