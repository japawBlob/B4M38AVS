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
#include "stm32f2x7_eth.h"
#include "main.h"
#include "netconf.h"
#include "httpd.h"
#include "serial_driver.h"
#include <string.h>
#include <stdlib.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define SYSTEMTICK_PERIOD_MS  10

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t LocalTime = 0; /* this variable is used to create a time reference incremented by 10ms */
uint32_t timingdelay;



/* Private function prototypes -----------------------------------------------*/
static void LCD_LED_Init(void);
static void UART_Init(void);
static void Button_Init(void);
static void SysTick_Init(void);
static void Application_Periodic_Handle(__IO uint32_t localtime);

void InitADC(void);
void InitDAC(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program.
 * @param  None
 * @retval None
 */
int main(void) {


    /*!< At this stage the microcontroller clock setting is already configured to 
         120 MHz, this is done through SystemInit() function which is called from
         startup file (startup_stm32f2xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_stm32f2xx.c file
     */

    SysTick_Init();

    UART_Init();

    iprintf("\r\n");
    iprintf("SC-KIT Demo\r\n");

    Button_Init();
    
    InitADC();
    InitDAC();

    /* Initialize LCD and LEDs */
    LCD_LED_Init();

    /* Configure Ethernet (GPIOs, clocks, MAC, DMA) */
    ETH_BSP_Config();

    /* Initialize the LwIP stack */
    LwIP_Init();

    /* Initialize HTTP webserver  */
    httpd_init();

    /* Infinite loop */
    while (1) {
        /* check if any packet received */
        if (ETH_CheckFrameReceived()) {
            /* process received ethernet packet */
            LwIP_Pkt_Handle();
        }
        /* handle periodic timers for LwIP */
        LwIP_Periodic_Handle(LocalTime);

        Application_Periodic_Handle(LocalTime);
    }
}

void updateLEDs(char userInput)
{
    int i;
    for(i = 0; i < 8; i++){
        STM_EVAL_LEDOff(i);
    }
    for(i = 0; i < 8; i++){
        if( (userInput & 1) == 1){
            STM_EVAL_LEDOn(i);
        }
        userInput = userInput >> 1;
    }
}

/**
 * Handles parameters of index.html page.
 * @param iIndex index of the CGI within the ppcURLs array
 * @param iNumParams number of parameters
 * @param pcParam array of parameters
 * @param pcValue array of values
 * @return pointer to string with web page name
 */
const char *HandleIndexParameter(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]) {
    int i;

    /* Search parameters */
    for (i = 0; i < iNumParams; i++) {
        /* Display text of 'text' parameter */
        if (!strncmp(pcParam[i], "text", 4)) {
            LCD_DisplayStringLineEx(Line7, pcValue[i], LCD_FLAG_FILL_LINE);
        }
        if (!strncmp(pcParam[i], "bin", 3)) {
            int num = (int)strtol(pcValue[i], NULL, 16);
            if (0x00 <= num && num <= 0xFF) {
                updateLEDs(num); 
                char buff [100];
                sprintf(buff, "LED display: %d", num);
                LCD_DisplayStringLineEx(Line7, buff, LCD_FLAG_FILL_LINE);
            } else {
                LCD_DisplayStringLineEx(Line7, "LED value out of bounds", LCD_FLAG_FILL_LINE);
            }
            
        }
        if (!strncmp(pcParam[i], "dac", 3)) {
            int num = (int)strtol(pcValue[i], NULL, 10);
            DAC_SetChannel2Data(DAC_Align_12b_R, (uint16_t)num);
//            uint16_t adc1 = ADC_GetConversionValue(ADC1);
            char buff [100];
            sprintf(buff, "DAC set to: %d", num);
            LCD_DisplayStringLineEx(Line7, buff, LCD_FLAG_FILL_LINE);
        }
    }

    return "/index.html";
}



/**
 * BTN_Handler : SSI handler for Buttons 
 * @param iIndex index of the SSI within the ppcURLs array
 * @param pcInsert text to insert
 * @param iInsertLen text length
 * @return 
 */
u16_t BTN_Handler(int iIndex, char *pcInsert, int iInsertLen) {

    (void) iInsertLen;
    u16_t i;
    
    if (iIndex == 0) {
        
        i = siprintf(pcInsert, "{\"btn\":[%d,%d, %d]}", !STM_EVAL_PBGetState(BUTTON_SW2), !STM_EVAL_PBGetState(BUTTON_SW1), ADC_GetConversionValue(ADC2));
//        i = siprintf(pcInsert, "{\"btn\":[%d,%d, %d]}", !STM_EVAL_PBGetState(BUTTON_SW2), !STM_EVAL_PBGetState(BUTTON_SW1), ADC_GetConversionValue(ADC1));

        return i;
    }
    return 0;
}


/*******************************************************************************/

static void LedBlink(Led_TypeDef * leds, int32_t leds_count, int32_t * index) {
    int32_t idx = *index;

    // start condition
    if (idx < 0) {
        idx += leds_count;
    }

    // calculate next index
    STM_EVAL_LEDOff(leds[idx]);
    idx++;
    if (idx >= leds_count) {
        idx = 0;
    }
    STM_EVAL_LEDOn(leds[idx]);

    // update index
    *index = idx;
}

static void LedTask1(void) {
    static Led_TypeDef leds[] = {LED1, LED2, LED3, LED4, LED3, LED2};
    static int32_t leds_count = sizeof (leds) / sizeof (Led_TypeDef);
    static int32_t idx = -1;

    LedBlink(leds, leds_count, &idx);
}

static void LedTask2(void) {
    static Led_TypeDef leds[] = {LED8, LED7, LED6, LED5, LED6, LED7};
    static int32_t leds_count = sizeof (leds) / sizeof (Led_TypeDef);
    static int32_t idx = -1;

    LedBlink(leds, leds_count, &idx);
}

void Application_Periodic_Handle(__IO uint32_t localtime) {
    static uint32_t APPTimer = 0;

    // evry 100 ms
    if (localtime - APPTimer >= 100) {
        // LedTask1();
        // LedTask2();
        APPTimer = localtime;
    }
}

/**
 * @brief  Inserts a delay time.
 * @param  nCount: number of 10ms periods to wait for.
 * @retval None
 */
void Delay(uint32_t nCount) {
    /* Capture the current local time */
    timingdelay = LocalTime + nCount;

    /* wait until the desired delay finish */
    while (timingdelay > LocalTime) {
    }
}

/**
 * @brief  Updates the system local time
 * @param  None
 * @retval None
 */
void Time_Update(void) {
    LocalTime += SYSTEMTICK_PERIOD_MS;
}

/**
 * @brief  Initializes the STM322xG-EVAL's LCD and LEDs resources.
 * @param  None
 * @retval None
 */
void LCD_LED_Init(void) {
    Led_TypeDef led;

#ifdef USE_LCD
    /* Initialize the SC-KIT's LCD */
    LCD_Init();
#endif

    /* Initialize SC-KIT's LEDs */
    for (led = LED1; led < (LED1 + LEDn); led++) {
        /* Initialize STM322xG-EVAL's LEDs */
        STM_EVAL_LEDInit(led);
        /* leds off */
        STM_EVAL_LEDOff(led);
    }

#ifdef USE_LCD
    /* Clear the LCD */
    LCD_SetBacklight(100);
    LCD_Display(LCD_Bitmap_SCKIT);
    LCD_DisplayStringLine(Line7, "!!Connect UTP cable!!");
#endif
}

void UART_Init(void) {
    /* Configure Serial ports */
    ComPort_Init(COM1); // J10 - UART2
    ComPort_Init(COM2); // J15 - UART3
    /* configure        stdin,  stdout, stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);
}

void Button_Init(void) {
    // use interrupts
    // STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_EXTI);
    // STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_EXTI);

    // dont use interrupts
    STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_GPIO);
    STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_GPIO);
}

void SysTick_Init(void) {
    RCC_ClocksTypeDef RCC_Clocks;

    /* Configure Systick clock source as HCLK */
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);

    /* SystTick configuration: an interrupt every 10ms */
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);
}

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

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
