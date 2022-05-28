
#ifndef _LIST_H
#define _LIST_H
/*----------------------------------------------------------------------------*/
/*----------------------Header_File and Library ------------------------------*/
/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "PlatForm_Types.h"


typedef enum {
    WRONG_INDEX=-1,
    NO_SPACE=0,
    Empty_List,
    DONE
}STATUS_LIST;

typedef struct node{
    uint32_t entry;
    struct node *next;
}NODE;

typedef struct list{
    NODE *head;
    uint32_t size;
}LIST;


/*----------------------------------------------------------------------------*/
/*-----------------------------------PROTOTYPES-------------------------------*/
/*----------------------------------------------------------------------------*/
STATUS_LIST CreateList(LIST *HeadList);
STATUS_LIST Insert_To_FIRST(LIST *HeadList,uint32_t data);
STATUS_LIST Insert_To_End(LIST *HeadList,uint32_t data);
STATUS_LIST Insert_After(LIST *HeadList,uint32_t prevdata,uint32_t data);
STATUS_LIST Insert_Before(LIST *HeadList,uint32_t Nextdata,uint32_t data);
STATUS_LIST Insert_By_Index(LIST *HeadList,uint32_t index,uint32_t data);
uint32_t Search_For_Index(LIST *HeadList, uint32_t data);
STATUS_LIST DELET_End(LIST *HeadList, uint32_t *pdata);
STATUS_LIST DELET_FRIST(LIST *HeadList, uint32_t *pdata);
STATUS_LIST PrintList(LIST *HeadList);
uint32_t ListSize(LIST *HeadList);
STATUS_LIST Reverse_List_1(LIST *HeadList);
STATUS_LIST Reverse_List_2(LIST *HeadList);
STATUS_LIST Swap_Nodes(LIST *HeadList, uint32_t pos1, uint32_t pos2);
STATUS_LIST SORT_LIST(LIST *HeadList);




#endif //_LIST_H