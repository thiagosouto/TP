#ifndef incrudes
#define incrudes

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_ALFABETO 27

#endif

//-------------------------------------------
#define TAM 500
#define TAM2 5
#define TAM_PALAVRA 30

//--------------------------------------------
#ifndef funcao
#define funcao

/*funçao que verifica o tamanho do arquivo que o usuario entrou
 *
 *resp.: o tamanho do arquivo que o usuario entrou
 *
 *param: o nome do arquivo que usuario quer contar
*/

int get_size(char* arquivo);

/*funçao para ler o inteiro do arquivo que o usuario mandar
 *
 *param: inteiro para guardar o valor e o nome do arquivo
 *
 *
*/

void lerArqINT(int *quantidade, FILE *arquivo);

/*funçao para ler o string do arquivo que o usuario mandar
 *
 *param: string para guardar o valor e o nome do arquivo
 *
 *
*/

void lerArqSTR(char *mensagem, FILE *arquivo);

/*verifica se a palavra que o usuario digitou realmente esta dentro dos parametros da arvore
 *
 *param: string com a palavra do arquivo
 *
 *
*/

void conferir_palavra(char *mensagem);

#endif
