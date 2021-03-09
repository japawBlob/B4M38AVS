#ifndef SENDER_H
#define	SENDER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
    
#define SENDER_TASK_PRIO    ( tskIDLE_PRIORITY + 2 )

void SenderTask(void * arg);
void FillerTask(void * arg);


#ifdef	__cplusplus
}
#endif

#endif	/* SENDER_H */

