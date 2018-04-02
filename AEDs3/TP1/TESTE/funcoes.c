#include "main.h"
#include "funcoes.h"


void lerArqSTR(char *mensagem, FILE *arquivo)
{//*
    fscanf(arquivo,"%s", mensagem); //pega a string do arquivo e coloca na variavel

    //*/
    return;
}

void lerArqINT(int *quantidade_arquivo_procura, FILE *arquivo)
{//*
    fscanf(arquivo,"%d", quantidade_arquivo_procura);//pega a int do arquivo e coloca na variavel

    //*/
    return;
}

int arquivo_vazio(char* arquivo)
{//*
    FILE *file = fopen(arquivo, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END); //
    int size = ftell(file);
    fclose(file);
    //*/
    return size;
}

void alocar_composicao(Composicao* composicao)
{//*
    int i;

    composicao->Az = malloc (3 * sizeof (char));
    composicao->Vm = malloc (3 * sizeof (char));
    composicao->Am = malloc (3 * sizeof (char));
    composicao->Vd = malloc (3 * sizeof (char));
    for(i = 0;i < 3; i++)
    {
        composicao->Az[i] = 0;
        composicao->Vm[i] = 0;
        composicao->Am[i] = 0;
        composicao->Vd[i] = 0;
    }

    composicao->quantidade_de_bombas = 0;
    //*/
    return;
}

void desalocar_composicao(Composicao* composicao)
{//*
    free(composicao->Az);
    free(composicao->Am);
    free(composicao->Vm);
    free(composicao->Vd);

    //*/
    return;
    free(composicao);

}

void ler_composicao(Composicao* composicao, char* tipo, int quantidade)
{//*
    int indice = tipo[1]+tipo[2];


    switch (indice)
    {

        case 187:
            composicao->Az[tipo[0]-49] += quantidade ;
            composicao->quantidade_de_bombas += quantidade;
        break;

        case 174:
            composicao->Am[tipo[0]-49] += quantidade ;
            composicao->quantidade_de_bombas += quantidade;
        break;

        case 186:
            composicao->Vd[tipo[0]-49] += quantidade ;
            composicao->quantidade_de_bombas += quantidade;
        break;

        case 195:
            composicao->Vm[tipo[0]-49] += quantidade ;
            composicao->quantidade_de_bombas += quantidade;
        break;


    }



    //*/
    return;

}
