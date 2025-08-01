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

#include "drv_debugpin.h"

// #define DRV_DBG(...) console_printf(__VA_ARGS__)
#define DRV_DBG(...)

/* Debug pin GPIO configurations */
typedef struct {
    GPIO_TypeDef* gpio_port;
    uint16_t gpio_pin;
    uint8_t pin_source;
} debug_pin_config_t;

/* Debug pin mapping table */
static const debug_pin_config_t debug_pin_configs[DEBUG_PIN_NUM] = {
    { GPIOE, GPIO_Pin_14, GPIO_PinSource14 },  // DEBUG_PIN_0 - PE14
    { GPIOE, GPIO_Pin_13, GPIO_PinSource13 },  // DEBUG_PIN_1 - PE13
    { GPIOE, GPIO_Pin_11, GPIO_PinSource11 },  // DEBUG_PIN_2 - PE11
    { GPIOE, GPIO_Pin_9,  GPIO_PinSource9  },  // DEBUG_PIN_3 - PE9
    { GPIOD, GPIO_Pin_13, GPIO_PinSource13 },  // DEBUG_PIN_4 - PD13
    { GPIOD, GPIO_Pin_14, GPIO_PinSource14 },  // DEBUG_PIN_5 - PD14
};

/* Debug pin states tracking */
static debug_pin_state_t debug_pin_states[DEBUG_PIN_NUM] = {0};

/**
 * @brief Initialize debug pin GPIO
 */
static void _debugpin_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIO clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Configure GPIOE pins (PE14, PE13, PE11, PE9) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_11 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;           // 输出模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;       // 50MHz速度
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          // 推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;       // 无上下拉
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    /* Configure GPIOD pins (PD13, PD14) */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* Initialize all pins to low state */
    GPIO_ResetBits(GPIOE, GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_11 | GPIO_Pin_9);
    GPIO_ResetBits(GPIOD, GPIO_Pin_13 | GPIO_Pin_14);

    /* Reset states tracking */
    for (int i = 0; i < DEBUG_PIN_NUM; i++) {
        debug_pin_states[i] = DEBUG_PIN_LOW;
    }

    DRV_DBG("Debug pins initialized\n");
}

rt_err_t drv_debugpin_init(void)
{
    _debugpin_gpio_init();
    
    DRV_DBG("Debug pin driver initialized successfully\n");
    
    return RT_EOK;
}

rt_err_t debugpin_set_pull(debug_pin_id_t pin_id, debug_pin_pull_t pull_mode)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    if (pin_id >= DEBUG_PIN_NUM) {
        return RT_EINVAL;
    }
    
    const debug_pin_config_t* config = &debug_pin_configs[pin_id];
    
    /* Re-configure the pin with new pull mode */
    GPIO_InitStructure.GPIO_Pin = config->gpio_pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    switch (pull_mode) {
        case DEBUG_PIN_PULLUP:
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
            break;
        case DEBUG_PIN_PULLDOWN:
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
            break;
        case DEBUG_PIN_NOPULL:
        default:
            GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
            break;
    }
    
    GPIO_Init(config->gpio_port, &GPIO_InitStructure);
    
    DRV_DBG("Debug pin %d pull mode set to %d\n", pin_id, pull_mode);
    
    return RT_EOK;
}

rt_err_t debugpin_set_state(debug_pin_id_t pin_id, debug_pin_state_t state)
{
    if (pin_id >= DEBUG_PIN_NUM) {
        return RT_EINVAL;
    }
    
    const debug_pin_config_t* config = &debug_pin_configs[pin_id];
    
    if (state == DEBUG_PIN_HIGH) {
        GPIO_SetBits(config->gpio_port, config->gpio_pin);
        debugpin_set_high(pin_id);
    } else {
        GPIO_ResetBits(config->gpio_port, config->gpio_pin);
        debugpin_set_low(pin_id);
    }
    
    debug_pin_states[pin_id] = state;
    
    return RT_EOK;
}

rt_err_t debugpin_toggle(debug_pin_id_t pin_id)
{
    if (pin_id >= DEBUG_PIN_NUM) {
        return RT_EINVAL;
    }
    
    debug_pin_state_t current_state = debug_pin_states[pin_id];
    debug_pin_state_t new_state = (current_state == DEBUG_PIN_HIGH) ? DEBUG_PIN_LOW : DEBUG_PIN_HIGH;
    
    return debugpin_set_state(pin_id, new_state);
}

debug_pin_state_t debugpin_get_state(debug_pin_id_t pin_id)
{
    if (pin_id >= DEBUG_PIN_NUM) {
        return DEBUG_PIN_LOW;  // 默认返回低电平
    }
    
    const debug_pin_config_t* config = &debug_pin_configs[pin_id];
    
    /* Read actual pin state from GPIO */
    if (GPIO_ReadOutputDataBit(config->gpio_port, config->gpio_pin) == Bit_SET) {
        debug_pin_states[pin_id] = DEBUG_PIN_HIGH;
    } else {
        debug_pin_states[pin_id] = DEBUG_PIN_LOW;
    }
    
    return debug_pin_states[pin_id];
}
