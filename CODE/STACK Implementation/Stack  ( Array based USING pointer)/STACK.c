#include <stdio.h>
#include "STACK.h"


//Initialize the Stack pointers
STATUS_STACK CreateStack(STACK *PS)
{
    PS->Top = -1;
    PS->Size =0;
    return DONE;
}

/**
  * @brief  Add Element to the Stack
  * @param  PS Pointer to the Stack.
  * @param  The Data is a Value to be added
  * @retval Status if the function execution
  */
STATUS_STACK Push_Stack(STACK *PS, uint32_t data)
{
    if(PS->Top == MAX_STACK -1)
        return STACK_FULL;
    else
    {
        PS->Top ++;
        PS->entry[PS->Top] = data;
        PS->Size ++;
        return DONE;
    }
}

/**
  * @brief  Get Element from the Stack
  * @param  PS Pointer to the Stack.
  * @param  PDATA pointer to the variable that will store the returned value
  * @retval Status if the function execution
  */

STATUS_STACK Pop_Stack(STACK *PS, uint32_t *PDATA)
{
    if((PS->Top == -1))
        return STACK_Empty;
    else
    {
        *PDATA = PS->entry[PS->Top];
        PS->Top --;
        PS->Size --;
        return DONE;
    }
}

/**
  * @brief  Get the Top from the Stack
  * @param  PS Pointer to the Stack.
  * @param  Pdata pointer to the variable that will store the returned value
  * @note   Same preconditions of Pop
  */
STATUS_STACK StackTop(STACK *PS,uint32_t *Pdata)
{
    *Pdata = PS->entry[PS->Top];
    return DONE;
}

/**
  * @brief  Check if the Stack is Full or Not
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution
  */
STATUS_STACK StackFull(STACK *PS)
{
    //return (PS->Top == MAX_STACK -1) ;
    return STACK_FULL;
}

/**
  * @brief  Check if the Stack is Empty or Not
  * @param  PS Pointer to the Stack.
  * @retval return true if the function execution
  */

STATUS_STACK StackEmpty(STACK *PS)
{
    //return (PS->Top == -1) ;
    return STACK_Empty;
}

/**
  * @brief  Get the size of the Stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution
  */
STATUS_STACK StackSize(STACK *PS)
{
    return PS->Size;

}
//Same preconditions of CreateStack
STATUS_STACK ClearStack(STACK *PS)
{
    PS->Top  = -1;
    PS->Size = 0;
    return DONE;
}

STATUS_STACK Display_Stack(STACK *PS)
{
    int i;
    if(StackEmpty(PS))
        return STACK_Empty;
    else
    {
        for(i=PS->Top; i>=0; i--)
        {
            printf("\n%d",PS->entry[i]);
        }
        return DONE;
    }
}
