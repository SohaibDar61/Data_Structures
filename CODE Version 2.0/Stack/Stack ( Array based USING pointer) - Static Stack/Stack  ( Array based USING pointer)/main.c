/*
 ============================================================================
 Name        : main_stack.c
 Author      : Sohaib Dar
 Version     : version 2.0
 Copyright   : For free
 Description : Data_structure_Array Based STACK Implementation [static Stack]
 Date        : 13 / 1 / 2021
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"


STACK_DS_t myStack1;
uint32_t data;


int main()
{
    return_status_t ret = R_NOK;
    ret = CreateStack(&myStack1);
    if(ret == R_NOK){
        printf("the Stack is failed to be initialized\n\n");
    }
    else{
            Push_Stack(&myStack1,10);
            Push_Stack(&myStack1,20);
            Push_Stack(&myStack1,30);
            Push_Stack(&myStack1,40);
            Push_Stack(&myStack1,50);
            Push_Stack(&myStack1,60);
            StackSize(&myStack1);
            Display_Stack(&myStack1);
            Pop_Stack(&myStack1,&data);
            Pop_Stack(&myStack1,&data);
            Push_Stack(&myStack1,400);
            Push_Stack(&myStack1,500);
            Push_Stack(&myStack1,600);
            Display_Stack(&myStack1);
            StackSize(&myStack1);
            ClearStack(&myStack1);
            Pop_Stack(&myStack1,&data);

    }
    StackTop(&myStack1,&data);
    //======================================================//
    return 0;
}
