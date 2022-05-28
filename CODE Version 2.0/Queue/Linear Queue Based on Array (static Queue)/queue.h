#ifndef QUEUE_H_
#define QUEUE_H_



#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"



#define MAX_QUEUE 10
#define ZERO 0
#define QUEUE_INIT  -1


typedef struct
{
    uint32_t front;
    sint32_t near;
    uint32_t size;
    uint32_t QueueEntry[MAX_QUEUE];
} QUEUE;

typedef enum
{
    Queue_Empty,
    Queue_Full,
    Queue_NOTFUll,
} STATUS_Queue_t;

typedef enum
{
    Queue_NOT_OK,
    Queue_OK
} return_Queue_t;



//================================================================================//
//==                               PROTOTYPE                                  ==//
//=================================================================================//
return_Queue_t DisplayQueue(QUEUE *queue_obj);
return_Queue_t Dequeue(QUEUE *queue_obj, uint32_t *Pdata);
return_Queue_t Enqueue(QUEUE *pq, uint32_t item_data);
return_Queue_t CreateQueue(QUEUE *queue_obj);
return_Queue_t QueueSize(QUEUE *queue_obj);




#endif // QUEUE_H_
