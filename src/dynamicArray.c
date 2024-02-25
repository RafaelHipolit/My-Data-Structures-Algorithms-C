#include <stdio.h>
#include <stdlib.h>
#include "../include/dynamicArray.h"

dynamicArray_t* newDynamicArray(){
    dynamicArray_t* dynamicArr = (dynamicArray_t*)malloc(sizeof(dynamicArray_t));
    dynamicArr->maxSize = INITIAL_SIZE;
    dynamicArr->usedSize = 0;
    dynamicArr->arrayPtr = (int*)malloc(INITIAL_SIZE * sizeof(int));
    return dynamicArr;
}

int dynamicArraySize(dynamicArray_t* dynamicArray){
    return dynamicArray->usedSize;
}

void dynamicArrayAddEnd(dynamicArray_t* dynamicArray, int value){
    if (dynamicArray->usedSize < dynamicArray->maxSize)
    {
        dynamicArray->arrayPtr[dynamicArray->usedSize] = value;
        dynamicArray->usedSize++;
    }else
    {
        int newMaxSize = dynamicArray->maxSize * INCREASE_FACTOR;
        int* newArr = (int*)realloc(dynamicArray->arrayPtr,newMaxSize * sizeof(int));
        if (newArr == NULL)
        {
            printf("Error when resizing array\n"); //mudar isso, nao quero ficar dando print, quero de alguma retornar um status de erro
        }
        else {
            dynamicArray->arrayPtr = newArr;
            dynamicArray->maxSize = newMaxSize;

            dynamicArray->arrayPtr[dynamicArray->usedSize] = value;
            dynamicArray->usedSize++;
        } 
    }
}

int dynamicArrayRemoveEnd(dynamicArray_t* dynamicArray){
    if (dynamicArray->usedSize == 0)
    {
        return -1; //mudar isso
    }
    
    int value = dynamicArray->arrayPtr[dynamicArray->usedSize - 1];
    dynamicArray->usedSize--;
    
    //printf("tamanho pra diminuir %d\n", (int)(dynamicArray->maxSize * DECREASE_FACTOR));
    //printf("%d\n",dynamicArray->usedSize);
    if (dynamicArray->usedSize < (int)(dynamicArray->maxSize * DECREASE_FACTOR) && dynamicArray->maxSize > INITIAL_SIZE)
    {
        int newMaxSize = (int)(dynamicArray->maxSize / INCREASE_FACTOR);
        int* newArr = (int*)realloc(dynamicArray->arrayPtr, newMaxSize * sizeof(int));
        if (newArr == NULL)
        {
            printf("Error when resizing array\n"); //mudar isso
        }
        else {
            dynamicArray->arrayPtr = newArr;
            dynamicArray->maxSize = newMaxSize;
        }
        //printf("diminuiu, novo tamanho %d\n", newMaxSize);
    }

    return value;
}

void dynamicArrayAddAtIndex(dynamicArray_t* dynamicArray, int value, int index) {
    if (0 <= index && index < dynamicArray->usedSize) {
        //por enquanto, a funcao dynamicArrayAddAtIndex so vai add elementos em index ja preenchidos
        
        if (dynamicArray->usedSize < dynamicArray->maxSize) {
            for (int i = dynamicArray->usedSize - 1; i >= index; i--)
            {
                dynamicArray->arrayPtr[i + 1] = dynamicArray->arrayPtr[i];
            }
            dynamicArray->arrayPtr[index] = value;
            dynamicArray->usedSize++;
        }
        else {
            int newMaxSize = dynamicArray->maxSize * INCREASE_FACTOR;
            int* newArr = (int*)realloc(dynamicArray->arrayPtr, newMaxSize * sizeof(int)); //realloc aqui realmente eh a melhor opcao? 
            //tipo, se o realloc copia pra outro endereco e depois eu vou vou mover quase todos os elementos uma casa pra frente. nao sei mais eficaz fazer um malloc e ja copiar os elemntos uma casa pra frente?
            if (newArr == NULL)
            {
                printf("Error when resizing array\n"); //mudar isso
            }
            else {
                dynamicArray->arrayPtr = newArr;
                dynamicArray->maxSize = newMaxSize;

                for (int i = dynamicArray->usedSize - 1; i >= index; i--)
                {
                    dynamicArray->arrayPtr[i + 1] = dynamicArray->arrayPtr[i];
                }
                dynamicArray->arrayPtr[index] = value;
                dynamicArray->usedSize++;
            }
        } 
    }
}

int dynamicArrayRemoveAtIndex(dynamicArray_t* dynamicArray, int index){
    if (0 <= index && index < dynamicArray->usedSize) {
        int value = dynamicArray->arrayPtr[index];
        for (int i = index; i < dynamicArray->usedSize; i++)
        {
            dynamicArray->arrayPtr[i] = dynamicArray->arrayPtr[i + 1];
        }
        dynamicArray->usedSize--;

        if (dynamicArray->usedSize < (int)(dynamicArray->maxSize * DECREASE_FACTOR) && dynamicArray->maxSize > INITIAL_SIZE)
        {
            int newMaxSize = (int)(dynamicArray->maxSize / INCREASE_FACTOR);
            int* newArr = (int*)realloc(dynamicArray->arrayPtr, newMaxSize * sizeof(int));
            if (newArr == NULL)
            {
                printf("Error when resizing array\n"); //mudar isso
            }
            else {
                dynamicArray->arrayPtr = newArr;
                dynamicArray->maxSize = newMaxSize;
            }
            //printf("diminuiu, novo tamanho %d\n", newMaxSize);
        }

        return value;
    }
    else {
        // caso dynamicArray->usedSize == 0 cai aqui
        return -1;//mudar isso
    }
}

int dynamicArrayGet(dynamicArray_t* dynamicArray, int index){
    if (index > dynamicArray->usedSize - 1)
    {
        return -1; //mudar isso
    }
    return dynamicArray->arrayPtr[index];
}

void dynamicArraySet(dynamicArray_t* dynamicArray, int value, int index){
    if (index < dynamicArray->usedSize)
    {
        dynamicArray->arrayPtr[index] = value;
    }
}

void dynamicArrayPrint(dynamicArray_t* dynamicArray){
    for (int i = 0; i < dynamicArray->usedSize; i++)
    {
        printf("DynamicArray[%d] = %d\n", i, dynamicArray->arrayPtr[i]);
    }
}

void dynamicArrayClear(dynamicArray_t* dynamicArray){
    free(dynamicArray->arrayPtr);
    dynamicArray->arrayPtr = (int*)malloc(INITIAL_SIZE * sizeof(int));
    dynamicArray->maxSize = INITIAL_SIZE;
    dynamicArray->usedSize = 0;
}

int* dynamicArrayToArray(dynamicArray_t* dynamicArray){
    int* arr = (int*)malloc(dynamicArray->usedSize * sizeof(int));
    for (int i = 0; i < dynamicArray->usedSize; i++)
    {
        arr[i] = dynamicArray->arrayPtr[i];
    }
    return arr;
}

void dynamicArrayDelete(dynamicArray_t* dynamicArray){
    free(dynamicArray->arrayPtr);
    free(dynamicArray);
}