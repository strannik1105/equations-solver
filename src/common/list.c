#include <stdlib.h>
#include "list.h"
#include "alloc.h"

typedef struct Node
{
    struct Node* prev;
    void* data;
} Node;

Node* make_node(void* data);

void delete_node(Node* node);

typedef struct List
{
    Node* head;
} List;


Node* make_node(void* data)
{
    Node* node = (Node*)allocate(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    return node;
}

void delete_node(Node* node)
{
    if (node->prev != NULL)
    {
        delete_node(node->prev);
    } 
    free(node->data);
    free(node);
}

List* make_list()
{
    List* list = (List*)allocate(sizeof(List));
    list->head = NULL;
    return list;
}


void append(List* lst, void* data)
{
    if(lst->head == NULL)
    {
        lst->head = make_node(data);
    }
    else
    {
        Node* cursor = make_node(data);
        cursor->prev = lst->head;
        lst->head = cursor;
    }
}

void* pop(List* lst)
{
    if(lst->head == NULL)
    {
        return NULL;
    }

    Node* head = lst->head;
    void* data = head->data;
    lst->head = head->prev;
    free(head);
    return data;
}

void delete_list(List* lst)
{
    if(lst->head != NULL)
    {
        delete_node(lst->head);
    }
    free(lst);
}