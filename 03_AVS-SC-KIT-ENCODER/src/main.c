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
#define ENCODER_COUNTER_ZERO (0xFFFF/2)
#define ENCODER_PULSES_PER_ROTATION 96
#define ENCODER_COUNTER_RANGE (0xFFFF/2)
#define ENCODER_POSITION (int)(TIM4->CNT-ENCODER_COUNTER_ZERO)/4
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void LED_Init(void);
void init_encoder_timer();
void init_button();
/* Private functions ---------------------------------------------------------*/

/**
 * Main program.
 * @return Nothing.
 */
int main(void) {

    /* Initialize all LEDs */
    LED_Init();
    init_button();

    /* Initialize COM2 == USART3 (USB <==> Serial Port) */
    ComPort_Init(COM2);

    /* Configure COM2 as stdin, stdout and stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);

    /* INITIALIZE ECODER */
    init_encoder_timer();
    /* It is not that hard, no help today. */
    /* Look into SCKit schematics for the encoder connection */
    /* Read STM32F207 datasheet and reference manual */
    /* Do not forget to configure the encoder pins */
    /* Do not forget to configure clock for a counter */

    iprintf("\nRun.");
    while (1) {
        // STM_EVAL_LEDToggle(LED1);
        // iprintf(".");
        iprintf("%d\n", ENCODER_POSITION);
        
        if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 0){
            TIM4->CNT = ENCODER_COUNTER_ZERO;
            while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 0){
                continue;
            }
        }
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
void init_button(){
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}


void init_encoder_timer()
{
/* Initialize the corresponding input pins */
        GPIO_InitTypeDef GPIO_InitStructure;
/* Enable clock to GPIOD */
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
        GPIO_StructInit(&GPIO_InitStructure);
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);

/* Initialize the timer */
/* Enable clock to TIM4 */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

        TIM_TimeBaseInitTypeDef TIM_InitStructure;
        TIM_TimeBaseStructInit(&TIM_InitStructure);
        TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
        TIM_InitStructure.TIM_Period = 0xFFFF;
        TIM_InitStructure.TIM_Prescaler = 0;
        TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
        TIM_TimeBaseInit(TIM4, &TIM_InitStructure);

/* Set the timer up for quadrature decoding */
        TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
        TIM4->CNT = ENCODER_COUNTER_ZERO;
        TIM_Cmd(TIM4, ENABLE);
}
