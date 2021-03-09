#ifndef _LED_TASK_H_
#define _LED_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#define LED_TASK_PRIO    ( tskIDLE_PRIORITY + 1 )

void LedTask(void * arg);
void LedTimer(xTimerHandle xTimer);



#endif // _LED_TASK_H_

