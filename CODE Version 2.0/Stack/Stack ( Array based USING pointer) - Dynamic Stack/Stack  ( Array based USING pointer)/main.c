/*
 ============================================================================
 Name        : main_stack.c
 Author      : Sohaib Dar
 Version     : version 2.0
 Copyright   : For free
 Description : Data_structure_Array Based STACK Implementation [Dynamic Stack]
 Date        : 13 / 1 / 2021
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"


STACK *stack1 = NULL;;
uint32_t MaxSize_Stack;
uint32_t Stack1_Count;
void *Stack_Top = NULL;
void *stack_return_data= NULL;
uint32_t valu_1 =12;
float32_t valu_2 =55.22;
uint8_t valu_3 ='S';


int main()
{
    Stack_Status_t return_status = STACK_NOK;
    printf("Enter MAx Size of Stack : ");
    scanf("%i",&MaxSize_Stack);
    stack1 = CreateStack(MaxSize_Stack,&return_status);
    if(stack1)
    {
        printf("Stack 1 created \n");
    }
    return_status = Push_Stack(stack1,&valu_1);
    return_status = Push_Stack(stack1,&valu_2);
    return_status = Push_Stack(stack1,&valu_3);

    return_status = StackSize(stack1, &Stack1_Count);
    printf("return_status = %i \n", return_status);
    printf("Stack1_Count = %i \n", Stack1_Count);


    stack_return_data = Pop_Stack(stack1,&return_status);
    printf("return_status = %i \n", return_status);
    printf("stack_return_data = %c \n", *(uint8_t*)stack_return_data);

    stack_return_data = Pop_Stack(stack1,&return_status);
    printf("return_status = %i \n", return_status);
    printf("stack_return_data = %f \n", *(float32_t*)stack_return_data);

    stack_return_data = Pop_Stack(stack1,&return_status);
    printf("return_status = %i \n", return_status);
    printf("stack_return_data = %i \n", *(uint32_t*)stack_return_data);

    return_status = StackSize(stack1, &Stack1_Count);
    printf("return_status = %i \n", return_status);
    printf("Stack1_Count = %i \n", Stack1_Count);

    stack_return_data = Pop_Stack(stack1,&return_status);
    printf("return_status = %i \n", return_status);

    stack1 = DestoryStack(stack1, &return_status);
    if(!stack1){
        printf("Stack 1 destroyed \n");
    }
    //======================================================//
    return 0;
}
