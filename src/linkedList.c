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

void listAddAtIndex(linkedList_t* list, int value, int index) {
    if (0 <= index && index < list->size){
        if (index == 0)
        {
            listAddBegin(list, value);
        }else
        {
            nodeList_t* node = (nodeList_t*) malloc(sizeof(nodeList_t));
            node->value = value;

            nodeList_t* prevNode = list->head;
            for (int i = 0; i < index - 1; i++)
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

int listRemoveAtIndex(linkedList_t* list, int index){
    if (list->size == 0)
    {
        return -1; //erro
    }
    if (0 <= index && index < list->size){
        if (index == 0)
        {
            return listRemoveBegin(list);
        }else if (index == list->size - 1)
        {
            return listRemoveEnd(list);
        }else
        {
            nodeList_t* prevNode = list->head;
            for (int i = 0; i < index - 1; i++)
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

int listGet(linkedList_t* list, int index){ // return the value at index  
    if (0 <= index && index < list->size)
    {
        nodeList_t* node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        
        return node->value;
    }

    return -1; //erro
}

void listSet(linkedList_t* list, int newValue, int index){ // set the value at index  
    if (0 <= index && index < list->size)
    {
        nodeList_t* node = list->head;
        for (int i = 0; i < index; i++)
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

/*
// FUNCTION sortList() - funcao para organizar a lista

// funcao antiga com erro simples: variavel criada nos paramentros da funcao nao altera a variavel que foi passa na chamada da funcao 
void listSortERRO(linkedList_t* list){
    int* arr = listToArray(list);
    int size = list->size;
    quickSort(arr, 0, size-1);

    listDelete(list);   
    list = newLinkedListFromArray(arr, size);
    printf("Endereco da nova lista ligada = %p\n", list);

    free(arr);
}
// listDelete(list); desaloca a lista ligada desorganizada que list estava apontando. Assim list agora aponta pra um endereco que nao tem mais uma lista ligada
// list = newLinkedListFromArray(arr, size); aloca uma nova lista ligada organizada num outro endereco e faz list apontar pro endereco da nova lista
// tudo correto, porem essa alteracao eh somente para a var list dessa funcao, enquanto a var que foi passada na chamada da funcao la na main vai continua apontando pro endereco da antiga lista desorganizada que nem existe mais
// por isso a var list dessa funcao funciona corretamente e a var la da main da segmentation fault
// bizarramente as vezes nao dava erro pq o endereco na nova lista ligada organizada acabava "coincidentemente" sendo o mesmo da antiga lista ligada

// Uma solucao eh receber por parametro o endereco da var la da main para altera seu conteudo dentro da funcao
void listSort(linkedList_t** listPtr){ 
    int* arr = listToArray(*listPtr);
    int size = (*listPtr)->size;
    quickSort(arr, 0, size-1);

    listDelete(*listPtr);   
    *listPtr = newLinkedListFromArray(arr, size);
    printf("Endereco da nova lista ligada = %p\n", *listPtr);

    //ListPrint(*list);
    free(arr);
}

// Mas por fim vou preferir uma solucao mais extensa: nao alocar uma nova lista e sim alterar o conteudo da ja existente 
*/

void listSort(linkedList_t* list){
    int* arr = listToArray(list);
    int size = list->size;
    quickSort(arr, 0, size-1);   
    linkedList_t* listSorted = newLinkedListFromArray(arr, size);

    listCopy(listSorted, list);
    //printf("Endereco da nova lista ligada = %p\n", list);

    listDelete(listSorted);
    free(arr);
}

void listCopy(linkedList_t* listCopy, linkedList_t* listPaste){
    nodeList_t* node = listPaste->head;
    nodeList_t* nextNode;
    for (int i = 0; i < listPaste->size; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    listPaste->size = 0;
    listPaste->head = NULL;
    listPaste->end = NULL;

    nodeList_t* nodeCopy = listCopy->head;
    for (int i = 0; i < listCopy->size; i++)
    {
        node = (nodeList_t*) malloc(sizeof(nodeList_t));
        node->value = nodeCopy->value;
        node->next= NULL;
        if (listPaste->size == 0)
        {
            listPaste->head = node;
            listPaste->end = node;
        }else
        {
            listPaste->end->next = node;
            listPaste->end = node;
        }
        listPaste->size++;

        nodeCopy = nodeCopy->next;
    }
    
}

//TEM QUE DOCUMENTAR AS FUNCOES
