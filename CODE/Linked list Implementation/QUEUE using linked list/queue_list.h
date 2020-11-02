
#ifndef _QUEUE_H
#define _QUEUE_H


#include <stdio.h>
#include <stdlib.h>

#define nullptr (void*)0
#define ZERO 0
#define ONE 1
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum {
    NO_SPACE=0,
    WRONG_INDEX=-1,
    Empty_QUEUE,
    DONE
}STATUS_QUEUE;

typedef struct node{
    uint32_t entry;
    struct node *next;
}NODE;

typedef struct queue{
    NODE *front;
    NODE *near;
    uint32_t size;
}QUE;


STATUS_QUEUE printALL(QUE *pq);
STATUS_QUEUE CreateQueue(QUE *pq);
STATUS_QUEUE Enqueue(QUE *pq,int data);
STATUS_QUEUE Dequeue(QUE *pq, uint32_t *pdata);
STATUS_QUEUE ClearQueue(QUE *pq);
uint32_t QueueEmpty(QUE *pq);
uint32_t QueueFull(QUE *pq);
uint32_t QueueSize(QUE *pq);

//STATUS_QUEUE Append(QUE *pq,int data);
//STATUS_QUEUE Serve(QUE *pq, uint32_t *pdata);

#endif // _QUEUE_H
