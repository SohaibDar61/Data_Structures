#ifndef _STACK_H
#define _STACK_H

#include "STACK_Type.h"
#define MAX_STACK 10

typedef enum status_stack{
    STACK_NOT_FULL,
    STACK_FULL,
    STACK_Empty,
    DONE
}STATUS_STACK;

typedef enum return_status{
    R_NOK,
    R_OK
}return_status_t;

typedef struct Stack{
  uint32_t entry[MAX_STACK];
  sint16_t Top;
  uint32_t Size;
}STACK;


STATUS_STACK CreateStack(STACK *PS);
STATUS_STACK ClearStack(STACK *PS);
STATUS_STACK StackTop(STACK *PS, uint32_t *Pdata);
STATUS_STACK Push_Stack(STACK *PS, uint32_t data);
STATUS_STACK Pop_Stack(STACK *PS, uint32_t *PDATA);
STATUS_STACK Display_Stack(STACK *PS);
STATUS_STACK StackFull(STACK *PS);
STATUS_STACK StackEmpty(STACK *PS);
STATUS_STACK StackSize(STACK *PS);

#endif //_STACK_H
