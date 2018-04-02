#include "main.h"
#include "inteligencia.h"
#include <time.h>


int main(int argc, char *argv[])
{

    Mala mala;
    int quantidades_configuracao = 0, i = 0, cont = 1, verificador,verificador2;
    int* quant_bomba;
    char* ca;
    char* cai;
    //double tempo_exec ,tempo_exec2;
     unsigned long int tempo_exec ,tempo_exec2;
    // clock_t c_nomal;    //variavel para guardar o tempo de execução do valor

    struct timespec tempo;
    struct timespec tempo2;


    FILE *arq_resposta = fopen("saidaTP1.txt", "w");
    FILE *arq_tabela = fopen("tabela.txt", "w");


    fprintf(arq_tabela,"quantidade\tvalida(microseg)\tinvalida(micr3seg)\n ");



    if(arq_resposta == NULL)
    {
        printf("Problema para abrir ou criar arquivo de resposta\n");
        return 0;
    }



    criar_mala(&mala);

    criar_composicao(argv[1], &mala);

    while(cont < 15)
    {
        if(cont == 1)
        {
            ca = malloc (30 * sizeof (char));
            ca = "ConfComp/3cf1.txt";
            cai = malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi1.txt";

        }else if(cont == 2)
        {
            ca = malloc (30 * sizeof (char));
            ca = "ConfComp/3cf5.txt";
            cai = malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi5.txt";
        }else if(cont == 3)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf10.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi10.txt";

        }else if(cont == 4)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf20.txt";
            cai= malloc (30 * sizeof (char));
            cai= "ConfComp/3cfi20.txt";

        }else if(cont == 5)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf30.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi30.txt";

        }else if(cont == 6)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf40.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi40.txt";

        }else if(cont == 7)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf50.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi50.txt";

        }else if(cont == 8)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf100.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi100.txt";

        }else if(cont == 9)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf500.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi500.txt";

        }else if(cont ==10 )
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf1000.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi1000.txt";

        }else if(cont ==11 )
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf2500.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi2500.txt";

        }else if(cont ==12 )
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf5000.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi5000.txt";

        }else if(cont == 13)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf7500.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi7500.txt";

        }else if(cont == 14)
        {
            ca= malloc (30 * sizeof (char));
            ca = "ConfComp/3cf10000.txt";
            cai= malloc (30 * sizeof (char));
            cai = "ConfComp/3cfi10000.txt";

        }
        printf("%s\n",ca );
        FILE *arq_configuracao = fopen(ca, "r");

        if(arq_configuracao == NULL)
        {
            printf("Problema para abrir configuracao\n");
            return 0;

        }


        quantidades_configuracao = quantidade_configuracao(ca);

        quant_bomba = malloc(quantidades_configuracao * sizeof (int));

        quantidade_bomba(ca, quantidades_configuracao, quant_bomba);

        fprintf(arq_tabela,"%i\t",quantidades_configuracao );
        verificador = quantidades_configuracao;


        //c_nomal = clock();
        //clock_gettime(CLOCK_REALTIME,&tempo);
        clock_gettime(CLOCK_THREAD_CPUTIME_ID,&tempo);

        while(quantidades_configuracao)
        {
            i = 0;
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



            //resposta(&mala ,arq_resposta);

            desalocar_bomba(&mala,quant_bomba[i]);
            free(mala.configuracao);
            quantidades_configuracao--;
            i++;



        }
        //tempo_exec = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;
        clock_gettime(CLOCK_THREAD_CPUTIME_ID,&tempo2);
        tempo_exec = ((unsigned long int)(tempo2.tv_nsec - tempo.tv_nsec)/1000);


        printf("%s\n",cai );
        FILE *arq_configuracao2 = fopen(cai, "r");

        if(arq_configuracao2 == NULL)
        {
            printf("1Problema para abrir configuracao\n");
            return 0;

        }


        quantidades_configuracao = quantidade_configuracao(cai);
        verificador2 = quantidades_configuracao;
        quant_bomba = malloc(quantidades_configuracao * sizeof (int));


        quantidade_bomba(cai, quantidades_configuracao, quant_bomba);

        //c_nomal = clock();
        //clock_gettime(CLOCK_REALTIME,&tempo);
        clock_gettime(CLOCK_THREAD_CPUTIME_ID,&tempo);

        while(quantidades_configuracao)
        {
            i = 0;
            mala.configuracao= malloc (15 * sizeof (char));
            alocar_bomba(&mala,quant_bomba[i]);
            criar_configuracoes(&mala,arq_configuracao2,quant_bomba[i]);



            verificar_quantidade(&mala);

            verificar_max_espaco(&mala,quant_bomba[i]);

            verificar_configuracao(&mala);

            verificar_tamanho(&mala,quant_bomba[i]);

            verificar_tamanho_bomba(&mala,quant_bomba[i]);

            verificar_posicao_repetida(&mala);

            verificar_proximidade(&mala);

            verificar_meio(&mala);



            //resposta(&mala ,arq_resposta);

            desalocar_bomba(&mala,quant_bomba[i]);
            free(mala.configuracao);
            quantidades_configuracao--;
            i++;



        }

        //tempo_exec2 = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;
        clock_gettime(CLOCK_THREAD_CPUTIME_ID,&tempo2);
        tempo_exec2 = ((unsigned long int )(tempo2.tv_nsec - tempo.tv_nsec)/1000);

        if(verificador2 != verificador )
        {
            printf("erro na quantidade de configuraçoes no %s, na parte valida tem %i configurações e na nao valida tem %i configurações\n",ca,verificador,verificador2 );
            //return 0;

        }


        cont ++;
        fprintf(arq_tabela,"%li\t%li\n",tempo_exec,tempo_exec2 );
        free(quant_bomba);
        fclose(arq_configuracao2);

        fclose(arq_configuracao);
    }
    fclose(arq_resposta);
    fclose(arq_tabela);
    destruir_mala(&mala);

    return 0;
}
