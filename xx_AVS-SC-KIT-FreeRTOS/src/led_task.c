


#include "stm32_eval.h"

#include "led_task.h"

static void DoSomeWork(void);

void LedTask(void * arg) {

    (void) arg; // ignore arg parameter

    Led_TypeDef leds[] = {LED1, LED2, LED3, LED4, LED3, LED2};
    int32_t leds_count = sizeof (leds) / sizeof (Led_TypeDef);
    int32_t idx = leds_count - 1;

    while (1) {
        vTaskDelay(100);

        // start condition
        if (idx < 0) {
            idx += leds_count;
        }

        STM_EVAL_LEDOff(leds[idx]);

        idx++;

        if (idx >= leds_count) {
            idx = 0;
        }

        STM_EVAL_LEDOn(leds[idx]);

        if (RESET == STM_EVAL_PBGetState(BUTTON_SW1)) {
            DoSomeWork();
        }
    }
}

void LedTimer(xTimerHandle xTimer) {
    (void) xTimer;

    static Led_TypeDef leds[] = {LED8, LED7, LED6, LED5, LED6, LED7};
    static int32_t leds_count = sizeof (leds) / sizeof (Led_TypeDef);
    static int32_t idx = -1;

    // start condition
    if (idx < 0) {
        idx += leds_count;
    }

    STM_EVAL_LEDOff(leds[idx]);

    idx++;

    if (idx >= leds_count) {
        idx = 0;
    }

    STM_EVAL_LEDOn(leds[idx]);

    if (RESET == STM_EVAL_PBGetState(BUTTON_SW2)) {
        /* This in not good practice to do heavy work in timer */
        DoSomeWork();
    }
}

void DoSomeWork(void) {
    vu32 nCount = 0x00FFFF;
    for (; nCount != 0; nCount--);
}