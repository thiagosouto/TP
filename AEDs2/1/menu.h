#ifndef incrudes
#define incrudes

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#endif


#ifndef fun_menu
#define fun_menu

/* função para definir, de acordo com o usuario, o tamanho que vai ter o vetor
 * que sera ordenado quando o codigo e usado na forma Normal
 *
 * param: recebe o endereço da variavel que
 *        sera usada para definir o tamanho
 *        do vetor que serar ordenado
*/
void defineTamanho(int *tamanho);

/*função menu para escolha de qual variação do quickSort deseja usar
 *
 *param1: ponteiro do vetor que deseja ordenar
 *param2: ponteiro do tamanho do vetor que deseja ordenar
*/
void defineQuick(int *vetor, int *tamanho);

/*função menu para selecionar qual o tipo de vetor o usuario deseja ordenar,
 *se é Aleatorio, Crescente ou Decrescente
 *
 *param1: O ponteiro aonde os valores serao armazenado
 *param2: O ponteiro da variavel que fala o tamanho do vetor
*/
void defineVetor(int *vetor, int *tamanho);

/*Função para imprimir vetor o vetor na tela
 *
 *param1: O ponteiro aonde os valores serao armazenado
 *param2: O ponteiro da variavel que fala o tamanho do vetor
*/
void imprimeVetor(int *vetor, int *tamanho);

/*Função para criar Valores Aleatorios para preencher o vetor
 *
 *param1: O ponteiro aonde os valores serao armazenado
 *param2: O ponteiro da variavel que fala o tamanho do vetor
 *param3: Um int para chaviar o printf para nao demorar muito na hora de gerar tabela
*/
void vetorRandom(int *vetor, int *tamanho, int chave);

/*Função para criar Valores Sequenciais crescente para preencher o vetor
 *
 *param1: O ponteiro aonde os valores serao armazenado
 *param2: O ponteiro da variavel que fala o tamanho do vetor
 *param3: Um int para chaviar o printf para nao demorar muito na hora de gerar tabela
*/
void vetorCrescente(int *vetor, int *tamanho, int chave);

/*Função para criar Valores Sequenciais decrescente para preencher o vetor
 *
 *param1: O ponteiro aonde os valores serao armazenado
 *param2: O ponteiro da variavel que fala o tamanho do vetor
 *param3: Um int para chaviar o printf para nao demorar muito na hora de gerar tabela
*/
void vetorDecrescente(int *vetor, int *tamanho, int chave);

/*Função para grava o vetor ja ordenado,
 *em arquivo
 *
 *param1: O ponteiro aonde os valores estao
 *param2: O ponteiro da variavel que fala o tamanho do vetor
 *param3: Double que recebe o tempo de execuçao do codigo.
*/
void gravaVetorOrdenado(int *vetor, int *tamanho, double tempo_exec);

/*Função para grava o vetor original (sem ordenar),
 *em arquivo
 *
 *param1: O ponteiro aonde os valores estao
 *param2: O ponteiro da variavel que fala o tamanho do vetor
*/
void gravaVetorOriginal(int *vetor, int *tamanho);

/*Função para calcular o desvio padrao do tempo de execução do codigo
 *
 *param1:o vetor com os tempos de execução
 *param2:a media dos tempos de execução
 *param3:o tamanho do vetor de tempos de execução
 *
 *return: envia um double com o desvio padrao do vetor ordenado recebido
 *
*/
double desvio_padrao(double *vetor_tempo ,double media_tempo, int tamanho);

/*Funçao que gera uma tabela com o tempo de execução com varios tipos de vetores
 *com o do quickSort puro
 *
 *param1: um ponteiro de arquivo para imprimir no a tabela no arquivo
 *param2: uma chave para o tipo de vetor que vai ordenar
 *
*/
void Tab_quick(FILE *arquivo,int tipo,int repeticao);

/*Funçao que gera uma tabela com o tempo de execução com varios tipos de vetores
 *com o do quickSort Mediana
 *
 *param1: um ponteiro de arquivo para imprimir no a tabela no arquivo
 *param2: uma chave para o tipo de vetor que vai ordenar
 *
*/
void Tab_quickMediana(FILE *arquivo,int tipo,int repeticao);

/*Funçao que gera uma tabela com o tempo de execução com varios tipos de vetores
 *com o do quickSort Insertion
 *
 *param1: um ponteiro de arquivo para imprimir no a tabela no arquivo
 *param2: uma chave para o tipo de vetor que vai ordenar
 *
*/
void Tab_quickInsertion(FILE *arquivo,int tipo,int repeticao);

/*Funçao que gera uma tabela com o tempo de execução com varios tipos de vetores
 *com o do quickSort Mesclado
 *
 *param1: um ponteiro de arquivo para imprimir no a tabela no arquivo
 *param2: uma chave para o tipo de vetor que vai ordenar
 *
*/
void Tab_quickMesclado(FILE *arquivo,int tipo,int repeticao);

#endif
