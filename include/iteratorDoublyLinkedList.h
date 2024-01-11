#pragma once

#include "doublyLinkedList.h"

typedef struct iteratorDoublyLinkedList
{
    nodeDoublyLinkedList_t* node;
    doublyLinkedList_t* list;
}iteratorDoublyLinkedList_t;

iteratorDoublyLinkedList_t* newIteratorDoublyLinkedList(doublyLinkedList_t* list);
int iteratorNext(iteratorDoublyLinkedList_t* i);
int iteratorPrevious(iteratorDoublyLinkedList_t* i);
int iteratorGetValue(iteratorDoublyLinkedList_t* i);
void iteratorSetValue(iteratorDoublyLinkedList_t* i, int value);
int iteratorIsEnd(iteratorDoublyLinkedList_t* i);
void iteratorToBegin(iteratorDoublyLinkedList_t* i);