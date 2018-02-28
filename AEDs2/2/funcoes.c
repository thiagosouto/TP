#include "funcoes.h"

void lerArqSTR(char *mensagem, FILE *arquivo)
{
    fscanf(arquivo,"%s", mensagem); //pega a string do arquivo e coloca na variavel
    return;
}

void conferir_palavra(char *mensagem)
{
    int i,j;
    for(i = 0; i < TAM_PALAVRA; i++)
    {
        if(mensagem[i] < 65 || mensagem[i] > 90)//verifica se a palavra esta dentro do escopo definido
        {
            while((mensagem[i] >= 1 && mensagem[i] < 65) || (mensagem[i] > 90 && mensagem[i] <= 255) )//anda com todos os vetores 
            {
                for(j = i; j < TAM_PALAVRA; j++)
                {
                    mensagem[j]=mensagem[j+1];
                }
            }
        }
    }
    return;
}

void lerArqINT(int *quantidade_arquivo_procura, FILE *arquivo)
{
    fscanf(arquivo,"%d", quantidade_arquivo_procura);//pega a int do arquivo e coloca na variavel

    return;
}

int get_size(char* arquivo)
{
    FILE *file = fopen(arquivo, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}
