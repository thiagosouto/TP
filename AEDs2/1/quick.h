#ifndef incrudes
#define incrudes

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#endif


#ifndef Funcao_quick
#define Funcao_quick

/* QuickSort tradicional que usa um pivo na metade do vetor recebido
 *param 1: ponteiro de int com o primeiro
 *param 2: int com o indice da direita dp vetor
 *param 3: int com o indice da esquerda do vetor
*/
void quickSort(int *vetor, int esquerda, int direita);

/* QuickSort que usa a chave antes e a chave depois para escolher um melhor pivo
 *param 1: ponteiro de int com o primeiro
 *param 2: int com o indice da direita dp vetor
 *param 3: int com o indice da esquerda do vetor
*/
void quickSortMediana(int *vetor, int esquerda, int direita);

/* QuickSort que usa o Insertion quando o vetor esta quase todo ordenado.
 *param 1: ponteiro de int com o primeiro
 *param 2: int com o indice da direita dp vetor
 *param 3: int com o indice da esquerda do vetor
*/
void quickSortInsertion(int *vetor, int esquerda, int direita);

/* QuickSort que usa o Insertion quando o vetor esta quase todo organizado e
 *tamebm usa o metodo de mediana para usar um melhor pivo.
 *param 1: ponteiro de int com o primeiro
 *param 2: int com o indice da direita dp vetor
 *param 3: int com o indice da esquerda do vetor
*/
void quickSortMesclado(int *vetor, int esquerda, int direita);

/* QuickSort tradicional porem ordena vetor double .
 *param 1: ponteiro de int com o primeiro
 *param 2: int com o indice da direita dp vetor
 *param 3: int com o indice da esquerda do vetor
*/
void quickSortDOUBLE(double *vetor, int esquerda, int direita);

#endif
