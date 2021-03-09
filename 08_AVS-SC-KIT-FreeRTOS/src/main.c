/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V1.0.2
 * @date    06-June-2011
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "main.h"
#include "serial_driver.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "led_task.h"
#include "sender.h"

#include "system_conf.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void LED_Init(void);
static void Button_Init(void);
static void UART_Init(void);
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void) {

    xTimerHandle ledTimer;
    xQueueHandle xQueue;

    /* Initialize hardware */
    UART_Init();
    LED_Init();
    Button_Init();

    /* Start LED task : Blinks LED1-LED4 */
    xTaskCreate(LedTask, (signed char *) "LedTask", configMINIMAL_STACK_SIZE, NULL, LED_TASK_PRIO, NULL);

    /* Start LED timer : Blinks LED5-LED8 */
    ledTimer = xTimerCreate((signed char *) "LedTimer", 100, pdTRUE, NULL, LedTimer);
    xTimerStart(ledTimer, 0);

    xQueue = xQueueCreate(10, sizeof (uint32_t));
    if (NULL == xQueue) {
        while (1);
    }

    /* Start Sender tasks */
    xTaskCreate(SenderTask, (signed char *) "SenderTask", configMINIMAL_STACK_SIZE, (void *) xQueue, SENDER_TASK_PRIO, NULL);
    xTaskCreate(FillerTask, (signed char *) "FillerTask", configMINIMAL_STACK_SIZE, (void *) xQueue, SENDER_TASK_PRIO + 1, NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    /* We should never get here as control is now taken by the scheduler */
    for (;;);
}

void Button_Init(void) {
    // don't use interrupts
    STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_GPIO);
    STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_GPIO);
}

void LED_Init(void) {
    Led_TypeDef led;

    for (led = LED1; led < (LED1 + LEDn); led++) {
        /* Initialize STM322xG-EVAL's LEDs */
        STM_EVAL_LEDInit(led);
        /* leds off */
        STM_EVAL_LEDOff(led);
    }
}

void UART_Init(void) {
    /* Configure Serial port */
    ComPort_Init(COM2); // J15 - UART3
    /* configure        stdin,  stdout, stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
