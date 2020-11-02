/*
 ===========================================================
===================
 PROGRAM : Linked list implementation
 Author  :  Sohaib Reda Dar
 Date    :  13 / 1 / 2019
 Version : 1.0
 Description :
 ===========================================================
===================
*/
#include "list.h"


//===========================================================================

uint8_t searchforindex(LIST *pl, int data)
{
    uint8_t i;
    NODE *ptr= pl->head;
    if(pl->head == nullptr)
        return 0;
    else
    {
        for(i=0; ptr !=NULL ; i++)
        {
            if(ptr->entry == data)
                return i;
            else
                ptr = ptr->next;
        }
    }
    return i;
}


STATUS_LIST insert_after(LIST *pl,int prevdata,int data)
{
    int index =searchforindex(pl,prevdata);
    insertbyindex(pl,index+1,data);
    return DONE;

}

STATUS_LIST insert_Before(LIST *pl,int Nextdata,int data)
{
    int index =searchforindex(pl,Nextdata);
    insertbyindex(pl,index,data);
    return DONE;
}



STATUS_LIST insertbyindex(LIST *pl,int index,int data)
{
    uint8_t i;
    NODE *current, *ptr =(NODE*)malloc(sizeof(NODE));
    if(ptr == nullptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        current = pl->head;
        if(index == 0)
        {
            ptr->next =pl->head;
            pl->head =ptr;
        }
        else
        {
            for(i=0; i<index - 1; i++)
            {
                if(current == nullptr)
                {
                    return WRONG_INDEX;
                }
                current = current->next;
            }
            ptr->next =current->next;
            current->next = ptr;
        }
        pl->size++;
        return DONE;
    }
}

STATUS_LIST DELET_End(LIST *pl, uint32_t *pdata)
{
    NODE *ptr,*D_node;
    if(pl->head == nullptr)
        return Empty_List;
    else
    {
        if(pl->size == ONE)
        {
            *pdata = pl->head->entry;
            free(pl->head);
            pl->head = nullptr;
        }
        else
        {
            ptr = pl->head;
            D_node = pl->head;
            while(D_node->next != nullptr)
            {
                ptr = D_node;
                D_node = D_node->next;
            }
            *pdata = ptr->entry;
            ptr->next = nullptr;
            free(D_node);
        }
        pl->size --;
        return DONE;
    }
}

STATUS_LIST DELET_FRIST(LIST *pl, uint32_t *pdata)
{
    NODE *ptr ;
    if(pl->head == nullptr)
        return Empty_List;
    else
    {
        if(pl->size == 1)
        {
            *pdata =pl->head->entry;
            free(pl->head);
            pl->head =NULL;
        }
        else
        {
            ptr = pl->head;
            pl->head = pl->head->next;
            *pdata= ptr->entry;
            free(ptr);
        }
        pl->size --;
        return DONE;
    }
}


STATUS_LIST AddToFirst(LIST *pl,int data)
{
    NODE *ptr =(NODE *)malloc(sizeof(NODE)); //New named node (ptr) declared with size of node declared before
    if(ptr == nullptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        if(pl->head == nullptr)
        {
            pl->head = ptr;
            ptr->next = nullptr;
        }
        else
        {
            ptr->next = pl->head;
            pl->head =ptr;
        }
        pl->size ++;
        return DONE;
    }
}


STATUS_LIST AddToEnd(LIST *pl,int data)
{
    NODE *P;
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr == nullptr)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        ptr->next = nullptr;
        if(pl->head == nullptr)
        {
            pl->head = ptr;
        }
        else
        {
            P = pl->head;
            while(P->next != nullptr)
            {
                P = P->next;
            }
            P->next = ptr;
        }
        pl->size ++;
        return DONE;
    }
}


STATUS_LIST printALL(LIST *pl)
{
    NODE *current = pl->head;
    while(current != nullptr)
    {
        printf("%d  ",current->entry);
        current = current->next;
    }
    printf("\n");
    return DONE;
}

STATUS_LIST CreateList(LIST *pl)
{
    pl->head = nullptr;
    pl->size = ZERO;
    return DONE;
}

uint32_t ListSize(LIST *pl)
{
    return (pl->size);
}

uint32_t ListFull(LIST *pl)
{
    return 0;
}

uint32_t ListEmpty(LIST *pl)
{
    return (!pl->size);
}
