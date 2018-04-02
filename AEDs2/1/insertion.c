#include "insertion.h"

void insertionSort(int *vetor, int tamanho)
{
    int i, j;
    int key;

    for(j = 1; j < tamanho; ++j)  // percorrer o vetor
    {
        key = vetor[j];
        i = j - 1;
        while(vetor[i] > key && i >= 0) //movimentar o vetor 
        {
            vetor[i+1] = vetor[i];
            --i;
        }
        vetor[i+1]= key;
    }
    return;
}
