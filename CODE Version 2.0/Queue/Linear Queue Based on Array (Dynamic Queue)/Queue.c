#include "Queue.h"








//================================================================================//
//==                               Static Function                               ==//
//=================================================================================//
static char_t QueueIsFull(QUEUE_t *queue_obj){
    return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

static char_t QueueIsEmpty(QUEUE_t *queue_obj){
    return (0 == queue_obj->ElementCount);
}


//=================================================================================//
//==                               Applications                                  ==//
//=================================================================================//




/**
 * \brief  Create an empty Queue by allocating the head structure
           and the array from dynamic memory
 * \param  (Status_QUEUE_t) status returned while performed this operation
 * \param  (max_Size) number of max number of elements
 * \return (QUEUE_t) pointer to the allocated queue in the heap
 */
QUEUE_t *CreateQueue(uint32_t maxSize, Status_QUEUE_t *ret_status){
    QUEUE_t *MyQueue;
    /* Create queue object in the heap to hold the queue information */
    MyQueue = (QUEUE_t *)malloc(sizeof(QUEUE_t));
    if(NULL == MyQueue){
        *ret_status = QUEUE_NULL_POINTER;
        MyQueue = NULL;
    }
    else{
        /* Create array of <void *> to hold the addresses of the Queue elements */
        MyQueue->QueueArray = (void **)calloc(maxSize, sizeof(void *));
        if(NULL == MyQueue->QueueArray){
            *ret_status = QUEUE_NOK;
            MyQueue = NULL;
        }
        else{
            MyQueue->ElementCount = 0;
            MyQueue->QueueFront = -1;
            MyQueue->QueueRear = -1;
            MyQueue->QueueMaxSize = maxSize;
            *ret_status = QUEUE_OK;
        }
    }
    return MyQueue;
}






/**
 * \brief  (Enqueue) an item on to the queue.
 * \param  (queue_obj) pointer to the allocated queue in the heap
 * \param  (item_ptr) pointer to be inserted
 * \return (Status_QUEUE_t) status returned while performed this operation
 */
Status_QUEUE_t EnqueueElement(QUEUE_t *queue_obj, void *item_ptr){
    Status_QUEUE_t status = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == item_ptr)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Validate if the queue is not full */
        if(QueueIsFull(queue_obj)){
            status = QUEUE_FULL; /* Queue is full, can't enqueue new element */
        }
        else{
            /* Increment Queue Rear Index */
            (queue_obj->QueueRear)++;
            /* Queue wraps to element 0 (Circular Queue) */
            if(queue_obj->QueueRear == queue_obj->QueueMaxSize){
                queue_obj->QueueRear = 0;
            }
            else{ /*Nothing */ }
            /* Insert the input data in to the rear position */
            queue_obj->QueueArray[queue_obj->QueueRear] = item_ptr;
            /* validate if the queue was empty, (front and rear points to the first element) */
            if(queue_obj->ElementCount == 0){
                queue_obj->QueueFront = 0;
                queue_obj->ElementCount = 1;
            }
            else{
                (queue_obj->ElementCount)++; /* New element has been added to the Queue */
            }
            status = QUEUE_OK;
        }
    }
    return status;
}







/**
 * \brief  (Dequeue) an item from the queue.
 * \param  (queue_obj) pointer to the allocated queue in the heap
 * \param  (Status_QUEUE_t) status returned while performed this operation
 * \return (void) pointer to user data if successful, NULL if underflow
 */
void* DequeueElement(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status){
    void *Ret_Element = NULL;
    if((NULL == queue_obj) || (NULL == ret_status)){
        *ret_status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(!queue_obj->ElementCount){
            *ret_status = QUEUE_EMPTY; /* Queue is empty */
            Ret_Element = NULL;
        }
        else{ /* Queue is not empty */
            Ret_Element = queue_obj->QueueArray[queue_obj->QueueFront];
            /* Increment Queue Front Index */
            (queue_obj->QueueFront)++;
            /* Queue front has wrapped to element 0 (Circular Queue) */
            if(queue_obj->QueueFront == queue_obj->QueueMaxSize){
                queue_obj->QueueFront = 0;
            }
            else{ /* Nothing */ }
            /* Check if the element is the last element in the Queue */
            if(1 == queue_obj->ElementCount){
                queue_obj->QueueFront = -1; /* Queue is empty */
                queue_obj->QueueRear = -1;  /* Queue is empty */
            }
            else{ /* Nothing */ }
            (queue_obj->ElementCount)--; /* Element has been deleted from the Queue */
            *ret_status = QUEUE_OK;
        }
    }
    return Ret_Element;
}




/**
 * \brief  (return) data of queue-front only
 * \param  (queue_obj) pointer to the allocated queue in the heap
 * \param  ((Status_QUEUE_t) status returned while performed this operation
 * \return (void) pointer to user data if successful, NULL if underflow
 */
void *QueueFront(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status){
    void *Ret_Element = NULL;
    if((NULL == queue_obj) || (NULL == ret_status)){
        *ret_status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(!queue_obj->ElementCount){
            *ret_status = QUEUE_EMPTY; /* Queue is empty */
            Ret_Element = NULL;
        }
        else{ /* Queue is not empty */
            Ret_Element = queue_obj->QueueArray[queue_obj->QueueFront];
            *ret_status = QUEUE_OK;
        }
    }
    return Ret_Element;
}




/**
 * \brief  (return) data of queue-rear only
 * \param  (queue_obj) pointer to the allocated queue in the heap
 * \param  (Status_QUEUE_t) status returned while performed this operation
 * \return (void) pointer to user data if successful, NULL if underflow
 */
void *QueueRear(QUEUE_t *queue_obj, Status_QUEUE_t *ret_status){
    void *Ret_Element = NULL;
    if((NULL == queue_obj) || (NULL == ret_status)){
        *ret_status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(!queue_obj->ElementCount){
            *ret_status = QUEUE_EMPTY; /* Queue is empty */
            Ret_Element = NULL;
        }
        else{ /* Queue is not empty */
            Ret_Element = queue_obj->QueueArray[queue_obj->QueueRear];
            *ret_status = QUEUE_OK;
        }
    }
    return Ret_Element;
}



/**\brief   Check the count of Queue
 * \param   (queue_obj) Pointer to the Queue.
 * \param   (QueueCount) pointer to number of elements allocated in the Queue
 * \return  Status if the function execution
 */
Status_QUEUE_t GetQueueCount(QUEUE_t *queue_obj, uint32_t *QueueCount){
    Status_QUEUE_t status = QUEUE_NOK;
    if((NULL == queue_obj) || (NULL == QueueCount)){
        status = QUEUE_NULL_POINTER;
    }
    else{
        /* Check if the queue is empty */
        if(!queue_obj->ElementCount){
            *QueueCount = 0;    /* Queue is empty */
        }
        else{ /* Queue is not empty */
            *QueueCount = queue_obj->ElementCount;
        }
        status = QUEUE_OK;
    }
    return status;
}



/**
 * \brief  Destroy all the elements of queue.
 * \param  (QUEUE_t) pointer to the allocated queue in the heap
 * \return (Status_QUEUE_t) status returned while performed this operation
 */
Status_QUEUE_t DestroyQueue(QUEUE_t *queue_obj){
    Status_QUEUE_t status = QUEUE_NOK;
    if(NULL == queue_obj){
        status = QUEUE_NULL_POINTER;
    }
    else{
        free(queue_obj->QueueArray);
        free(queue_obj);
        status = QUEUE_OK;
    }
    return status;
}

