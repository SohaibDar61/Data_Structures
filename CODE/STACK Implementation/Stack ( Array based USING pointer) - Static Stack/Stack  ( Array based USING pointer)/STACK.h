#ifndef _STACK_H
#define _STACK_H

#include "Stack_Types.h"


#define MAX_STACK 5
#define STACK_DEBUG

typedef struct Stack{
  uint32_t entry[MAX_STACK];
  sint16_t Top;
  uint32_t Size;
}STACK_DS_t;


typedef enum return_status{
    R_NOK,
    R_OK
}return_status_t;


typedef enum status_stack{
    STACK_Empty,
    STACK_Not_Full,
    STACK_FULL,
    DONE
}STATUS_STACK_t;

//============================PROTOTYPE SECTION===============================================//

/**
 * \brief Create Stack(initialize stack pointer)
 * \param PS pointer to the Stack
 * \return Status of initialization process(CreateStack)
 */
return_status_t CreateStack(STACK_DS_t *PS);


/**
  * @brief  Add Element to the Stack
  * @param  PS Pointer to the Stack.
  * @param  The Data is a Value to be added
  * @retval Status if the function execution(Push_Stack)
  */
return_status_t Push_Stack(STACK_DS_t *PS, uint32_t data);



/**
  * @brief  Get Element from the Stack
  * @param  PS Pointer to the Stack.
  * @param  PDATA pointer to the variable that will store the returned value
  * @retval Status if the function execution(Pop_Stack)
  */
return_status_t Pop_Stack(STACK_DS_t *PS, uint32_t *PDATA);


/**
  * @brief  Get the size of the Stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(StackSize)
  */
return_status_t StackSize(STACK_DS_t *PS);



/**
  * @brief  Clear The Top stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(ClearStack)
  */
return_status_t ClearStack(STACK_DS_t *PS);



/**
  * @brief  Display the elements of stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(Display_Stack)
  */
return_status_t Display_Stack(STACK_DS_t *PS);




/**
  * @brief  Get the Top from the Stack
  * @param  PS Pointer to the Stack.
  * @param  Pdata pointer to the variable that will store the returned value
  * @retval Status if the function execution(StackTop)
  **/
return_status_t StackTop(STACK_DS_t *PS, uint32_t *Pdata);



/**
  * @brief  Check if the Stack is Full or Not
  * @param  PS Pointer to the Stack.
  * @retval Status of stack if return Function(StackFull) is full or not
  */
STATUS_STACK_t StackFull(STACK_DS_t *PS);


/**
  * @brief  Check if the Stack is Empty or Not
  * @param  PS Pointer to the Stack.
  * @retval Status of stack if return Function(StackEmpty) is empty or not
  */
STATUS_STACK_t StackEmpty(STACK_DS_t *PS);

#endif //_STACK_H
