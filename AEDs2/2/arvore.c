#include "arvore.h"
#include "funcoes.h"


void setArvore(raiz raiz_arvore)
{
    int i;
    for(i = 0; i < TAM_ALFABETO; i++)//setar todoas os ponteiros da folha
    {
        raiz_arvore->alfabeto[i] = NULL;
    }
    return;
}

void verifica_palavra(char *arq_arvore, raiz raiz_arvore)
{
    char palavra[TAM_PALAVRA];
    char palavra2[TAM_PALAVRA];
    int i;


    FILE *arquivo = fopen(arq_arvore, "r");

    if (arquivo == NULL)  // Se houve erro na abertura
    {
        printf("1 Problemas na abertura do arquivo\n");
        return;
    }
    raiz_arvore->letra = 1;//para quando for verificar se a arvore e vazia, dar como nao vazia

    do{
        lerArqSTR(palavra, arquivo);
        conferir_palavra(palavra);
        if (!strcmp(palavra,palavra2)) //faz uma verificação para ver se a ultima palavra que foi inserida e igual a penultima.
        {
            break;
        }


        recurs_prencher(raiz_arvore,palavra);


        for(i = 0; i < TAM_PALAVRA; i++) //guarda a palavra para fazer a comparação na proxima vez que for fazer o while
        {
            palavra2[i]=palavra[i];
        }

    }while (!feof(arquivo));

    return;
}

void recurs_prencher(raiz raiz_arvore, char *palavra)
{

    if(palavra[0] == '\0') // verifica se a palavra existe ou nao, pq se nao existe nao tem o que preencher na arvore
    {
        setArvore(raiz_arvore);
        return;
    }else{
        if(!raiz_arvore->alfabeto[palavra[0]-65]) //verifica se a letra ja foi colocada na arvore se nao aloca um espaço para ela
        {
            raiz_arvore->alfabeto[palavra[0]-65] = (No*)malloc(sizeof(No));
        }

        raiz_arvore->alfabeto[palavra[0]-65]->letra = palavra[0]; //coloca a letra no nó dela

        if(palavra[1]=='\0') //verifica se chegou ao fim da palavra
        {
            raiz_arvore->alfabeto[palavra[0]-65]->isPalavra = 1;
        }

        recurs_prencher(raiz_arvore->alfabeto[palavra[0]-65],palavra+1);//chama a recursividade de novo
    }

}

int isArvore_vazia(raiz raiz_arvore)
{
    if(raiz_arvore->letra != '\0')//verifica se a arvore foi setada e se esta vazia
    {
        return 1;
    }else{
        return 0;
    }

}

void percorrer_arvore(char *arq_procura, raiz raiz_arvore)
{
    int quantidade_arquivo;
    int aux = 0,i,j,tam_palavra = 0, tam_imprimir = 0;
    char palavra[TAM_PALAVRA]={'\0'};
    char imprimir[TAM_PALAVRA]={'\0'};

    FILE *arquivo = fopen(arq_procura, "r");

    if (arquivo == NULL)  // Se houve erro na abertura do arquivo
    {
        printf("2 Problemas na abertura do arquivo\n");
        return;
    }

    lerArqINT(&quantidade_arquivo, arquivo); //le a quantidade de pesquisa que vai fazer

    while(aux < quantidade_arquivo) //loop para pegar as pesquisas que vao fazer
    {

        tam_palavra = 0;
        tam_imprimir = 0;
        for(j = 0;j < TAM_PALAVRA; j++)
        {
            imprimir[j]='\0';
            palavra[j]='\0';
        }

        lerArqSTR(palavra, arquivo);
        printf("%s: ",palavra);

        for(tam_palavra = 0,i = 0; palavra[i] != '\0'; i++)
        {
            tam_palavra++;
        }

        raiz raiz_arvore_aux = raiz_arvore; //criado um ponteiro para nao perde a raiz da arvore


            for(i = 0;i < tam_palavra; i++ ) //loop para caminhar na arvore ate a ultima letra da pesquisa
            {

                if(raiz_arvore_aux->alfabeto[palavra[i]-65] != NULL)
                {
                    if(raiz_arvore_aux->alfabeto[palavra[i]-65]->letra == palavra[i])
                    {
                        imprimir[tam_imprimir] = raiz_arvore_aux->alfabeto[palavra[i]-65]->letra;
                        raiz_arvore_aux = raiz_arvore_aux->alfabeto[palavra[i]-65];
                        tam_imprimir = tam_imprimir + 1;
                    }
                }
            }

            if(tam_imprimir == tam_palavra)//verifica se a pesquisa existe na arvore, comparando no que vai ser impresso e igual ao que o usuario quer
            {
                percorrer_arvore_recursivo(raiz_arvore_aux,imprimir, tam_imprimir);
                printf("\n");
            }else{
                    printf("Nenhuma ocorrencia\n");
            }

        aux++;
    }


}
void percorrer_arvore_recursivo(raiz raiz_arvore,char *imprimir, int tam_imprimir )
{
    int i,j = 0,vazio = 0;
    int nao_vazio[TAM_ALFABETO];


    for(i = 0; i < TAM_ALFABETO; i++) //loop para verificar se chegou na folha e se nao chegou quais os ponteiro que tem caminho.
    {
        if(!raiz_arvore->alfabeto[i])
        {
            vazio ++;
        }else{
            nao_vazio[j] = i;
            j++;
        }
    }

    if(vazio == TAM_ALFABETO )//condição de saida da recursividade suponde que toda folha e uma palavra pois foi alocada e nao tem como fazer retirada da arvore
    {
        imprimir[tam_imprimir-1] = raiz_arvore->letra;
        printf(",%s ",imprimir);
        imprimir[tam_imprimir-1] = '\0';
        return;
    }

    for(i = 0; i < j; i++)//percorrer os todos os caminhos possiveis da arvore pela recursividade
    {

        if(raiz_arvore->isPalavra)
        {
            printf("%s ",imprimir);
        }

        imprimir[tam_imprimir-1] = raiz_arvore->letra;
        percorrer_arvore_recursivo(raiz_arvore->alfabeto[nao_vazio[i]],imprimir, tam_imprimir + 1);
        imprimir[tam_imprimir-1] = '\0';

    }
}
