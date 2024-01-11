#include <stdio.h>
#include <stdlib.h>
#include "../include/doublyLinkedList.h"

doublyLinkedList_t* newDoublyLinkedList(){
    doublyLinkedList_t* list = (doublyLinkedList_t*) malloc(sizeof(doublyLinkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void doublyListAddEnd(doublyLinkedList_t* list, int v){ //push a new value
    nodeDoublyLinkedList_t* node = (nodeDoublyLinkedList_t*) malloc(sizeof(nodeDoublyLinkedList_t));
    node->value = v;
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

int doublyListRemoveEnd(doublyLinkedList_t* list){
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
        nodeDoublyLinkedList_t* node = list->end;
        int value = list->end->value;
        list->end = list->end->previous;
        list->end->next = NULL;
        free(node);
        list->size--;
        return value;
    }
}
