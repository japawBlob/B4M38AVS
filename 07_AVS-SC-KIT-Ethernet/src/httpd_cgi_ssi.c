/**
 ******************************************************************************
 * @file    httpd_cg_ssi.c
 * @author  MCD Application Team
 * @version V1.1.0
 * @date    07-October-2011
 * @brief   Webserver SSI and CGI handlers
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


#include "lwip/debug.h"
#include "httpd.h"
#include "lwip/tcp.h"
#include "fs.h"
#include "main.h"

#include <string.h>
#include <stdlib.h>

tSSIHandler ADC_Page_SSI_Handler;
uint32_t ADC_not_configured = 1;

/* we will use character "t" as tag for CGI */
char const* TAGCHAR = "t";
char const** TAGS = &TAGCHAR;

/* Handle parameters for index page, for example /index.html?a=b */
extern const char *HandleIndexParameter(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

extern u16_t BTN_Handler(int iIndex, char *pcInsert, int iInsertLen);

const tCGI stIndexHandler = {
    .pcCGIName = "/index.html",
    .pfnCGIHandler = HandleIndexParameter
};

/**
 * Initialize SSI handlers
 */
void httpd_ssi_init(void) {
    /* configure SSI handlers (ADC page SSI) */
    http_set_ssi_handler(BTN_Handler, (char const **) TAGS, 1);
}

/**
 * Initialize CGI handlers
 */
void httpd_cgi_init(void) {
    /* configure CGI handler */
    http_set_cgi_handlers(&stIndexHandler, 1);
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
