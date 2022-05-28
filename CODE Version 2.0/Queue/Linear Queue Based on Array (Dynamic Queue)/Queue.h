#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"


typedef struct{
    void **QueueArray;                   /* Pointer to array of void pointers */
    uint32_t QueueMaxSize;               /* Has Maximum elements in the Queue */
    sint32_t ElementCount;               /* Has Number of elements in the Queue */
    sint32_t QueueFront;                 /* Has Index of the front elements */
    sint32_t QueueRear;                  /* Has Index of the rear elements */
}QUEUE_t;

typedef enum{
    QUEUE_NOK = 0,                     /* Queue operation not performed successfully */
    QUEUE_OK,                          /* Queue operation performed successfully  */
    QUEUE_FULL,                        /* Queue is full */
    QUEUE_EMPTY,                       /* Queue is empty */
    QUEUE_NULL_POINTER                 /* NULL pointer passed to the Queue */
}Status_QUEUE_t;

QUEUE_t *CreateQueue(uint32_t maxSize, Status_QUEUE_t *ret_status);
Status_QUEUE_t EnqueueElement(QUEUE_t *queue_obj, void *item_ptr);
void *DequeueElement(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status);
void *QueueFront(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status);
void *QueueRear(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status);
Status_QUEUE_t GetQueueCount(QUEUE_t *queue_obj, uint32_t *QueueCount);
Status_QUEUE_t DestroyQueue(QUEUE_t *queue_obj);

#endif // QUEUE_H_
