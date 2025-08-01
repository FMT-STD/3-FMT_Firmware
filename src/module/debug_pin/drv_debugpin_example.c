/******************************************************************************
 * Debug Pin Usage Example
 * 
 * This file demonstrates how to use the debug pins for function timing
 * measurement and general debugging purposes.
 *****************************************************************************/

#include "drv_debugpin.h"

/* Example: Function timing measurement */
void example_function_timing(void)
{
    /* Method 1: Manual high/low control */
    DEBUG_PIN_SET_HIGH(DEBUG_PIN_0);  // 函数开始
    
    // Your function code here
    for (volatile int i = 0; i < 1000; i++) {
        // Some work...
    }
    
    DEBUG_PIN_SET_LOW(DEBUG_PIN_0);   // 函数结束
    
    /* Method 2: Using convenience macros */
    DEBUG_FUNC_START(DEBUG_PIN_1);    // 函数开始
    
    // Your function code here
    for (volatile int i = 0; i < 2000; i++) {
        // Some work...
    }
    
    DEBUG_FUNC_END(DEBUG_PIN_1);      // 函数结束
}

/* Example: ISR timing measurement */
void example_isr_timing(void)
{
    /* Use toggle for ISR timing - each trigger creates a pulse */
    DEBUG_FUNC_TOGGLE(DEBUG_PIN_2);   // ISR开始触发
    
    // ISR code here
    
    DEBUG_FUNC_TOGGLE(DEBUG_PIN_2);   // ISR结束触发
}

/* Example: State machine debugging */
typedef enum {
    STATE_IDLE = 0,
    STATE_RUNNING = 1,
    STATE_ERROR = 2
} system_state_t;

void example_state_machine_debug(system_state_t state)
{
    switch (state) {
        case STATE_IDLE:
            DEBUG_PIN_SET_LOW(DEBUG_PIN_3);
            DEBUG_PIN_SET_LOW(DEBUG_PIN_4);
            break;
            
        case STATE_RUNNING:
            DEBUG_PIN_SET_HIGH(DEBUG_PIN_3);
            DEBUG_PIN_SET_LOW(DEBUG_PIN_4);
            break;
            
        case STATE_ERROR:
            DEBUG_PIN_SET_LOW(DEBUG_PIN_3);
            DEBUG_PIN_SET_HIGH(DEBUG_PIN_4);
            break;
    }
}

/* Example: Loop timing measurement */
void example_loop_timing(void)
{
    for (int loop = 0; loop < 10; loop++) {
        DEBUG_PIN_SET_HIGH(DEBUG_PIN_5);  // 循环开始
        
        // Loop work here
        for (volatile int i = 0; i < 500; i++) {
            // Some work in loop
        }
        
        DEBUG_PIN_SET_LOW(DEBUG_PIN_5);   // 循环结束
        
        // Some delay or other work
        for (volatile int i = 0; i < 100; i++) {
            // Delay
        }
    }
}

/* Example: Multi-pin pattern for complex debugging */
void example_complex_debug_pattern(void)
{
    // Pattern 1: All pins high
    for (int i = 0; i < DEBUG_PIN_NUM; i++) {
        DEBUG_PIN_SET_HIGH((debug_pin_id_t)i);
    }
    
    // Some delay
    for (volatile int i = 0; i < 1000; i++);
    
    // Pattern 2: All pins low  
    for (int i = 0; i < DEBUG_PIN_NUM; i++) {
        DEBUG_PIN_SET_LOW((debug_pin_id_t)i);
    }
    
    // Pattern 3: Sequential toggle
    for (int i = 0; i < DEBUG_PIN_NUM; i++) {
        DEBUG_PIN_TOGGLE((debug_pin_id_t)i);
        for (volatile int j = 0; j < 500; j++);  // Delay between toggles
    }
}

/* Example: Performance comparison */
void example_performance_comparison(void)
{
    /* Test Algorithm A */
    DEBUG_PIN_SET_HIGH(DEBUG_PIN_0);
    
    // Algorithm A implementation
    for (volatile int i = 0; i < 1000; i++) {
        // Algorithm A work
    }
    
    DEBUG_PIN_SET_LOW(DEBUG_PIN_0);
    
    /* Small gap between tests */
    for (volatile int i = 0; i < 100; i++);
    
    /* Test Algorithm B */
    DEBUG_PIN_SET_HIGH(DEBUG_PIN_1);
    
    // Algorithm B implementation  
    for (volatile int i = 0; i < 1000; i++) {
        // Algorithm B work (potentially optimized)
    }
    
    DEBUG_PIN_SET_LOW(DEBUG_PIN_1);
}

/*
 * Usage Notes:
 * 
 * 1. Function Timing:
 *    - Use DEBUG_PIN_SET_HIGH at function start
 *    - Use DEBUG_PIN_SET_LOW at function end
 *    - Measure pulse width on oscilloscope
 * 
 * 2. ISR Timing:
 *    - Use DEBUG_PIN_TOGGLE for each ISR trigger
 *    - Creates square wave pattern
 *    - Frequency = ISR frequency / 2
 * 
 * 3. State Debugging:
 *    - Use different pins for different states
 *    - Create binary patterns for state identification
 * 
 * 4. Performance Analysis:
 *    - Use different pins for different algorithms
 *    - Compare pulse widths to analyze performance
 * 
 * 5. Oscilloscope Setup:
 *    - Connect probes to debug pins
 *    - Set appropriate time base (μs/ms)
 *    - Use trigger on rising/falling edge
 *    - Measure pulse width, frequency, duty cycle
 */
