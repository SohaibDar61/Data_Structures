#ifndef _STACK_H
#define _STACK_H

#include "STACK_Type.h"
#define MAX_STACK 10

typedef enum{
    STACK_NOT_FULL,
    STACK_FULL,
    STACK_Empty,
    DONE
}STATUS_STACK;

typedef struct Stack{
  int entry[MAX_STACK];
  int Top;
  int Size;
}STACK;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

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
