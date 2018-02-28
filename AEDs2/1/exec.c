#include "menu.h"


void execucao_tabela()
{

    int aux = 0;
    int repeticao; //quantidade de vezes que cada codigo vai repetir, somente numeros potencia de 10 com limite em 100000 para nao demorar muito .
    do
    {
        printf("\nEscreva quantas vezes cada codigo vai rodar com cada entrada diferente.\nSo e valido multiplos de 10 menor que 100000 \nDigite: ");
        scanf("%d",&repeticao);
        setbuf(stdin, NULL);

        if(repeticao != 10 && repeticao != 100 && repeticao != 1000 && repeticao != 10000 && repeticao != 100000) //verificar se o repeticao do vetor e realmente os predefinidos
        {
            int i = 1;
            do{

                printf("\n O repeticao tem que ser 10, 100, 1000, 10000, 100000\n");
                printf("\nEscreva o repeticao desejado: ");
                scanf("%d", &repeticao);
                setbuf(stdin, NULL);
                if(repeticao == 10 || repeticao == 100 || repeticao == 1000 || repeticao == 10000 || repeticao == 100000) //caso tenha colocado o valor certo sair do loop
                {
                    i = 0;
                }

            }while ( i == 1 );
        }
        repeticao++;
        do
        {

            printf("\n\tMENU DE TABELAS\n1 - QuickSort Normal\n2 - QuickSort Mediana \n3 - QuickSort Insertion\n4 - QuickSort Mesclado  \nDigite: ");
            scanf("%d",&aux);
            setbuf(stdin, NULL);

        }while((aux != 1) &&(aux != 2) &&(aux != 3) &&(aux != 4));

        if(aux == 1)
        {
            FILE *arquivo1; //Gerado nessa função para ficar mais facil alterar caso queira em apenas em um arquivo.
            arquivo1 = fopen("TabTempoQuickSortNormal.txt", "wt");

            if (arquivo1 == NULL){
                printf("O Arquivo nao foi criado!\n");
                return;
            }

            Tab_quick(arquivo1,1,repeticao);

            Tab_quick(arquivo1,2,repeticao);

            Tab_quick(arquivo1,3,repeticao);  //Gerador tabela qualquer com varios tipos de vetoreis

            printf("\nTambem foi criado um arquivo com esses valores!  TabTempoQuickSortNormal.txt\n");
            fclose(arquivo1);

        }else if(aux == 2){

            FILE *arquivo2;
            arquivo2 = fopen("TabTempoQuickSortMediana.txt", "wt");

            if (arquivo2 == NULL){
                printf("O Arquivo nao foi criado!\n");
                return;
            }

            Tab_quickMediana(arquivo2,1,repeticao);

            Tab_quickMediana(arquivo2,2,repeticao);

            Tab_quickMediana(arquivo2,3,repeticao);//Gerador tabela qualquer com varios tipos de vetoreis

            printf("\nTambem foi criado um arquivo com esses valores!  TabTempoQuickSortMediana.txt\n");
            fclose(arquivo2);


        }else if(aux == 3){

            FILE *arquivo3;
            arquivo3 = fopen("TabTempoQuickSortInsertion.txt", "wt");

            if (arquivo3 == NULL){
                printf("O Arquivo nao foi criado!\n");
                return;
            }

            Tab_quickInsertion(arquivo3,1,repeticao);

            Tab_quickInsertion(arquivo3,2,repeticao);

            Tab_quickInsertion(arquivo3,3,repeticao);//Gerador tabela qualquer com varios tipos de vetoreis

            printf("\nTambem foi criado um arquivo com esses valores!  TabTempoQuickSortInsertion.txt\n");

            fclose(arquivo3);

        }else if(aux == 4){

            FILE *arquivo4;
            arquivo4 = fopen("TabTempoQuickSortMesclado.txt", "wt");

            if (arquivo4 == NULL){
                printf("O Arquivo nao foi criado!\n");
                return;
            }

            Tab_quickMesclado(arquivo4,1,repeticao);

            Tab_quickMesclado(arquivo4,2,repeticao);

            Tab_quickMesclado(arquivo4,3,repeticao);//Gerador tabela qualquer com varios tipos de vetoreis

            printf("\nTambem foi criado um arquivo com esses valores!  TabTempoQuickSortMesclado.txt\n");
            fclose(arquivo4);
        }



        printf("\nMENU FINAL\nQualquer Valor - Gerar outra tabela\n9 - Sair\nDigite: ");
        scanf("%d",&aux);
        setbuf(stdin, NULL);


    }while (aux != 9 );
    return;
}

void execucao_normal()
{
    int comando = -1;
    int tamanho = -1;


    while(comando != 9)
    {
        system("clear||cls");
        defineTamanho(&tamanho);
        int vetor [tamanho];
        defineVetor(vetor, &tamanho);
        defineQuick(vetor, &tamanho);
        printf("\nGostaria de continuar testando o codigo?");
        printf("\nQualquer valor - Continuar testando\n8 -  Gererar Tabela com varias entradas \n9 - Para sair");
        printf("\nqual a opcao: ");
        scanf("%i", &comando);
        setbuf(stdin, NULL);
        if(comando == 8)
        {
            execucao_tabela();
        }


    }
    return ;
}
