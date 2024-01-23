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

// Returns the address of the new stringList_t
stringList_t* newString(char* strPtr);

// Returns the address of a char array with the same content as the stringList_t
char* stringToCharPtr(stringList_t* string);

// Concatenates the content of string2 into string1
void stringConcatenation(stringList_t* string1, stringList_t* string2); 

// Concatenates the content of stricharPtrng2 into string
void stringConcCharPtr(stringList_t* string, char* charPtr);

// If the content of both stringList_t are equals return 1, else return 0
int stringComparation(stringList_t *string1, stringList_t *string2);

// Changes the content of stringPaste to be the same as stringCopy
void stringCopy(stringList_t *stringCopy, stringList_t *stringPaste);

// Returns a array of stringList_t* with the parts of string divided by separator
stringList_t **stringSplit(stringList_t *string, char separator, int *arrayLength);

// Changes the content of string to be the same as charPtr
void stringSet(stringList_t* string, char* charPtr);

// returns a stringList_t* with the same content as the string in a specific range of indices
stringList_t *stringGetInterval(stringList_t *string, int indexStart, int indexEnd);

// Returns the address of the new stringList_t with the reversed content of the string
stringList_t *stringReverse(stringList_t *string);

// Prints on the terminal the content of the string
void stringPrint(stringList_t* string);

// frees the stringList_t
void stringDelete(stringList_t* string);