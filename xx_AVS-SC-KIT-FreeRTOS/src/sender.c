#include "stm32_eval.h"

#include "sender.h"

void SenderTask(void * pInputQueue) {
    xQueueHandle xQueue = (xQueueHandle) pInputQueue;
    uint32_t iCount;

    if (NULL == xQueue) {
        while (1);
    }

    iprintf("Sender started.\n", iCount);
    
    while (1) {
        if (xQueueReceive(xQueue, &iCount, portMAX_DELAY)) {
            // pcRxedMessage now points to the struct AMessage variable posted
            // by vATask.
        }
        iprintf("iCount = %lu\n", iCount);
    }

}

void FillerTask(void * pOutputQueue) {
    xQueueHandle xQueue = (xQueueHandle) pOutputQueue;
    if (NULL == xQueue) {
        while (1);
    }

    uint32_t iCount = 0;

    while (1) {
        if (pdPASS != xQueueSend(xQueue, (void *) &iCount, 10)) {
            // Failed to post the message, even after 10 ticks.
        }
        iCount++;
        vTaskDelay(100);
    }
}
