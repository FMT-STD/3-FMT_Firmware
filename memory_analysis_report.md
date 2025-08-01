# FMT Firmware 内存占用分析报告

## 总体内存使用情况

| 内存类型 | 大小 (bytes) | 大小 (KB) | 百分比 |
|---------|-------------|-----------|--------|
| **Flash总计** | 231,478 | 226.1 | 100% |
| - .text (代码段) | 151,328 | 147.8 | 65.4% |
| - .rodata (只读数据) | 69,333 | 67.7 | 30.0% |
| - .data (初始化数据) | 10,817 | 10.6 | 4.7% |
| **RAM总计** | 24,380 | 23.8 | 100% |
| - .data (初始化数据) | 10,817 | 10.6 | 44.4% |
| - .bss (未初始化数据) | 13,563 | 13.2 | 55.6% |

## 内存占用可视化

### Flash使用分布
```
Text段:   ████████████████████████████████ 147.8KB
RoData段: ██████████████ 67.7KB  
Data段:   ██ 10.6KB
```

### RAM使用分布
```
Data段: ██████████████████████ 10.6KB
BSS段:  ███████████████████████████ 13.2KB
```

## Top 30 内存占用最大的目标文件

| 排名 | 文件名 | 大小 (bytes) | 大小 (KB) | 百分比 |
|------|--------|-------------|-----------|--------|
| 1 | `calibration.o` | 118,288 | 115.5 | 51.10% |
| 2 | `INS.o` | 10,760 | 10.5 | 4.65% |
| 3 | `ff.o` | 10,128 | 9.9 | 4.38% |
| 4 | `Plant.o` | 7,724 | 7.5 | 3.34% |
| 5 | `ins_interface.o` | 5,898 | 5.8 | 2.55% |
| 6 | `light_matrix.o` | 4,683 | 4.6 | 2.02% |
| 7 | `control_interface.o` | 4,378 | 4.3 | 1.89% |
| 8 | `FMS.o` | 4,004 | 3.9 | 1.73% |
| 9 | `toml.o` | 3,912 | 3.8 | 1.69% |
| 10 | `mavlink_param.o` | 3,459 | 3.4 | 1.49% |
| 11 | `board.o` | 3,321 | 3.2 | 1.43% |
| 12 | `fms_interface.o` | 3,310 | 3.2 | 1.43% |
| 13 | `cmd_param.o` | 3,021 | 3.0 | 1.31% |
| 14 | `cmd.o` | 2,745 | 2.7 | 1.19% |
| 15 | `cm_backtrace.o` | 2,578 | 2.5 | 1.11% |
| 16 | `msh_file.o` | 2,389 | 2.3 | 1.03% |
| 17 | `dfs_posix.o` | 2,089 | 2.0 | 0.90% |
| 18 | `cmd_calib.o` | 2,051 | 2.0 | 0.89% |
| 19 | `dfs_file.o` | 2,037 | 2.0 | 0.88% |
| 20 | `cmd_act.o` | 1,902 | 1.9 | 0.82% |
| 21 | `time.o` | 1,714 | 1.7 | 0.74% |
| 22 | `mavlink_status.o` | 1,547 | 1.5 | 0.67% |
| 23 | `pilot_cmd_config.o` | 1,513 | 1.5 | 0.65% |
| 24 | `sensor_hub.o` | 1,423 | 1.4 | 0.61% |
| 25 | `drv_gpio.o` | 1,284 | 1.3 | 0.55% |
| 26 | `mem.o` | 1,260 | 1.2 | 0.54% |
| 27 | `ipc.o` | 1,142 | 1.1 | 0.49% |
| 28 | `drv_usart.o` | 1,124 | 1.1 | 0.49% |
| 29 | `dfs.o` | 1,083 | 1.1 | 0.47% |
| 30 | `dfs_fs.o` | 992 | 1.0 | 0.43% |


## 模块分类分析

### 内核模块 (RT-Thread)
| 模块 | 大小 (KB) |
|------|-----------|
| `ff.o` | 9.9 |
| `cmd.o` | 2.7 |
| `msh_file.o` | 2.3 |
| `dfs_posix.o` | 2.0 |
| `dfs_file.o` | 2.0 |
| `time.o` | 1.7 |
| `mem.o` | 1.2 |
| `ipc.o` | 1.1 |
| `dfs.o` | 1.1 |
| `dfs_fs.o` | 1.0 |
| `cpuport.o` | 0.7 |
| `syscalls.o` | 0.5 |
| `thread.o` | 0.4 |
| `mempool.o` | 0.3 |
| `context_gcc.o` | 0.3 |
| `kservice.o` | 0.3 |
| `dfs_elm.o` | 0.3 |
| `device.o` | 0.2 |
| `timer.o` | 0.2 |
| `msh.o` | 0.2 |
| `idle.o` | 0.2 |
| `shell.o` | 0.2 |
| `object.o` | 0.1 |
| `dataqueue.o` | 0.1 |
| `cxx_crt.o` | 0.1 |
| `ringblk_buf.o` | 0.1 |
| `completion.o` | 0.1 |
| `scheduler.o` | 0.1 |
| `dfs_romfs.o` | 0.1 |
| `workqueue.o` | 0.1 |
| `waitqueue.o` | 0.0 |
| `pipe.o` | 0.0 |
| `showmem.o` | 0.0 |
| `crt_init.o` | 0.0 |
| `backtrace.o` | 0.0 |
| `ringbuffer.o` | 0.0 |
| `romfs.o` | 0.0 |
| `stdio.o` | 0.0 |
| `div0.o` | 0.0 |
| `clock.o` | 0.0 |
| `components.o` | 0.0 |
| `irq.o` | 0.0 |
| `signal.o` | 0.0 |
| `cxx_Mutex.o` | 0.0 |
| `cxx_Semaphore.o` | 0.0 |
| `cxx_Thread.o` | 0.0 |
| `ffunicode.o` | 0.0 |
| `libc.o` | 0.0 |
| `libc_syms.o` | 0.0 |
| **内核总计** | **29.9** |

### FMT应用模块
| 模块 | 大小 (KB) |
|------|-----------|
| `calibration.o` | 115.5 |
| `INS.o` | 10.5 |
| `Plant.o` | 7.5 |
| `ins_interface.o` | 5.8 |
| `light_matrix.o` | 4.6 |
| `control_interface.o` | 4.3 |
| `FMS.o` | 3.9 |
| `toml.o` | 3.8 |
| `mavlink_param.o` | 3.4 |
| `fms_interface.o` | 3.2 |
| `cmd_param.o` | 3.0 |
| `cm_backtrace.o` | 2.5 |
| `cmd_calib.o` | 2.0 |
| `cmd_act.o` | 1.9 |
| `mavlink_status.o` | 1.5 |
| `pilot_cmd_config.o` | 1.5 |
| `sensor_hub.o` | 1.4 |
| `cmd_mcn.o` | 0.9 |
| `actuator_config.o` | 0.9 |
| `fmtio.o` | 0.8 |
| `gcs_cmd.o` | 0.7 |
| `mission_data.o` | 0.7 |
| `mavlink_console.o` | 0.7 |
| `calibration_param.o` | 0.7 |
| `rc_param.o` | 0.7 |
| `gps_ubx.o` | 0.6 |
| `fmtio_uploader.o` | 0.6 |
| `mavproxy_config.o` | 0.6 |
| `ulog.o` | 0.6 |
| `power_manage.o` | 0.6 |
| `console_config.o` | 0.6 |
| `param.o` | 0.6 |
| `task_status.o` | 0.6 |
| `mavobc.o` | 0.5 |
| `mavproxy_cmd.o` | 0.5 |
| `cmd_adc.o` | 0.5 |
| `cmd_task.o` | 0.5 |
| `pilot_cmd.o` | 0.5 |
| `mavproxy.o` | 0.4 |
| `mpu6000.o` | 0.4 |
| `cmd_fmtio.o` | 0.4 |
| `ms4525.o` | 0.4 |
| `toml_util.o` | 0.3 |
| `cmd_ps.o` | 0.3 |
| `auto_cmd.o` | 0.3 |
| `mavlink_mission.o` | 0.3 |
| `mlog.o` | 0.3 |
| `file_manager.o` | 0.3 |
| `devmq.o` | 0.3 |
| `mavgcs.o` | 0.3 |
| `sensor_airspeed.o` | 0.2 |
| `fmtio_dev.o` | 0.2 |
| `l3gd20h.o` | 0.2 |
| `uMCN.o` | 0.2 |
| `msp.o` | 0.2 |
| `lsm303d.o` | 0.2 |
| `sensor_imu.o` | 0.2 |
| `task_manager.o` | 0.2 |
| `hmc5883.o` | 0.2 |
| `serial.o` | 0.2 |
| `battery.o` | 0.1 |
| `cmd_boot_log.o` | 0.1 |
| `cmd_mlog.o` | 0.1 |
| `boot_log.o` | 0.1 |
| `i2c_bit_ops.o` | 0.1 |
| `ms5611.o` | 0.1 |
| `conversion.o` | 0.1 |
| `task_logger.o` | 0.1 |
| `work_queue.o` | 0.1 |
| `workqueue_manager.o` | 0.1 |
| `sensor_baro.o` | 0.1 |
| `mavlink_rtcm.o` | 0.1 |
| `sensor_gps.o` | 0.1 |
| `startup.o` | 0.1 |
| `sensor_mag.o` | 0.1 |
| `optparse.o` | 0.1 |
| `spi_dev.o` | 0.1 |
| `sys_param.o` | 0.1 |
| `spi_core.o` | 0.1 |
| `cmd_delay.o` | 0.1 |
| `ftp_manager.o` | 0.1 |
| `yxml.o` | 0.1 |
| `gps.o` | 0.1 |
| `adc.o` | 0.1 |
| `barometer.o` | 0.1 |
| `syscmd.o` | 0.1 |
| `i2c_dev.o` | 0.0 |
| `systime.o` | 0.0 |
| `systick.o` | 0.0 |
| `actuator.o` | 0.0 |
| `sbus.o` | 0.0 |
| `accel.o` | 0.0 |
| `gyro.o` | 0.0 |
| `actuator_cmd.o` | 0.0 |
| `mag.o` | 0.0 |
| `pin.o` | 0.0 |
| `cmd_exec.o` | 0.0 |
| `rc.o` | 0.0 |
| `cmd_test.o` | 0.0 |
| `usbd_cdc.o` | 0.0 |
| `rt_nonfinite.o` | 0.0 |
| `mavproxy_dev.o` | 0.0 |
| `tca62724.o` | 0.0 |
| `ap_math.o` | 0.0 |
| `airspeed.o` | 0.0 |
| `task_comm.o` | 0.0 |
| `statistic.o` | 0.0 |
| `task_fmtio.o` | 0.0 |
| `i2c_core.o` | 0.0 |
| `console.o` | 0.0 |
| `task_vehicle.o` | 0.0 |
| `mavproxy_monitor.o` | 0.0 |
| `file_ex_ops.o` | 0.0 |
| `protocol.o` | 0.0 |
| `ppm.o` | 0.0 |
| `plant_interface.o` | 0.0 |
| `Plant_data.o` | 0.0 |
| `FMS_data.o` | 0.0 |
| `Controller.o` | 0.0 |
| `Controller_data.o` | 0.0 |
| `rtGetInf.o` | 0.0 |
| `rtGetNaN.o` | 0.0 |
| `quaternion.o` | 0.0 |
| `rotation.o` | 0.0 |
| `ringbuffer.o` | 0.0 |
| `butter.o` | 0.0 |
| `ublox.o` | 0.0 |
| **FMT模块总计** | **198.5** |

### 库文件
| 模块 | 大小 (KB) |
|------|-----------|
| `calibration.o` | 115.5 |
| `INS.o` | 10.5 |
| `Plant.o` | 7.5 |
| `FMS.o` | 3.9 |
| `cm_backtrace.o` | 2.5 |
| `cmd_calib.o` | 2.0 |
| `time.o` | 1.7 |
| `cpuport.o` | 0.7 |
| `calibration_param.o` | 0.7 |
| `syscalls.o` | 0.5 |
| `stm32f4xx_spi.o` | 0.4 |
| `stm32f4xx_dma.o` | 0.3 |
| `stm32f4xx_tim.o` | 0.3 |
| `context_gcc.o` | 0.3 |
| `stm32f4xx_i2c.o` | 0.2 |
| `stm32f4xx_adc.o` | 0.2 |
| `stm32f4xx_dac.o` | 0.2 |
| `stm32f4xx_rng.o` | 0.1 |
| `stm32f4xx_dbgmcu.o` | 0.1 |
| `stm32f4xx_syscfg.o` | 0.1 |
| `stm32f4xx_flash.o` | 0.1 |
| `stm32f4xx_usart.o` | 0.1 |
| `stm32f4xx_cryp.o` | 0.1 |
| `stm32f4xx_dcmi.o` | 0.1 |
| `stm32f4xx_exti.o` | 0.1 |
| `stm32f4xx_fsmc.o` | 0.1 |
| `stm32f4xx_gpio.o` | 0.1 |
| `stm32f4xx_hash.o` | 0.1 |
| `stm32f4xx_iwdg.o` | 0.1 |
| `stm32f4xx_sdio.o` | 0.1 |
| `stm32f4xx_wwdg.o` | 0.1 |
| `stm32f4xx_can.o` | 0.1 |
| `stm32f4xx_pwr.o` | 0.1 |
| `stm32f4xx_rcc.o` | 0.1 |
| `stm32f4xx_rtc.o` | 0.1 |
| `misc.o` | 0.1 |
| `showmem.o` | 0.0 |
| `backtrace.o` | 0.0 |
| `rt_nonfinite.o` | 0.0 |
| `startup_stm32f427x.o` | 0.0 |
| `stdio.o` | 0.0 |
| `div0.o` | 0.0 |
| `stm32f4xx_crc.o` | 0.0 |
| `stm32f4xx_cryp_aes.o` | 0.0 |
| `stm32f4xx_cryp_des.o` | 0.0 |
| `stm32f4xx_cryp_tdes.o` | 0.0 |
| `stm32f4xx_hash_md5.o` | 0.0 |
| `stm32f4xx_hash_sha1.o` | 0.0 |
| `arm_cos_f32.o` | 0.0 |
| `arm_sin_f32.o` | 0.0 |
| `arm_abs_f32.o` | 0.0 |
| `arm_add_f32.o` | 0.0 |
| `arm_dot_prod_f32.o` | 0.0 |
| `arm_mult_f32.o` | 0.0 |
| `arm_negate_f32.o` | 0.0 |
| `arm_offset_f32.o` | 0.0 |
| `arm_scale_f32.o` | 0.0 |
| `arm_sub_f32.o` | 0.0 |
| `arm_mat_add_f32.o` | 0.0 |
| `arm_mat_init_f32.o` | 0.0 |
| `arm_mat_inverse_f32.o` | 0.0 |
| `arm_mat_mult_f32.o` | 0.0 |
| `arm_mat_scale_f32.o` | 0.0 |
| `arm_mat_sub_f32.o` | 0.0 |
| `arm_mat_trans_f32.o` | 0.0 |
| `arm_copy_f32.o` | 0.0 |
| `arm_fill_f32.o` | 0.0 |
| `libc.o` | 0.0 |
| `libc_syms.o` | 0.0 |
| `Plant_data.o` | 0.0 |
| `FMS_data.o` | 0.0 |
| `Controller.o` | 0.0 |
| `Controller_data.o` | 0.0 |
| `rtGetInf.o` | 0.0 |
| `rtGetNaN.o` | 0.0 |
| **库文件总计** | **148.9** |

## 优化建议

### 1. 代码优化
- **最大的模块**: calibration.o (115.5KB)
- **建议**: 检查是否有未使用的函数可以移除
- **编译优化**: 确保使用 `-Os` 或 `-O2` 优化级别

### 2. 库优化
- 总库文件占用: 148.9KB (65.9%)
- **建议**: 检查是否有未使用的库函数被链接进来
- **工具**: 使用 `--gc-sections` 链接选项移除未使用的段

### 3. 数据优化
- BSS段占用: 13.2KB
- **建议**: 检查大的全局数组和静态变量
- **优化**: 考虑使用动态分配或减小数组大小

### 4. 目标设备限制
- **STM32F427/437**: Flash: 1MB, RAM: 256KB
- **当前Flash使用**: 226.1KB (22.1%)
- **当前RAM使用**: 23.8KB (9.3%)

### 5. 立即优化项
- 检查 `calibration.o` 是否有优化空间
- 检查 `INS.o` 是否有优化空间

## 技术说明

- **分析时间**: 2025-07-31 22:50:44
- **分析工具**: Python MAP文件解析器
- **数据来源**: `fmt_pixhawk-fmuv2.map`
- **目标平台**: Pixhawk FMUv2 (STM32F427)

---
*此报告由自动化工具生成，建议结合实际代码审查进行优化决策*
