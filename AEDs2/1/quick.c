#include "quick.h"
#include "insertion.h"

void quickSort(int *vetor, int esquerda, int direita)
{
    int i, j;
    int pivo, y;
    i = esquerda; j = direita;
    pivo = *(vetor+(esquerda+direita)/2);   //escolhe o vetor pelo metade da parte do vetor que vai ordenar

    do{
        while(*(vetor+i) < pivo && i < direita)
            i++;
        while(pivo < *(vetor+j) && j > esquerda)
            j--;
        if(i <= j)
        {
            y = *(vetor+i);
            *(vetor+i) = *(vetor+j);
            *(vetor+j) = y;
            i++;
            j--;
        }
    }while(i <= j);

    if(esquerda < j)            //empilha a funçao na recursividade
        quickSort(vetor, esquerda, j);
    if(i < direita)
        quickSort(vetor, i, direita);
    return;
}

void quickSortDOUBLE(double *vetor, int esquerda, int direita)
{
    //mesma coisa que a funçao anterior porem essa funçao e para ordenar numero fracionarios
    int i, j;
    double pivo, y;
    i = esquerda; j = direita;
    pivo = *(vetor+(esquerda+direita)/2);

    do{
        while(*(vetor+i) < pivo && i < direita)
            i++;
        while(pivo < *(vetor+j) && j > esquerda)
            j--;
        if(i <= j)
        {
            y = *(vetor+i);
            *(vetor+i) = *(vetor+j);
            *(vetor+j) = y;
            i++;
            j--;
        }
    }while(i <= j);

    if(esquerda < j)
        quickSortDOUBLE(vetor, esquerda, j);
    if(i < direita)
        quickSortDOUBLE(vetor, i, direita);
    return;
}

void quickSortMediana(int *vetor, int esquerda, int direita)
{
    int i, j;
    int pivoaAux[3],pivo, y;
    i = esquerda; j = direita;
    pivoaAux[0] = *(vetor+(esquerda+direita)/2);
    pivoaAux[1] = *(vetor+(((esquerda+direita)/2)+1));
    pivoaAux[2] = *(vetor+(((esquerda+direita)/2)-1));

    if( (pivoaAux[0] >= pivoaAux[1] && pivoaAux[2] >= pivoaAux[0]) || (pivoaAux[0] >= pivoaAux[2] && pivoaAux[1] >= pivoaAux[0]) )
        {
        pivo = pivoaAux[0];
        }
    else if( (pivoaAux[1] >= pivoaAux[0] && pivoaAux[2] >= pivoaAux[1]) || (pivoaAux[1] >= pivoaAux[2] && pivoaAux[0] >= pivoaAux[1]) )
        {
        pivo = pivoaAux[1];
        }
    else if( (pivoaAux[2] >= pivoaAux[0] && pivoaAux[1] >= pivoaAux[2]) || (pivoaAux[2] >= pivoaAux[1] && pivoaAux[0] >= pivoaAux[2]) )
        {
        pivo = pivoaAux[2];
    }  //escolhedo o pivo de forma de mediana

    do{
        while(*(vetor+i) < pivo && i < direita)
            i++;
        while(pivo < *(vetor+j) && j > esquerda)
            j--;
        if(i <= j){
            y = *(vetor+i);
            *(vetor+i) = *(vetor+j);
            *(vetor+j) = y;
            i++;
            j--;
        }
    }while(i <= j);

    if(esquerda < j)
        quickSortMediana(vetor, esquerda, j);
    if(i < direita)
        quickSortMediana(vetor, i, direita);
    return;
}

void quickSortMesclado(int *vetor, int esquerda, int direita)
{

    int i, j;
    int pivoaAux[3],pivo, y;
    i = esquerda; j = direita;
    pivoaAux[0] = *(vetor+(esquerda+direita)/2);
    pivoaAux[1] = *(vetor+(((esquerda+direita)/2)+1));
    pivoaAux[2] = *(vetor+(((esquerda+direita)/2)-1));

    if( (pivoaAux[0] >= pivoaAux[1] && pivoaAux[2] >= pivoaAux[0]) || (pivoaAux[0] >= pivoaAux[2] && pivoaAux[1] >= pivoaAux[0]) )
        {
        pivo = pivoaAux[0];
        }
    else if( (pivoaAux[1] >= pivoaAux[0] && pivoaAux[2] >= pivoaAux[1]) || (pivoaAux[1] >= pivoaAux[2] && pivoaAux[0] >= pivoaAux[1]) )
        {
        pivo = pivoaAux[1];
        }
    else if( (pivoaAux[2] >= pivoaAux[0] && pivoaAux[1] >= pivoaAux[2]) || (pivoaAux[2] >= pivoaAux[1] && pivoaAux[0] >= pivoaAux[2]) )
        {
        pivo = pivoaAux[2];
        }  //escolher o melhor pivo mediano

    do{
        while(*(vetor+i) < pivo && i < direita)
            i++;
        while(pivo < *(vetor+j) && j > esquerda)
            j--;
        if(i <= j){
            y = *(vetor+i);
            *(vetor+i) = *(vetor+j);
            *(vetor+j) = y;
            i++;
            j--;
        }
    }while(i <= j);

    if(( (direita - esquerda ) <= 5 ) ){   //e sair do quick quando tiver pequeno e quase ordenado e entrar no insertion.
        return;
    }
    else if(esquerda < j)
    {
        quickSortMesclado(vetor, esquerda, j);
    }
    else if(i < direita)
    {
        quickSortMesclado(vetor, i, direita);
    }
    return;
}

void quickSortInsertion(int *vetor, int esquerda, int direita)
{
    int i, j;
    int pivo, y;
    i = esquerda; j = direita;
    pivo = *(vetor+(esquerda+direita)/2);

    do{
        while(*(vetor+i) < pivo && i < direita)
            i++;
        while(pivo < *(vetor+j) && j > esquerda)
            j--;
        if(i <= j){
            y = *(vetor+i);
            *(vetor+i) = *(vetor+j);
            *(vetor+j) = y;
            i++;
            j--;
        }
    }while(i <= j);

    if(( (direita - esquerda ) <= 5 ) ){  //comparação para sair do quicksort e entrar no insertion
        return;
    }
    else if(esquerda < j)
    {
        quickSortInsertion(vetor, esquerda, j);
    }
    else if(i < direita)
    {
        quickSortInsertion(vetor, i, direita);
    }
    return;
}
