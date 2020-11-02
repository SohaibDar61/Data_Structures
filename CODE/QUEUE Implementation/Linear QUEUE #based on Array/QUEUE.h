#ifndef _QUEUE_H
#define _QUEUE_H

#include "QUEUE_TYPE.h"
#define MAX_QUEUE 10
#define ZERO 0
#define QUEUE_INIT  -1


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef struct{
    uint32_t front;
    sint32_t near;
    uint32_t size;
    uint32_t enrty[MAX_QUEUE];
}QUEUE;

typedef enum{
    Queue_Empty,
    Queue_Full,
    Queue_NOTFUll,
    DONE
}STATUS_Queue;


STATUS_Queue DisplayQueue(QUEUE *pq);
STATUS_Queue Dequeue(QUEUE *pq, uint32_t *pdata);
STATUS_Queue Enqueue(QUEUE *pq, uint32_t data);
STATUS_Queue CreateQueue(QUEUE *pq);
uint32_t QueueFull(QUEUE *pq);
uint32_t QueueSize(QUEUE *pq);
uint32_t QueueEmpty(QUEUE *pq);



#endif  // _QUEUE_H
