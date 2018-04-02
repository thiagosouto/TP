#include "main.h"
#include "inteligencia.h"
#include "funcoes.h"

void criar_mala(Mala* mala)
{//*


    alocar_composicao(&mala->composicao_final);
    alocar_composicao(&mala->composicao_padrao);

    mala->isValido = 1;

    //*/
    return;
}

void destruir_mala(Mala* mala)
{//*

    desalocar_composicao(&mala->composicao_padrao);
    desalocar_composicao(&mala->composicao_final);
    //*/
    return;
}

void criar_composicao(char* nome_arq_composicao, Mala* mala)
{//*
    char* tipo;
    int quantidade;
    FILE *arq_composicao = fopen(nome_arq_composicao, "r");


    if (!arquivo_vazio(nome_arq_composicao))
    {
        printf("O Arquivo de composicao esta vazio\n");
        mala->isValido = 0;
        return;
    }






    while (!feof(arq_composicao)){

        lerArqINT(&quantidade ,arq_composicao);

        tipo = malloc (3 * sizeof (char));
        lerArqSTR(tipo, arq_composicao);

        ler_composicao(&mala->composicao_padrao,tipo, quantidade);

        free(tipo);
    }

    fclose(arq_composicao);

    //*/
    return;
}

int quantidade_configuracao(char* nome_arq_configuracao)
{//*

    FILE *arq_configuracao = fopen(nome_arq_configuracao, "r");
    char* palavra = malloc(13 * sizeof (char));
    int valor = 0;


    if (!arquivo_vazio(nome_arq_configuracao))
    {
        printf("O Arquivo de configuracao esta vazio\n");
        return valor;

    }
    do{

        lerArqSTR(palavra, arq_configuracao);



        if(strcmp(palavra, "configuracao") > 0)
        {
            valor++;
        }

        free(palavra);
        palavra = malloc(13 * sizeof (char));
    }while (!feof(arq_configuracao));




    fclose(arq_configuracao);
    free(palavra);

    return valor;

    //*/return;
}

void alocar_bomba(Mala *mala,int quantidade)
{//*
    int i;
    mala->bomba = malloc(quantidade * sizeof(Bomba));



    for(i = 0; i < quantidade; i++)
    {
        mala->bomba[i].tipo = malloc (3 * sizeof (char));
        mala->bomba[i].id = 0;
        mala->bomba[i].tamanho = 0;
        mala->bomba[i].x_inicial = 0;
        mala->bomba[i].y_inicial = 0;
        mala->bomba[i].x_final = 0;
        mala->bomba[i].y_final = 0;
    }

    //*/

    return;
}

void desalocar_bomba(Mala *mala, int quantidade)
{//*
    int i;
    for (i = 0; i < quantidade; i++)  //Percorre as linhas do Vetor de Ponteiros
    {

        free(mala->bomba[i].tipo);


    }
    free(mala->bomba);
    //*/
    return;
}

void quantidade_bomba(char* nome_arq_configuracao, int quantidade_de_configuracao, int* vet_quantidade)
{//*

    FILE *arq_configuracao = fopen(nome_arq_configuracao, "r");
    char* palavra = malloc(13 * sizeof (char));
    char* palavra2 = malloc(13 * sizeof (char));
    int i;




    if (!arquivo_vazio(nome_arq_configuracao))
    {
        printf("O Arquivo de configuracao esta vazio\n");
        return ;

    }

    for(i = 0; i < quantidade_de_configuracao; i++)
    {
        vet_quantidade[i] = 0;
        lerArqSTR(palavra, arq_configuracao);


        do{
            free(palavra);
            palavra = malloc(13 * sizeof (char));
            lerArqSTR(palavra, arq_configuracao);

            free(palavra2);
            palavra2 = malloc(13 * sizeof (char));
            lerArqSTR(palavra2, arq_configuracao);

            free(palavra2);
            palavra2 = malloc(13 * sizeof (char));
            lerArqSTR(palavra2, arq_configuracao);

            free(palavra2);
            palavra2 = malloc(13 * sizeof (char));
            lerArqSTR(palavra2, arq_configuracao);

            free(palavra2);
            palavra2 = malloc(13 * sizeof (char));
            lerArqSTR(palavra2, arq_configuracao);



            vet_quantidade[i]++;

        }while ( strcmp("configuracao",palavra) > 0 && !feof(arq_configuracao) );

    }



    vet_quantidade[0]--;

    fclose(arq_configuracao);
    free(palavra);
    free(palavra2);


    //*/
    return;
}

void criar_configuracoes( Mala* mala, FILE* arq_configuracao, int quantidade_de_bombas)
{//*

    int indice = quantidade_de_bombas;
    int idn = 0;
    char* conf;




    desalocar_composicao(&mala->composicao_final);
    alocar_composicao(&mala->composicao_final);
    lerArqSTR(mala->configuracao, arq_configuracao);


    do{
        conf= malloc (3 * sizeof (char));

        lerArqINT(&mala->bomba[idn].x_inicial, arq_configuracao);
        lerArqINT(&mala->bomba[idn].y_inicial, arq_configuracao);
        lerArqINT(&mala->bomba[idn].x_final, arq_configuracao);
        lerArqINT(&mala->bomba[idn].y_final, arq_configuracao);

        lerArqSTR(conf,arq_configuracao);

        mala->bomba[idn].tamanho = conf[0] - 48;

        mala->bomba[idn].tipo[0] = conf[1];
        mala->bomba[idn].tipo[1] = conf[2];
        mala->bomba[idn].tipo[2] = '\0';

        ler_composicao (&mala->composicao_final, conf , 1);

        mala->bomba[idn].id = idn;
        idn++;


        indice--;

        free(conf);
    }while(indice);

    mala->composicao_final.quantidade_de_bombas = idn;


        //*/
    return;

}

//------------------------------------------FUNÇOES DE VERIFICAÇÃO E RESPOSTA----------------------------------------

void verificar_quantidade(Mala *mala)
{//*
    if(!mala->isValido)
    {
        return;
    }


    if(mala->composicao_padrao.quantidade_de_bombas != mala->composicao_final.quantidade_de_bombas)
    {
        //printf("%s quantidade de bomba diferente\n",mala->configuracao ); //dbug
        mala->isValido = 0;

    }

    //*/
    return;
}

void verificar_configuracao(Mala *mala)
{//*
    if(!mala->isValido)
    {
        return;
    }
    int i;
    for(i = 0; i < 3; i++)
    {
        if(mala->composicao_padrao.Az[i] != mala->composicao_final.Az[i])
        {
            //printf("%s quantidade de bomba %iAz diferente. comp %i conf %i\n",mala->configuracao,i+1,mala->composicao_padrao.Az[i], mala->composicao_final.Az[i] );//dbug
            mala->isValido = 0;
            return;
        }

        else if(mala->composicao_padrao.Am[i] != mala->composicao_final.Am[i])
        {
            //printf("%s quantidade de bomba %iAm diferente. comp %i conf %i\n",mala->configuracao,i+1,mala->composicao_padrao.Am[i] , mala->composicao_final.Am[i] );//dbug
            mala->isValido = 0;
            return;
        }

        else if(mala->composicao_padrao.Vm[i] != mala->composicao_final.Vm[i])
        {
            //printf("%s quantidade de bomba %iVm diferente. comp %i conf %i\n",mala->configuracao,i+1,mala->composicao_padrao.Vm[i] , mala->composicao_final.Vm[i] );//dbug
            mala->isValido = 0;
            return;
        }

        else if(mala->composicao_padrao.Vd[i] != mala->composicao_final.Vd[i])
        {
            //printf("%s quantidade de bomba %iVd diferente. comp %i conf %i\n",mala->configuracao,i+1,mala->composicao_padrao.Vd[i] , mala->composicao_final.Vd[i] );//dbug
            mala->isValido = 0;
            return;
        }
    }
    //*/
    return;
}

void verificar_max_espaco(Mala* mala, int quantidade_de_bombas)
{//*/
    if(!mala->isValido)
    {
        return;
    }

    int tamanho = 0 ;
    int i;
    for(i = 0; i < quantidade_de_bombas ;i ++)
    {
        tamanho = tamanho + mala->bomba[i].tamanho;
    }

    if(tamanho > 36)
    {
        //printf("%s extrapola espaço max\n",mala->configuracao);//dbug
        mala->isValido = 0;
    }

    //*/
    return;
}

void verificar_tamanho(Mala *mala,int quantidade_de_bombas)
{//*
    if(!mala->isValido)
    {
        return;
    }

    int i;
    for(i = 0; i < quantidade_de_bombas ;i ++)
    {
        if((mala->bomba[i].x_inicial > 6) || (mala->bomba[i].x_inicial < 1))
        {
            //printf("%s o tamanho da bomba %i %i %i %i %i%s extrapola\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
            mala->isValido = 0;
            return;
        }else if((mala->bomba[i].x_final > 6) || (mala->bomba[i].x_final < 1))
        {
            //printf("%s o tamanho da bomba %i %i %i %i %i%s\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
            mala->isValido = 0;
            return;
        }else if((mala->bomba[i].y_inicial > 6)|| (mala->bomba[i].y_inicial <1))
        {
            //printf("%s o tamanho da bomba %i %i %i %i %i%s\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
            mala->isValido = 0;
            return;
        }else if((mala->bomba[i].y_final > 6) || (mala->bomba[i].y_final < 1))
        {
            //printf("%s o tamanho da bomba %i %i %i %i %i%s\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
            mala->isValido = 0;
            return;
        }
    }


    //*/
    return;
}

void verificar_tamanho_bomba(Mala *mala,int quantidade_de_bombas)
{//*
    if(!mala->isValido)
    {
        return;
    }
        int modulo = 0;
        int i;

        for(i = 0; i < quantidade_de_bombas ;i ++)
        {
            if(mala->bomba[i].tamanho == 1){

                if((mala->bomba[i].x_final != mala->bomba[i].x_inicial) && (mala->bomba[i].y_final == mala->bomba[i].y_inicial))
                {
                    //printf("%s o modulo da bomba %i %i %i %i %i%s diferente do tamanho enviado\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                    mala->isValido = 0;
                    return;

                }

            }else{

                if(mala->bomba[i].x_final == mala->bomba[i].x_inicial)
                {
                    modulo = mala->bomba[i].y_final - mala->bomba[i].y_inicial + 1;

                }else{

                    modulo = mala->bomba[i].x_final - mala->bomba[i].x_inicial + 1;

                }

                if(modulo != mala->bomba[i].tamanho  )
                {
                    //printf("%s o modulo da bomba %i %i %i %i %i%s diferente do tamanho enviado\n",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                    mala->isValido = 0;
                    return;
                }

            }

        }
    //*/
    return;
}

void verificar_posicao_repetida(Mala *mala)
{//*
    if(!mala->isValido)
    {
        return;
    }
    int i,j;

    for(i = 0; i < mala->composicao_final.quantidade_de_bombas; i++)
    {
        for(j = i+1; j < mala->composicao_final.quantidade_de_bombas; j++ )
        {


            if(((mala->bomba[i].x_inicial == mala->bomba[j].x_inicial) && (mala->bomba[i].y_inicial == mala->bomba[j].y_inicial))
                || ((mala->bomba[i].x_inicial == mala->bomba[j].x_final) && (mala->bomba[i].y_inicial == mala->bomba[j].y_final)))
                {
                    // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                    // printf(" e a bomba %i %i %i %i %i%s estão com a mesma posição\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);//dbug
                    mala->isValido = 0;
                }
            if(mala->bomba[i].tamanho == 3)
            {
                int x_meio, y_meio;
                if(mala->bomba[i].x_inicial == mala->bomba[i].x_final )
                {
                    if(mala->bomba[i].y_inicial < mala->bomba[i].y_final)
                    {
                        x_meio = mala->bomba[i].x_inicial;
                        y_meio = mala->bomba[i].y_inicial + 1;
                    }else{
                        x_meio = mala->bomba[i].x_inicial;
                        y_meio = mala->bomba[i].y_inicial - 1;
                    }
                }else{
                    if(mala->bomba[i].x_inicial < mala->bomba[i].x_final)
                    {
                        x_meio = mala->bomba[i].x_inicial + 1;
                        y_meio = mala->bomba[i].y_inicial ;
                    }else{
                        x_meio = mala->bomba[i].x_inicial - 1;
                        y_meio = mala->bomba[i].y_inicial ;
                    }

                }

                if((x_meio == mala->bomba[j].x_inicial && y_meio == mala->bomba[j].y_inicial)
                    || (x_meio == mala->bomba[j].x_final && y_meio == mala->bomba[j].y_final))
                    {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf(" e a bomba %i %i %i %i %i%s tem conflito no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                    }


                if(mala->bomba[j].tamanho == 3)
                {
                    int x_meio_j, y_meio_j;

                    if(mala->bomba[j].x_inicial == mala->bomba[j].x_final )
                    {
                        if(mala->bomba[j].y_inicial < mala->bomba[j].y_final)
                        {
                            x_meio_j = mala->bomba[j].x_inicial;
                            y_meio_j = mala->bomba[j].y_inicial + 1;
                        }else{
                            x_meio_j = mala->bomba[j].x_inicial;
                            y_meio_j = mala->bomba[j].y_inicial - 1;
                        }
                    }else{
                        if(mala->bomba[j].x_inicial < mala->bomba[j].x_final)
                        {
                            x_meio_j = mala->bomba[j].x_inicial + 1;
                            y_meio_j = mala->bomba[j].y_inicial ;
                        }else{
                            x_meio_j = mala->bomba[j].x_inicial - 1;
                            y_meio_j = mala->bomba[j].y_inicial ;
                        }

                    }

                    if(x_meio == x_meio_j && y_meio == y_meio_j)
                    {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf("e a bomba %i %i %i %i %i%s estao cruzando no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                    }
                }
            }
        }
    }

    //*/
    return;
}

void verificar_proximidade(Mala* mala)
{//*
    if(!mala->isValido)
    {
        return;
    }
    int i,j;

    for(i = 0; i < mala->composicao_final.quantidade_de_bombas; i++)
    {
        for(j = i + 1 ; j < mala->composicao_final.quantidade_de_bombas; j++)
        {
            if ((mala->bomba[j].tipo[0] == mala->bomba[i].tipo[0]) && (mala->bomba[j].tipo[1] == mala->bomba[i].tipo[1]))
            {
                if((mala->bomba[i].x_inicial == mala->bomba[j].x_inicial + 1) && (mala->bomba[i].y_inicial == mala->bomba[j].y_inicial))
                {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf(" e bomba %i %i %i %i %i%s estão proxima\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                }
                else if((mala->bomba[i].x_inicial == mala->bomba[j].x_inicial) && (mala->bomba[i].y_inicial == mala->bomba[j].y_inicial + 1))
                {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf(" e bomba %i %i %i %i %i%s estão proxima\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                }
                else if((mala->bomba[i].x_inicial == mala->bomba[j].x_inicial - 1) && (mala->bomba[i].y_inicial == mala->bomba[j].y_inicial))
                {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf(" e bomba %i %i %i %i %i%s estão proxima\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                }
                else if((mala->bomba[i].x_inicial == mala->bomba[j].x_inicial) && (mala->bomba[i].y_inicial == mala->bomba[j].y_inicial -1))
                {
                        // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                        // printf(" e bomba %i %i %i %i %i%s estão proxima\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                        mala->isValido = 0;
                        return;
                }
            }
        }
    }


    //*/
    return;
}

void verificar_meio(Mala *mala)
{//*
    if(!mala->isValido)
    {
        return;
    }

    int i,j;
    int x_meio, y_meio;
    for(i = 0; i < mala->composicao_final.quantidade_de_bombas; i++)
    {
        if(mala->bomba[i].tamanho == 3)
        {
            if(mala->bomba[i].x_inicial == mala->bomba[i].x_final )
            {
                if(mala->bomba[i].y_inicial < mala->bomba[i].y_final)
                {
                    x_meio = mala->bomba[i].x_inicial;
                    y_meio = mala->bomba[i].y_inicial + 1;
                }else{
                    x_meio = mala->bomba[i].x_inicial;
                    y_meio = mala->bomba[i].y_inicial - 1;
                }
            }else{
                if(mala->bomba[i].x_inicial < mala->bomba[i].x_final)
                {
                    x_meio = mala->bomba[i].x_inicial + 1;
                    y_meio = mala->bomba[i].y_inicial ;
                }else{
                    x_meio = mala->bomba[i].x_inicial - 1;
                    y_meio = mala->bomba[i].y_inicial ;
                }

            }


            for(j = i; j < mala->composicao_final.quantidade_de_bombas; j++)
            {

                if(mala->bomba[i].x_inicial == mala->bomba[i].x_final )
                {

                    if(y_meio == mala->bomba[j].y_inicial && x_meio == mala->bomba[j].x_inicial + 1)
                    {
                            if ((mala->bomba[j].tipo[0] == mala->bomba[i].tipo[0]) && (mala->bomba[j].tipo[1] == mala->bomba[i].tipo[1]))
                            {
                                // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                                // printf(" 1 esta cruzando a bomba %i %i %i %i %i%s no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                                mala->isValido = 0;
                                return;
                            }
                    }

                    if(y_meio == mala->bomba[j].y_inicial - 1 && x_meio == mala->bomba[j].x_inicial - 1)
                    {
                            if ((mala->bomba[j].tipo[0] == mala->bomba[i].tipo[0]) && (mala->bomba[j].tipo[1] == mala->bomba[i].tipo[1]))
                            {
                                // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                                // printf(" 2 esta cruzando a bomba %i %i %i %i %i%s no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                                mala->isValido = 0;
                                return;
                            }
                    }

                }else{

                    if(y_meio == mala->bomba[j].y_inicial + 1 && x_meio == mala->bomba[j].x_inicial)
                    {
                        if ((mala->bomba[j].tipo[0] == mala->bomba[i].tipo[0]) && (mala->bomba[j].tipo[1] == mala->bomba[i].tipo[1]))
                        {
                            // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                            // printf(" 3 esta cruzando a bomba %i %i %i %i %i%s no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                            mala->isValido = 0;
                            return;
                        }
                    }

                    if(y_meio == mala->bomba[j].y_inicial - 1 && x_meio == mala->bomba[j].x_inicial)
                    {
                            if ((mala->bomba[j].tipo[0] == mala->bomba[i].tipo[0]) && (mala->bomba[j].tipo[1] == mala->bomba[i].tipo[1]))
                            {
                                // printf("%s a bomba %i %i %i %i %i%s",mala->configuracao,mala->bomba[i].x_inicial ,mala->bomba[i].y_inicial,mala->bomba[i].x_final,mala->bomba[i].y_final,mala->bomba[i].tamanho,mala->bomba[i].tipo);//dbug
                                // printf(" 4 esta cruzando a bomba %i %i %i %i %i%s no meio\n",mala->bomba[j].x_inicial ,mala->bomba[j].y_inicial,mala->bomba[j].x_final,mala->bomba[j].y_final,mala->bomba[j].tamanho,mala->bomba[j].tipo);
                                mala->isValido = 0;
                                return;
                            }
                    }
                }
            }
        }
    }
    //*/
    return;
}

void resposta(Mala* mala,FILE *arq_resposta)
{//*
    if(mala->isValido)
    {

        fprintf(arq_resposta,"%s:valido \n",mala->configuracao);

    }else{

        fprintf(arq_resposta,"%s:nao-valido\n",mala->configuracao);

    }
    mala->isValido = 1;
    //*/
    return;
}
