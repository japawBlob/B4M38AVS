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
void InitADC(void);
void InitDAC(void);
/* Private functions ---------------------------------------------------------*/

/**
 * Main program.
 * @return Nothing.
 */
int main(void) {
    
    /* Initialize SCKit's LEDs, buttons, LCD and COM2 */
    InitPeripherals();

    /**
     * BNC1: ADC1_Channel_3
     * BNC2: DAC_Channel_2
     */

    /* ADC initialization */
    InitADC();
    
    /* DAC initialization */
    InitDAC();

    /* Program loop */
    while (1); 
    
}

/**
 * Interrupt rutine from ADC - sampling time 50 kHz
 */
void ADC_IRQHandler (void){

    ADC_ClearITPendingBit(ADC1,ADC_IT_EOC);
    uint16_t adc1_value = ADC_GetConversionValue(ADC1);        
    DAC_SetChannel2Data(DAC_Align_12b_R,adc1_value);
 }




/**
 * Initialize ADC
 */
void InitADC(void) {

    /* ADC configuration */
    GPIO_InitTypeDef GPIO_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    NVIC_InitTypeDef NVIC_InitStruct;

    /* Enable GPIO clocks */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    /* ADC Peripheral clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    /* Configure ADC12 Channel3 pin as analog input */
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Reset ADC */
    ADC_DeInit();

    ADC_CommonStructInit(&ADC_CommonInitStructure);
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div8;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_18Cycles;
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
    
    NVIC_InitStruct.NVIC_IRQChannel = ADC_IRQn;
    /* Set priority */
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
    /* Set sub priority */
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
    /* Enable interrupt */
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    /* Add to NVIC */
    NVIC_Init(&NVIC_InitStruct);
    
    /* enable interrupt from EOC */
    ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);
    
  

    /* Add channel 3 to ADC1 */
    ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 1, ADC_SampleTime_144Cycles);

    /* Enable ADC1  */
    ADC_Cmd(ADC1, ENABLE);

  /* start convertion on ADC1  */
    ADC_SoftwareStartConv(ADC1);
 


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
 * Initialize SCKit's LEDs, buttons and COM2
 */
void InitPeripherals(void) {
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

}

      