/*
 ===========================================================
===================
 PROGRAM : list.c
 Author  :  Sohaib Reda Dar
 Date    :  13 / 1 / 2019
 Version : 1.0
 ===========================================================
===================
*/
#include "List.h"
//===========================================================================//
//==================static function prototype================================//
//===========================================================================//
static uint32_t ListEmpty(LIST *HeadList);
static uint32_t ListEmpty(LIST *HeadList);
//===========================================================================//

/**
 * \brief check if list is full or not
 * \param (HeadList) pointer of struct node (LIST)
 * \return (uint32_t) return value
 */
static uint32_t ListFull(LIST *HeadList)
{
    return 0;
}

/**
 * \brief check if list is Empty or not
 * \param (HeadList) pointer of struct node (LIST)
 * \return (uint32_t) return value
 */
static uint32_t ListEmpty(LIST *HeadList)
{
    return (!HeadList->size);
}


//==================================================================================================//
//==================================================================================================//
/**
 * \brief Create Node of linked list
 * \param (HeadList) pointer of struct node (LIST)
 * \return (STATUS_LIST) status if the function execution
 */
STATUS_LIST CreateList(LIST *HeadList)
{
    HeadList->head = nullptr;
    HeadList->size = ZERO;
    return DONE;
}

//==============================================================//


/**
 * \brief Search in list by data for getting the index
 * \param (HeadList) pointer of struct node (LIST)
 * \param (data) int number that searching for getting its index
 * \return (uint32_t) return value
 */
uint32_t Search_For_Index(LIST *HeadList, uint32_t data)
{
    uint32_t index;
    NODE *ptr = HeadList->head;
    if(HeadList->head == nullptr)
        return Empty_List;
    else
    {
        for(index=0; ptr !=NULL ; index++)
        {
            if(ptr->entry == data)
                return index;
            else
                ptr = ptr->next;
        }
    }
    return index;
}

//==============================================================//


/**
 * \brief  insert a new node after specified node
 * \param  (HeadList) pointer of struct node (LIST)
 * \param  (data) int number that searching for getting its index
 * \param  (prevdata) int number that will insert a new node after it
 * \return (STATUS_LIST) status if the function execution
 */
STATUS_LIST Insert_After(LIST *HeadList,uint32_t prevdata,uint32_t data)
{
    uint32_t index = Search_For_Index(HeadList,prevdata);
    Insert_By_Index(HeadList,index+1,data);
    return DONE;
}

//==============================================================//


/**
 * \brief insert a new node before specified node
 * \param (HeadList) pointer of struct node (LIST)
 * \param (data) int number that insert by a specified a the next node
 * \param (Nextdata) int number that insert a new node before it
 * \return (STATUS_LIST) status if the function execution
 */
STATUS_LIST Insert_Before(LIST *HeadList,uint32_t Nextdata,uint32_t data)
{
    uint32_t index = Search_For_Index(HeadList,Nextdata);
    Insert_By_Index(HeadList,index,data);
    return DONE;
}
//==============================================================//


/**
 * \brief Insert a new node in list by specified index
 * \param (HeadList) pointer of struct node (LIST)
 * \param (data) int number that insert by its index
 * \param (index) int number that insert a new node in a specified place by a specified index
 * \return (STATUS_LIST) status if the function execution
 */
STATUS_LIST Insert_By_Index(LIST *HeadList,uint32_t index,uint32_t data)
{
    char_t i;
    NODE *current;
    NODE *ptr =(NODE*)malloc(sizeof(NODE));
    if(ptr == NULL)
        return NO_SPACE;
    else
    {
        ptr->entry = data;
        current = HeadList->head;
        if(index == 0)
        {
            ptr->next =HeadList->head;
            HeadList->head =ptr;
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
        HeadList->size++;
        return DONE;
    }
}

//==============================================================//

/**
 * \brief  Delete node from End of list
 * \param (HeadList) pointer of struct node (LIST)
 * \param (Pdata) pointer to the variable that will store the returned value
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST DELET_End(LIST *HeadList, uint32_t *pdata)
{
    NODE *ptr_help;
    NODE *D_node;
    if(HeadList->head == nullptr)
        return Empty_List;
    else
    {
        if(HeadList->size == ONE)
        {
            *pdata = HeadList->head->entry;
            free(HeadList->head);
            HeadList->head = nullptr;
        }
        else
        {
            ptr_help = HeadList->head;
            D_node = HeadList->head;
            while(D_node->next != nullptr)
            {
                ptr_help = D_node;
                D_node = D_node->next;
            }
            *pdata = ptr_help->entry;
            ptr_help->next = nullptr;
            free(D_node);
        }
        HeadList->size --;
        return DONE;
    }
}

//==============================================================//


/**
 * \brief  Delete node from first of list
 * \param (HeadList) pointer of struct node (LIST)
 * \param (Pdata) pointer to the variable that will store the returned value
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST DELET_FRIST(LIST *HeadList, uint32_t *pdata)
{
    NODE *ptr_help ;
    if(HeadList->head == nullptr)
        return Empty_List;
    else
    {
        if(HeadList->size == ONE)
        {
            *pdata =HeadList->head->entry;
            free(HeadList->head);
            HeadList->head =NULL;
        }
        else
        {
            ptr_help = HeadList->head;
            HeadList->head = HeadList->head->next;
            *pdata= ptr_help->entry;
            free(ptr_help);
        }
        HeadList->size --;
        return DONE;
    }
}

//==============================================================//

/**
 * \brief inset node to first of list
 * \param (HeadList) pointer of struct node (LIST)
 * \param (data) int number that addding it to list start
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST Insert_To_FIRST(LIST *HeadList,uint32_t data)
{
    //New named node (ptr) declared with size of node declared before
    NODE *ptr_NewNOde =(NODE *)malloc(sizeof(NODE));
    if(ptr_NewNOde == nullptr)
        return NO_SPACE;
    else
    {
        ptr_NewNOde->entry = data;
        if(HeadList->head == nullptr)
        {
            HeadList->head = ptr_NewNOde;
            ptr_NewNOde->next = nullptr;
        }
        else
        {
            ptr_NewNOde->next = HeadList->head;
            HeadList->head =ptr_NewNOde;
        }
        HeadList->size ++;
        return DONE;
    }
}

//==============================================================//


/**
 * \brief inset node to end of list
 * \param (HeadList) pointer of struct node (LIST)
 * \param (data) int number that addding it to list end
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST Insert_To_End(LIST *HeadList,uint32_t data)
{
    NODE *Ptr_help;
    NODE *ptr_NewNOde = (NODE*)malloc(sizeof(NODE));
    if(ptr_NewNOde == nullptr)
        return NO_SPACE;
    else
    {
        ptr_NewNOde->entry = data;
        ptr_NewNOde->next = nullptr;
        if(HeadList->head == nullptr)
        {
            HeadList->head = ptr_NewNOde;
        }
        else
        {
            Ptr_help = HeadList->head;
            while(Ptr_help->next != nullptr)
            {
                Ptr_help = Ptr_help->next;
            }
            Ptr_help->next = ptr_NewNOde;
        }
        HeadList->size ++;
        return DONE;
    }
}

//==============================================================//


/**
 * \brief  Print all data of nodes
 * \param  (HeadList) pointer of struct node (LIST)
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST PrintList(LIST *HeadList)
{
    if(HeadList == NULL)
        return Empty_List;
    else
    {
        NODE *current = HeadList->head;
        while(current != nullptr)
        {
            printf("%d  ",current->entry);
            current = current->next;
        }
        printf("\n");
        return DONE;
    }
}
//==============================================================//


/**
 * \brief  reverse the linked list nodes
 * \param  (HeadList) double pointer of struct node (LIST)
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST Reverse_List_1(LIST *HeadList)
{
    NODE *prev = NULL;
    NODE *next = NULL;
    NODE *current = HeadList->head;
    if(HeadList->head == NULL)
        return Empty_List;

    else
    {

        if(HeadList->size == ONE)
            return DONE;
        else
        {
            while(current != NULL)
            {
                // Store next
                next = current->next;

                // Reverse current node's pointer
                current->next = prev;

                // Move pointers one position ahead.
                prev = current;
                current = next;
            }
            HeadList->head = prev;
            return DONE;
        }
    }
}

//==============================================================//

/**
 * \brief  reverse the linked list nodes
 * \param  (HeadList) double pointer of struct node (LIST)
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST Reverse_List_2(LIST *HeadList)
{
   NODE *prevNode = NULL;
   NODE *curNode  = NULL;

    if(HeadList->head != NULL)
    {
        prevNode = HeadList->head;

        curNode  = HeadList->head->next;

        HeadList->head = HeadList->head->next;

        // Make first node as last node
        prevNode->next = NULL;

        while(HeadList->head != NULL)
        {
            HeadList->head = HeadList->head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = HeadList->head;
        }

        // Make last node as head
        HeadList->head = prevNode;

        return DONE;
    }
    else return Empty_List;
}

//===========================================================//

/**
 * \brief  Swap two nodes in a linked list
 * \param  (HeadList) double pointer of struct node (LIST)
 * \param  (pos1) int number of the first location of node
 * \param  (pos2) int number of the second location of node
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST Swap_Nodes(LIST *HeadList, uint32_t pos1, uint32_t pos2)
{
    NODE *node1, *node2, *prev1, *prev2, *temp;
    sint32_t i;

      // Get the far position among both
    const uint32_t maxPos = (pos1 > pos2) ? pos1 : pos2;

    // Get total nodes in the list
    const uint32_t totalNodes = ListSize(HeadList);

    if(HeadList->head == NULL)
        return Empty_List;
    // Validate swap positions
    if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
    {
        return WRONG_INDEX;
    }

    // If both positions are same then no swapping required
    if (pos1 == pos2)
    {
        return DONE;
    }

    // Identify both nodes to swap
    i = 1;
    temp  = HeadList->head;
    prev1 = NULL;
    prev2 = NULL;

    // Find nodes to swap
    while (temp != NULL && (i <= maxPos))
    {
        if (i == pos1 - 1)
            prev1 = temp;
        if (i == pos1)
            node1 = temp;

        if (i == pos2 - 1)
            prev2 = temp;
        if (i == pos2)
            node2 = temp;

        temp = temp->next;
        i++;
    }

    // If both nodes to swap are found.
    if (node1 != NULL && node2 != NULL)
    {
        // Link previous of node1 with node2
        if (prev1 != NULL)
            prev1->next = node2;

        // Link previous of node2 with node1
        if (prev2 != NULL)
            prev2->next = node1;

        // Swap node1 and node2 by swapping their
        // next node links
        temp        = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Make sure to swap head node when swapping
        // first element.
        if (prev1 == NULL)
            HeadList->head = node2;
        else if (prev2 == NULL)
            HeadList->head = node1;
    }
    return DONE;
}


//==============================================================//

/**
 * \brief  sort the linked list nodes
 * \param  (HeadList) double pointer of struct node (LIST)
 * \return (STATUS_LIST) Status if the function execution
 */
STATUS_LIST SORT_LIST(LIST *HeadList)
{
    NODE *current = HeadList->head;
    NODE *index = NULL;
    uint32_t temp;
    if(HeadList->head == NULL)
        return Empty_List;
    else{

         while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

                while(index != NULL) {
                    //If current node's data is greater than index's node data, swap the data between them
                    if(current->entry > index->entry) {
                        temp = current->entry;
                        current->entry = index->entry;
                        index->entry = temp;
                    }
                    index = index->next;
                }
                current = current->next;
          }
          return DONE;
    }
}


//==============================================================//
/**
 * \brief  count the number of nodes in list
 * \param  (HeadList) pointer of struct node (LIST)
 * \return (uint32_t) char return value
 */
uint32_t ListSize(LIST *HeadList)
{
    return (HeadList->size);
}

