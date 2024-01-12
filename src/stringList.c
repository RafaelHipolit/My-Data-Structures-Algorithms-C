#include <stdio.h>
#include <stdlib.h>
#include "../include/stringList.h"
#include "../include/stack.h"

stringList_t *newString(char *strPtr)
{
    stringList_t *string = (stringList_t *)malloc(sizeof(stringList_t));
    string->head = NULL;
    string->end = NULL;
    string->length = 0;

    if (*strPtr == '\0')
    {
        return string;
    }

    nodeStringList_t *node;
    while (*strPtr != '\0')
    {
        node = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
        node->value = *strPtr;
        node->next = NULL;
        if (string->length == 0)
        {
            string->head = node;
            string->end = node;
        }
        else
        {
            string->end->next = node;
            string->end = node;
        }
        string->length++;

        strPtr++;
    }
    return string;
}

char *stringToCharPtr(stringList_t *string)
{
    char *charPtr = (char *)malloc((string->length + 1) * sizeof(char));
    nodeStringList_t *node = string->head;
    for (int i = 0; i < string->length; i++)
    {
        *charPtr = node->value;
        // printf("%c", *charPtr);
        node = node->next;
        charPtr++;
    }
    *charPtr = '\0';                 // atualmente ta apontando pro ultimo elemento ('\0')
    return charPtr - string->length; // retorna o endereco do primeiro elemento
}

stringList_t *stringGetInterval(stringList_t *string, int positionStart, int positionEnd)
{
    if ((positionStart > positionEnd)||(positionStart < 0)||(positionStart < 0)||(positionStart >= string->length)||(positionEnd >= string->length))
    {
        return NULL;
    }
    
    stringList_t *newString = (stringList_t *)malloc(sizeof(stringList_t));
    newString->head = NULL;
    newString->end = NULL;
    newString->length = 0;

    nodeStringList_t *node = string->head;
    nodeStringList_t *nodeNewString;
    for (int i = 0; i <= positionEnd; i++)
    {
        if (i >= positionStart)
        {
            nodeNewString = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
            nodeNewString->value = node->value;
            nodeNewString->next = NULL;
            if (newString->length == 0)
            {
                newString->head = nodeNewString;
                newString->end = nodeNewString;
            }
            else
            {
                newString->end->next = nodeNewString;
                newString->end = nodeNewString;
            }
            newString->length++;
        }

        node = node->next;
    }

    return newString;
}

stringList_t *stringReverse(stringList_t *string){
    stack_t* stack = newStack();
    nodeStringList_t *node = string->head;
    for (int i = 0; i < string->length; i++)
    {
        stackPush(stack, node->value);
        node = node->next;
    }

    stringList_t *newString = (stringList_t *)malloc(sizeof(stringList_t));
    newString->head = NULL;
    newString->end = NULL;
    newString->length = 0;
    nodeStringList_t *nodeNewString;
    for (int i = 0; i < string->length; i++)
    {
        nodeNewString = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
        nodeNewString->value = stackPop(stack);
        nodeNewString->next = NULL;
        if (newString->length == 0)
        {
            newString->head = nodeNewString;
            newString->end = nodeNewString;
        }
        else
        {
            newString->end->next = nodeNewString;
            newString->end = nodeNewString;
        }
        newString->length++;
    }
    return newString;
}

void stringPrint(stringList_t *string)
{
    nodeStringList_t *node = string->head;
    for (int i = 0; i < string->length; i++)
    {
        printf("%c", node->value);
        node = node->next;
    }
    printf("\n");
}