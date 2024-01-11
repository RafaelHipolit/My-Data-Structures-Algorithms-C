#include <stdio.h>
#include <stdlib.h>
#include "../include/iteratorDoublyLinkedList.h"

iteratorDoublyLinkedList_t* newIteratorDoublyLinkedList(doublyLinkedList_t* list){
    iteratorDoublyLinkedList_t* i = (iteratorDoublyLinkedList_t*) malloc(sizeof(iteratorDoublyLinkedList_t));
    i->list = list;
    i->node = list->head;
    return i;
}

int iteratorNext(iteratorDoublyLinkedList_t* i){
    if (i->node->next == NULL)
    {
        return -1;
    }
    i->node = i->node->next;
    return 0;
}

int iteratorPrevious(iteratorDoublyLinkedList_t* i){
    if (i->node->previous == NULL)
    {
        return -1;
    }
    i->node = i->node->previous;
    return 0;
}

int iteratorGetValue(iteratorDoublyLinkedList_t* i){
    return i->node->value;
}

void iteratorSetValue(iteratorDoublyLinkedList_t* i, int value){
    i->node->value = value;
}

int iteratorIsEnd(iteratorDoublyLinkedList_t* i){
    if (i->node == i->list->end)
    {
        return 1;
    }else{
        return 0;
    }
}

void iteratorToBegin(iteratorDoublyLinkedList_t* i){ //ver se tem um nome melhor
    i->node = i->list->head;
}

