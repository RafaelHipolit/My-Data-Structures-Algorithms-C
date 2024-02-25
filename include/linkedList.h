#pragma once
/*
## node of linked list
*/
typedef struct nodeList
{
    int value;
    struct nodeList* next;
}nodeList_t;


typedef struct linkedList
{
    /*
    Not recommended access directly
    */
    nodeList_t* head;
    nodeList_t* end;
    int size;
}linkedList_t;

linkedList_t* newLinkedList();

void initLinkedList(linkedList_t* list);

linkedList_t* newLinkedListFromArray(int *arr, int length);
void listAddEnd(linkedList_t* list, int value);
int listRemoveEnd(linkedList_t* list);
void listAddBegin(linkedList_t* list, int v);
int listRemoveBegin(linkedList_t* list);
void listAddAtIndex(linkedList_t* list, int value, int index);
int listRemoveAtIndex(linkedList_t* list, int index);
int listGet(linkedList_t* list, int index);
void listSet(linkedList_t* list, int newValue, int index);
void ListPrint(linkedList_t* list);
int* listToArray(linkedList_t* list);
void listDelete(linkedList_t* list);
void listSort(linkedList_t* list);

void listCopy(linkedList_t* listCopy, linkedList_t* listPaste);

/*
# copia o conteudo do array para a lista
```c
linkedList_t* listPaste, int* arrayCopy, int arrayLenght
```
@param linkedList_t* listPaste, int* arrayCopy, int arrayLenght
*/
void listCopyArray(linkedList_t* listPaste, int* arrayCopy, int arrayLenght);

void listClear(linkedList_t* list);