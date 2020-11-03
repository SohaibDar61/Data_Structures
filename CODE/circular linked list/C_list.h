#ifndef _LIST_H
#define _LIST_H

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
    NODE *tail;
    uint32_t size;
}LIST;


STATUS_LIST Delete_front_Node(LIST *pl);
STATUS_LIST Delete_Last_Node(LIST *pl);
STATUS_LIST INSERT_At_End(LIST *pl, uint32_t data);
STATUS_LIST INSERT_AT_FIRST(LIST *pl, uint32_t data);
STATUS_LIST createList(LIST *pl);
STATUS_LIST printfall(LIST *pl);
uint32_t SizeList(LIST *pl);

#endif // _LIST_H
