#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int vetor[], int inicio, int fim);
void mergeSortRecusao(int vetor[], int inicio, int fim, int esq[], int dir[]);
void merge(int vetor[], int inicio, int meio, int fim, int esq[], int dir[]);
void printVetor(int v[], int tamanho);

void mergeSort(int vetor[], int inicio, int fim){
    if (inicio < fim)
    {
        int meio = (inicio + fim)/2;

        int esqSize = meio - inicio + 1 + 1;
        int* esq = (int*)malloc((esqSize)*sizeof(int));

        int dirSize = fim - meio + 1;
        int* dir = (int*)malloc((dirSize)*sizeof(int));

        mergeSortRecusao(vetor, inicio, meio, esq, dir);
        mergeSortRecusao(vetor, meio+1, fim, esq, dir);

        if (vetor[meio] > vetor[meio+1])
        {
            merge(vetor, inicio, meio, fim, esq, dir);
        }
        
           

        free(esq);
        free(dir);   
    }
    
}

void mergeSortRecusao(int vetor[], int inicio, int fim, int esq[], int dir[]){
    if (inicio < fim)
    {
        int meio = (inicio + fim)/2;
        mergeSortRecusao(vetor, inicio, meio, esq, dir);
        mergeSortRecusao(vetor, meio+1, fim, esq, dir);

        if (vetor[meio] > vetor[meio+1])
        {
            merge(vetor, inicio, meio, fim, esq, dir);
        }      
    }
    
}

void merge(int vetor[], int inicio, int meio, int fim, int esq[], int dir[]){
    int esqSize = meio - inicio + 1 + 1;

    int dirSize = fim - meio + 1;

    for (int i = 0; i < esqSize; i++)
    {
        esq[i] = vetor[inicio + i];
    }
    esq[esqSize-1] = __INT_MAX__;
    //printf("esq=");
    //printVetor(esq,esqSize);

    for (int i = 0; i < dirSize; i++)
    {
        dir[i] = vetor[meio + 1 + i];
    }
    dir[dirSize-1] = __INT_MAX__;
    //printf("dir=");
    //printVetor(dir,dirSize);

    int j = 0;
    int k = 0;
    for (int i = 0; i < fim - inicio + 1; i++)
    {
        if (esq[j] <= dir[k])
        {
            vetor[inicio + i] = esq[j];
            j++;
        }else
        {
            vetor[inicio + i] = dir[k];
            k++;
        }
        
        
    }
    //printVetor(vetor,6);
    
}

void printVetor(int v[], int tamanho) {

    for (int i = 0; i < tamanho; i++)
        {
            printf("%i, ",v[i]);
        }
    printf("\n");
}

int organized(int vetor[], int tamanho){

    int organizado = 1;
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i-1] > vetor[i])
        {
            organizado = 0;
            break;
        }
        
    }

    if (organizado)
    {
        printf("Organizado!\n");
    }else{
        printf("Nao ordenado :(\n");
    }
    
    return organizado;

}

int main(){ 
    int size = 100000000;
    //int size = 10;
    int* vetor = (int*)malloc((size)*sizeof(int));

    srand((unsigned int) clock());
    for (int i = 0; i < size; i++)
    {
        vetor[i] = rand();
    }
    printf("gerado\n");
    //printVetor(vetor,size);

    clock_t start ,end;
    double intevalo;

    start = clock();
    mergeSort(vetor,0,size-1);
    end = clock();

    intevalo = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n",intevalo);

    //printVetor(vetor,size);
    printf("verificando...");
    organized(vetor,size);

    return 0;
}