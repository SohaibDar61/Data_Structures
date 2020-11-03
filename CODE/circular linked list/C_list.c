#include <stdio.h>
#include <stdlib.h>
#include "C_list.h"

//================================================================================================//
//                               Applications                                                                  //
//================================================================================================//

//get the first node from the list
STATUS_LIST Delete_front_Node(LIST *pl)
{
    NODE *p = pl->head;
    if(pl->head == nullptr)
        return NO_SPACE;
    else
    {
        //check if the list contains only one element
        if(pl->head == pl->head->next)
        {
            free(pl->head);
        }
        else
        {
            while(pl->tail->next !=pl->head)
            {
                pl->tail = pl->tail->next;
            }
            pl->head = p->next;
            pl->tail->next = pl->head;
            free(p);
        }
        pl->size --;
        return DONE;
    }
}

//get the last node from the list
STATUS_LIST Delete_Last_Node(LIST *pl)
{
    NODE *p = pl->head;
    pl->tail = pl->head;
    //check if the list is Empty
    if(pl->head == nullptr)
        return NO_SPACE;
    else
    {
        //check if the list contains only one element
        if(pl->size == ONE)
        {
            free(pl->head);
            pl->head = nullptr;
        }
        // the list contains more than element
        else
        {
            while (pl->tail->next != pl->head)
            {
                p = pl->tail;
                pl->tail = pl->tail->next;
            }
            free(pl->tail);
            pl->tail = p;
            pl->tail->next = pl->head;
        }
        pl->size --;
        return DONE;
    }
}

// insert item at the end of the list
STATUS_LIST INSERT_At_End(LIST *pl, uint32_t data)
{
    pl->tail = pl->head;
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    if(!ptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        ptr->next = ptr;
        while (pl->tail->next != pl->head)
            pl->tail = pl->tail->next;

      //check if the list contains only one element
        if(pl->head == nullptr)
            pl->head = ptr;
        else
        {
            ptr->next = pl->tail->next;
            pl->tail->next = ptr;
            pl->tail = ptr;
        }
        pl->size ++;
        return DONE;
    }
}

//INITIALIZE list
STATUS_LIST createList(LIST *pl)
{
    pl->head = nullptr;
    pl->tail = nullptr;
    pl->size =ZERO;
    return DONE;
}

// Insert at the beginning of the list
STATUS_LIST INSERT_AT_FIRST(LIST *pl, uint32_t data)
{
    NODE *current = pl->head;
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    if(!ptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        ptr->next = ptr;

        //check if the list contains only one element
        if(current == nullptr)
        {
            pl->head = ptr;

        }
        else
        {
            while (current->next != pl->head)
                current = current->next;

            ptr->next = pl->head;
            current->next = ptr;
            pl->head = ptr;
        }
        pl->size ++;
        return DONE;
    }
}

// display list using iteration
STATUS_LIST printfall(LIST *pl)
{
    NODE *p = pl->head;
    do
    {
        printf("%d ",p->entry);
        p = p->next;

    }
    while(p != pl->head);
    printf("\n");
    return DONE;
}

//return the number of nodes
uint32_t SizeList(LIST *pl)
{
    return pl->size;
}
