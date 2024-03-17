#include <stdlib.h>
#include "list.h"
#include "alloc.h"


Node* make_node(void* data)
{
    Node* node = (Node*)allocate(sizeof(Node));
    node->data = data;
    return node;
}

void delete_node(Node* node)
{
    if (node->next != NULL)
    {
        delete_node(node->next);
    } 
    free(node->data);
    free(node);
}

List* make_list()
{
    List* list = (List*)allocate(sizeof(List));
    list->root = NULL;
    return list;
}


void append(List* lst, void* data)
{
    if(lst->root == NULL)
    {
        lst->root = make_node(data);
    }
    else
    {
        Node* cursor = lst->root;
        while(cursor->next != NULL)
        {
            cursor = cursor->next;
        }
        cursor->next = make_node(data);
    }
}

Node* pop(const List* lst)
{
    if (lst->root == NULL)
    {
        return NULL;
    } 
    Node* cursor = lst->root;
    Node* back = NULL;
    while(cursor->next != NULL)
    {
        back = cursor;
        cursor = cursor->next;
    }
    back->next = NULL;
    return cursor;   
}

void delete_list(List* lst)
{
    delete_node(lst->root);
    free(lst);
}