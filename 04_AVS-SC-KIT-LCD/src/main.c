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


#define LCD_CENTER_X (LCD_PIXEL_WIDTH / 2)
#define LCD_CENTER_Y (LCD_PIXEL_HEIGHT / 2)

#define CMD_DISPLAY_OFF 0xAE
#define CMD_DISPLAY_ON 0xAF

#define CMD_SET_DISP_START_LINE 0x40
#define CMD_SET_PAGE 0xB0

#define CMD_SET_COLUMN_UPPER 0x10
#define CMD_SET_COLUMN_LOWER 0x00

#define CMD_SET_ADC_NORMAL 0xA0
#define CMD_SET_ADC_REVERSE 0xA1

#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7

#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON 0xA5
#define CMD_SET_BIAS_9 0xA2
#define CMD_SET_BIAS_7 0xA3

#define CMD_RMW 0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET 0xE2
#define CMD_SET_COM_NORMAL 0xC0
#define CMD_SET_COM_REVERSE 0xC8
#define CMD_SET_POWER_CONTROL 0x28
#define CMD_SET_RESISTOR_RATIO 0x20
#define CMD_SET_VOLUME_FIRST 0x81
#define CMD_SET_VOLUME_SECOND 0
#define CMD_SET_STATIC_OFF 0xAC
#define CMD_SET_STATIC_ON 0xAD
#define CMD_SET_STATIC_REG 0x0
#define CMD_SET_BOOSTER_FIRST 0xF8
#define CMD_SET_BOOSTER_234 0
#define CMD_SET_BOOSTER_5 1
#define CMD_SET_BOOSTER_6 3
#define CMD_NOP 0xE3
#define CMD_TEST 0xF0
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
void LED_Init(void);
void init_encoder_timer();
void init_button();

void init_LCD();
void setup_LCD();
// void LCD_SendByte(uint8_t byte);
void LCD_SendData(uint8_t data);
void LCD_SendCommand(uint8_t cmd);
void LCD_DrawRectWithDiagonals(uint8_t x, uint8_t line);
void LCD_DrawCentreRectangleDiag();
void LCD_DrawOrnament(uint8_t x, uint8_t line, uint8_t length);
void LCD_DrawVLine(uint8_t x, uint8_t y, uint8_t length);
void LCD_DrawHLine(uint8_t x, uint8_t y, uint8_t length);
void LCD_DrawRectangleDiag(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
void LCD_ClearDisplay();
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
    
    init_LCD();
    setup_LCD();
    LCD_ClearDisplay();
//    LCD_DrawRectWithDiagonals(8, 2);
    //LCD_DrawVLine(64,32,15);
//    LCD_DrawVLine(63,32,1);
//    LCD_DrawVLine(62,32,6);
//    LCD_DrawVLine(61,32,4);
//    LCD_DrawVLine(60,32,3);
//    LCD_DrawVLine(50,32,2);
//    LCD_DrawVLine(50,32,2);
//    LCD_DrawVLine(64,32,15);

    
    
//    LCD_DrawHLine(64,32,15);

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
//        LCD_SetPos(3,25);
//        LCD_SendData((uint8_t)ENCODER_POSITION);
//        LCD_DrawVLine(64,32,ENCODER_POSITION);
//        LCD_DrawVLine(65,32,ENCODER_POSITION);
//        LCD_DrawVLine(66,32,ENCODER_POSITION);
//        LCD_DrawHLine(50,37,ENCODER_POSITION);
        //LCD_DrawRectangleDiag(32,16,60,32);
        /* USE ECODER :) */
        /* Look at the A4M38AVS web pages for your assignment*/
        LCD_DrawCentreRectangleDiag();
        
        delay(0x0FFFFF);
        LCD_ClearDisplay();
        
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

// Sets the whole LCD RAM to 0
void LCD_ClearDisplay()
{
    uint8_t line = LCD_PIXEL_HEIGHT / 8, column;
    while (line--)
    {
        LCD_SendCommand(CMD_SET_PAGE | (line));
        LCD_SendCommand(CMD_SET_COLUMN_LOWER | 0);
        LCD_SendCommand(CMD_SET_COLUMN_UPPER | 0);
        LCD_SendCommand(CMD_RMW);
        column = LCD_PIXEL_WIDTH;
        while (column--)
        {
            LCD_SendData(0x00);
        }
    }
}

// Sets LCD cursor position
void LCD_SetPos(uint8_t line, uint8_t column)
{
    LCD_SendCommand(CMD_SET_PAGE | (line & 0x0F));
    LCD_SendCommand(CMD_SET_COLUMN_LOWER | ((column)&0xf));
    LCD_SendCommand(CMD_SET_COLUMN_UPPER | (((column) >> 4) & 0x0F));
    LCD_SendCommand(CMD_RMW);
}

// Draws a small square with diagonals
void LCD_DrawRectWithDiagonals(uint8_t x, uint8_t line)
{
    uint8_t x_width = 8;

    LCD_SetPos(line, x);
    while (x_width--)
    {
        if (x_width == 7) // Prvni vertikalni cara
            LCD_SendData(0xFF);
        else if (x_width == 0) // Druha vertikalni cara
            LCD_SendData(0xFF);
        else
            LCD_SendData(1 << 0 |                 // horni horizontalni cara
                         1 << 7 |                 // spodni horizontalni cara
                         1 << (x_width % 8) |     // jedna uhlopricka
                         1 << (7 - (x_width % 8)) // druha uhlopricka
            );
    }
}

// Draws a sawtooth line (with changing width from 1 to 8)
void LCD_DrawOrnament(uint8_t x, uint8_t line, uint8_t length)
{
    LCD_SetPos(line, x);
    while (length--)
    {
        LCD_SendData(0xFF >> (length % 8));
    }
}

// Draws a vertical line
void LCD_DrawVLine(uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t cur_line = y / 8;
    uint8_t column = x;
    uint8_t n_lines = length / 8 + 1;
    uint8_t data;
    uint8_t col_start = y % 8;
    
//    if (length < 8) {
//        unsigned bin_number = col_start;
//        int i;
//        for (i = 0; i<length; i++){
//            bin_number = (bin_number << 1) | 1;
//        }
//        LCD_SetPos(cur_line++, column);
//        LCD_SendData(bin_number);
//    } else {

        data = ((0xff) << (col_start));
       

        while (n_lines--)
        {
            LCD_SetPos(cur_line++, column);
            LCD_SendData(data);
            if (n_lines == 1) // Set data for the next iteration
                data = (0xff >> (8 - ((col_start + length) % 8)));
            else
                data = 0xff;
//        }
    }
}

// Draws a horizontal line
void LCD_DrawHLine(uint8_t x, uint8_t y, uint8_t length)
{
    uint8_t start_line = y / 8;
    uint8_t start_column = x;
    uint8_t data;
    uint8_t col_pos = y % 8;
    data = (1 << col_pos);

    LCD_SetPos(start_line, start_column);
    for (; length; length--)
        LCD_SendData(data);
}
// Must not be on span of one line
void LCD_DrawRectangleDiag(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
    unsigned a = abs(x1-x2);
    unsigned b = abs(y1-y2);
    
   LCD_DrawHLine(x1,y1,a);
   LCD_DrawHLine(x1,y2,a);
   LCD_DrawVLine(x1,y1,b+1);
   LCD_DrawVLine(x2,y1,b+1);
   
   unsigned D = 2*b-a;
   unsigned y = y1;
   
   int x;
   for(x = x1; x<x2; x++ ){
       LCD_DrawVLine(x,y,1);
       if (D>0) {
           y = y+1;
           D = D-2*a;
       }
       D = D + 2*b;
   }
}

void LCD_DrawCentreRectangleDiag(){
    uint8_t x0=32, y0=16, x1=96, y1=48;
    unsigned a = abs(x1-x0);
    unsigned b = abs(y1-y0);
    
   LCD_DrawHLine(x0,y0,a);
   LCD_DrawHLine(x0,y1,a);
   LCD_DrawVLine(x0,y0,b+1);
   LCD_DrawVLine(x1,y0,b+1);
}

void LCD_SendByte(uint8_t byte)
{
    /*!< Loop while DR register in not emplty */
    while (SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_TXE) == RESET)
        ;

    /*!< Send byte through the SPI1 peripheral */
    SPI_I2S_SendData(LCD_SPI, byte);

    /*!< Wait to receive a byte */
    while (SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_RXNE) == RESET)
        ;

    /*!< Return the byte read from the SPI bus */
    SPI_I2S_ReceiveData(LCD_SPI);
}

void LCD_SendData(uint8_t data)
{
    GPIO_SetBits(GPIOD, GPIO_Pin_14); // Set A0 to HIGH to indicate data
    LCD_SendByte(data);
}

void LCD_SendCommand(uint8_t cmd)
{
    GPIO_ResetBits(GPIOD, GPIO_Pin_14); // Set A0 to LOW to indicate command
    LCD_SendByte(cmd);
}

// Sets up the LCD parameters
void setup_LCD()
{
    /* reset sequence for the LCD */
    GPIO_ResetBits(GPIOD, GPIO_Pin_11); // Set LCD_RESET to LOW to reset the device
    delay(50);
    GPIO_SetBits(GPIOD, GPIO_Pin_11); // Set LCD_RESET to HIGH to start normal function
    delay(50);

    LCD_SendCommand(CMD_SET_BIAS_7);
    LCD_SendCommand(CMD_SET_ADC_NORMAL);
    LCD_SendCommand(CMD_SET_COM_NORMAL);
    LCD_SendCommand(CMD_SET_DISP_START_LINE);
    LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x4); // VC=1, VR =0, VF = 0
    delay(50);
    LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x6); // VC=1, VR =1, VF = 0
    delay(50);
    LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x7); // VC=1, VR =1, VF = 1
    delay(50);
    LCD_SendCommand(CMD_SET_RESISTOR_RATIO | 0x6); // regulator resistor, ref. voltage resistor
    delay(50);
    LCD_SendCommand(CMD_DISPLAY_ON);
    LCD_SendCommand(CMD_SET_VOLUME_FIRST);
    LCD_SendCommand(CMD_SET_VOLUME_SECOND | (0x10 & 0x3f));
}

// Initializes the SPI and GPIO HW for communication with the LCD
void init_LCD()
{
    /* Initialize the corresponding pins */
    GPIO_InitTypeDef GPIO_InitStructure;
    /* Enable clock to GPIOB, C and D */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_SPI2);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF_SPI2);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource3, GPIO_AF_SPI2);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
    /*!< SPI configuration */
    SPI_InitTypeDef SPI_InitStructure;
    SPI_StructInit(&SPI_InitStructure);
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;

    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_Init(LCD_SPI, &SPI_InitStructure);

    /*!< Enable the LCD_SPI */
    SPI_Cmd(LCD_SPI, ENABLE);

    GPIO_ResetBits(GPIOD, GPIO_Pin_15); // Set CS to LOW to activate SPI communication
    GPIO_SetBits(GPIOC, GPIO_Pin_7);    // Set BACKLIGHT pin to HIGH to activate backlight
}