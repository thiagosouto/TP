#ifndef incrudes
#define incrudes

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#endif


#ifndef executor
#define executor

/*função para rodar o codigo na forma em que seja possivel
 *usar cada ordenador de forma separada e com vetores de tamanho
 * e ordem diferente.
*/
void execucao_normal();

/*função para rodar o codigo com todos as formas de ordenação implementada
 *com varias entradas e gera na tela e em um arquivo uma tabela
 *com a media, mediana e variancia do tempo de execuçao dos modelos
*/
void execucao_tabela();

#endif
