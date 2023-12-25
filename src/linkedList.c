#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeList
{
    int value;
    struct nodeList* next;
}nodeList_t;


typedef struct linkedList
{
    nodeList_t* head;
    nodeList_t* end;
    int size;
}linkedList_t;


linkedList_t* newLinkedList();
void listAddEnd(linkedList_t* list, int value);
int listRemoveEnd(linkedList_t* list);
void ListPrint(linkedList_t* list);

linkedList_t* newLinkedList(){
    linkedList_t* list = (linkedList_t*) malloc(sizeof(linkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void listAddEnd(linkedList_t* list, int v){
    nodeList_t* e = (nodeList_t*) malloc(sizeof(nodeList_t));
    e->value = v;
    e->next= NULL;
    if (list->size == 0)
    {
        list->head = e;
        list->end = e;
    }else
    {
        list->end->next = e;
        list->end = e;
    }
    list->size++;
}

int listRemoveEnd(linkedList_t* list){
    if (list->size == 0)
    {
        return -1; //erro
    }else if (list->size == 1)
    {
        int v = list->end->value;
        free(list->end);
        list->end = NULL;
        list->head = NULL;
        list->size--;
        return v;
    }else
    {  
        nodeList_t* prevEnd = list->head;
        while (prevEnd->next->next != NULL)
        {
            prevEnd = prevEnd->next;
        }
        
        int v = list->end->value;
        free(list->end);
        list->end = prevEnd;
        prevEnd->next = NULL;
        list->size--;
        return v;
    }
}

void ListPrint(linkedList_t* list){
    nodeList_t* e = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("%d\n",e->value);
        e = e->next;
    }
    
}

#endif