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
#include <stdlib.h>

#include "stm32_eval.h"
#include "stm32f2xx_rtc.h"
#include "stm32_eval_spi_accel.h"
#include "lcd_framebuffer.h"
#include "stm32_eval_i2c_ee.h"
#include "dht11.h"
#include "stm32f2xx_pwr.h"
#include "accelerometer.h"
#include "logger.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LCD_MAX_CHARS (int)(LCD_PIXEL_WIDTH/ LCD_FONT_WIDTH)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void init_IO();
void Button_Init(void);
void init_rtc();
void init_accelerometer();
void InitADC(void);
/* Private functions ---------------------------------------------------------*/

/**
 * Main program.
 * @return Nothing.
 */
uint8_t frame_buffer[128*64];
uint8_t buf[100];

static void used_functions(){
    // eeprom:
    sEE_Init();
    sEE_ReadBuffer(buf, 0x200, 1);
    sEE_WriteBuffer(buf, 0x200, 1);
    
    // dht11
    setup_dht11();
    struct DHT11_response ret = read_DHT11();
    uint8_t temperature = ret.integral_T;
    uint8_t humidity = ret.integral_RH;
    
    // rtc
    //....
    
//    RTC_WriteBackupRegister();
//    RTC_ReadBackupRegister();
    
    RTC_DateTypeDef date;
    RTC_GetDate(0, &date);
    RTC_TimeTypeDef time;
    RTC_GetTime(0, &time);
    
    // accelerometer
    //....
    
    // ADC
    //....
    
    // LCD controll and screens
    //....
    
    // LCD scroll?
}

int main(void) {
    memset(frame_buffer,128*64,0);
    // sEE_WriteBuffer(0, 0x0, sizeof(size_t));
    init_IO();
    // set_number_of_records(0);
    // uint16_t b = 0;
    //sEE_WriteBuffer(&b, start_address, sizeof(uint16_t));

    struct data_entry blob = {
        4, 5, 6, 55
    };  
    append_mem_entry(blob);
    iprintf("running\n");
//    LCD_DisplayStringLine(Line0, "Hello.");
//    LCD_DisplayStringLine(Line6, "huhuhu");  
//    LCD_DisplayStringLine(Line6, "heheheh");
    unsigned counter = 0;
    uint16_t num = get_number_of_records();
    struct data_entry * entries = get_entries();
    int i;
    iprintf("%d\n", get_number_of_records());
    for(i=0; i<num; i++){
        char buff [100];
        sprintf(buff, "%d: %d  %d    %d    %d\n", i, entries[i].time_stamp, entries[i].temperature, entries[i].humidity, entries[i].vibrations);
        iprintf("%s", buff);
    }
    iprintf("done\n");
    struct data_entry buffrator [10];
    uint16_t size = 10*sizeof(struct data_entry);
    sEE_ReadBuffer(buffrator, start_address+sizeof(uint16_t), &size);
    for(i=0; i<10; i++){
        char buff [100];
        sprintf(buff, "%d: %d  %d   %d    %d\n", i, buffrator[i].time_stamp, buffrator[i].temperature, buffrator[i].humidity, buffrator[i].vibrations);
        iprintf("%s", buff);
    }
    return 0;
//    
//    RTC_DateTypeDef date;
//    RTC_GetDate(0, &date);
//    RTC_TimeTypeDef time;
//    RTC_GetTime(0, &time);
//    
////    struct data_entry blob = {
////        date, time, 0, 0, 0
////    };    
//    struct data_entry blob = {
//        4, 5, 6, 7
//    };  
//    
////    store_record_at_address(blob, 0xA0);
////    iprintf("%u %d %u %u\n", blob.time_stamp, blob.temperature, blob.humidity, blob.vibrations);
////    struct data_entry ret = get_record_at_address(0xA0);
////    
////    
////    iprintf("%u %d %u %u\n", ret.time_stamp, ret.temperature, ret.humidity, ret.vibrations);
//
//    
//    append_mem_entry(blob);
//    blob.temperature = 11;
//    blob.time_stamp += 1;
//    sEE_WaitEepromStandbyState();
//    append_mem_entry(blob);
//    blob.temperature = 15;
//    blob.humidity = 15;
//    blob.time_stamp += 1;
//    sEE_WaitEepromStandbyState();
//    append_mem_entry(blob);
//    sEE_WaitEepromStandbyState();
//    append_mem_entry(blob);
//    blob.temperature = 11;
//    blob.time_stamp += 1;
//    append_mem_entry(blob);
//    blob.temperature = 11;
//    blob.time_stamp += 1;
//    append_mem_entry(blob);
//    blob.temperature = 11;
//    blob.time_stamp += 1;
//    append_mem_entry(blob);
//    blob.temperature = 11;
//    blob.time_stamp += 1;
//    size_t num = get_number_of_records();
//    iprintf("%u\n", num);
//    sEE_WaitEepromStandbyState();
//    struct data_entry* entries = get_entries();
//    int i = 0;
//    for(i=0; i<num; i++){
//        char buff [100];
//        sprintf(buff, "%d: %d  %d    %d    %d\n", i, entries[i].time_stamp, entries[i].temperature, entries[i].humidity, entries[i].vibrations);
//        iprintf("%s", buff);
//    }
//    // sEE_WriteBuffer(entries, 0xA0+sizeof(size_t), num*sizeof(struct data_entry));
//    struct data_entry buffrator [10];
//    
//    struct data_entry first;
//    uint16_t size_data = sizeof(struct data_entry);
//    //sEE_WriteBuffer((char*)blob, 0xA0+sizeof(size_t), sizeof(struct data_entry));
//    blob.vibrations = 69;
//    sEE_WaitEepromStandbyState();
//    write_mem_entry(blob, start_address+sizeof(uint16_t));
//    append_mem_entry(blob);
//    //sEE_ReadBuffer(buffrator, 0xA0, &size_data);
//    //write_mem_entry(blob, 0xA0);
//    sEE_WaitEepromStandbyState();
//    num = get_number_of_records();
//    uint16_t* stored_num;
//    uint16_t stored_num_size = sizeof(uint16_t);
//    sEE_ReadBuffer(stored_num, start_address, &stored_num_size);
//    iprintf("%d %d done\n", num, stored_num);
//    uint16_t size = num*sizeof(struct data_entry);
//    sEE_ReadBuffer(buffrator, start_address+sizeof(uint16_t), &size);
//    iprintf("%d %d %d done\n", size, num, stored_num);
////    char buff [100];
////    sprintf(buff, "%d: %d  %d   %d    %d\n", i, first.time_stamp, first.temperature, first.humidity, first.vibrations);
////    iprintf("%s", buff);
//    
//    for(i=0; i<num; i++){
//        char buff [100];
//        sprintf(buff, "%d: %d  %d   %d    %d\n", i, buffrator[i].time_stamp, buffrator[i].temperature, buffrator[i].humidity, buffrator[i].vibrations);
//        iprintf("%s", buff);
//    }
//    iprintf("donnnnne\n");
//        sEE_ReadBuffer(buffrator, start_address+sizeof(uint16_t), &size);
//    iprintf("done\n");
////    char buff [100];
////    sprintf(buff, "%d: %d  %d   %d    %d\n", i, first.time_stamp, first.temperature, first.humidity, first.vibrations);
////    iprintf("%s", buff);
//    
//    for(i=0; i<num; i++){
//        char buff [100];
//        sprintf(buff, "%d: %d  %d   %d    %d\n", i, buffrator[i].time_stamp, buffrator[i].temperature, buffrator[i].humidity, buffrator[i].vibrations);
//        iprintf("%s", buff);
//    }
//        iprintf("done\n");      
    return 0;
    while(1){
        // Handle butttons
        // Change scene
        
        // Handle Accelerometer
        //      Sample
        counter += sample_accelerometer();
        
        //Every second (or so)
        if (counter >= 20){
            /// Write temp
            /// Write humidity
            /// Write Seismic
            /// Read time
        }
        // Handle period
                // Resolve and clear accelerometer
                // 
                // Write to memory
        
//        ADC_RegularChannelConfig(ADC1, ADC_Channel_TempSensor, 1, ADC_SampleTime_480Cycles);
//        ADC_SoftwareStartConv(ADC1);
//        while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);

        // Read the converted value from the ADC data register
        iprintf("%u  %u\n", sizeof(struct data_entry), sizeof(int));
        delay(0xFFFFFF);
    }
}

void init_IO(){
    ComPort_Init(COM2); // J15 - UART3
    /* Configure stdin,  stdout, stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);
    Button_Init();
    setup_dht11();
    init_rtc();
    sEE_Init();
    LCD_Init();
    LCD_SetBacklight(100);
    LCD_Clear();
    delay(0xFFFFF);
    LCD_Clear();
    init_accelerometer();
    init_logger();
}

void init_rtc(){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    
    RCC_BackupResetCmd(ENABLE);
    RCC_BackupResetCmd(DISABLE);
    RTC_WriteProtectionCmd(DISABLE);
    RCC_LSICmd(ENABLE);
    
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET) {}
    
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
    RCC_RTCCLKCmd(ENABLE);
    RTC_WaitForSynchro();
    
    
    RTC_InitTypeDef rtc_init;
    RTC_StructInit(&rtc_init);
    unsigned ret = RTC_Init(&rtc_init);
    PWR_BackupAccessCmd(DISABLE);
}

void Button_Init(void) {
    // use interrupts
    // STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_EXTI);
    // STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_EXTI);

    // dont use interrupts
    STM_EVAL_PBInit(BUTTON_SW1, BUTTON_MODE_GPIO);
    STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_GPIO);
}

/**
 * Delay function
 * @param nCount = Number of cycles to delay.
 */
void delay(vu32 nCount) {
    for (; nCount != 0; nCount--);
}
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

void init_internal_temperature(void) {

    
    /* ADC configuration */
    ADC_InitTypeDef ADC_InitStructure;
//    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    
    /* ADC Peripheral clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    
    ADC_DeInit();
    
//    ADC_CommonStructInit(&ADC_CommonInitStructure);
//    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
//    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
//    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
//    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
//    ADC_CommonInit(&ADC_CommonInitStructure);

    /* Configure the ADC1 */
    ADC_StructInit(&ADC_InitStructure);
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
    
    ADC_TempSensorVrefintCmd(ENABLE);
    ADC_Cmd(ADC1, ENABLE);
    
    
    ADC_RegularChannelConfig(ADC1, ADC_Channel_TempSensor, 1, ADC_SampleTime_480Cycles);
    ADC_SoftwareStartConv(ADC1);
    
    uint16_t adc_val = ADC_GetConversionValue(ADC1);

    float adc_float = ((float)adc_val);
    float temp = (((float)adc_float-760.0f)/2.5f)+25.0f;
}