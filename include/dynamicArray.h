#pragma once

#define INITIAL_SIZE 2

#define INCREASE_FACTOR 2

#define DECREASE_FACTOR 1/4

typedef struct dynamicArray
{
    int usedSize;
    int maxSize;
    int* arrayPtr;
}dynamicArray_t;

dynamicArray_t* newDynamicArray();

int dynamicArraySize(dynamicArray_t* dynamicArray);

void dynamicArrayAddEnd(dynamicArray_t* dynamicArray, int value);

int dynamicArrayRemoveEnd(dynamicArray_t* dynamicArray);

void dynamicArrayAddAtIndex(dynamicArray_t* dynamicArray, int value, int index);

int dynamicArrayRemoveAtIndex(dynamicArray_t* dynamicArray, int index);

int dynamicArrayGet(dynamicArray_t* dynamicArray, int index);

void dynamicArraySet(dynamicArray_t* dynamicArray, int value, int index);

void dynamicArrayPrint(dynamicArray_t* dynamicArray);

void dynamicArrayClear(dynamicArray_t* dynamicArray);

int* dynamicArrayToArray(dynamicArray_t* dynamicArray);

void dynamicArrayDelete(dynamicArray_t* dynamicArray);