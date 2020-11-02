#include <stdio.h>
#include <stdlib.h>
#include "QUEUE.h"




//================================================================================//
//==                               Applications                                  ==//
//=================================================================================//
/**
  * @brief  Initialize the Queue pointers
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Queue CreateQueue(QUEUE *pq)
{
    pq->front = ZERO;
    pq->near = QUEUE_INIT;
    pq->size =ZERO;
    return DONE;
}


/**
  * @brief  Get Element from the Queue
  * @param  pq    Pointer to the Queue.
  * @param  value   pointer to the variable that will store the returned value
  * @retval Status if the function execution
  */
STATUS_Queue Dequeue(QUEUE *pq, uint32_t *pdata)
{
    if (pq->size == ZERO)
        return Queue_Empty;
    else
    {
       *pdata = pq->enrty[pq->front] ;
        pq->front ++;
        pq->size --;
        return DONE;
    }
}



/** @brief  Add Element to the Queue
  * @param  pq    Pointer to the Queue.
  * @param  data   Value to be added
  * @retval Status if the function execution
  */
STATUS_Queue Enqueue(QUEUE *pq, uint32_t data)
{
    if(pq->size == MAX_QUEUE)
        return Queue_Full;
    else
    {
        if(pq->size == ZERO)
        {
            pq->front = ZERO;
            pq->near = ZERO;
        }
        else
        {
            pq->near ++;
        }
        pq->enrty[pq->near] = data;
        pq->size ++;
        return DONE;
    }
}

/**
// we can write code with this also
STATUS_Queue Enqueue(QUEUE *pq, uint32_t data)
{
    pq->near = (pq->near + ONE ) % MAX_QUEUE ;
    pq->enrty[pq->near] = data;
    pq->size ++;
    return DONE;
*/





/**
  * @brief  Check the size of the Queue
  * @param  pq  Pointer to the Queue.
  * @retval Status if the function execution
  */
uint32_t QueueSize(QUEUE *pq)
{
    return (pq->size);
}

/**
  * @brief  Check if the Queue is Empty or Not
  * @param  pq  Pointer to the Queue.
  * @retval Status if the function execution
  */

uint32_t QueueEmpty(QUEUE *pq)
{
    return (!pq->size);
}

/**
  * @brief  Check if the Queue is Full or Not
  * @param  pq  Pointer to the Queue.
  * @retval Status if the function execution
  */
uint32_t QueueFull(QUEUE *pq)
{
    return (pq->size == MAX_QUEUE);
}


/**
  * @brief  Display the Elements of the Queue
  * @param  pq    Pointer to the Queue.
  * @retval Status if the function execution
  */
STATUS_Queue DisplayQueue(QUEUE *pq)
{
    sint32_t l_counter = ZERO;
    if(QueueEmpty(pq))
    {
        return Queue_Empty;
    }
    else
    {
        for(l_counter = pq->front; l_counter <= pq->near; l_counter++)
        {
            printf("%d  ", pq->enrty[l_counter]);
           // printf("\n");
        }
        return DONE;
    }
}
