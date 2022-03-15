#include <stdio.h>
#include "STACK.h"



/**
 * \brief Create Stack(initialize stack pointer)
 * \param PS pointer to the Stack
 * \return Status of initialization process
 */
extern return_status_t CreateStack(STACK_DS_t *PS)
{
    return_status_t ret = R_NOK;
    if(PS == NULL)
    {
        ret = R_NOK;
    }
    else
    {
        PS->Top  = -1;
        PS->Size = ZERO;
        ret = R_OK;
    }
    return ret;
}


/**
  * @brief  Add Element to the Stack
  * @param  PS Pointer to the Stack.
  * @param  The Data is a Value to be added
  * @retval Status if the function execution
  */
return_status_t Push_Stack(STACK_DS_t *PS, uint32_t data)
{
    return_status_t ret = R_NOK;
    if(StackFull(PS) == STACK_FULL || (PS == NULL))
    {
#ifdef STACK_DEBUG
        printf("ERROR !! Stack is FULL, can't Push [%i]\n",data);
#endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        PS->Top ++;
        PS->entry[PS->Top] = data;
#ifdef STACK_DEBUG
        printf("Data [%i] is Pushed in Stack\n",data);
#endif // STACK_DEBUG
        PS->Size ++;
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief  Get Element from the Stack
  * @param  PS Pointer to the Stack.
  * @param  PDATA pointer to the variable that will store the returned value
  * @retval Status if the function execution(Pop_Stack)
  */
return_status_t Pop_Stack(STACK_DS_t *PS, uint32_t *PDATA)
{
    return_status_t ret = R_NOK;
    if((StackEmpty(PS) == STACK_Empty || PS == NULL)){
         #ifdef STACK_DEBUG
         printf("\nERROR !! can't POP from Stack\n");
         #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        *PDATA = PS->entry[PS->Top];
        #ifdef STACK_DEBUG
        printf("\nData [%i] is POPED from Stack\n",*PDATA);
        #endif // STACK_DEBUG
        PS->Top--;
        PS->Size--;
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief  Get the Top from the Stack
  * @param  PS Pointer to the Stack.
  * @param  Pdata pointer to the variable that will store the returned value
  * @retval Status if the function execution
  **/
return_status_t StackTop(STACK_DS_t *PS, uint32_t *Pdata)
{
    return_status_t ret = R_NOK;
    if(StackEmpty(PS) == STACK_Empty || (PS == NULL) || (Pdata == NULL))
    {
        #ifdef STACK_DEBUG
         printf("\nERROR !! Stack is Empty\n");
         #endif // STACK_DEBUG
        ret = R_NOK;
    }
    else
    {
        *Pdata = PS->entry[PS->Top];
         #ifdef STACK_DEBUG
         printf("StackTop = %i\n",*Pdata);
         #endif // STACK_DEBUG
         ret = R_OK;
    }
    return ret;
}


/**
  * @brief  Check if the Stack is Full or Not
  * @param  PS Pointer to the Stack.
  * @retval Status of stack if return is full or not
  */
STATUS_STACK_t StackFull(STACK_DS_t *PS)
{
    if(PS->Top == MAX_STACK - 1)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_Not_Full;
    }
}

/**
  * @brief  Check if the Stack is Empty or Not
  * @param  PS Pointer to the Stack.
  * @retval Status of stack if return is empty or not
  */
STATUS_STACK_t StackEmpty(STACK_DS_t *PS)
{

    if(PS->Top ==  - 1)
    {
        return STACK_Empty;
    }
    else
    {
        return STACK_Not_Full;
    }
}

/**
  * @brief  Get the size of the Stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(StackSize)
  */
return_status_t StackSize(STACK_DS_t *PS)
{
    return_status_t ret = R_NOK;
    if(PS == NULL)
    {
        ret = R_NOK;
    }
    else
    {
        printf("The StackSize = %i\n",PS->Size);
        ret = R_OK;
    }
    return ret;
}

/**
  * @brief  Clear The Top stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(ClearStack)
  */
return_status_t ClearStack(STACK_DS_t *PS)
{
    PS->Top  = -1;
    PS->Size = 0;
    return R_OK;
}


/**
  * @brief  Display the elements of stack
  * @param  PS Pointer to the Stack.
  * @retval Status if the function execution(Display_Stack)
  */
return_status_t Display_Stack(STACK_DS_t *PS)
{
    return_status_t ret = R_NOK;
    static sint16_t Counter;
    if(StackEmpty(PS)== STACK_Empty || PS == NULL)
    {
        ret = R_NOK;
    }
    else
    {
        printf("Stack Data : ");
        for(Counter=PS->Top; Counter>=ZERO; Counter--)
        {
            printf("%d\t",PS->entry[Counter]);
        }
        printf("\n\n");
        ret = R_OK;
    }
    return ret;
}

