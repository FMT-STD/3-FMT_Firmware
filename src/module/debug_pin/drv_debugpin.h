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

#ifndef __DRV_DEBUGPIN_H__
#define __DRV_DEBUGPIN_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Debug pin definitions */
#define DEBUG_PIN_NUM           6

/* Debug pin IDs */
typedef enum {
    DEBUG_PIN_0 = 0,    // PE14 - Debug Pin 0
    DEBUG_PIN_1 = 1,    // PE13 - Debug Pin 1  
    DEBUG_PIN_2 = 2,    // PE11 - Debug Pin 2
    DEBUG_PIN_3 = 3,    // PE9  - Debug Pin 3
    DEBUG_PIN_4 = 4,    // PD13 - Debug Pin 4
    DEBUG_PIN_5 = 5,    // PD14 - Debug Pin 5
} debug_pin_id_t;

/* Debug pin pull mode */
typedef enum {
    DEBUG_PIN_PULLUP = 0,      // Pull-up mode
    DEBUG_PIN_PULLDOWN = 1,    // Pull-down mode
    DEBUG_PIN_NOPULL = 2,      // No pull-up/down
} debug_pin_pull_t;

/* Debug pin state */
typedef enum {
    DEBUG_PIN_LOW = 0,         // Low level
    DEBUG_PIN_HIGH = 1,        // High level
} debug_pin_state_t;

/**
 * @brief Initialize debug pins
 * @return rt_err_t RT_EOK on success
 */
rt_err_t drv_debugpin_init(void);

/**
 * @brief Set debug pin pull mode
 * @param pin_id Debug pin ID (0-5)
 * @param pull_mode Pull mode (up/down/none)
 * @return rt_err_t RT_EOK on success
 */
rt_err_t debugpin_set_pull(debug_pin_id_t pin_id, debug_pin_pull_t pull_mode);

/**
 * @brief Set debug pin output state
 * @param pin_id Debug pin ID (0-5)
 * @param state Pin state (high/low)
 * @return rt_err_t RT_EOK on success
 */
rt_err_t debugpin_set_state(debug_pin_id_t pin_id, debug_pin_state_t state);

/**
 * @brief Toggle debug pin state
 * @param pin_id Debug pin ID (0-5)
 * @return rt_err_t RT_EOK on success
 */
rt_err_t debugpin_toggle(debug_pin_id_t pin_id);

/**
 * @brief Get debug pin state
 * @param pin_id Debug pin ID (0-5)
 * @return debug_pin_state_t Current pin state
 */
debug_pin_state_t debugpin_get_state(debug_pin_id_t pin_id);

/**
 * @brief Set debug pin high (inline for performance)
 * @param pin_id Debug pin ID (0-5)
 */
static inline void debugpin_set_high(debug_pin_id_t pin_id)
{
    switch(pin_id) {
        case DEBUG_PIN_0: GPIOE->BSRRL = GPIO_Pin_14; break;
        case DEBUG_PIN_1: GPIOE->BSRRL = GPIO_Pin_13; break;
        case DEBUG_PIN_2: GPIOE->BSRRL = GPIO_Pin_11; break;
        case DEBUG_PIN_3: GPIOE->BSRRL = GPIO_Pin_9;  break;
        case DEBUG_PIN_4: GPIOD->BSRRL = GPIO_Pin_13; break;
        case DEBUG_PIN_5: GPIOD->BSRRL = GPIO_Pin_14; break;
        default: break;
    }
}

/**
 * @brief Set debug pin low (inline for performance)
 * @param pin_id Debug pin ID (0-5)
 */
static inline void debugpin_set_low(debug_pin_id_t pin_id)
{
    switch(pin_id) {
        case DEBUG_PIN_0: GPIOE->BSRRH = GPIO_Pin_14; break;
        case DEBUG_PIN_1: GPIOE->BSRRH = GPIO_Pin_13; break;
        case DEBUG_PIN_2: GPIOE->BSRRH = GPIO_Pin_11; break;
        case DEBUG_PIN_3: GPIOE->BSRRH = GPIO_Pin_9;  break;
        case DEBUG_PIN_4: GPIOD->BSRRH = GPIO_Pin_13; break;
        case DEBUG_PIN_5: GPIOD->BSRRH = GPIO_Pin_14; break;
        default: break;
    }
}

/**
 * @brief Toggle debug pin (inline for performance)
 * @param pin_id Debug pin ID (0-5)
 */
static inline void debugpin_toggle_fast(debug_pin_id_t pin_id)
{
    switch(pin_id) {        
        case DEBUG_PIN_0: GPIOE->ODR ^= GPIO_Pin_14; break;
        case DEBUG_PIN_1: GPIOE->ODR ^= GPIO_Pin_13; break;
        case DEBUG_PIN_2: GPIOE->ODR ^= GPIO_Pin_11; break;
        case DEBUG_PIN_3: GPIOE->ODR ^= GPIO_Pin_9; break;
        case DEBUG_PIN_4: GPIOD->ODR ^= GPIO_Pin_13; break;
        case DEBUG_PIN_5: GPIOD->ODR ^= GPIO_Pin_14; break;
        default: break;
    }
}

/* Macros for easy debugging */
#define DEBUG_PIN_SET_HIGH(pin)     debugpin_set_high(pin)
#define DEBUG_PIN_SET_LOW(pin)      debugpin_set_low(pin)
#define DEBUG_PIN_TOGGLE(pin)       debugpin_toggle_fast(pin)

/* Function timing measurement macros */
#define DEBUG_FUNC_START(pin)       DEBUG_PIN_SET_HIGH(pin)
#define DEBUG_FUNC_END(pin)         DEBUG_PIN_SET_LOW(pin)
#define DEBUG_FUNC_TOGGLE(pin)      DEBUG_PIN_TOGGLE(pin)

#ifdef __cplusplus
}
#endif

#endif /* __DRV_DEBUGPIN_H__ */
