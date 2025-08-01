/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include <firmament.h>

#include "module/task_manager/task_manager.h"

#undef LOG_TAG
#define LOG_TAG "PinTask"

#define FMT_USING_DEBUG_PIN

#ifdef FMT_USING_DEBUG_PIN
#include "module/debug_pin/drv_debugpin.h"

#define EVENT_PIN_UPDATE (1 << 0)

static struct rt_timer timer_pin;
static struct rt_event event_pin;

static void timer_pin_update(void* parameter)
{
    rt_event_send(&event_pin, EVENT_PIN_UPDATE);
}

static void pin_sequence_control(void)
{
    static uint8_t sequence_step = 0;
    static uint32_t last_step_time = 0;
    uint32_t current_time = systime_now_ms();
    
    switch (sequence_step) {
        case 0: // 启动序列，设置 PIN0 高电平
            DEBUG_PIN_SET_HIGH(DEBUG_PIN_0);
            LOG_D("PIN0 set HIGH");
            last_step_time = current_time;
            sequence_step++;
            break;
            
        case 1: // 等待10ms后设置 PIN1 高电平
            if (current_time - last_step_time >= 10) {
                DEBUG_PIN_SET_HIGH(DEBUG_PIN_1);
                LOG_D("PIN1 set HIGH");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 2: // 等待10ms后设置 PIN2 高电平
            if (current_time - last_step_time >= 10) {
                DEBUG_PIN_SET_HIGH(DEBUG_PIN_2);
                LOG_D("PIN2 set HIGH");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 3: // 等待10ms后设置 PIN3 高电平
            if (current_time - last_step_time >= 10) {
                DEBUG_PIN_SET_HIGH(DEBUG_PIN_3);
                LOG_D("PIN3 set HIGH");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 4: // 等待10ms后设置 PIN4 高电平
            if (current_time - last_step_time >= 10) {
                DEBUG_PIN_SET_HIGH(DEBUG_PIN_4);
                LOG_D("PIN4 set HIGH");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 5: // 等待10ms后设置 PIN5 高电平
            if (current_time - last_step_time >= 10) {
                DEBUG_PIN_SET_HIGH(DEBUG_PIN_5);
                LOG_D("PIN5 set HIGH");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 6: // 等待10ms后一起设置所有PIN为低电平
            if (current_time - last_step_time >= 10) {
                for (int i = 0; i < DEBUG_PIN_NUM; i++) {
                    DEBUG_PIN_SET_LOW((debug_pin_id_t)i);
                }
                LOG_D("All PINs set LOW");
                last_step_time = current_time;
                sequence_step++;
            }
            break;
            
        case 7: // 等待一段时间后重新开始序列
            if (current_time - last_step_time >= 100) { // 等待100ms
                sequence_step = 0; // 重新开始序列
                LOG_D("Sequence restart");
            }
            break;
            
        default:
            sequence_step = 0;
            break;
    }
}

void task_pin_entry(void* parameter)
{
    rt_err_t res;
    rt_uint32_t recv_set = 0;
    uint32_t wait_set = EVENT_PIN_UPDATE;

    LOG_I("Pin task started");

    while (1) {
        res = rt_event_recv(&event_pin, wait_set, RT_EVENT_FLAG_OR | RT_EVENT_FLAG_CLEAR, RT_WAITING_FOREVER, &recv_set);

        if (res == RT_EOK) {
            if (recv_set & EVENT_PIN_UPDATE) {
                /* 执行PIN序列控制 */
                pin_sequence_control();
            }
        }
    }
}

fmt_err_t task_pin_init(void)
{
    /* 初始化调试引脚 */
    if (drv_debugpin_init() != RT_EOK) {
        LOG_E("Failed to initialize debug pins");
        return FMT_ERROR;
    }

    /* 创建事件 */
    if (rt_event_init(&event_pin, "pin", RT_IPC_FLAG_FIFO) != RT_EOK) {
        LOG_E("Failed to create pin event");
        return FMT_ERROR;
    }

    /* 注册定时器事件，1ms周期以确保精确的时序控制 */
    rt_timer_init(&timer_pin, "pin", timer_pin_update, RT_NULL, 1, RT_TIMER_FLAG_PERIODIC | RT_TIMER_FLAG_HARD_TIMER);
    if (rt_timer_start(&timer_pin) != RT_EOK) {
        LOG_E("Failed to start pin timer");
        return FMT_ERROR;
    }

    LOG_I("Pin task initialized successfully");
    return FMT_EOK;
}

#else /* FMT_USING_DEBUG_PIN */

void task_pin_entry(void* parameter)
{
    LOG_W("Debug pin support is disabled");
    while (1) {
        sys_msleep(1000);
    }
}

fmt_err_t task_pin_init(void)
{
    LOG_W("Debug pin support is disabled, pin task will not function");
    return FMT_EOK;
}

#endif /* FMT_USING_DEBUG_PIN */

TASK_EXPORT __fmt_task_desc = {
    .name = "pin",
    .init = task_pin_init,
    .entry = task_pin_entry,
    .priority = 25, /* 中等优先级 */
    .auto_start = true,
    .stack_size = 2048,
    .param = NULL,
    .dependency = NULL
};
