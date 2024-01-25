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
        int* newArr = (int*)malloc(newMaxSize * sizeof(int));
        for (int i = 0; i < dynamicArray->usedSize; i++)
        {
            newArr[i] = dynamicArray->arrayPtr[i];
        }
        free(dynamicArray->arrayPtr);
        dynamicArray->arrayPtr = newArr;
        dynamicArray->maxSize = newMaxSize;

        dynamicArray->arrayPtr[dynamicArray->usedSize] = value;
        dynamicArray->usedSize++;
    }
}

int dynamicArrayRemoveEnd(dynamicArray_t* dynamicArray){
    if (dynamicArray->usedSize == 0)
    {
        return -1;
    }
    
    int value = dynamicArray->arrayPtr[dynamicArray->usedSize - 1];
    dynamicArray->usedSize--;
    
    //printf("tamanho pra diminuir %d\n", (int)(dynamicArray->maxSize * DECREASE_FACTOR));
    printf("%d\n",dynamicArray->usedSize);
    if (dynamicArray->usedSize < (int)(dynamicArray->maxSize * DECREASE_FACTOR) && dynamicArray->maxSize > INITIAL_SIZE)
    {
        int newMaxSize = (int)(dynamicArray->maxSize / INCREASE_FACTOR);
        int* newArr = (int*)malloc(newMaxSize * sizeof(int));
        for (int i = 0; i < dynamicArray->usedSize; i++)
        {
            newArr[i] = dynamicArray->arrayPtr[i];
        }
        free(dynamicArray->arrayPtr);
        dynamicArray->arrayPtr = newArr;
        dynamicArray->maxSize = newMaxSize;
        //printf("diminuiu, novo tamanho %d\n", newMaxSize);
    }

    return value;
}

int dynamicArrayGet(dynamicArray_t* dynamicArray, int index){
    if (index > dynamicArray->usedSize - 1)
    {
        return -1;
    }
    return dynamicArray->arrayPtr[index];
}

void dynamicArraySet(dynamicArray_t* dynamicArray, int value, int index){
    dynamicArray->arrayPtr[index] = value;
}

void dynamicArrayPrint(dynamicArray_t* dynamicArray){
    for (int i = 0; i < dynamicArray->usedSize; i++)
    {
        printf("DynamicArray[%d] = %d\n", i, dynamicArray->arrayPtr[i]);
    }
}

void dynamicArrayClean(dynamicArray_t* dynamicArray){
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