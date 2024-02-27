#pragma once
/*
### node of linked list
*/
typedef struct nodeSinglyLinkedList
{
    int value;
    struct nodeSinglyLinkedList* next;
}nodeSinglyLinkedList_t;


typedef struct singlyLinkedList
{
    /*
    Not recommended access directly
    */
    nodeSinglyLinkedList_t* head;
    nodeSinglyLinkedList_t* end;
    int size;
}singlyLinkedList_t;

/*
* Create a new singly linked list.
* Alloc and initialize a new singlyLinkedList_t.
* Returns a pointer to the new singlyLinkedList_t.
* @return singlyLinkedList_t*
*/
singlyLinkedList_t* newSinglyLinkedList();

void initSinglyLinkedList(singlyLinkedList_t* list);

singlyLinkedList_t* newSinglyLinkedListFromArray(int *arr, int length);

void singlyLinkedListAddEnd(singlyLinkedList_t* list, int value);

int singlyLinkedListRemoveEnd(singlyLinkedList_t* list);

void singlyLinkedListAddBegin(singlyLinkedList_t* list, int v);

int singlyLinkedListRemoveBegin(singlyLinkedList_t* list);

void singlyLinkedListAddAtIndex(singlyLinkedList_t* list, int value, int index);

int singlyLinkedListRemoveAtIndex(singlyLinkedList_t* list, int index);

int singlyLinkedListGet(singlyLinkedList_t* list, int index);

void singlyLinkedListSet(singlyLinkedList_t* list, int newValue, int index);

void singlyLinkedListPrint(singlyLinkedList_t* list);

int* singlyLinkedListToArray(singlyLinkedList_t* list);

void singlyLinkedListDelete(singlyLinkedList_t* list);

void singlyLinkedListSort(singlyLinkedList_t* list);

void singlyLinkedListCopy(singlyLinkedList_t* listCopy, singlyLinkedList_t* listPaste);

/*


```c
int a[] = {1,2,3};
singlyLinkedListCopyArray(list, a, 3);
```
@param singlyLinkedList_t* listPaste
@param int* arrayCopy
@param int arrayLenght
*/
void singlyLinkedListCopyArray(singlyLinkedList_t* listPaste, int* arrayCopy, int arrayLenght);

void singlyLinkedListClear(singlyLinkedList_t* list);