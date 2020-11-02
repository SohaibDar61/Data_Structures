/*
 ============================================================================
 Name        : main_stack_list.c
 Author      : Sohaib Reda Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Data_structure_Implement a stack using singly linked list
 Date        : 13 / 1 / 2019
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"
/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */

STACK S;
uint32_t *pdata;
uint32_t  data;
int main()
{
    pdata = &data;
    CreateStack(&S);
    /* ========================================================================== */
    /*                               Application                                  */
    /* ========================================================================== */
    //==============================//
    Push(&S,10);
    Push(&S,20);
    Push(&S,90);
    Push(&S,77);
    Push(&S,66);
    printALL(&S);
    Pop(&S,pdata);
    printALL(&S);
    Push(&S,10);
    Push(&S,20);
    Push(&S,90);
    Push(&S,77);
    Push(&S,66);
    printALL(&S);

    return 0;
}
