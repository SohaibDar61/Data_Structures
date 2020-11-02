#include <stdio.h>
#include <stdlib.h>
#include "que.h"

QUE q;
uint32_t data;
int main()
{
    CreateQueue(&q);
    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Enqueue(&q,50);
    Display(&q);
    Dequeue(&q,&data);
    Dequeue(&q,&data);
    Enqueue(&q,70);
    Enqueue(&q,80);
    Enqueue(&q,90);
    Enqueue(&q,100);
    Enqueue(&q,200);
    Enqueue(&q,300);
    Enqueue(&q,400);
    Enqueue(&q,500);

    Display(&q);
    return 0;
}
