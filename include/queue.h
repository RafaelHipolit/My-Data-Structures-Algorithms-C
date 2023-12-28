#pragma once

typedef struct nodeQueue
{
    int value;
    struct nodeQueue* next;
}nodeQueue_t;


typedef struct queue
{
    nodeQueue_t* head;
    nodeQueue_t* end;
    int size;
}queue_t;

queue_t* newQueue();
void queueEnqueue(queue_t* q, int value);
int queueDequeue(queue_t* q);
void queuePrint(queue_t* q);