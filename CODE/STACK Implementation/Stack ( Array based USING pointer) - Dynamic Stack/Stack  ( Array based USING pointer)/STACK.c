#include <stdio.h>
#include "STACK.h"




//===================================STATIC FUNCTIONS PROTOTYPE=====================================================//

static uint8_t StackFull(STACK* stack_obj);
static uint8_t StackEmpty(STACK* stack_obj);

//==================================================================================================================//


//=========================================================================================//
/**
 * \brief  Create an empty Stack by allocating the head structure
           and the array from dynamic memory
 * \param  (Stack_Status_t) status returned while performed this operation
 * \param  (max_Size) number of max number of elements
 * \return (STACK) pointer to the allocated stack in the heap
 */
STACK* CreateStack(uint32_t max_Size, Stack_Status_t *ret_status_t)
{
    STACK *my_stack = NULL;
    if(NULL == ret_status_t)
    {
        *ret_status_t = STACK_NULL_Pointer;       /* NULL pointer passed to the function */
         my_stack = NULL;
    }
    else
    {
        my_stack = (STACK*)malloc(sizeof(STACK)); /* Allocate the stack in the heap */
        if(!my_stack){
            *ret_status_t = STACK_NOK;            /* Stack not created successfully */
            my_stack = NULL;
        }
        else{
          my_stack->Top = -1;           /* Initialize the stack pointer to -1 (empty stack) */
          my_stack->Size = ZERO;        /* Initialize the element counter to 0 (empty stack) */
          my_stack->MAXSize_STACK = 5;  /* Initialize the maximum number of elements in the stack */
          my_stack->StackArray = (void**)calloc((my_stack->MAXSize_STACK),sizeof(void*));
          if(!my_stack->StackArray){
            free(my_stack);             /* Free the stack object as the Array not created successfully */
            my_stack = NULL;           /* Array not created successfully */
            *ret_status_t = STACK_NOK;
          }
          else{
            *ret_status_t = STACK_OK;
          }
        }
    }
    return my_stack;

}

//=========================================================================================//

/**
 * \brief  (Destroy)releases all memory to the heap.
 * \param  (Stack_Status_t) status returned while performed this operation
 * \param  (STACK) pointer to the allocated stack in the heap
 * \return (STACK) pointer to the allocated stack in the heap
 */
STACK* DestoryStack(STACK* stack_obj, Stack_Status_t* ret_status_t){
    if((NULL == stack_obj) || (NULL == ret_status_t))
    {
        *ret_status_t = STACK_NULL_Pointer;   /* Release the Array object */
    }
    else
    {
        free(stack_obj->StackArray);   /* Release the Array object */
        free(stack_obj);               /* Release the stack object */
        *ret_status_t = STACK_OK;
    }
    return NULL;
}

//=========================================================================================//
/**
 * \brief  (Push_stack)pushes an item onto the stack.
 * \param  (STACK) pointer to the allocated stack in the heap
 * \param  (Ptr_item) pointer to be inserted
 * \return (Stack_Status_t) status returned while performed this operation
 */
Stack_Status_t Push_Stack(STACK* stack_obj, void* Ptr_item)
{
    Stack_Status_t status_stack = STACK_NOK;
    if((NULL == stack_obj) || (NULL == Ptr_item))
    {
        status_stack = STACK_NULL_Pointer;     /* NULL pointer passed to the function */
    }
    else
    {
        if(StackFull(stack_obj)){
        status_stack = STACK_FULL;       /* Stack is full, prevent stack overflow */
        }
            stack_obj->Top++;            /* Points to the next element in the stack */
            stack_obj->StackArray[stack_obj->Top] = Ptr_item;
            stack_obj->Size++;           /* Increment the number of elements in the stack */
           status_stack = STACK_OK;
    }
    return status_stack;
}


//=========================================================================================//
/**
 * \brief  (Pop_Stack)Pop an item from the stack.
 * \param  (STACK) pointer to the allocated stack in the heap
 * \param  (Stack_Status_t) status returned while performed this operation
 * \return (void) pointer to user data if successful, NULL if underflow
 */
void* Pop_Stack(STACK* stack_obj, Stack_Status_t* ret_status_t)
{
    void *Ptr_data_poped = NULL;
    if((NULL == stack_obj) || (NULL == ret_status_t)){
        *ret_status_t = STACK_NULL_Pointer;
        Ptr_data_poped = NULL;
    }
    else
    {
         if(StackEmpty(stack_obj)){
        *ret_status_t = STACK_Empty;       /* Stack is Empty, prevent stack underflow */
        Ptr_data_poped = NULL;
    }
    else{
        Ptr_data_poped = stack_obj->StackArray[stack_obj->Top];
        stack_obj->Top--;
        stack_obj->Size--;
        *ret_status_t = STACK_OK;
    }
  }
  return Ptr_data_poped;
}

//=========================================================================================//
/**
 * \brief  (StackTop) retrieves the data from the top of the
            stack without changing the stack
 * \param  (STACK) pointer to the allocated stack in the heap
 * \param  (Stack_Status_t) status returned while performed this operation
 * \return (void) user data if successful, NULL if underflow
 */
void* StackTop(STACK* stack_obj, Stack_Status_t* ret_status_t)
{
     void *Ptr_data_TOP = NULL;
    if((NULL == stack_obj) || (NULL == ret_status_t)){
        *ret_status_t = STACK_NULL_Pointer;
        Ptr_data_TOP = NULL;
    }
    else
    {
         if(StackEmpty(stack_obj)){
        *ret_status_t = STACK_Empty;       /* Stack is Empty, prevent stack underflow */
        Ptr_data_TOP = NULL;
    }
    else{
        /* Copy the top element to the user */
        Ptr_data_TOP = stack_obj->StackArray[stack_obj->Top];
        *ret_status_t = STACK_OK;
    }
   }
  return Ptr_data_TOP;
}
//=========================================================================================//

/**
 * \brief  (StackSize)returns number of elements in stack.
 * \param  (STACK) pointer to the allocated stack in the heap
 * \param  (stack_size) number of elements allocated in the stack
 * \return (Stack_Status_t) status returned while performed this operation
 */
Stack_Status_t StackSize(STACK* stack_obj, uint32_t* stack_size)
{
    Stack_Status_t status_stack = STACK_NOK;
    if((NULL == stack_obj) || (NULL == stack_size))
    {
        status_stack = STACK_NULL_Pointer;     /* NULL pointer passed to the function */
    }
    else
    {
      *stack_size = stack_obj->Size;
         status_stack = STACK_OK;
    }
    return status_stack;
}


//=========================================================================================//


/**
  * @brief  Check if the Stack is Full or Not
  * @param  (STACK) pointer to the allocated stack in the heap
  * @retval (uint8_t)  returned 1 if ture or Zero if false
  */
static uint8_t StackFull(STACK* stack_obj)
{
    return(stack_obj->Size == stack_obj->MAXSize_STACK);
}

//=========================================================================================//
/**
  * @brief  Check if the Stack is Empty or Not
  * @param  (STACK) pointer to the allocated stack in the heap
  * @retval (uint8_t)  returned 1 if ture or Zero if false
  */
static uint8_t StackEmpty(STACK* stack_obj)
{
    return(stack_obj->Size == ZERO);
}
//=========================================================================================//
