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

void stringConcatenation(stringList_t *string1, stringList_t *string2)
{ // concatenates the content of string2 into string1
    nodeStringList_t *node1 = string1->end;
    nodeStringList_t *node2 = string2->head;
    for (int i = 0; i < string2->length; i++)
    {
        node1->next = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
        node1 = node1->next;
        node1->value = node2->value;
        node1->next = NULL;
        string1->length++;

        node2 = node2->next;
    }
}

void stringConcCharPtr(stringList_t *string, char *charPtr)
{
    nodeStringList_t *node1 = string->end;
    while (*charPtr != '\0')
    {
        node1->next = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
        node1 = node1->next;
        node1->value = *charPtr;
        node1->next = NULL;
        string->length++;

        charPtr++;
    }
}

int stringComparation(stringList_t *string1, stringList_t *string2)
{
    if (string1->length != string2->length)
    {
        return 0;
    }
    nodeStringList_t* node1 = string1->head;
    nodeStringList_t* node2 = string2->head;
    for (int i = 0; i < string1->length; i++)
    {
        if (node1->value != node2->value)
        {
            return 0;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    
    return 1;
}

void stringCopy(stringList_t *stringCopy, stringList_t *stringPaste)
{   
    char* copy = stringToCharPtr(stringCopy);
    stringSet(stringPaste, copy);
    free(copy);
}

stringList_t **stringSplit(stringList_t *string, char character, int *arrayLength){
    int numString = 0;
    nodeStringList_t *node = string->head;
    int achou = 0;
    for (int i = 0; i < string->length; i++)
    {
        if (node->value != character && achou == 0)
        {
            achou = 1;
            numString++;
        }
        if (achou == 1 && node->value == character)
        {
            achou = 0;
        }
        node = node->next;
    }

    stringList_t **stringArray = (stringList_t **)malloc((numString) * sizeof(stringList_t *));
    node = string->head;
    int lastIndex = 0;
    achou = 0;
    for (int i = 0; i < string->length; i++)
    {
        if (node->value != character && achou == 0)
        {
            achou = 1;
            lastIndex = i;
        }
        if (achou == 1 && node->value == character)
        {
            achou = 0;
            *stringArray = stringGetInterval(string, lastIndex, i-1);
            stringArray++;
        }
        node = node->next;
    }

    *arrayLength = numString;
    return stringArray - numString;  // retorna o endereco do primeiro elemento do array
}

void stringSet(stringList_t *string, char *charPtr)
{ // pensar nome melhor
    nodeStringList_t *node = string->head;
    nodeStringList_t *nextNode;
    for (int i = 0; i < string->length; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    string->length = 0;
    string->head = NULL;
    string->end = NULL;

    while (*charPtr != '\0')
    {
        node = (nodeStringList_t *)malloc(sizeof(nodeStringList_t));
        node->value = *charPtr;
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

        charPtr++;
    }

    /*
    //uma opcao um pouco menos eficiente
    stringDelete(s);
    s = newString(charPtr);
    */
}

stringList_t *stringGetInterval(stringList_t *string, int positionStart, int positionEnd)
{
    if ((positionStart > positionEnd) || (positionStart < 0) || (positionStart < 0) || (positionStart >= string->length) || (positionEnd >= string->length))
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

stringList_t *stringReverse(stringList_t *string)
{
    stack_t *stack = newStack();
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

void stringDelete(stringList_t *string)
{
    nodeStringList_t *node = string->head;
    nodeStringList_t *nextNode;
    for (int i = 0; i < string->length; i++)
    {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
    free(string);
}