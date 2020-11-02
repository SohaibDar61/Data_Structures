#include "stack_list.h"

/* ========================================================================== */
/*                               Application                                  */
/* ========================================================================== */
//============================================================================//

/**
  * @brief  Get the last Element from the Stack
  * @param  Ps Pointer to the Stack.
  * @param  PDATA pointer to the variable that will store the returned value
  * @retval Status if the function execution
  */
STATUS_STACK Pop(STACK *ps, uint32_t *pdata)
{
    NODE *ptr,*D_node;
    if(ps->top == nullptr)
        return Empty_Stack;
    else
    {
        if(ps->size == ONE)
        {
            *pdata = ps->top->entry;
            free(ps->top);
            ps->top = nullptr;
        }
        else
        {
            ptr = ps->top;
            D_node = ps->top;
            while(D_node->next != nullptr)
            {
                ptr = D_node;
                D_node = D_node->next;
            }
            *pdata = ptr->entry;
            ptr->next = nullptr;
            free(D_node);
        }
        ps->size --;
        return DONE;
    }
}



/**
  * @brief  Add Element to the end of the Stack
  * @param  Ps Pointer to the Stack.
  * @param  DATA pointer to the variable that will store the returned value
  * @retval Status if the function execution
  */
STATUS_STACK Push(STACK *ps,int data)
{
    NODE *P;
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr == nullptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        ptr->next = nullptr;
        if(ps->top == nullptr)
        {
            ps->top = ptr;
        }
        else
        {
            P = ps->top;
            while(P->next != nullptr)
            {
                P = P->next;
            }
            P->next = ptr;
        }
        ps->size ++;
        return DONE;
    }
}


//Display the elements of the stack
STATUS_STACK printALL(STACK *ps)
{
    NODE *current = ps->top;
    while(current != nullptr)
    {
        printf("%d  ",current->entry);
        current = current->next;
    }
    printf("\n");
    return DONE;
}


//Initialize the stack
STATUS_STACK CreateStack(STACK *ps)
{
    ps->top = nullptr;
    ps->size = ZERO;
    return DONE;
}


/**
  * @brief  Get the size of the Stack
  * @param  Ps Pointer to the Stack.
  * @retval Status if the function execution
  */
uint32_t StackSize(STACK *ps)
{
    return (ps->size);
}



/**
  * @brief  Check if the Stack is FULL or Not
  * @param  Ps Pointer to the Stack.
  * @retval return true if the function execution
  */
uint32_t StackFull(STACK *ps)
{
    return 0;
}


/**
  * @brief  Check if the Stack is Empty or Not
  * @param  Ps Pointer to the Stack.
  * @retval return true if the function execution
  */
uint32_t StackEmpty(STACK *ps)
{
    return (!ps->size);
}

