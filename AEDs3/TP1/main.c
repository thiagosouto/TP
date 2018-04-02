#include "main.h"
#include "inteligencia.h"


int main(int argc, char *argv[])
{
    Mala mala;
    int quantidades_configuracao = 0, i = 0;
    int* quant_bomba;

    FILE *arq_resposta = fopen("saidaTP1.txt", "w");
    FILE *arq_configuracao = fopen(argv[2], "r");

    if(arq_configuracao == NULL)
    {
        printf("Problema para abrir configuracao\n");
        return 0;

    }

    if(arq_resposta == NULL)
    {
        printf("Problema para abrir ou criar arquivo de resposta\n");
        return 0;
    }



    criar_mala(&mala);

    criar_composicao(argv[1], &mala);

    quantidades_configuracao = quantidade_configuracao(argv[2]);

    quant_bomba = malloc(quantidades_configuracao * sizeof (int));


    quantidade_bomba(argv[2], quantidades_configuracao, quant_bomba);



    while(quantidades_configuracao)
    {

        mala.configuracao= malloc (15 * sizeof (char));
        alocar_bomba(&mala,quant_bomba[i]);
        criar_configuracoes(&mala,arq_configuracao,quant_bomba[i]);



        verificar_quantidade(&mala);

        verificar_max_espaco(&mala,quant_bomba[i]);

        verificar_configuracao(&mala);

        verificar_tamanho(&mala,quant_bomba[i]);

        verificar_tamanho_bomba(&mala,quant_bomba[i]);

        verificar_posicao_repetida(&mala);

        verificar_proximidade(&mala);

        verificar_meio(&mala);



        resposta(&mala ,arq_resposta);

        desalocar_bomba(&mala,quant_bomba[i]);
        free(mala.configuracao);
        quantidades_configuracao--;
        i++;

    }

    fclose(arq_configuracao);
    fclose(arq_resposta);
    free(quant_bomba);
    destruir_mala(&mala);

    return 0;
}
