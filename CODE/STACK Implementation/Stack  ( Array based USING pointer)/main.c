/*
 ============================================================================
 Name        : main_stack.c
 Author      : Sohaib Reda Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Data_structure_Array Based STACK Implementation
 Date        : 13 / 1 / 2019
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"

/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */

STACK S;
uint32_t data;
uint32_t *Pdata =&data;
uint32_t i,temp;
int main()
{
    CreateStack(&S);
    Push_Stack(&S,10);
    Push_Stack(&S,20);
    Push_Stack(&S,30);
    Push_Stack(&S,40);
    Push_Stack(&S,50);
    Pop_Stack(&S,&data);
    //==============================//
    if(StackFull(&S))
    {
        printf(" \nThe Stack is FULL \n");
    }
    else if(StackEmpty(&S))
    {
        printf(" \nThe Stack is Empty \n");
    }
    else
    {
        printf(" \nThe Stacksize is  %d\n",StackSize(&S));
    }

    printf("\n===============================");


    //======================================================//

    temp =StackSize(&S);
    //temp =PS->top;
    for (i=0; i<temp; i++)
    {
        Pop_Stack(&S,Pdata);
        printf(" \nThe Element that Poped is  %d\n\n",*Pdata);
        printf(" \nThe SIZE is  %d\n\n",StackSize(&S));
        printf("\n\n==========================\n ");
    }
    //======================================================//
    return 0;
}
