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

    printf("Endereco da var list da main antes de chama a funcao = %p\n", list);
    listSort(list);
    printf("Endereco da var list da main apos chama a funcao = %p\n", list);
    ListPrint(list);

    int a[16] = {165,651,56,1,51,6,21,218,5,15,1,351,21,5,31,5};
    linkedList_t* l = newLinkedListFromArray(a,16);

    printf("Endereco da var list da main antes de chama a funcao = %p\n", l);
    listSort(l);
    printf("Endereco da var list da main apos chama a funcao = %p\n", l);
    ListPrint(l);
}

void testListCopy(){
    linkedList_t* list = newLinkedList();
    listAddEnd(list, 10);
    listAddEnd(list, 1);
    listAddEnd(list, 5);
    listAddEnd(list, 7);
    listAddEnd(list, 14242);
    listAddEnd(list, 2);

    int a[16] = {165,651,56,1,51,6,21,218,5,15,1,351,21,5,31,5};
    linkedList_t* l = newLinkedListFromArray(a,16);

    ListPrint(list);
    listCopy(l,list);
    ListPrint(list);
}

void testDoublyLinkedList(){
    //TESTAR   
    //doublyLinkedList_t* list = newDoublyLinkedList();
    //iteratorDoublyLinkedList_t* i = newIteratorDoublyLinkedList(list);
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

    int* arr = stackToArray(s);
    for (int i = 0; i < s->size; i++)
    {
        printf("%d\n",arr[i]);
    }

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

    stackDelete(s);

    printf("%d\n",s->end->value);
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

void testString(){
    stringList_t* s1 = newString("abc");
    stringList_t* s2 = newString("123");
    
    stringConcatenation(s1, s2);
    stringPrint(s1);
    stringPrint(s2);
    stringDelete(s1);
    stringDelete(s2);

    stringList_t* s = newString("abc");
    stringPrint(s);
    stringSet(s, "oyasuminasai");
    stringPrint(s);
}

void testLinkedListTime(){
    double intevalo = 0;
    clock_t start, end;
    

    start = clock();
    linkedList_t* l = newLinkedList();
    for (int i = 0; i < 99999; i++)
    {
        listAddEnd(l,i);
    }
    for (int i = 0; i < l->size; i++)
    {
        listSet(l,3,i);
    }
    listDelete(l);
   
    end = clock();

    intevalo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n", intevalo);
}

void testSortTime(){
    int size = 99999999;
    int *vetor1 = (int *)malloc((size) * sizeof(int));

    printf("gerando\n");
    srand((unsigned int)clock());
    int randomNum = 0;
    for (int i = 0; i < size; i++)
    {
        randomNum = rand();
        vetor1[i] = randomNum;

    }

    printf("organizando...\n");
    clock_t start, end;
    double intevalo = 0;

    start = clock();
    quickSort(vetor1, 0, size - 1);
    end = clock();

    intevalo = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n", intevalo);

    //printVetor(vetor1,size);
    printf("verificando... ");
    organized(vetor1, size);
}

void testSplit(){
    stringList_t* s = newString("---a----bbbb----c---------");
    int n = 0;
    stringList_t** arr = stringSplit(s,'-',&n);
    printf("n = %d\n",n);
    for (int i = 0; i < n; i++)
    {
        stringPrint(arr[i]);
    }
}

void testStringComp(){
    printf("%d\n", stringComparation(newString(""),newString("")));
}

void testStringCopy(){
    stringList_t* s = newString("abc");
    stringCopy(newString("delta"),s);
    stringPrint(s);
}

int main(){

    testStack();

    //add delete queue and stack and to array
    
    return 0;
}

