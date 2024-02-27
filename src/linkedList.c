#include <stdio.h>
#include <stdlib.h>
#include "../include/linkedList.h"

linkedList_t* newLinkedList(){
    linkedList_t* list = (linkedList_t*) malloc(sizeof(linkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void linkedListAddEnd(linkedList_t* list, int value){
    nodeLinkedList_t* node = (nodeLinkedList_t*) malloc(sizeof(nodeLinkedList_t));
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    if (list->size == 0)
    {
        list->head = node;
        list->end = node;
    }else
    {
        list->end->next = node;
        node->previous = list->end;
        list->end = node;
    }
    list->size++;
}

int linkedListRemoveEnd(linkedList_t* list){
    if (list->size == 0)
    {
        return -1;
    }else if (list->size == 1)
    {
        int value = list->end->value;
        free(list->end);
        list->end = NULL;
        list->head = NULL;
        list->size--;
        return value;
    }else{
        nodeLinkedList_t* node = list->end;
        int value = list->end->value;
        list->end = list->end->previous;
        list->end->next = NULL;
        free(node);
        list->size--;
        return value;
    }
}
