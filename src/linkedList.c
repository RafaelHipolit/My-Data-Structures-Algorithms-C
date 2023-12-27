#include <stdio.h>
#include <stdlib.h>
#include "../include/sortAlgorithms.h"
#include "../include/linkedList.h"

linkedList_t* newLinkedList(){
    linkedList_t* list = (linkedList_t*) malloc(sizeof(linkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

linkedList_t* newLinkedListFromArray(int *arr, int length){
    linkedList_t* list = newLinkedList();
    for (int i = 0; i < length; i++)
    {
        listAddEnd(list, arr[i]);
    }
    return list;
}

void listAddEnd(linkedList_t* list, int v){ //push a new value
    nodeList_t* e = (nodeList_t*) malloc(sizeof(nodeList_t));
    e->value = v;
    e->next= NULL;
    if (list->size == 0)
    {
        list->head = e;
        list->end = e;
    }else
    {
        list->end->next = e;
        list->end = e;
    }
    list->size++;
}

int listRemoveEnd(linkedList_t* list){ //pop the last value
    if (list->size == 0)
    {
        return -1; //erro
    }else if (list->size == 1)
    {
        int v = list->end->value;
        free(list->end);
        list->end = NULL;
        list->head = NULL;
        list->size--;
        return v;
    }else
    {  
        nodeList_t* prevEnd = list->head;
        while (prevEnd->next->next != NULL)
        {
            prevEnd = prevEnd->next;
        }
        
        int v = list->end->value;
        free(list->end);
        list->end = prevEnd;
        prevEnd->next = NULL;
        list->size--;
        return v;
    }
}

void listAddBegin(linkedList_t* list, int v){
    nodeList_t* node = (nodeList_t*) malloc(sizeof(nodeList_t));
    node->value = v;
    if (list->size == 0)
    {
        node->next= NULL;
        list->head = node;
        list->end = node;
    }else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

int listRemoveBegin(linkedList_t* list){
    if (list->size == 0)
    {
        return -1; //erro
    }else if (list->size == 1)
    {
        int v = list->head->value;
        free(list->head);
        list->end = NULL;
        list->head = NULL;
        list->size--;
        return v;
    }else
    { 
        int v = list->head->value;
        nodeList_t* newHead = list->head->next;
        free(list->head);
        list->head = newHead;
        list->size--;
        return v;
    }
}

void listAddAtPosition(linkedList_t* list, int value, int pos) {
    if (0 <= pos && pos < list->size){
        if (pos == 0)
        {
            listAddBegin(list, value);
        }else
        {
            nodeList_t* node = (nodeList_t*) malloc(sizeof(nodeList_t));
            node->value = value;

            nodeList_t* prevNode = list->head;
            for (int i = 0; i < pos - 1; i++)
            {
                prevNode = prevNode->next;
            }
            nodeList_t* nextNode = prevNode->next;
            
            prevNode->next = node;
            node->next = nextNode;
            list->size++;
        }
    }
}

int listRemoveAtPosition(linkedList_t* list, int pos){
    if (list->size == 0)
    {
        return -1; //erro
    }
    if (0 <= pos && pos < list->size){
        if (pos == 0)
        {
            return listRemoveBegin(list);
        }else if (pos == list->size - 1)
        {
            return listRemoveEnd(list);
        }else
        {
            nodeList_t* prevNode = list->head;
            for (int i = 0; i < pos - 1; i++)
            {
                prevNode = prevNode->next;
            }
            nodeList_t* nextNode = prevNode->next->next;
            
            int v = prevNode->next->value;
            free(prevNode->next);
            prevNode->next = nextNode;
            list->size--;
            return v;
        }
    }else
    {
        return -1; //erro
    }
    
}

int listGet(linkedList_t* list, int pos){ // return the value at position pos   
    if (0 <= pos && pos < list->size)
    {
        nodeList_t* node = list->head;
        for (int i = 0; i < pos; i++)
        {
            node = node->next;
        }
        
        return node->value;
    }

    return -1; //erro
}

void listSet(linkedList_t* list, int newValue, int pos){ // set the value at position pos   
    if (0 <= pos && pos < list->size)
    {
        nodeList_t* node = list->head;
        for (int i = 0; i < pos; i++)
        {
            node = node->next;
        }
        
        node->value = newValue;
    }
}

void ListPrint(linkedList_t* list){
    printf("Linked List with %d values\n", list->size);
    nodeList_t* e = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("list[%d] = %d\n",i,e->value);
        e = e->next;
    }
    
}

int* listToArray(linkedList_t* list){
    int *arr = (int *)malloc((list->size) * sizeof(int));
    nodeList_t* node = list->head;
    for (int i = 0; i < list->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    return arr;
}

void listDelete(linkedList_t* list){
    nodeList_t* node = list->head;
    nodeList_t* nextNode;
    for (int i = 0; i < list->size; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(list);
}

void listSort(linkedList_t** list){ //ENTENDER O QUE TA ACONTECENDO AQUI
    int* arr = listToArray(*list);
    int size = list[0]->size;
    quickSort(arr, 0, size-1);

    listDelete(*list);   
    *list = newLinkedListFromArray(arr, size);

    //ListPrint(*list);
    free(arr);
}

//TEM QUE DOCUMENTAR AS FUNCOES
