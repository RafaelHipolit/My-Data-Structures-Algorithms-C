#pragma once

typedef struct nodeLinkedList
{
    int value;
    struct nodeLinkedList *previous;
    struct nodeLinkedList *next;
} nodeLinkedList_t;

/*
A doubly linked list
*/
typedef struct linkedList
{
    int size;
    nodeLinkedList_t *head;
    nodeLinkedList_t *end;

} linkedList_t;

linkedList_t* newLinkedList();
void linkedListAddEnd(linkedList_t* list, int value);
int linkedListRemoveEnd(linkedList_t* list);
