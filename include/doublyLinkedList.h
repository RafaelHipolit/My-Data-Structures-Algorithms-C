#pragma once

typedef struct nodeDoublyLinkedList
{
    int value;
    struct nodeDoublyLinkedList *previous;
    struct nodeDoublyLinkedList *next;
} nodeDoublyLinkedList_t;

typedef struct doublyLinkedList
{
    int size;
    nodeDoublyLinkedList_t *head;
    nodeDoublyLinkedList_t *end;

} doublyLinkedList_t;

doublyLinkedList_t* newDoublyLinkedList();
void doublyListAddEnd(doublyLinkedList_t* list, int v);
int doublyListRemoveEnd(doublyLinkedList_t* list);
