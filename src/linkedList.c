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
    if (list->size == 0)
    {
        node->next = NULL;
        node->previous = NULL;
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

void linkedListAddAtIndex(linkedList_t *list, size_t index, int value, linkedListStatus_t *OperationStatus)
{
    if (list->size == SIZE_MAX)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_MAX_LENGTH;
        return;
    }

    if (index > list->size)
    {
        if (OperationStatus != NULL)
            *OperationStatus = LINKED_LIST_ERRO_INDEX_OUT_BOUNDS;
        return;
    }

    if (index == 0)
    {
        // add inicio
        return;
    }

    if (index == list->size)
    {
        linkedListAddEnd(list, value, OperationStatus);
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

    if (list->size == 0)
    {
        node->next = NULL;
        node->previous = NULL;
        list->head = node;
        list->end = node;
    }
    else
    {
        nodeLinkedList_t *nodeIndex;
        if (index < list->size / 2)
        {
            nodeIndex = list->head;
            for (size_t i = 0; i < index; i++)
            {
                nodeIndex = nodeIndex->next;
            }
        }
        else
        {
            nodeIndex = list->end;
            for (size_t i = list->size - 1; i > index; i--)
            {
                nodeIndex = nodeIndex->previous;
            }
        }

        node->previous = nodeIndex->previous;
        node->next = nodeIndex;
        nodeIndex->previous->next = node;
        nodeIndex->previous = node;
    }

    list->size++;
    if (OperationStatus != NULL)
        *OperationStatus = LINKED_LIST_SUCESS;
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

void linkedListDelete(linkedList_t *list)
{
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

void linkedListPrintStatusErro(linkedListStatus_t OperationStatus)
{
    if (OperationStatus != LINKED_LIST_SUCESS)
    {
        printf("An error occurred in a linked list function - Code = %d - ", OperationStatus);
        switch (OperationStatus)
        {
        case LINKED_LIST_ERRO_MALLOC:
            printf("LINKED_LIST_ERRO_MALLOC - Memory allocation error\n");
            break;
        case LINKED_LIST_ERRO_EMPTY:
            printf("LINKED_LIST_ERRO_EMPTY - The linked list is empty\n");
            break;
        case LINKED_LIST_ERRO_MAX_LENGTH:
            printf("LINKED_LIST_ERRO_MAX_LENGTH - The Linked list has reached the maximum number of items\n");
            break;
        case LINKED_LIST_ERRO_INDEX_OUT_BOUNDS:
            printf("LINKED_LIST_ERRO_INDEX_OUT_BOUNDS - The index was out of bounds\n");
            break;
        default:
            printf("Unknown erro");
            break;
        }
    }
}