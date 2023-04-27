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
#include "stm32_eval_spi_accel.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LCD_MAX_CHARS (int)(LCD_PIXEL_WIDTH/ LCD_FONT_WIDTH)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
/* Private functions ---------------------------------------------------------*/

/**
 * Main program.
 * @return Nothing.
 */
int main(void) {
    char sTmp[LCD_MAX_CHARS];
    uint8_t lowRetX, highRetX, lowRetY, highRetY;
    /* Accelerometer initialization */
    sACCEL_Init();

    /* LCD initialization */
    LCD_Init();
    LCD_SetBacklight(100);
    LCD_DisplayStringLine(Line0, "Hello.");
    sACCEL_WriteReg(0x20, 0x83);
    while (1) {
        /* Accelerometer */
        /* 
         * uint8_t sACCEL_ReadReg(uint8_t Addr);
         * uint8_t sACCEL_WriteReg(uint8_t Addr, uint8_t Data);
         * uint16_t sACCEL_ReadWord(uint8_t Addr);
         */

        /* Read and display WHO_AM_I register */
        // GDB - c like kalkulačka
        lowRetX = sACCEL_ReadReg(0x28);
        highRetX = sACCEL_ReadReg(0x29);
        snprintf(sTmp, LCD_MAX_CHARS, "0x28,0x29=0x%02X, 0x%02X", lowRetX, highRetX);
        LCD_DisplayStringLine(Line2, sTmp);
        lowRetY = sACCEL_ReadReg(0x2A);
        highRetY = sACCEL_ReadReg(0x2B);
        snprintf(sTmp, LCD_MAX_CHARS, "0x28,0x29=0x%02X, 0x%02X", lowRetY, highRetY);
        LCD_DisplayStringLine(Line3, sTmp);
        delay(0xFFFFFF);
        LCD_ClearLine(Line2);
        LCD_ClearLine(Line3);
        delay(0xFFFFF);

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
