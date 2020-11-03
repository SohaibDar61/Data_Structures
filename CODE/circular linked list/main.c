/*
 ============================================================================
 Name        : main.c
 Author      : Sohaib Reda Dar
 Version     : ver 1.0
 Copyright   : For free
 Description : Data_structure_Implement circular singly linked list
 Date        : 14 / 1 / 2019
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "C_list.h"
/* ========================================================================== */
/*                 Default declarations                        */
/* ========================================================================== */
/* None */

LIST l;
uint32_t data;
uint32_t num_node;
int main()
{
    createList(&l);
    /* ========================================================================== */
    /*                               Application                                  */
    /* ========================================================================== */
    //==============================//
    INSERT_AT_FIRST(&l,10);
    INSERT_AT_FIRST(&l,20);
    INSERT_AT_FIRST(&l,30);
    INSERT_At_End(&l,320);
    INSERT_At_End(&l,420);
    INSERT_At_End(&l,820);
    Delete_Last_Node(&l);
    INSERT_AT_FIRST(&l,10);
    INSERT_AT_FIRST(&l,20);
    INSERT_AT_FIRST(&l,30);
    Delete_Last_Node(&l);
    Delete_front_Node(&l);
    num_node =SizeList(&l);
    printf("\n%d",num_node);

    INSERT_At_End(&l,320);
    INSERT_AT_FIRST(&l,1000);
    INSERT_AT_FIRST(&l,2000);
    Delete_front_Node(&l);
    num_node =SizeList(&l);
    printf("\n%d\n",num_node);



    printfall(&l);
    return 0;
}
