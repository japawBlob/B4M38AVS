
/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team (Edit Jakub Jira)
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
#include "string.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define CHECK_NUMER (int)20
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void delay(vu32 nCount);
char keyboardHandler();
void updateLEDs(char userInput);
void printChar(char inputKey);
void waitForRelease();
/* Private functions ---------------------------------------------------------*/
void init_usart()
{
    /* Initialize USART3 (USB <==> Serial Port) */
    /* Definition of init structures */
    USART_InitTypeDef USART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
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

extern void init_timer_TIM2()
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
 
    TIM_TimeBaseInitTypeDef timerInitStructure; 
    //timerInitStructure.TIM_Prescaler = 40000;
    timerInitStructure.TIM_Prescaler = 500;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    //timerInitStructure.TIM_Period = 500;
    timerInitStructure.TIM_Period = 60000;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &timerInitStructure);
    
    TIM_Cmd(TIM2, ENABLE);
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}
void init_keyboard()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    GPIO_StructInit(&GPIO_InitStructure);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_SetBits(GPIOB, GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_SetBits(GPIOC, GPIO_Pin_3);

}
/**
 * Main program.
 * @return Nothing.
 */
void init_LEDs()
{
    STM_EVAL_LEDInit(LED1);
    STM_EVAL_LEDInit(LED2);
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);
    STM_EVAL_LEDInit(LED7);
    STM_EVAL_LEDInit(LED8);
}

int main(void) 
{
    /* Init SCKIT Buttons */
    STM_EVAL_PBInit(BUTTON_SW2, BUTTON_MODE_GPIO);
    
    init_usart();
    init_keyboard();
    init_LEDs();
    init_timer_TIM2();

    char* welcomeMessage = "\n\rWelcome to this simple program.\n\r"
    "Pressed keys will be displayed in binary form using LEDs on kit\n\r"
    "You can also use keyboard attached to board to send characters\n\r"
    "Use '*' for backspace and '#' for '\\n\\r'\n\r";
    unsigned i;
    for (i = 0; i < strlen(welcomeMessage); i++) {
        while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
        USART_SendData(USART3, welcomeMessage[i]);
    }
    
    char inputKey = 0;
    while (1) {
        if(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) != RESET){
            char userInput;
            userInput = USART_ReceiveData(USART3); // Collect Char
            updateLEDs(userInput);
        }
        if(inputKey == 0){
            inputKey = keyboardHandler();
        }
        
        if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
            TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
            if(inputKey != 0){
                printChar(inputKey);
            }
            waitForRelease();
            GPIO_ToggleBits(GPIOE, GPIO_Pin_15);
            inputKey = 0;
        }
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
void printChar(char inputKey)
{
    unsigned i;
    
    while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
    
    if(inputKey == '#'){
        char *tail = "\n\r";
        for (i = 0; i < strlen(tail); i++) {
            while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
            USART_SendData(USART3, tail[i]);
        }
    } else if (inputKey == '*') {
        USART_SendData(USART3, (char)8);
    } else {
        USART_SendData(USART3, inputKey);
    } 
}

char keyboardHandler()
{
    int a = 0, b = 0, c = 0, d = 0;
    char buffer[255];
    buffer[0] = '\0';
    while (d < CHECK_NUMER*2){
        GPIO_ResetBits(GPIOB, GPIO_Pin_9);
        if((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) || 
           (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0) || 
           (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)) == 0 || 
           (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)) == 0 ){
            a++;
            if(a > CHECK_NUMER){
               if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 0){
                    sprintf(buffer, "1\n\r"); 
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){
                    sprintf(buffer, "4\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0){
                    sprintf(buffer, "7\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7) == 0){
                    sprintf(buffer, "*\n\r");
                } 
                break;
            }
        }
        GPIO_SetBits(GPIOB, GPIO_Pin_9);
        GPIO_ResetBits(GPIOB, GPIO_Pin_10);
        if((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) || 
           (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0) || 
           (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)) == 0 || 
           (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)) == 0 ){
            b++;
            if(b > CHECK_NUMER){
                if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 0){
                    sprintf(buffer, "2\n\r"); 
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){
                    sprintf(buffer, "5\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0){
                    sprintf(buffer, "8\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7) == 0){
                    sprintf(buffer, "0\n\r");
                }  
                break;
            }
        }
        GPIO_SetBits(GPIOB, GPIO_Pin_10);
        GPIO_ResetBits(GPIOC, GPIO_Pin_3);
        if((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) || 
           (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0) || 
           (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)) == 0 || 
           (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)) == 0 ){
            c++;
            if(c > CHECK_NUMER){
                if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 0){
                    sprintf(buffer, "3\n\r"); 
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0){
                    sprintf(buffer, "6\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0){
                    sprintf(buffer, "9\n\r");
                } else if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7) == 0){
                    sprintf(buffer, "#\n\r");
                } 
                break;
            }
        }
        GPIO_SetBits(GPIOC, GPIO_Pin_3);
        d++;
    }
    if(strlen(buffer) > 0){
        waitForRelease();
    }
    return buffer[0];
}
void waitForRelease()
{
    int blob = 0;
    GPIO_ResetBits(GPIOB, GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_ResetBits(GPIOC, GPIO_Pin_3);
    while(blob < CHECK_NUMER*10){
        blob++;
        while((GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0) || 
              (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 0) || 
              (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)) == 0 || 
              (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7)) == 0 );
    }
    GPIO_SetBits(GPIOB, GPIO_Pin_9 | GPIO_Pin_10);
    GPIO_SetBits(GPIOC, GPIO_Pin_3);
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
