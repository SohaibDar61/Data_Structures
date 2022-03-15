#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>
#include "Stack_Types.h"



typedef struct Stack{
  void **StackArray;                //points on the array of address in the stack
  uint32_t MAXSize_STACK;           //has Max. number of stack_size in the stack
  sint16_t Top;                     //has index of top_Element in the stack
  uint32_t Size;                    //has number of Elements in the stack
}STACK;


typedef enum stack_status{
    STACK_NOK,                        //Stack operation not performed successfully
    STACK_OK,                         //Stack operations performed successfully
    STACK_Empty,                      //Stack is Empty
    STACK_FULL,                       //Stack is Full
    STACK_NULL_Pointer                //Null pointer passed to the stack operations
}Stack_Status_t;


//============================PROTOTYPE SECTION===============================================//
/**
 * \brief Create an empty Stack by allocating the head structure
          and the array from dynamic memory
 * \param (Stack_Status_t) status returned while performed this operation
 * \param (max_Size) number of max number of elements
 * \return (STACK) pointer to the allocated stack in the heap
 */
STACK* CreateStack(uint32_t max_Size, Stack_Status_t *ret_status_t);



/**
 * \brief Create Stack(initialize stack pointer)
 * \param PS pointer to the Stack
 * \return Status of initialization process(CreateStack)
 */
STACK* DestoryStack(STACK* stack_obj, Stack_Status_t* ret_status_t);



/**
  * @brief  Add Element to the Stack
  * @param  PS Pointer to the Stack.
  * @param  The Data is a Value to be added
  * @retval Status if the function execution
  */
Stack_Status_t Push_Stack(STACK* stack_obj, void* Ptr_item);

/**
  * @brief  Get Element from the Stack
  * @param  PS Pointer to the Stack.
  * @param  PDATA pointer to the variable that will store the returned value
  * @retval Status if the function execution(Pop_Stack)
  */
void* Pop_Stack(STACK* stack_obj, Stack_Status_t* ret_status_t);


/**
 * \brief  (StackTop) retrieves the data from the top of the
            stack without changing the stack
 * \param  (STACK) pointer to the allocated stack in the heap
 * \param  (Stack_Status_t) status returned while performed this operation
 * \return (void) user data if successful, NULL if underflow
 */
void* StackTop(STACK* stack_obj, Stack_Status_t* ret_status_t);



/**
  * @brief  Get the size of the Stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(StackSize)
  */
Stack_Status_t StackSize(STACK* stack_obj, uint32_t* stack_size);




#endif //_STACK_H


