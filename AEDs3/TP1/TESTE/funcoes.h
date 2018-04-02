#ifndef funcao
#define funcao


void lerArqSTR(char *mensagem, FILE *arquivo);
/*Funcao para ler o string do arquivo que o usuario mandar
 *
 *param: string para guardar o valor e o nome do arquivo
*/

void lerArqINT(int *quantidade, FILE *arquivo);
/*Funcao para ler o string do arquivo que o usuario mandar
 *
 *param: string para guardar o valor e o nome do arquivo
*/

int arquivo_vazio(char* arquivo);
/*Verifica se o arquivo esta vAzio.
 *
 *parAm: recebe o nome do arquivo que deseja abrir
 *
 *return: 0 se o arquivo estiver vAzio, ou qualquer outro valor se não estiver vAzio.
*/

void alocar_composicao(Composicao* composicao);
/*Funcao para alocar memoria da composicao que recebe;
 *
 *param: recebe o ponteiro da struct composicao e coloca os valores na composicao
*/

void desalocar_composicao(Composicao* composicao);
/*Funcao para setar os valores da composicao que recebe;
 *
 *param: recebe o ponteiro da struct composicao e coloca os valores na composicao
*/

void ler_composicao(Composicao* composicao, char* tipo, int quantidade);

/*Funcao que ler um arquivo de composicao e guarda dentro de uma composicao
 *
 *pama: recebe um ponteiro de composicao, uma string com o tipod a bomba e a quantidade
*/



#endif
