#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../include/linkedList.h"

linkedList_t *newLinkedList(linkedListStatus_t *OperationStatus)
{
    linkedList_t *list = (linkedList_t *)malloc(sizeof(linkedList_t));
    if (list == NULL && OperationStatus != NULL)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_MALLOC;
        return list;
    }

    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    if (OperationStatus != NULL)
        *OperationStatus = LINKED_LIST_SUCESS;
    return list;
}

void linkedListAddEnd(linkedList_t *list, int value, linkedListStatus_t *OperationStatus)
{
    if (list->size == SIZE_MAX)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_MAX_LENGTH;
        return;
    }

    nodeLinkedList_t *node = (nodeLinkedList_t *)malloc(sizeof(nodeLinkedList_t));
    if (node == NULL)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_MALLOC;
        return;
    }

    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    if (list->size == 0)
    {
        list->head = node;
        list->end = node;
    }
    else
    {
        list->end->next = node;
        node->previous = list->end;
        list->end = node;
    }
    list->size++;
    if (OperationStatus != NULL)
        *OperationStatus = LINKED_LIST_SUCESS;
}

int linkedListRemoveEnd(linkedList_t *list, linkedListStatus_t *OperationStatus)
{
    if (list->size == 0)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_EMPTY;
        return -1;
    }

    int value;
    if (list->size == 1)
    {
        value = list->end->value;
        free(list->end);
        list->end = NULL;
        list->head = NULL;
    }
    else
    {
        nodeLinkedList_t *node = list->end;
        value = list->end->value;
        list->end = list->end->previous;
        list->end->next = NULL;
        free(node);
    }
    list->size--;
    if (OperationStatus != NULL)
        *OperationStatus = LINKED_LIST_SUCESS;
    return value;
}

void linkedListPrint(linkedList_t *list)
{
    nodeLinkedList_t *node = list->head;
    for (size_t i = 0; i < list->size; i++)
    {
        printf("Linked list [%lu] = %d \n", i, node->value);
        node = node->next;
    }
}

void linkedListDelete(linkedList_t *list){
    nodeLinkedList_t *node = list->head;
    nodeLinkedList_t *nextNode;
    for (size_t i = 0; i < list->size; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(list);
}