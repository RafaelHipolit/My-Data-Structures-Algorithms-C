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
    size_t size;
    nodeLinkedList_t *head;
    nodeLinkedList_t *end;

} linkedList_t;

typedef enum linkdedListStatus
{
    LINKED_LIST_SUCESS = 0,
    LINKED_LIST_ERRO_MALLOC = -1,
    LINKED_LIST_ERRO_EMPTY = -2,
    LINKED_LIST_ERRO_MAX_LENGTH = -3
} linkdedListStatus_t;

linkedList_t *newLinkedList(linkdedListStatus_t *status);

void linkedListAddEnd(linkedList_t *list, int value, linkdedListStatus_t *status);

int linkedListRemoveEnd(linkedList_t *list, linkdedListStatus_t *status);
