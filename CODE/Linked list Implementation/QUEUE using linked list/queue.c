#include "queue_list.h"

/* ========================================================================== */
/*                               Application                                  */
/* ========================================================================== */
//=============================================================================//

/**
  * @brief  Delete the last node of QUEUE
  * @param  pq Pointer to the QUEUE.
  * @param  The pdata is a pointer to the  deleted element
  * @retval Status if the function execution
  * @concept FIFO
  */
STATUS_QUEUE Dequeue(QUE *pq, uint32_t *pdata)
{
    NODE *ptr,*D_node;
    if(pq->front == nullptr)
        return Empty_QUEUE;
    else
    {
        if(pq->size == ONE)
        {
            *pdata = pq->front->entry;
            free(pq->front);
            pq->front = pq->near  = nullptr;
        }
        else
        {
            ptr = pq->front;
            D_node = pq->front;
            while(D_node->next != nullptr)
            {
                ptr = D_node;
                D_node = D_node->next;
            }
            *pdata = ptr->entry;
            ptr->next = nullptr;
            pq->near = ptr;
            free(D_node);
        }
        pq->size --;
        return DONE;
    }
}

/*
//delete element from the first of queue
STATUS_QUEUE Serve(QUE *pq, uint32_t *pdata)
{
    NODE *ptr = pq->front;
    if(pq->front == nullptr)
        return Empty_QUEUE;
    else
    {
        *pdata = ptr->entry;
        if(pq->size == ONE)
        {
            free(pq->front);
            pq->front = pq->near =nullptr;
        }
        else
        {
            pq->front = pq->front->next;
            free(ptr);
        }
        pq->size --;
        return DONE;
    }

}
*/
//=============================================================================//
//==============================================================================//
//==============================================================================//



/**
  * @brief  Add to the first of QUEUE
  * @param  pq Pointer to the QUEUE.
  * @param  The data is a value to be added
  * @retval Status if the function execution
  * @concept FIFO
  */
STATUS_QUEUE Enqueue(QUE *pq,int data)
{
    NODE *ptr =(NODE *)malloc(sizeof(NODE)); //New named node (ptr) declared with size of node declared before
    if(ptr == nullptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        ptr->next = nullptr;
        // if((pq->front == nullptr )&& (pq->near == nullptr))
        //if(pq->size == ZERO)
        if(QueueEmpty(pq))
        {
            pq->front = pq->near = ptr;
            ptr->next = nullptr;
        }
        else
        {
            ptr->next = pq->front;
            pq->front =ptr;
        }
        pq->size ++;
        return DONE;
    }
}
/*
// ADD element in the last of Queue
STATUS_QUEUE Append(QUE *pq,int data)
{
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    if(!ptr)
        return NO_SPACE;
    else
    {
        ptr->entry =data;
        if(pq->front == nullptr)
        {
            pq->front = pq->near =ptr;
            ptr->next = nullptr;
        }
        else
        {
            pq->near->next = ptr;
            pq->near = ptr;
            ptr->next = nullptr;
        }
        pq->size ++;
        return DONE;
    }
}
*/

//=============================================================================//
//==============================================================================//
//==============================================================================//



/**
  * @brief  Display the data of nodes
  * @param  pq Pointer to the queue.
  */
STATUS_QUEUE printALL(QUE *pq)
{
    NODE *current = pq->front;
    while(current != nullptr)
    {
        printf("%d  ",current->entry);
        current = current->next;
    }
    printf("\n");
    return DONE;
}

/**
  * @brief  Initialize the queue
  * @param  pq Pointer to the queue.
  */
STATUS_QUEUE CreateQueue(QUE *pq)
{
    pq->front = nullptr;
    pq->near  = nullptr;
    pq->size = ZERO;
    return DONE;
}

/**
  * @brief  count the elements that exist in the QUEUE
  * @param  pq Pointer to the queue.
  */
uint32_t QueueSize(QUE *pq)
{
    return (pq->size);
}

/**
  * @brief  Check if the queueu is FULL or Not
  * @param  pq Pointer to the queue.
  * @retval return true if the function execution
  */
uint32_t QueueFull(QUE *pq)
{
    return 0;
}


/**
  * @brief  Check if the QUEUE is Empty or Not
  * @param  pq Pointer to the queue.
  * @retval return true if the function execution
  */
uint32_t QueueEmpty(QUE *pq)
{
    return (!pq->size);
}


/**
  * @brief  CLEAR the elements of QUEUE
  * @param  pq Pointer to the queue.
  * @retval return true if the function execution
  */
STATUS_QUEUE ClearQueue(QUE *pq)
{
    if(pq->front == nullptr)
        return Empty_QUEUE;
    else
    {
        if(pq->size == ONE)
        {
            free(pq->front);
            pq->front = pq->near = nullptr;
        }
        else
        {
            while(pq->front)
            {
                pq->near = pq->front->next;
                free(pq->front);
                pq->front = pq->near;
            }
        }
        pq->size = ZERO;
        return DONE;
    }
}


