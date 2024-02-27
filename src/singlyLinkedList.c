#include <stdio.h>
#include <stdlib.h>
#include "../include/sortAlgorithms.h"
#include "../include/singlyLinkedList.h"

singlyLinkedList_t* newSinglyLinkedList(){
    singlyLinkedList_t* list = (singlyLinkedList_t*) malloc(sizeof(singlyLinkedList_t));
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void initSinglyLinkedList(singlyLinkedList_t* list){
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
}

singlyLinkedList_t* newSinglyLinkedListFromArray(int *arr, int length){
    singlyLinkedList_t* list = newSinglyLinkedList();
    for (int i = 0; i < length; i++)
    {
        singlyLinkedListAddEnd(list, arr[i]);
    }
    return list;
}

void singlyLinkedListAddEnd(singlyLinkedList_t* list, int v){ //push a new value
    nodeSinglyLinkedList_t* node = (nodeSinglyLinkedList_t*) malloc(sizeof(nodeSinglyLinkedList_t));
    node->value = v;
    node->next= NULL;
    if (list->size == 0)
    {
        list->head = node;
        list->end = node;
    }else
    {
        list->end->next = node;
        list->end = node;
    }
    list->size++;
}

int singlyLinkedListRemoveEnd(singlyLinkedList_t* list){ //pop the last value
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
        nodeSinglyLinkedList_t* prevEnd = list->head;
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

void singlyLinkedListAddBegin(singlyLinkedList_t* list, int v){
    nodeSinglyLinkedList_t* node = (nodeSinglyLinkedList_t*) malloc(sizeof(nodeSinglyLinkedList_t));
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

int singlyLinkedListRemoveBegin(singlyLinkedList_t* list){
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
        nodeSinglyLinkedList_t* newHead = list->head->next;
        free(list->head);
        list->head = newHead;
        list->size--;
        return v;
    }
}

void singlyLinkedListAddAtIndex(singlyLinkedList_t* list, int value, int index) {
    if (0 <= index && index < list->size){
        if (index == 0)
        {
            singlyLinkedListAddBegin(list, value);
        }else
        {
            nodeSinglyLinkedList_t* node = (nodeSinglyLinkedList_t*) malloc(sizeof(nodeSinglyLinkedList_t));
            node->value = value;

            nodeSinglyLinkedList_t* prevNode = list->head;
            for (int i = 0; i < index - 1; i++)
            {
                prevNode = prevNode->next;
            }
            nodeSinglyLinkedList_t* nextNode = prevNode->next;
            
            prevNode->next = node;
            node->next = nextNode;
            list->size++;
        }
    }
}

int singlyLinkedListRemoveAtIndex(singlyLinkedList_t* list, int index){
    if (list->size == 0)
    {
        return -1; //erro
    }
    if (0 <= index && index < list->size){
        if (index == 0)
        {
            return singlyLinkedListRemoveBegin(list);
        }else if (index == list->size - 1)
        {
            return singlyLinkedListRemoveEnd(list);
        }else
        {
            nodeSinglyLinkedList_t* prevNode = list->head;
            for (int i = 0; i < index - 1; i++)
            {
                prevNode = prevNode->next;
            }
            nodeSinglyLinkedList_t* nextNode = prevNode->next->next;
            
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

int singlyLinkedListGet(singlyLinkedList_t* list, int index){ // return the value at index  
    if (0 <= index && index < list->size)
    {
        nodeSinglyLinkedList_t* node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        
        return node->value;
    }

    return -1; //erro
}

void singlyLinkedListSet(singlyLinkedList_t* list, int newValue, int index){ // set the value at index  
    if (0 <= index && index < list->size)
    {
        nodeSinglyLinkedList_t* node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        
        node->value = newValue;
    }
}

void singlyLinkedListPrint(singlyLinkedList_t* list){
    printf("Linked List with %d values\n", list->size);
    nodeSinglyLinkedList_t* node = list->head;
    for (int i = 0; i < list->size; i++)
    {
        printf("list[%d] = %d\n",i,node->value);
        node = node->next;
    }
    
}

int* singlyLinkedListToArray(singlyLinkedList_t* list){
    int *arr = (int *)malloc((list->size) * sizeof(int));
    nodeSinglyLinkedList_t* node = list->head;
    for (int i = 0; i < list->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    return arr;
}

void singlyLinkedListDelete(singlyLinkedList_t* list){
    nodeSinglyLinkedList_t* node = list->head;
    nodeSinglyLinkedList_t* nextNode;
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
void listSort_COM_ERRO(singlyLinkedList_t* list){
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
void listSort(singlyLinkedList_t** listPtr){ 
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

void singlyLinkedListSort(singlyLinkedList_t* list){
    int* arr = singlyLinkedListToArray(list);
    int size = list->size;
    quickSort(arr, 0, size-1);   

    singlyLinkedListCopyArray(list, arr, size);
    //printf("Endereco da nova lista ligada = %p\n", list);

    free(arr);
}

void singlyLinkedListCopy(singlyLinkedList_t* listCopy, singlyLinkedList_t* listPaste){
    nodeSinglyLinkedList_t* node = listPaste->head;
    nodeSinglyLinkedList_t* nextNode;
    for (int i = 0; i < listPaste->size; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    listPaste->size = 0;
    listPaste->head = NULL;
    listPaste->end = NULL;

    nodeSinglyLinkedList_t* nodeCopy = listCopy->head;
    for (int i = 0; i < listCopy->size; i++)
    {
        node = (nodeSinglyLinkedList_t*) malloc(sizeof(nodeSinglyLinkedList_t));
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

void singlyLinkedListCopyArray(singlyLinkedList_t* listPaste, int* arrayCopy, int arrayLenght){
    nodeSinglyLinkedList_t* node = listPaste->head;
    if (listPaste->size >= arrayLenght)
    {
        for (int i = 0; i < arrayLenght - 1; i++)
        {
            node->value = arrayCopy[i];
            node = node->next;
        }
        node->value = arrayCopy[arrayLenght - 1];
        listPaste->end = node;
        listPaste->size = arrayLenght;
        node = node->next;
        nodeSinglyLinkedList_t* nextNode;
        for (int i = arrayLenght; i < listPaste->size; i++)
        {
            nextNode = node->next;
            free(node);
            node = nextNode;  
        }
    }else
    {
        for (int i = 0; i < listPaste->size; i++)
        {
            node->value = arrayCopy[i];
            node = node->next;
        }
        for (int i = listPaste->size; i < arrayLenght; i++)
        {
            singlyLinkedListAddEnd(listPaste, arrayCopy[i]);
        }
    }
    
}

void singlyLinkedListClear(singlyLinkedList_t* list){
    nodeSinglyLinkedList_t* node = list->head;
    nodeSinglyLinkedList_t* nextNode;
    for (int i = 0; i < list->size; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
}

//TEM QUE DOCUMENTAR AS FUNCOES
