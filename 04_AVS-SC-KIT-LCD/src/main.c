/**
******************************************************************************
* @file main.c
* @author MCD Application Team
* @version V1.1.0
* @date 07-October-2011
* @brief Main program body
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
// #include "lcd_framebuffer.h"
#include <math.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define PI 3.1415926535897932384626433832795028842
#define ENCODER_COUNTER_ZERO (0xFFFF/2)
#define ENCODER_PULSES_PER_ROTATION 96
#define ENCODER_COUNTER_RANGE (0xFFFF/2)
#define LCD_CENTER_X (LCD_PIXEL_WIDTH/2)
#define LCD_CENTER_Y (LCD_PIXEL_HEIGHT/2)


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
void USART_print_button_states(uint8_t button_states[]);
void USART_binprint_uint16(uint16_t data);
void USART_send_char_blocking(USART_TypeDef* USARTx, uint16_t data);
void delay(vu32 nCount);
void init_LEDs();
void init_matrix();
void init_UART();
void init_UART_ISR();
void init_encoder_timer();
void init_EXTI();
void init_LCD();
void setup_LCD();
//void LCD_SendByte(uint8_t byte);
void LCD_SendData(uint8_t data);
void LCD_SendCommand(uint8_t cmd);
void LCD_DrawRectWithDiagonals(uint8_t x, uint8_t line);
void LCD_DrawOrnament(uint8_t x, uint8_t line, uint8_t length);
void LCD_DrawVLine(uint8_t x, uint8_t y, uint8_t length);
void LCD_DrawHLine(uint8_t x, uint8_t y, uint8_t length);
void LCD_ClearDisplay();
/* Private functions ---------------------------------------------------------*/

/**
* Main program.
* @return Nothing.
*/
int main(void)
{
        uint8_t lcdBuffer[LCD_FB_SIZE] = {0};
// int i;
// uint16_t matrix;
// uint8_t button_states[N_BUTTONS] = {0};
// int8_t i;
// //char buts[] = {'3', '5', '0', '8', '2', '4', '9', '7', '1', 'F', 'N', '6'};
// char buts[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'F', 'N'};
// Initialization of peripherals
        init_LEDs();
        init_UART();
        init_UART_ISR();
        init_encoder_timer();
        init_EXTI();
        init_LCD();
        setup_LCD();
        LCD_ClearDisplay();

        printf("Setup OK\r\n");

/* Draw using direct write to LCD */
        LCD_DrawVLine(2, 1, 30);
        LCD_DrawHLine(3, 1, 80);
        LCD_DrawHLine(3, 30, 80);
        LCD_DrawVLine(82, 1, 30);
        LCD_DrawOrnament(5, 32/8, LCD_PIXEL_WIDTH-10);
        LCD_DrawRectWithDiagonals(50, 55/8);

        //while(1);
        delay(5000); //cca 5s

        /* Program loop */
        while (1)
        {
                // Calculate the angle of the encoder
                float angle = -((float)TIM4->CNT - ENCODER_COUNTER_ZERO)/ENCODER_PULSES_PER_ROTATION*2.0*PI;
                float length = 10; // length of the line to be displayed
                char buf[64]; // buffer for the on-screen text
                sprintf(buf, "Encoder: %ld", TIM4->CNT);

                /* Draw using the framebuffer library */
//                FB_Clear(lcdBuffer, 0);
//                FB_DrawUniLine(lcdBuffer, LCD_CENTER_X, LCD_CENTER_Y, LCD_CENTER_X+length*cos(angle), LCD_CENTER_Y+length*sin(angle));
//                FB_Display(lcdBuffer);
                LCD_DisplayStringLineEx(0, buf, 0);

                /* Write the encoder value and angle (in radians) to UART */
                printf("%10ld, %2.10f\r", TIM4->CNT-ENCODER_COUNTER_ZERO, angle);
                fflush(stdout);
                delay(100);
        }

}

// Sets the whole LCD RAM to 0
void LCD_ClearDisplay()
{
        uint8_t line = LCD_PIXEL_HEIGHT/8, column;
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
        LCD_SendCommand(CMD_SET_COLUMN_LOWER | ((column) & 0xf));
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
                        LCD_SendData(1<<0 | // horni horizontalni cara
                        1<<7 | // spodni horizontalni cara
                        1<<(x_width%8) | // jedna uhlopricka
                        1<<(7 - (x_width%8)) // druha uhlopricka
                        );
        }
}

// Draws a sawtooth line (with changing width from 1 to 8)
void LCD_DrawOrnament(uint8_t x, uint8_t line, uint8_t length)
{
        LCD_SetPos(line, x);
        while (length--)
        {
                LCD_SendData(0xFF>>(length%8));
        }
}

// Draws a vertical line
void LCD_DrawVLine(uint8_t x, uint8_t y, uint8_t length)
{
        uint8_t cur_line = y/8;
        uint8_t column = x;
        uint8_t n_lines = length/8 +1;
        uint8_t data;
        uint8_t col_start = y%8;
        data = ((0xFF)<<(col_start));

        while (n_lines--)
        {
                LCD_SetPos(cur_line++, column);
                LCD_SendData(data);
                if (n_lines == 1) // Set data for the next iteration
                        data = (0xFF>>(8 - ((col_start + length)%8)));
                else
                        data = 0xFF;
        }
}

// Draws a horizontal line
void LCD_DrawHLine(uint8_t x, uint8_t y, uint8_t length)
{
        uint8_t start_line = y/8;
        uint8_t start_column = x;
        uint8_t data;
        uint8_t col_pos = y%8;
        data = (1<<col_pos);

        LCD_SetPos(start_line, start_column);
        for (; length; length--)
                LCD_SendData(data);
}

void LCD_SendByte(uint8_t byte)
{
/*!< Loop while DR register in not emplty */
        while (SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_TXE) == RESET);

/*!< Send byte through the SPI1 peripheral */
        SPI_I2S_SendData(LCD_SPI, byte);

/*!< Wait to receive a byte */
        while (SPI_I2S_GetFlagStatus(LCD_SPI, SPI_I2S_FLAG_RXNE) == RESET);

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
        LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x4); //VC=1, VR =0, VF = 0
        delay(50);
        LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x6); //VC=1, VR =1, VF = 0
        delay(50);
        LCD_SendCommand(CMD_SET_POWER_CONTROL | 0x7); //VC=1, VR =1, VF = 1
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
        GPIO_SetBits(GPIOC, GPIO_Pin_7); // Set BACKLIGHT pin to HIGH to activate backlight
}

// Initializes the external interrupt on button connected to pin PC15
void init_EXTI()
{
/* Enable clock for GPIOC */
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
/* Enable clock for SYSCFG */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

/* Set pin as input */
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
        GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(GPIOC, &GPIO_InitStruct);

/* Tell system that you will use PC15 for EXTI_Line15 */
        SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource15);


        EXTI_InitTypeDef EXTI_InitStruct;
        EXTI_StructInit(&EXTI_InitStruct);
        EXTI_InitStruct.EXTI_Line = EXTI_Line15;
        EXTI_InitStruct.EXTI_LineCmd = ENABLE;
        EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
        EXTI_Init(&EXTI_InitStruct);

/* Add IRQ vector to NVIC */
        NVIC_InitTypeDef NVIC_InitStruct;
/* PC15 is connected to EXTI_Line15, which has EXTI15_10_IRQn vector */
        NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
/* Set priority */
        NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x0F;
/* Set sub priority */
        NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x0F;
/* Enable interrupt */
        NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
/* Add to NVIC */
        NVIC_Init(&NVIC_InitStruct);
}

/**
* Delay function
* @param nCount = Number of ms to (approximately) delay.
*/
void delay(vu32 nCount) {
        nCount *= 10000;
        for (; nCount != 0; nCount--);
}

// The external interrupt only clears the encoder counter
void EXTI15_10_IRQHandler()
{
        TIM4->CNT = ENCODER_COUNTER_ZERO;
        EXTI_ClearITPendingBit(EXTI_Line15);
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
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
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

// Not used
void init_encoder_ISR()
{
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);
        TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
}


// For debug (unused)
void USART_binprint_uint16(uint16_t data)
{
        int8_t i;
        USART_send_char_blocking(USART3, '0');
        USART_send_char_blocking(USART3, 'b');
        for (i = 15; i>=0; i--)
        {
                USART_send_char_blocking(USART3, (((data)&(1<<i))>>i) + '0');
        }
        USART_send_char_blocking(USART3, ' ');
        USART_send_char_blocking(USART3, ' ');
        USART_send_char_blocking(USART3, ' ');
        USART_send_char_blocking(USART3, ' ');
        USART_send_char_blocking(USART3, '\r');
}

// Not used
void USART_send_char_blocking(USART_TypeDef* USARTx, uint16_t data)
{
        while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
        USART_SendData(USARTx, data);
}

// Not used
void USART3_IRQHandler()
{
        GPIOE->ODR &= 0x00FF;
        GPIOE->ODR |= (USART3->DR & (uint16_t)0x00FF) << 8;
}

// Not used
void init_UART()
{
/* Definition of init structures */
        USART_InitTypeDef USART_InitStructure;
        GPIO_InitTypeDef GPIO_InitStructure;

/* Initialize USART3 (USB <==> Serial Port) */

/* Enable clock to GPIOD */
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
/* Enable clock to USART3 */
        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

/* Set RX and TX pins as Alternate Function USART3 */
        GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_USART3);

        GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);

/* Configure RX and TX pins */
        GPIO_StructInit(&GPIO_InitStructure);
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(GPIOD, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
        GPIO_Init(GPIOD, &GPIO_InitStructure);

/* Configure USART 3 */
        USART_StructInit(&USART_InitStructure);
        USART_InitStructure.USART_BaudRate = 115200;
        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
        USART_InitStructure.USART_StopBits = USART_StopBits_1;
        USART_InitStructure.USART_Parity = USART_Parity_No;
        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
        USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
        USART_Init(USART3, &USART_InitStructure);

/* Enable USART 3 */
        USART_Cmd(USART3, ENABLE);

}

// Not used
void init_UART_ISR()
{
        NVIC_InitTypeDef NVIC_InitStructure;
        NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);
        USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
}

// Not used
void init_LEDs()
{
        GPIO_InitTypeDef GPIO_InitStructure;
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
        GPIO_StructInit(&GPIO_InitStructure);
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_Init(GPIOE, &GPIO_InitStructure);

}

// Not used
void init_matrix()
{
/*
* matrix out 1R -> PB10
* matrix out 2R -> PC3
* matrix out 3R -> PC7
* matrix in 4S -> PB0
* matrix in 5S -> PB1
* matrix in 6S -> PD7
* matrix in 7S -> PD10
*/
        GPIO_InitTypeDef GPIO_InitStructure;
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

        GPIO_StructInit(&GPIO_InitStructure);
        GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_7;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
        GPIO_Init(GPIOB, &GPIO_InitStructure);

        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_10;
        GPIO_Init(GPIOD, &GPIO_InitStructure);
}

// Not used
uint16_t read_matrix_row()
{
        uint16_t data = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
        data <<= 1;
        data |= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1);
        data <<= 1;
        data |= GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7);
        data <<= 1;
        data |= GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_10);
        return data;
}

// Not used
uint16_t read_matrix()
{
        uint16_t matrix_status = 0xFFFF;
/*
* matrix out 1R -> PB10
* matrix out 2R -> PC3
* matrix out 3R -> PC7
* matrix in 4S -> PB0
* matrix in 5S -> PB1
* matrix in 6S -> PD7
* matrix in 7S -> PD10
*/

// Set first row to log. 0
        GPIO_ResetBits(GPIOB, GPIO_Pin_10);
// Wait for the change to propagate
        delay(100);
// Read first row
        matrix_status &= ~(read_matrix_row() << 4*0);
// Set row back to log. 1
        GPIO_SetBits(GPIOB, GPIO_Pin_10);

// Set second row to log. 0
        GPIO_ResetBits(GPIOC, GPIO_Pin_3);
// Wait for the change to propagate
        delay(100);
// Read second row
        matrix_status &= ~(read_matrix_row() << 4*1);
// Set row back to log. 1
        GPIO_SetBits(GPIOC, GPIO_Pin_3);

// Set third row to log. 0
        GPIO_ResetBits(GPIOC, GPIO_Pin_7);
// Wait for the change to propagate
        delay(100);
// Read third row
        matrix_status &= ~(read_matrix_row() << 4*2);
// Set row back to log. 1
        GPIO_SetBits(GPIOC, GPIO_Pin_7);

        return matrix_status;
}