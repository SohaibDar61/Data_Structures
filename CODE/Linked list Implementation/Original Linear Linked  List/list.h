//#include <stdio.h>
//#include <stdlib.h>


#ifndef _LIST_H
#define _LIST_H

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


STATUS_LIST CreateList(LIST *pl);
uint32_t ListSize(LIST *pl);
uint32_t ListFull(LIST *pl);
uint32_t ListEmpty(LIST *pl);
STATUS_LIST AddToFirst(LIST *pl,int data);
STATUS_LIST AddToEnd(LIST *pl,int data);
STATUS_LIST printALL(LIST *pl);
STATUS_LIST insertbyindex(LIST *pl,int index,int data);
uint8_t searchforindex(LIST *pl, int data);
STATUS_LIST insert_after(LIST *pl,int prevdata,int data);
STATUS_LIST insert_Before(LIST *pl,int Nextdata,int data);

STATUS_LIST DELET_End(LIST *pl, uint32_t *pdata);
STATUS_LIST DELET_FRIST(LIST *pl, uint32_t *pdata);




#endif // _LIST_H
