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
#include "stm32_eval.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
/* Private functions ---------------------------------------------------------*/




/**
 * Main program.
 * @return Nothing.
 */
void GPIO_config()
{
    GPIO_InitTypeDef GPIO_InitStructure; /* hmm, I should be declared on function start :) */

    GPIO_StructInit(&GPIO_InitStructure); /* !! important !!, initialization of the structure. */

    /* Enable the GPIO_LED Clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* Configure the GPIO_LED pin */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/*
void SysTick_Handler(void)
{
    static uint8_t word = 0xF0;
    GPIO_WriteBit(GPIOE, GPIO_Pin_7, word & 0x1);
    word = word >> 1;
}*/
void TIM2_IRQHandler(){
    static int blink_pattern [] = {1,0,0,0,1,0};
    static unsigned i = 0;
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        GPIO_WriteBit(GPIOE, GPIO_Pin_13, blink_pattern[i]);
        i = ++i %(sizeof(blink_pattern)/sizeof(int));
    }
//    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
//        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//        GPIO_ToggleBits(GPIOA, GPIO_Pin_0);
//    }
}

extern void init_timer_TIM2(){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    //Enabeling timer interrupt
    NVIC_InitTypeDef blob;
    blob.NVIC_IRQChannel = TIM2_IRQn;
    blob.NVIC_IRQChannelPreemptionPriority = 0;
    blob.NVIC_IRQChannelSubPriority = 0;
    blob.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&blob);
    
    //Enabeling timer TIM_2
    TIM_TimeBaseInitTypeDef timer;
    
    timer.TIM_CounterMode = TIM_CounterMode_Up;
    timer.TIM_ClockDivision = TIM_CKD_DIV1;
    timer.TIM_Prescaler = 59;
    timer.TIM_Period = 1000000;
    timer.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timer);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  
    TIM_Cmd(TIM2, ENABLE);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void init_buttons()
{
    RCC->AHB1ENR |= RCC_AHB1LPENR_GPIOCLPEN;

    GPIOC->MODER &= ~0x30000000;
    GPIOC->OSPEEDR &= ~0x30000000;
    GPIOC->OTYPER &= ~0x00000080;
    GPIOC->PUPDR &= ~0x30000000;
    
    GPIOC->MODER |= 0x000000000;
    GPIOC->OSPEEDR |= 0x00000000;
    GPIOC->OTYPER |= 0x00000000;
    GPIOC->PUPDR |= 0x10000000;
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void) 
{
    GPIO_config();
    init_buttons();
    init_timer_TIM2();
    
    char g = RCC_GetSYSCLKSource();
        
    RCC_ClocksTypeDef blob;
    RCC_GetClocksFreq(&blob);
    
    
    int gpioC_14_counter = 0;  // For debounce
    int gpioC_15_counter = 0;  

    while (1) {
        //TIM2_IRQHandler();
        if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14) == 0){
            if(gpioC_14_counter < 5){
                gpioC_14_counter++;
            } else {
                GPIO_SetBits(GPIOE, GPIO_Pin_10);
            }
        } else {
            if(gpioC_14_counter > 0){
                gpioC_14_counter--;
            } else {
                GPIO_ResetBits(GPIOE, GPIO_Pin_10);
            }
        }
        if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15) == 0){
            if(gpioC_15_counter < 5){
                gpioC_15_counter++;
            } else {
                GPIO_SetBits(GPIOE, GPIO_Pin_11);
            }
        } else {
            if(gpioC_15_counter > 0){
                gpioC_15_counter--;
            } else {
                GPIO_ResetBits(GPIOE, GPIO_Pin_11);
            }
        }
    }
}

/**
 * Delay function
 * @param nCount = Number of cycles to delay.
 */
void delay(vu32 nCount) 
{
    for (; nCount != 0; nCount--);
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
