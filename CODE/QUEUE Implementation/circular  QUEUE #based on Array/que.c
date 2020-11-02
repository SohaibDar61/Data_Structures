#include "que.h"
#include <stdio.h>

/**
  * @brief  Initialize the Queue pointers
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Que CreateQueue(QUE *pq)
{
    pq->front = QUE_INIT;
    pq->near  = QUE_INIT;
    pq->size = ZERO;
    return DONE;
}



/**
  * @brief  Display the Elements of the Queue
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Que Display(QUE *pq)
{
    sint32_t I_COUNTER;
    if(pq->front > pq->near)
    {
        for(I_COUNTER = pq->front; I_COUNTER < MAX_QUEUE; I_COUNTER ++)
        {
            printf("%d\t",pq->entry[I_COUNTER]);
        }
        for (I_COUNTER = ZERO; I_COUNTER <= pq->near; I_COUNTER++)
            printf("%d\t", pq->entry[I_COUNTER]);
    }
    else
    {
        for (I_COUNTER = pq->front; I_COUNTER <= pq->near; I_COUNTER++)
            printf("%d\t", pq->entry[I_COUNTER]);
    }
    printf("\n");
    return DONE;
}



/**
  * @brief  Add Element to the Queue
  * @param  pq    Pointer to the Queue.
  * @param  value   Value to be added
  * @retval Status if the function execution
  */
STATUS_Que Enqueue(QUE *pq,uint32_t data)
{
    if((pq->front == ZERO && pq->near == MAX_QUEUE - ONE) || (pq->front == pq->near + ONE))
    {
        return Queue_Full;
    }
    if(pq->near == QUE_INIT)
    {
        pq->front = ZERO;
        pq->near = ZERO;
    }
    else
    {
        if(pq->near == MAX_QUEUE - ONE && pq->front > ZERO)
            pq->near =ZERO;
        else
            pq->near ++;
    }
    pq->entry[pq->near] = data;
    pq->size ++;
    return DONE;
}




/**
  * @brief  Get Element from the Queue
  * @param  pq    Pointer to the Queue.
  * @param  value   pointer to the variable that will store the returned value
  * @retval Status if the function execution
  */
STATUS_Que Dequeue(QUE *pq,uint32_t *pdata)
{
    if(pq->front == QUE_INIT)
    {
        printf("Queue Underflow\n");
        return Queue_Empty;
    }
    else
    {
        *pdata= pq->entry[pq->front];
        if(pq->front == MAX_QUEUE - ONE)
            pq->front = ZERO;
        else
            pq->front ++;
    }
    pq->size --;
    return DONE;
}




/**
  * @brief  Check if the Queue is Empty or Not
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Que QueueEmpty(QUE *pq)
{
    if((pq->front == QUE_INIT )&& (pq->near == QUE_INIT))
        return Queue_Empty;
    else
        return Queue_NOTFUll;
}

/**
  * @brief  Check if the Queue is FuLL or Not
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Que QueueFull(QUE *pq)
{
    if(((pq->front == ZERO) && (pq->near == MAX_QUEUE - 1)) ||
            (pq->front == pq->near + ONE))
        return Queue_Full;
    else
        return Queue_NOTFUll;
}
