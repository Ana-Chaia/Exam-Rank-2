/* 
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------
Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.
It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
cmp takes two void* and returns 0 when both parameters are equal.
You have to use the ft_list.h file, which will contain:
$>cat ft_list.h
typedef struct    s_list
{
    struct  s_list *next;
    void           *data;
}                  t_list;
$>
 */

//To solve the problem of removing elements from a linked list that match a given condition, you need to define a function ft_list_remove_if. This function iterates over the list, checks each element against a reference data using a comparison function, and removes the element if it matches.

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) // This is a double pointer to the list's head. A double pointer is necessary because you might modify the head of the list itself (for example, if the first element needs to be removed);
{
    t_list *current = *begin_list; // preservation of the Head Pointer: By using a separate pointer (cur) to traverse and manipulate the list, you ensure that the original reference to the head of the list (begin_list) remains unchanged unless explicitly modified. This is important because you may need to update the head of the list if the first element is removed, but you don’t want to lose your reference to the list's starting point;

    if(begin_list == NULL || *begin_list == NULL) // if either is NULL, it returns immediately, doing nothing. This is necessary to avoid dereferencing a NULL pointer and to handle empty lists;
        return;
    if((*cmp)(current->data, data_ref) == 0) // the parameter (data_ref) is a direct pointer to the data you are using as a reference for removal, not a pointer to another list node. This means: (data_ref) is not a node of the list itself but rather a pointer to some data against which the list node data is compared.(cmp) function is supposed to compare directly the data held in list nodes (cur->data) with this reference data (data_ref) and NOT (data_ref->data);
    { // if the data in the current node (cur->data) matches the reference data (data_ref) according to the comparison function (cmp(cur->data, data_ref) == 0), the node needs to be removed;
        *begin_list = current->next; // updates the head of the list to the next node;
        free(current); // then frees the current node;
        ft_list_remove_if(begin_list, data_ref, cmp); // the function calls itself recursively to continue checking from the new head of the list, this recursive call ensures that all matching nodes from the start are removed;
    }
    else
        ft_list_remove_if(&current->next, data_ref, cmp); // if the current node does not need to be removed, the function then calls itself recursively for the next node in the list. This effectively moves the check one node down the list;
}