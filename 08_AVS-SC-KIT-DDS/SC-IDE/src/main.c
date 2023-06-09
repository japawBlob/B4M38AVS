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
#include "serial_driver.h"
#include "stdio.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void InitPeripherals(void);
void init_timer_TIM2();
void InitADC(void);
void InitDAC(void);
/* Private functions ---------------------------------------------------------*/

uint16_t sin_wave [] = {
    0x800,0x832,0x864,0x896,0x8c8,0x8fa,0x92c,0x95e,
    0x98f,0x9c0,0x9f1,0xa22,0xa52,0xa82,0xab1,0xae0,
    0xb0f,0xb3d,0xb6b,0xb98,0xbc5,0xbf1,0xc1c,0xc47,
    0xc71,0xc9a,0xcc3,0xceb,0xd12,0xd39,0xd5f,0xd83,
    0xda7,0xdca,0xded,0xe0e,0xe2e,0xe4e,0xe6c,0xe8a,
    0xea6,0xec1,0xedc,0xef5,0xf0d,0xf24,0xf3a,0xf4f,
    0xf63,0xf76,0xf87,0xf98,0xfa7,0xfb5,0xfc2,0xfcd,
    0xfd8,0xfe1,0xfe9,0xff0,0xff5,0xff9,0xffd,0xffe,
    0xfff,0xffe,0xffd,0xff9,0xff5,0xff0,0xfe9,0xfe1,
    0xfd8,0xfcd,0xfc2,0xfb5,0xfa7,0xf98,0xf87,0xf76,
    0xf63,0xf4f,0xf3a,0xf24,0xf0d,0xef5,0xedc,0xec1,
    0xea6,0xe8a,0xe6c,0xe4e,0xe2e,0xe0e,0xded,0xdca,
    0xda7,0xd83,0xd5f,0xd39,0xd12,0xceb,0xcc3,0xc9a,
    0xc71,0xc47,0xc1c,0xbf1,0xbc5,0xb98,0xb6b,0xb3d,
    0xb0f,0xae0,0xab1,0xa82,0xa52,0xa22,0x9f1,0x9c0,
    0x98f,0x95e,0x92c,0x8fa,0x8c8,0x896,0x864,0x832,
    0x800,0x7cd,0x79b,0x769,0x737,0x705,0x6d3,0x6a1,
    0x670,0x63f,0x60e,0x5dd,0x5ad,0x57d,0x54e,0x51f,
    0x4f0,0x4c2,0x494,0x467,0x43a,0x40e,0x3e3,0x3b8,
    0x38e,0x365,0x33c,0x314,0x2ed,0x2c6,0x2a0,0x27c,
    0x258,0x235,0x212,0x1f1,0x1d1,0x1b1,0x193,0x175,
    0x159,0x13e,0x123,0x10a,0xf2,0xdb,0xc5,0xb0,
    0x9c,0x89,0x78,0x67,0x58,0x4a,0x3d,0x32,
    0x27,0x1e,0x16,0xf,0xa,0x6,0x2,0x1,
    0x0,0x1,0x2,0x6,0xa,0xf,0x16,0x1e,
    0x27,0x32,0x3d,0x4a,0x58,0x67,0x78,0x89,
    0x9c,0xb0,0xc5,0xdb,0xf2,0x10a,0x123,0x13e,
    0x159,0x175,0x193,0x1b1,0x1d1,0x1f1,0x212,0x235,
    0x258,0x27c,0x2a0,0x2c6,0x2ed,0x314,0x33c,0x365,
    0x38e,0x3b8,0x3e3,0x40e,0x43a,0x467,0x494,0x4c2,
    0x4f0,0x51f,0x54e,0x57d,0x5ad,0x5dd,0x60e,0x63f,
    0x670,0x6a1,0x6d3,0x705,0x737,0x769,0x79b,0x7cd
};

/**
 * Main program.
 * @return Nothing.
 */
int main(void) {
    
    /* Initialize SCKit's LEDs, buttons, LCD and COM2 */
    InitPeripherals();
    InitDAC();
    
    LCD_Clear();
    
    volatile uint16_t ACC = 0;
    volatile uint16_t delta_ACC = 1024;
    volatile uint16_t pointer;
    
    uint8_t sw_1_pushed = 0;
    uint8_t sw_1_counter = 0;
    uint8_t sw_2_pushed = 0;
    uint8_t sw_2_counter = 0;

    /* Program loop */
    while (1) {
        
        if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
            TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
            ACC = ACC + delta_ACC;
            pointer = ACC >> 8;
            uint16_t dac = sin_wave[pointer];
            DAC_SetChannel2Data(DAC_Align_12b_R, dac);
//            char buffer [100];
//            sprintf(buffer, "DAC : %x", dac);
//            LCD_DisplayStringLineEx(1, buffer, LCD_FLAG_FILL_LINE);
//            sprintf(buffer, "po : %x, ACC : %x", pointer, ACC);
//            LCD_DisplayStringLineEx(3, buffer, LCD_FLAG_FILL_LINE);
        }
        if (STM_EVAL_PBGetState(BUTTON_SW1) == 0 ){
            // sw_1_counter = 0;
            if (sw_1_pushed != 1){
                sw_1_pushed = 1;
                if (delta_ACC < 16000){
                    delta_ACC += 256;
                }
            }
        } else {
            sw_1_pushed = 0;
//            sw_1_counter++;
//            if (sw_1_counter > 100) {
//                
//            }
        }
        if (STM_EVAL_PBGetState(BUTTON_SW2) == 0){
            if (sw_2_pushed != 1){
                sw_2_pushed = 1;
                if (delta_ACC > 260){
                    delta_ACC -= 256;
                }
            }     
        } else {
            sw_2_pushed = 0;
        }

        //iprintf("%d %d\n", adc1, adc2);
        /* and write to DAC data register */
        // STM_EVAL_LEDToggle(LED1);

        // delay(0xf);
    }
}

/**
 * Initialize ADC
 */
void InitADC(void) {

    /* ADC configuration */
    GPIO_InitTypeDef GPIO_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;

    /* Enable GPIO clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOC, ENABLE);

    /* ADC Peripheral clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_ADC2, ENABLE);

    /* Configure ADC12 Channel3 pin as analog input */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Configure ADC123 Channel10 pin as analog input */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    /* Reset ADC */
    ADC_DeInit();

    ADC_CommonStructInit(&ADC_CommonInitStructure);
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);

    /* Configure the ADC1 */
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADC1, &ADC_InitStructure);

    /* Add channel 3 to ADC1 */
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_3Cycles);

    /* Configure the ADC2 */
    ADC_Init(ADC2, &ADC_InitStructure);

    /* Add channel 10 to ADC2 */
    ADC_RegularChannelConfig(ADC2, ADC_Channel_10, 1, ADC_SampleTime_3Cycles);

    /* Enable ADC1 and ADC2 */
    ADC_Cmd(ADC1, ENABLE);
    ADC_Cmd(ADC2, ENABLE);
    
    ADC_SoftwareStartConv(ADC1);
    ADC_SoftwareStartConv(ADC2);

}

/**
 * Initialize DAC
 */
void InitDAC(void) {

    /* DAC configuration */
    GPIO_InitTypeDef GPIO_InitStructure;
    DAC_InitTypeDef DAC_InitStructure;

    /* DAC Pin clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* DAC Peripheral clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

    /* DAC channel 2 (DAC_OUT2 = PA.5) configuration */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* Reset DAC */
    DAC_DeInit();

    /* DAC channel2 Configuration */
    DAC_StructInit(&DAC_InitStructure);
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_2, &DAC_InitStructure);

    /* Enable DAC channel2 */
    DAC_Cmd(DAC_Channel_2, ENABLE);
}

/**
 * Initialize SCKit's LEDs, buttons, LCD and COM2
 */
void InitPeripherals(void) {
    init_timer_TIM2();
    Led_TypeDef led;

    for (led = LED1; led < (LED1 + LEDn); led++) {
        /* Initialize SCKit's LEDs */
        STM_EVAL_LEDInit(led);
        /* LEDs off */
        STM_EVAL_LEDOff(led);
    }

    /* Initialize buttons */
    STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_GPIO);
    STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_GPIO);

    /* Configure Serial port */
    ComPort_Init(COM2); // J15 - UART3
    /* Configure stdin,  stdout, stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);

    /* Initialize LCD */
    LCD_Init();
    LCD_SetBacklight(100);
}



void init_timer_TIM2(){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    
    //Enabeling timer interrupt
//    NVIC_InitTypeDef blob;
//    blob.NVIC_IRQChannel = TIM2_IRQn;
//    blob.NVIC_IRQChannelPreemptionPriority = 0;
//    blob.NVIC_IRQChannelSubPriority = 0;
//    blob.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&blob);
    
    //Enabeling timer TIM_2
    TIM_TimeBaseInitTypeDef timer;
    
    timer.TIM_CounterMode = TIM_CounterMode_Up;
    timer.TIM_ClockDivision = TIM_CKD_DIV1;
    timer.TIM_Prescaler = 14;
    timer.TIM_Period = 1;
    timer.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timer);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  
    TIM_Cmd(TIM2, ENABLE);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

/**
 * Delay function
 * @param nCount = Number of cycles to delay.
 */
void delay(vu32 nCount) {
    for (; nCount != 0; nCount--);
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
