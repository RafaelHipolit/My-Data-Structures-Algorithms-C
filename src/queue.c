#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

queue_t* newQueue(){
    queue_t* q = (queue_t*) malloc(sizeof(queue_t));
    q->head = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
}

void queueEnqueue(queue_t* q, int value){
    nodeQueue_t* node = (nodeQueue_t*) malloc(sizeof(nodeQueue_t));
    node->value = value;
    node->next= NULL;
    if (q->size == 0)
    {
        q->head = node;
        q->end = node;
    }else
    {
        q->end->next = node;
        q->end = node;
    }
    q->size++;
}

int queueDequeue(queue_t* q){
    if (q->size == 0)
    {
        return -1; //erro
    }else if (q->size == 1)
    {
        int v = q->head->value;
        free(q->head);
        q->end = NULL;
        q->head = NULL;
        q->size--;
        return v;
    }else
    { 
        int v = q->head->value;
        nodeQueue_t* newHead = q->head->next;
        free(q->head);
        q->head = newHead;
        q->size--;
        return v;
    }
}

int* queueToArray(queue_t* queue){
    int* arr = (int*)malloc(queue->size * sizeof(int));
    nodeQueue_t* node = queue->head;
    for (int i = 0; i < queue->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    return arr;
}

void queuePrint(queue_t* q){
    printf("Queue with %d values\n", q->size);
    nodeQueue_t* node = q->head;
    for (int i = 0; i < q->size; i++)
    {
        printf("list[%d] = %d\n",i,node->value);
        node = node->next;
    }
}

void queueDelete(queue_t* queue){
    for (int i = 0; i < queue->size; i++)
    {
        queueDequeue(queue);
    }
    free(queue);
}