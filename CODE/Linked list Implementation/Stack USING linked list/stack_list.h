#ifndef _STACK_H
#define _STACK_H



#include <stdio.h>
#include <stdlib.h>

#define nullptr (void*)0
#define ZERO 0
#define ONE 1
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum {
    NO_SPACE=0,
    WRONG_INDEX=-1,
    Empty_Stack,
    DONE
}STATUS_STACK;

typedef struct node{
    uint32_t entry;
    struct node *next;
}NODE;

typedef struct stack{
    NODE *top;
    uint32_t size;
}STACK;


STATUS_STACK CreateStack(STACK *ps);
STATUS_STACK printALL(STACK *ps);
uint32_t StackSize(STACK *ps);
uint32_t StackFull(STACK *ps);
uint32_t StackEmpty(STACK *ps);
STATUS_STACK Push(STACK *ps,int data);
STATUS_STACK Pop(STACK *ps, uint32_t *pdata);


#endif // _STACK_H
