#include <stdio.h>
#include <stdlib.h>
#include "../include/iteratorLinkedList.h"

iteratorLinkedList_t* newIteratorDoublyLinkedList(linkedList_t* list){
    iteratorLinkedList_t* i = (iteratorLinkedList_t*) malloc(sizeof(iteratorLinkedList_t));
    i->list = list;
    i->node = list->head;
    return i;
}

int iteratorNext(iteratorLinkedList_t* i){
    if (i->node->next == NULL)
    {
        return -1;
    }
    i->node = i->node->next;
    return 0;
}

int iteratorPrevious(iteratorLinkedList_t* i){
    if (i->node->previous == NULL)
    {
        return -1;
    }
    i->node = i->node->previous;
    return 0;
}

int iteratorGetValue(iteratorLinkedList_t* i){
    return i->node->value;
}

void iteratorSetValue(iteratorLinkedList_t* i, int value){
    i->node->value = value;
}

int iteratorIsEnd(iteratorLinkedList_t* i){
    if (i->node == i->list->end)
    {
        return 1;
    }else{
        return 0;
    }
}

void iteratorToBegin(iteratorLinkedList_t* i){ //ver se tem um nome melhor
    i->node = i->list->head;
}

