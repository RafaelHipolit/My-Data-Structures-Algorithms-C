#pragma once

typedef struct nodeList
{
    int value;
    struct nodeList* next;
}nodeList_t;


typedef struct linkedList
{
    nodeList_t* head;
    nodeList_t* end;
    int size;
}linkedList_t;

linkedList_t* newLinkedList();
linkedList_t* newLinkedListFromArray(int *arr, int length);
void listAddEnd(linkedList_t* list, int value);
int listRemoveEnd(linkedList_t* list);
void listAddBegin(linkedList_t* list, int v);
int listRemoveBegin(linkedList_t* list);
void listAddAtPosition(linkedList_t* list, int value, int pos);
int listRemoveAtPosition(linkedList_t* list, int pos);
int listGet(linkedList_t* list, int pos);
void listSet(linkedList_t* list, int newValue, int pos);
void ListPrint(linkedList_t* list);
int* listToArray(linkedList_t* list);
void listDelete(linkedList_t* list);
void listSort(linkedList_t** list);
