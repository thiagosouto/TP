#ifndef inteligencia
#define intelifencia


//-------------------------------------FUNÇOES DE ARMAZENAMENTO-------------------------
void criar_mala(Mala* mala);
/*Funcao para criar e setar a composicao e os valores da mala que vai ter as bombas
 *
 *
 *param: a string com o nome do arquivo com a composicao, nome do arquivo com as configuracao o ponteiro da Mala
*/

void destruir_mala(Mala* mala);
/*funcao para desalocar as malas.
 *
 *param: recebe um ponteiro da mala que deseja desalocar
*/

void criar_composicao(char* nome_arq_composicao, Mala* mala);
/*Funcao para dar free memoria da composicao que recebe;
 *
 *param: recebe o ponteiro da struct composicao e coloca os valores na composicao
*/

int quantidade_configuracao(char* nome_arq_configuracao);
/*Descobre quantas configuraçoes tem no arquivo.
 *
 *param: nome do arquivo.
 *return: a quantidade de configuraçoes tem no arquivo
*/

void alocar_bomba(Mala* mala,int quantidade);
/*funcao para alocar memoria para matriz das bombas
 *
 *param:recebe da ponteiros mala,, e quantidade de bombas daquela cor
*/
void desalocar_bomba(Mala* malaa, int quantidade);
/*funcao para dar free na matriz das bombas
 *
 *param:recebe da ponteiros mala que quer desalocar, e quantidade de bombas daquela cor
*/

void quantidade_bomba(char* nome_arq_configuracao, int quantidade_de_configuracao, int* vet_quantidade);
/*Descobre quantas bombas configuraçoes.
 *
 *return:nome do arquvivo, a quantidade de configuraçoes tem no arquivo, e local para guardala.
*/

void criar_configuracoes(Mala* mala, FILE* arq_configuracao,int quantidade_de_bombas);
/*Funcao para alocar e definir as bombas e quais locais ele pertence.
  *
  *param: o ponteiro para a mala e o do arquivo e qantas bombas tem no arquivo.
 */

//------------------------------------------FUNÇOES DE VERIFICAÇÃO----------------------------------------

void verificar_quantidade(Mala *mala);
/*Funçao para verificar se a quantidade de bombas na configuração e a mesma da passada pela composicao.
 *
 *param: recebe um ponteiro para mala.
*/

void verificar_configuracao(Mala *mala);
/*Funcao para verificar se a quantidade de tipos de bombas sao iguais.
 *
 * param: recebe o ponteiro de mala;
*/

void verificar_max_espaco(Mala* mala , int quantidade_de_bombas);
/*Funcao para verificar se somando todos os espaços da bomba fica maior que o
 *aceitavel que é 6x6=36
 *
 *param: recebe o ponteiro de mala e quantas bombas tem na mala;
*/

void verificar_tamanho(Mala* mala,int quantidade_de_bombas);
/*Funçao que verifica se nenhuma bomba extrapola o tamanho da mala que é 6x6
 *
 *param: recebe o ponteiro da mala e a quantidade de bombas
*/

void verificar_tamanho_bomba(Mala *mala,int quantidade_de_bombas);
/*Funçao que verifica se nenhuma bomba tem o modulo maior que o tamanho passado por parametro
 *
 *param: recebe o ponteiro da mala e a quantidade de bombas
*/

void verificar_posicao_repetida(Mala *mala);
/*Funçao que verifica se tem alguma bomba em cima da outra
 *
 *
 *param: recebe o ponteiro da mala
*/

void verificar_proximidade(Mala* mala);
/*Funçao que verifica se nenhuma bomba tem outra de mesmo tipo no seus polos ou laterais
 *
 *param: recebe o ponteiro da mala
*/

void verificar_meio(Mala* mala);
/*Funçao que verifica se nenhuma bomba de tamanho 3 tem o meio encostando em alguma coisa
 *
 *param: recebe o ponteiro da mala
*/

void resposta(Mala* mala,FILE *arq_resposta);
/*Funçao para gerar resposta no arquivo, se e valida ou não.
 *
 *param: recebe a mala, recebe o ponteiro do arquivo que vai imprimir e se foi valida ou nao.
*/

#endif
