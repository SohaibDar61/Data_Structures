#include <stdio.h>
#include <stdlib.h>
#include "QUEUE.h"

QUEUE q;
uint32_t data;
int main()
{
    CreateQueue(&q);

    Enqueue(&q, 11); //DisplayQueue(&q);
    Enqueue(&q, 22); //DisplayQueue(&q);
    Enqueue(&q, 33); //DisplayQueue(&q);
    Enqueue(&q, 44); //DisplayQueue(&q);
    Enqueue(&q, 55); //DisplayQueue(&q);
    Dequeue(&q, &data);//DisplayQueue(&q);
    Dequeue(&q, &data); //DisplayQueue(&q);
    Dequeue(&q, &data); DisplayQueue(&q);
    Enqueue(&q, 100);
    Enqueue(&q, 99); //DisplayQueue(&q);
    Enqueue(&q, 111); //DisplayQueue(&q);
    Enqueue(&q, 222);//DisplayQueue(&q);
    Enqueue(&q, 2000);DisplayQueue(&q);
    Enqueue(&q, 200);DisplayQueue(&q);

    return 0;
}
