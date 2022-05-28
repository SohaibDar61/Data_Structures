/*
 ============================================================================
 Name        : main_Queue.c
 Author      : Sohaib Dar
 Version     : version 2.0
 Copyright   : For free
 Description : Data_structure_Linear Queue Based on Array Implementation [Dynamic Queue]
 Date        : 2 / 23 / 2022
 ============================================================================
 */
#include "Queue.h"




uint32_t Queue1MaxElem = 0;
QUEUE_t *Queue1;
void *QueueRetVal;

uint32_t Number1 = 0x11, Number2 = 0x22, Number3 = 0x33, Number4 = 0x44, Number5 = 0x55;
uint32_t QueueCount;

int main()
{
    Status_QUEUE_t ReturnQueueStatus = QUEUE_NOK;

    printf("Please enter number of elements in Queue1 : ");
    scanf("%i", &Queue1MaxElem);

    Queue1 = CreateQueue(Queue1MaxElem, &ReturnQueueStatus);
    printf("0x%X \n", Queue1);

    ReturnQueueStatus = EnqueueElement(Queue1, &Number1); printf("=> %i \n", ReturnQueueStatus);
    ReturnQueueStatus = EnqueueElement(Queue1, &Number2); printf("=> %i \n", ReturnQueueStatus);
    ReturnQueueStatus = EnqueueElement(Queue1, &Number3); printf("=> %i \n", ReturnQueueStatus);

    ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount); printf("=> %i \n", ReturnQueueStatus);
    printf("Count = %i \n", QueueCount);

    QueueRetVal = QueueRear(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("QueueRear = 0x%X \n", *((uint32_t *)QueueRetVal));

    ReturnQueueStatus = EnqueueElement(Queue1, &Number4); printf("=> %i \n", ReturnQueueStatus);
    QueueRetVal = QueueRear(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("QueueRear = 0x%X \n", *((uint32_t *)QueueRetVal));

    ReturnQueueStatus = EnqueueElement(Queue1, &Number5); printf("=> %i \n", ReturnQueueStatus);
    ReturnQueueStatus = EnqueueElement(Queue1, &Number5); printf("=> %i \n", ReturnQueueStatus);

    ReturnQueueStatus = GetQueueCount(Queue1, &QueueCount); printf("=> %i \n", ReturnQueueStatus);
    printf("Count = %i \n", QueueCount);

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = QueueFront(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Front = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));

    QueueRetVal = DequeueElement(Queue1, &ReturnQueueStatus); printf("=> %i \n", ReturnQueueStatus);
    if(QueueRetVal){
        printf("Value = 0x%X \n", *((uint32_t *)QueueRetVal));
    }

    ReturnQueueStatus = DestroyQueue(Queue1);

    return 0;
}
