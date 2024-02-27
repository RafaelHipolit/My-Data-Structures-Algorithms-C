#pragma once

#include "linkedList.h"

typedef struct iteratorLinkedList
{
    nodeLinkedList_t* node;
    linkedList_t* list;
}iteratorLinkedList_t;

iteratorLinkedList_t* newIteratorLinkedList(linkedList_t* list);
int iteratorNext(iteratorLinkedList_t* i);
int iteratorPrevious(iteratorLinkedList_t* i);
int iteratorGetValue(iteratorLinkedList_t* i);
void iteratorSetValue(iteratorLinkedList_t* i, int value);
int iteratorIsEnd(iteratorLinkedList_t* i);
void iteratorToBegin(iteratorLinkedList_t* i);