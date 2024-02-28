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

typedef enum linkedListStatus
{
    LINKED_LIST_SUCESS = 0,
    LINKED_LIST_ERRO_MALLOC = -1,
    LINKED_LIST_ERRO_EMPTY = -2,
    LINKED_LIST_ERRO_MAX_LENGTH = -3
} linkedListStatus_t;

linkedList_t *newLinkedList(linkedListStatus_t *OperationStatus);

void linkedListAddEnd(linkedList_t *list, int value, linkedListStatus_t *OperationStatus);

int linkedListRemoveEnd(linkedList_t *list, linkedListStatus_t *OperationStatus);

void linkedListPrint(linkedList_t *list);

void linkedListDelete(linkedList_t *list);