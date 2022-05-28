/*
 ============================================================================
 Name        : main_Queue.c
 Author      : Sohaib Dar
 Version     : version 2.0
 Copyright   : For free
 Description : Data_structure_Linear Queue Based on Array Implementation [Static Queue]
 Date        : 12 / 23 / 2020
 ============================================================================
 */
#include "queue.h"

QUEUE myQueue;
uint32_t data;

int main()
{
    return_Queue_t ret = Queue_NOT_OK;
    ret = CreateQueue(&myQueue);
    if(ret == Queue_NOT_OK)
        printf("the Queue is failed to be initialized\n\n");
    else{

    Enqueue(&myQueue, 11); DisplayQueue(&myQueue);
    Enqueue(&myQueue, 22); //DisplayQueue(&q);
    Enqueue(&myQueue, 33); //DisplayQueue(&q);
    Enqueue(&myQueue, 44); //DisplayQueue(&q);
    Enqueue(&myQueue, 55); //DisplayQueue(&q);
    Dequeue(&myQueue, &data);//DisplayQueue(&q);
    Dequeue(&myQueue, &data); //DisplayQueue(&q);
    Dequeue(&myQueue, &data); DisplayQueue(&myQueue);
    Enqueue(&myQueue, 100);
    Enqueue(&myQueue, 99); //DisplayQueue(&q);
    Enqueue(&myQueue, 111); //DisplayQueue(&q);
    Enqueue(&myQueue, 222);//DisplayQueue(&q);
    Enqueue(&myQueue, 2000);DisplayQueue(&myQueue);
    Enqueue(&myQueue, 200);DisplayQueue(&myQueue);
    }
    return 0;
}
