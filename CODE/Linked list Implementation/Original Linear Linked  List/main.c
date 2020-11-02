#include <stdio.h>
#include <stdlib.h>
#include "list.h"


LIST l;
uint32_t data;
uint32_t Num_node;
uint8_t inDex;
int main()
{
    uint32_t *pdata = &data;
    CreateList(&l);
    Num_node = ListSize(&l);
    printf("\n\nThe size of list is %d \n",Num_node);
    printALL(&l);

    AddToFirst(&l,6);
    AddToFirst(&l,30);
    AddToFirst(&l,400);
    printALL(&l);
    DELET_FRIST(&l,pdata);
    printALL(&l);
    AddToFirst(&l,60);
    AddToFirst(&l,45);
    AddToFirst(&l,47);
    AddToFirst(&l,88);
    AddToEnd(&l,10);
    AddToEnd(&l,20);
    AddToEnd(&l,90);
    AddToEnd(&l,77);
    AddToEnd(&l,66);

    printALL(&l);
    insertbyindex(&l,11,100);
    DELET_End(&l,pdata);
    printALL(&l);
    DELET_End(&l,pdata);
    inDex = searchforindex(&l,45);
    printf("\n\nThe index of data is %d \n",inDex);
    printALL(&l);

    AddToFirst(&l,60);
    AddToFirst(&l,45);
    AddToFirst(&l,47);
    AddToFirst(&l,88);

    printALL(&l);
    Num_node = ListSize(&l);
    printf("The size of list is %d \n",Num_node);


    AddToEnd(&l,10);
    AddToEnd(&l,20);
    AddToEnd(&l,90);
    AddToEnd(&l,77);
    AddToEnd(&l,66);

    printALL(&l);

}
