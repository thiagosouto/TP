
#ifndef incrudes
#define incrudes

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_ALFABETO 25

#endif

//-------------------------------------------
#ifndef no
#define no
/*Declaraçao de struct com os nos da arvore e seus elementos
 *
*/
typedef struct No *Apontador;

typedef struct No
{
    char letra;
    int isPalavra;
    Apontador alfabeto[TAM_ALFABETO];
} No;

typedef Apontador raiz;

#endif


//--------------------------------------
#ifndef arvri
#define arvri

/*Funçao para saber se a arvore toda é vazia
 *(so funciona com o primeira folha que é sempre vazia)
 *
 *resp.: um inteiro 0 para falso e 1 para verdadeiro
 *
 *param: recebe a raiz da arvore
*/

int isArvore_vazia(raiz raiz_arvore);

/*Funçao para percorrer a arvore com o caminho que o usuario envio no arquivo,
 *
 *param: a palavra que o usuario quer pesquisar na arvore,
 *e a raiz da arvore completa de busca
 *
*/

void percorrer_arvore(char *arq_procura, raiz raiz_arvore);


/*funçao para percorrer a arvore de forma recursiva, depois que ja se definil
 *a ultima raiz de onde o usuario que pesquiaser
 *
 *param: o no de de onde esta a ultima pesquisa, o vetor para concatenar as letras para imprimir,
 * e o tamanho que o vetor de imprimir tem
*/

void percorrer_arvore_recursivo(raiz raiz_arvore,char *imprimir, int tam_imprimir);

/*função para setar todos os ponteiros da folha da arvore
 *
 *param: o no que é a folha
 *
*/

void setArvore(raiz raiz_arvore);

/*função verificar a palavra que o usuario vai entrar se ele esta nos parametro certo
e se nao estiver ele coloca para poder usar na arvore
 *
 *param: recebe a string que vai ser colocada na arvore
 * e a raiz da arvore para enviar na recursao
 *
*/

void verifica_palavra(char *palavra, raiz raiz_arvore);

/*função para preencher recursivamente a arvore com o arquivo que o usuario entrar
 *
 *param: recebe a string que vai ser colocada na arvore
 * e a raiz da arvore
 *
*/

void recurs_prencher(raiz raiz_arvore, char *palavra);

#endif
