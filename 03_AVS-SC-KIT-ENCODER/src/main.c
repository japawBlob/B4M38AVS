/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V1.1.0
 * @date    07-October-2011
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
#include "stm32_eval.h"
#include "serial_driver.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void LED_Init(void);
/* Private functions ---------------------------------------------------------*/

/**
 * Main program.
 * @return Nothing.
 */
int main(void) {

    /* Initialize all LEDs */
    LED_Init();

    /* Initialize COM2 == USART3 (USB <==> Serial Port) */
    ComPort_Init(COM2);

    /* Configure COM2 as stdin, stdout and stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);

    /* INITIALIZE ECODER */
    /* It is not that hard, no help today. */
    /* Look into SCKit schematics for the encoder connection */
    /* Read STM32F207 datasheet and reference manual */
    /* Do not forget to configure the encoder pins */
    /* Do not forget to configure clock for a counter */

    iprintf("\nRun.");
    while (1) {
        STM_EVAL_LEDToggle(LED1);
        iprintf(".");
        
        /* USE ECODER :) */
        /* Look at the A4M38AVS web pages for your assignment*/
        
        delay(0x0FFFFF);
    }
}

/**
 * Initialize all LEDs 
 */
void LED_Init(void) {
    Led_TypeDef led;

    for (led = LED1; led < (LED1 + LEDn); led++) {
        /* Initialize SCKit's LEDs */
        STM_EVAL_LEDInit(led);
        /* Set LEDs off */
        STM_EVAL_LEDOff(led);
    }
}

/**
 * Delay function
 * @param nCount = Number of cycles to delay.
 */
void delay(vu32 nCount) {
    for (; nCount != 0; nCount--);
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
