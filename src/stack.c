#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

stack_t* newStack(){
    stack_t* s = (stack_t*) malloc(sizeof(stack_t));
    s->end = NULL;
    s->size = 0;
    return s;
}

void stackPush(stack_t* s, int value){
    nodeStack_t* node = (nodeStack_t*) malloc(sizeof(nodeStack_t));
    node->value = value;
    if (s->size == 0)
    {
        s->end = node;
        node->previous = NULL;
    }else
    {
        node->previous = s->end;
        s->end = node;
    }
    s->size++;
}

int stackPop(stack_t* s){
    if (s->size == 0)
    {
        return -1;
    }
    nodeStack_t* node = s->end;
    int v = node->value;
    s->end = s->end->previous;
    free(node);
    s->size--;
    return v;
}

void stackPrint(stack_t* s){
    nodeStack_t* node = s->end;
    for (int i = s->size - 1; i >= 0; i--)
    {
        printf("Stack[%d] = %d\n",i,node->value);
        node = node->previous;
    }
    
}