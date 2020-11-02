
#ifndef _QUE_H
#define _QUE_H
#include "que_type.h"

#define MAX_QUEUE 10
#define ZERO 0
#define ONE 1
#define QUE_INIT -1

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;


typedef struct queue{
    uint32_t entry[MAX_QUEUE];
    sint32_t front ;
    sint32_t near;
    uint32_t size;
}QUE;

typedef enum{
    Queue_Empty=-1,
    Queue_Full=-1,
    Queue_NOTFUll=0,
    DONE
}STATUS_Que;


STATUS_Que QueueEmpty(QUE *pq);
STATUS_Que QueueFull(QUE *pq);
STATUS_Que CreateQueue(QUE *pq);
STATUS_Que Enqueue(QUE *pq, uint32_t data);
STATUS_Que Dequeue(QUE *pq, uint32_t *pdata);
STATUS_Que Display(QUE *pq);



#endif //_QUE_H
