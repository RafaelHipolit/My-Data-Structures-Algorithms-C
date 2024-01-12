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
void stringPrint(stringList_t* string);
char* stringToCharPtr(stringList_t* string);
stringList_t* stringGetInterval(stringList_t* string, int positionStart, int positionEnd);
stringList_t *stringReverse(stringList_t *string);


