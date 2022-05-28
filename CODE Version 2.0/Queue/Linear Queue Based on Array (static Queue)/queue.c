
#include "queue.h"
#include "Platform_Types.h"

//================================================================================//
//==                               Static Function                                  ==//
//=================================================================================//
static char_t QueueFull(QUEUE *queue_obj);
static char_t QueueEmpty(QUEUE *queue_obj);

//================================================================================//
//==                               Applications                                  ==//
//=================================================================================//
/**
  * @brief  Initialize the Queue pointers
  * @param  (queue_obj) Pointer to the Queue.
  * @retval (return_Queue_t) if the function execution
  */
return_Queue_t CreateQueue(QUEUE *queue_obj)
{
    return_Queue_t ret = Queue_NOT_OK;
    if(queue_obj == NULL)
    {
        ret = Queue_NOT_OK;
    }
    else
    {
        queue_obj->front = QUEUE_INIT;
        queue_obj->near  = QUEUE_INIT;
        queue_obj->size  = ZERO;
        ret = Queue_OK;
    }
    return ret;
}


/**
  * @brief   Get Element from the Queue
  * @param  (queue_obj) Pointer to the Queue.
  * @param  (Pdata)  pointer to the variable that will store the returned value
  * @retval (return_Queue_t) if the function execution
  */
return_Queue_t Dequeue(QUEUE *queue_obj, uint32_t *Pdata)
{
    return_Queue_t ret = Queue_NOT_OK;
    if(QueueEmpty(queue_obj) == Queue_Empty || queue_obj ==NULL)
        ret =  Queue_NOT_OK;
    else
    {
        *Pdata = queue_obj->QueueEntry[queue_obj->front];
        queue_obj->front ++;
        queue_obj->size --;
        ret =  Queue_OK;
    }
    return ret;
}



/** @brief  Add Element to the Queue
  * @param  (queue_obj Pointer to the Queue.
  * @param  (item_data) Value to be added
  * @retval (return_Queue_t) if the function execution
  */
return_Queue_t Enqueue(QUEUE *queue_obj, uint32_t item_data)
{
    return_Queue_t ret = Queue_NOT_OK;
    if(QueueFull(queue_obj) == Queue_Full || queue_obj ==NULL)
        ret =  Queue_NOT_OK;
    else
    {
        if(queue_obj->size == ZERO)
        {
            queue_obj->front = ZERO;
            queue_obj->near = ZERO;
        }
        else
            queue_obj->near ++;

        queue_obj->QueueEntry[queue_obj->near] = item_data;
        queue_obj->size ++;
        ret = Queue_OK;
    }
    return ret;
}

/**
// we can write code with this also
STATUS_Queue Enqueue(QUEUE *queue_obj, uint32_t data)
{
    queue_obj->near = (queue_obj->near + ONE ) % MAX_QUEUE ;
    queue_obj->enrty[queue_obj->near] = data;
    queue_obj->size ++;
*/





/**
  * @brief  Check the size of the Queue
  * @param  queue_obj  Pointer to the Queue.
  * @retval Status if the function execution
  */
return_Queue_t QueueSize(QUEUE *queue_obj)
{
    return_Queue_t ret = Queue_NOT_OK;
    if(queue_obj == NULL)
        ret = Queue_NOT_OK;
    else
    {
        printf("The QueueSize = %i\n",queue_obj->size);
        ret = Queue_OK;
    }
    return ret;
}



/**
  * @brief  Display the Elements of the Queue
  * @param  queue_obj    Pointer to the Queue.
  * @retval Status if the function execution
  */
return_Queue_t DisplayQueue(QUEUE *queue_obj)
{
    static sint32_t l_counter = ZERO;
    return_Queue_t ret = Queue_NOT_OK;
    if( queue_obj == NULL || QueueEmpty(queue_obj) == Queue_Empty)
        ret =  Queue_NOT_OK;
    else
    {
        printf("Queue Data : ");
        for(l_counter = queue_obj->front; l_counter <= queue_obj->near; l_counter++)
        {
            printf("%d  ", queue_obj->QueueEntry[l_counter]);
        }
        printf("\n\n");
        ret = Queue_OK;
    }
    return ret;
}







/**
  * @brief  Check if the Queue is Empty or Not
  * @param  queue_obj  Pointer to the Queue.
  * @retval (char_t) return value
  */
static char_t QueueEmpty(QUEUE *queue_obj)
{
    return (!queue_obj->size);
}

/**
  * @brief  Check if the Queue is Full or Not
  * @param  queue_obj  Pointer to the Queue.
  * @retval (char_t) return value
  */
static char_t QueueFull(QUEUE *queue_obj)
{
    return (queue_obj->size == MAX_QUEUE);
}
