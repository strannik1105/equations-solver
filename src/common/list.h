#ifndef LIST_LIST_H
#define LIST_LIST_H

/*
    The assigment says it must be a part of math system
    So this List can be persivered as MokeList
*/


typedef struct Node
{
    struct Node* next;
    void* data;
} Node;

Node* make_node(void* data);

void delete_node(Node* node);

typedef struct 
{
    Node* root;
} List;


List* make_list();

void append(List* lst, void* data);

// remove last Node* from lst and returns it
Node* pop(const List* lst);

void delete_list(List* lst);

#endif