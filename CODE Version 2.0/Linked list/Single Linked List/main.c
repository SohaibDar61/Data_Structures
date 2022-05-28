/*
 ===========================================================
===================
 PROGRAM : Linked list implementation (Single List)
 Author  :  Sohaib Reda Dar
 Date    :  13 / 1 / 2019
 Version : 2.0
 Description : Linked list implementation
 ===========================================================
*/
#include <stdio.h>
#include "List.h"
#include "PlatForm_Types.h"

LIST list_obj;
uint32_t data;
uint32_t Num_node;
uint32_t inDex;


int main()
{
    uint32_t *pdata = &data;
    CreateList(&list_obj);
    Num_node = ListSize(&list_obj);
    printf("\n\nThe size of list is %d \n",Num_node);
    PrintList(&list_obj);

    Insert_To_FIRST(&list_obj,6);
    Insert_To_FIRST(&list_obj,30);
    Insert_To_FIRST(&list_obj,400);
    PrintList(&list_obj);
    DELET_FRIST(&list_obj,pdata);
    PrintList(&list_obj);
    Insert_To_FIRST(&list_obj,60);
    Insert_To_FIRST(&list_obj,45);
    Insert_To_FIRST(&list_obj,47);
    Insert_To_FIRST(&list_obj,88);
    Insert_To_End(&list_obj,10);
    Insert_To_End(&list_obj,20);
    Insert_To_End(&list_obj,90);
    Insert_To_End(&list_obj,77);
    Insert_To_End(&list_obj,66);

    PrintList(&list_obj);
    Insert_By_Index(&list_obj,7,100);
    DELET_End(&list_obj,pdata);
    PrintList(&list_obj);
    DELET_End(&list_obj,pdata);
    inDex = Search_For_Index(&list_obj,45);
    printf("\n\nThe index of data is %d\nthe location of data is %d\n\n",inDex, inDex+1);
    PrintList(&list_obj);

    Insert_To_FIRST(&list_obj,60);
    Insert_To_FIRST(&list_obj,45);
    Insert_To_FIRST(&list_obj,47);
    Insert_To_FIRST(&list_obj,88);

    PrintList(&list_obj);
    Num_node = ListSize(&list_obj);
    printf("The size of list is %d \n",Num_node);


    Insert_To_End(&list_obj,10);
    Insert_To_End(&list_obj,20);
    Insert_To_End(&list_obj,90);
    Insert_To_End(&list_obj,77);
    Insert_To_End(&list_obj,66);

    PrintList(&list_obj);
}
