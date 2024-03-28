#ifndef LIST_LIST_H
#define LIST_LIST_H


/*
    The assigment says it must be a part of math system
    So this List can be persivered as MokeList
*/


typedef struct List List;


//constructor
List* make_list();
//add new item in list
void append(List* lst, void* data);
// remove last inserted item from lst and returns it
void* pop(List* lst);
//destructor
void delete_list(List* lst);

#endif