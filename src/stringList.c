#include <stdio.h>
#include <stdlib.h>
#include "../include/stringList.h"

stringList_t* newString(char* strPtr){
    stringList_t* string = (stringList_t*) malloc(sizeof(stringList_t));
    string->head = NULL;
    string->end = NULL;
    string->length = 0;

    if (*strPtr == '\0')
    {
        return string;
    }

    nodeStringList_t* node;
    while (*strPtr != '\0')
    {
        node = (nodeStringList_t*) malloc(sizeof(nodeStringList_t));
        node->value = *strPtr;
        node->next = NULL;
        if (string->length == 0)
        {
            string->head = node;
            string->end = node;
        }else
        {
            string->end->next = node;
            string->end = node;
        }
        string->length++;

        strPtr++;
    }
    return string;
}

char* stringToCharPtr(stringList_t* string){
    char* charPtr = (char*)malloc((string->length + 1) * sizeof(char));
    nodeStringList_t* node = string->head;
    for (int i = 0; i < string->length; i++)
    {
        *charPtr = node->value;
        //printf("%c", *charPtr);
        node = node->next;
        charPtr++;
    }
    *charPtr = '\0'; //atualmente ta apontando pro ultimo elemento ('\0')
    return charPtr - string->length; // retorna o endereco do primeiro elemento
}

void stringPrint(stringList_t* string){
    nodeStringList_t* node = string->head;
    for (int i = 0; i < string->length; i++)
    {
        printf("%c",node->value);
        node = node->next;
    }
    printf("\n");
}