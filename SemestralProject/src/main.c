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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LCD_MAX_CHARS (int)(LCD_PIXEL_WIDTH/ LCD_FONT_WIDTH)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void Button_Init(void);
void init_rtc();
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
    
    // rtc
    //....
    
    //RTC_WriteBackupRegister();
    //RTC_ReadBackupRegister();
    
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
    
    ComPort_Init(COM2); // J15 - UART3
    /* Configure stdin,  stdout, stderr */
    ComPort_ConfigStdio(COM2, COM2, COM2);
    Button_Init();
    LCD_Init();
    LCD_SetBacklight(100);
    LCD_DisplayStringLine(Line0, "Hello.");
    sEE_Init();
    setup_dht11();
    // memset(buf, 1, 50);
    // sEE_WriteBuffer(buf, 0x200, 1);
    LCD_DisplayStringLine(Line6, "huhuhu");  
    sEE_ReadBuffer(buf, 0x200, 1);
    iprintf("%x\n", buf[0]);
    iprintf("%d\n", SystemCoreClock);
    LCD_DisplayStringLine(Line6, "heheheh");
    setup_dht11();
    init_rtc();
    
    
    
    while(1){
//        if (!STM_EVAL_PBGetState(BUTTON_SW1)) {
//            memset(buf, 4, 50);
//            sEE_WriteBuffer(buf, 0x200, 1);
//        }   
//        if (!STM_EVAL_PBGetState(BUTTON_SW2)) {
//            memset(buf, 8, 50);
//            sEE_WriteBuffer(buf, 0x200, 1);
//        } 
//        sEE_ReadBuffer(buf, 0x200, 1);
        // iprintf("%x", buf[0]);

        //struct DHT11_response ret = read_DHT11();
        //iprintf("%d %d %d %d %d\n",ret.integral_RH, ret.decimal_RH, ret.integral_T, ret.decimal_RH, ret.checksum);
        //delay(0xFFFFFF);
        struct DHT11_response ret = read_DHT11();
        iprintf("READ_2: %d %d %d %d %d\n",ret.integral_RH, ret.decimal_RH, ret.integral_T, ret.decimal_RH, ret.checksum);
        delay(0xFFFFFF);
        RTC_TimeTypeDef time;
        RTC_GetTime(0, &time);
        iprintf("%d %d %d\n",time.RTC_Seconds, time.RTC_Minutes, time.RTC_Hours);
    }
}

void init_rtc(){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    PWR_BackupAccessCmd(ENABLE);
    
    RCC_BackupResetCmd(ENABLE);
    RCC_BackupResetCmd(DISABLE);
    RTC_WriteProtectionCmd(DISABLE);
    RCC_LSICmd(ENABLE);
    
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET) {}
//    RCC_LSICmd(ENABLE);
//    RCC_HSEConfig(RCC_HSE_ON);
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);
    RCC_RTCCLKCmd(ENABLE);
    RTC_WaitForSynchro();
    
    
    RTC_InitTypeDef rtc_init;
    RTC_StructInit(&rtc_init);
    unsigned ret = RTC_Init(&rtc_init);
    PWR_BackupAccessCmd(DISABLE);
    RTC_DateTypeDef date;
    RTC_GetDate(0, &date);
    RTC_TimeTypeDef time;
    RTC_GetTime(0, &time);
    
    iprintf("%d %d %d %d\n", date.RTC_WeekDay, date.RTC_Date, date.RTC_Month, date.RTC_Year);
    iprintf("||ret=%d||%d %d %d\n",ret,time.RTC_Seconds, time.RTC_Minutes, time.RTC_Hours);
    
    delay(0x2FFFFF);
    iprintf("%d %d %d\n",time.RTC_Seconds, time.RTC_Minutes, time.RTC_Hours);
    
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
