#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int value;
    struct element* next;
}element_t;


typedef struct linkedList
{
    element_t* head;
    element_t* end;
    int size;
}linkedList_t;


linkedList_t* newLinkedList();
void addEnd(linkedList_t* list, int value);
void printList(linkedList_t* list);

linkedList_t* newLinkedList(){
    linkedList_t* list = (linkedList_t*) malloc(sizeof(linkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void addEnd(linkedList_t* list, int v){
    element_t* e = (element_t*) malloc(sizeof(element_t));
    e->value = v;
    e->next= NULL;
    if (list->size == 0)
    {
        list->head = e;
        list->end = e;
    }else
    {
        list->end->next = e;
    }
    list->size++;
}

void printList(linkedList_t* list){
    element_t* e = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n",e->value);
        e = e->next;
    }
    
}

#endif