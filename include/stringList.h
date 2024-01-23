#pragma once

typedef struct nodeStringList
{
    char value;
    struct nodeStringList* next;
}nodeStringList_t;

typedef struct stringList
{
    int length;
    nodeStringList_t* head;
    nodeStringList_t* end;
}stringList_t;

stringList_t* newString(char* strPtr);
char* stringToCharPtr(stringList_t* string);

//concatenates the content of string2 into string1
void stringConcatenation(stringList_t* string1, stringList_t* string2); 

void stringConcCharPtr(stringList_t* string, char* charPtr);

int stringComparation(stringList_t *string1, stringList_t *string2);

void stringCopy(stringList_t *stringCopy, stringList_t *stringPaste);

stringList_t **stringSplit(stringList_t *string, char character, int *arrayLength);

void stringSet(stringList_t* string, char* charPtr);
stringList_t* stringGetInterval(stringList_t* string, int positionStart, int positionEnd);
stringList_t *stringReverse(stringList_t *string);
void stringPrint(stringList_t* string);
void stringDelete(stringList_t* string);
