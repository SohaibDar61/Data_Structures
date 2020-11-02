/*
 ============================================================================
 Name        : main_queue_list.c
 Author      : Sohaib Reda Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Data_structure_Implement a QUEUE using singly linked list
 Date        : 13 / 1 / 2019
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"
/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */

QUE q;
uint16_t Size;
uint32_t *pdata;
uint32_t data;
int main()
{
    pdata = &data;
    CreateQueue(&q);
    /* ========================================================================== */
    /*                               Application                                  */
    /* ========================================================================== */
    //==============================//
    //Append(&q,10);
    //Append(&q,20);
    //Append(&q,30);
    //Append(&q,40);
    //Append(&q,50);
    Enqueue(&q,60);
    Enqueue(&q,45);
    Enqueue(&q,47);
    Enqueue(&q,88);
    printALL(&q);
    //Serve(&q,pdata);
    //Serve(&q,pdata);
    printALL(&q);
    ClearQueue(&q);
    Enqueue(&q,90);
    Enqueue(&q,15);
    Enqueue(&q,87);
    Enqueue(&q,38);
    Size = QueueSize(&q);
    printf("\n%d\n",Size);
    Dequeue(&q,pdata);
    printALL(&q);
    Dequeue(&q,pdata);
    printALL(&q);
    return 0;
}
