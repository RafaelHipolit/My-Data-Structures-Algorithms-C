#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/linkedList.h"
#include "../include/sortAlgorithms.h"


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

int main(){
    printf("Hello world!\n");

    linkedList_t* list = newLinkedList();
    listAddEnd(list, 10);
    listAddEnd(list, 1);
    listAddEnd(list, 5);
    listAddEnd(list, 7);
    listAddEnd(list, 14242);
    listAddEnd(list, 2);
    ListPrint(list);
    listSort(&list);

    int a[16] = {165,651,56,1,51,6,21,218,5,15,1,351,21,5,31,5};
    linkedList_t* l = newLinkedListFromArray(a,16);
    //ListPrint(l);
    ListPrint(l);
    listSort(&l);//PQ ISSO NAO FUNCIONA???????????????
    return 0;
}
