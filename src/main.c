#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/linkedList.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/sortAlgorithms.h"
#include "../include/doublyLinkedList.h"
#include "../include/iteratorDoublyLinkedList.h"
#include "../include/stringList.h"


void testList(){
    linkedList_t* list = newLinkedList();
    listAddEnd(list, 5);
    listAddEnd(list, 10);
    listAddEnd(list, 2);
    ListPrint(list);

    listAddAtPosition(list, 84, 0);
    ListPrint(list);

    listAddAtPosition(list, 84, 1);
    ListPrint(list);

    listAddAtPosition(list, 84, 3);
    ListPrint(list);

    listAddAtPosition(list, 84, 5);
    ListPrint(list);

    listAddAtPosition(list, 84, 7);
    ListPrint(list);

    listRemoveAtPosition(list, 0);
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 3));
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 4));
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 4));
    ListPrint(list);
}

void testSort(){
    //int size = 10000000;
    int size = 10000;
    int *vetor1 = (int *)malloc((size) * sizeof(int));
    int *vetor2 = (int *)malloc((size) * sizeof(int));
    int *vetor3 = (int *)malloc((size) * sizeof(int));

    printf("gerando\n");
    srand((unsigned int)clock());
    int randomNum = 0;
    for (int i = 0; i < size; i++)
    {
        randomNum = rand();
        vetor1[i] = randomNum;
        vetor2[i] = randomNum; 
        vetor3[i] = randomNum; 
    }
    
    //printVetor(vetor1,size);

    clock_t start, end;
    double intevalo = 0;



    printf("\nMergeSort\n");

    start = clock();
    mergeSort(vetor1, 0, size - 1);
    end = clock();

    intevalo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n", intevalo);

    //printVetor(vetor1,size);
    printf("verificando... ");
    organized(vetor1, size);




    printf("\nQuickSort\n");

    start = clock();
    quickSort(vetor2, 0, size - 1);
    end = clock();

    intevalo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n", intevalo);

    //printVetor(vetor2,size);
    printf("verificando... ");
    organized(vetor2, size);




    printf("\nInsertionSort\n");

    start = clock();
    insertionSort(vetor3, size);
    end = clock();

    intevalo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n", intevalo);

    //printVetor(vetor3,size);
    printf("verificando... ");
    organized(vetor3, size);
}

void testListSort(){
    linkedList_t* list = newLinkedList();
    listAddEnd(list, 10);
    listAddEnd(list, 1);
    listAddEnd(list, 5);
    listAddEnd(list, 7);
    listAddEnd(list, 14242);
    listAddEnd(list, 2);
    listSort(&list);
    ListPrint(list);

    int a[16] = {165,651,56,1,51,6,21,218,5,15,1,351,21,5,31,5};
    linkedList_t* l = newLinkedListFromArray(a,16);
    listSort(&l);
    ListPrint(l);
}

void testStack(){
    printf("Hello world!\n");

    stack_t* s = newStack();
    stackPush(s,1);
    stackPush(s,1);
    stackPush(s,2);
    stackPush(s,3);
    stackPush(s,5);
    stackPush(s,2);
    stackPrint(s);

    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    printf("pop %d\n",stackPop(s)); 
    stackPrint(s);

    stackPush(s,2);
    stackPrint(s);
}

void testQueue(){
    queue_t* q = newQueue();
    queueEnqueue(q, 1);
    queueEnqueue(q, 453);
    queueEnqueue(q, 345);
    queueEnqueue(q, 43);
    queueEnqueue(q, 4);
    queueEnqueue(q, -9242842);
    queuePrint(q);

    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));
    printf("dequeue %d\n",queueDequeue(q));

    queuePrint(q); 

    queueEnqueue(q, -9242842);
    queuePrint(q);
}

int main(){
    
    //TESTAR   
    //doublyLinkedList_t* list = newDoublyLinkedList();
    //iteratorDoublyLinkedList_t* i = newIteratorDoublyLinkedList(list);




    stringList_t* s = newString("");
    stringPrint(stringReverse(s));
    
    //stringPrint(s);
    //char* s2 = stringToCharPtr(s); 
    //printf("%s\n", s2);

    return 0;
}
