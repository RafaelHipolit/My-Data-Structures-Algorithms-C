#pragma once

typedef struct nodeStack
{
    int value;
    struct nodeStack* previous;
}nodeStack_t;


typedef struct stack
{
    nodeStack_t* end;
    int size;
}stack_t;

stack_t* newStack();
void stackPush(stack_t*, int value);
int stackPop(stack_t* s);
int* stackToArray(stack_t* stack);
void stackDelete(stack_t* stack);
void stackPrint(stack_t* s);