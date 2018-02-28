#include "menu.h"
#include "arvore.h"
#include "funcoes.h"


void Menu(char *arq_arvore,char *arq_procura)
{
    raiz raiz_arvore,raiz_arvore2;


    raiz_arvore = (No*)malloc(sizeof(No));

    setArvore(raiz_arvore);
    raiz_arvore->letra = '\0';



    if(get_size(arq_arvore) == 0)
    {
        printf("O arquivo esta vazio, ou nao existe.\n");
        return;
    }

    raiz_arvore2 = raiz_arvore;
    verifica_palavra(arq_arvore,raiz_arvore2);

    if(!isArvore_vazia(raiz_arvore))
    {
        printf("Arvore vazia! favor fazer uma entrada!\n");
        return;
    }

    percorrer_arvore(arq_procura,raiz_arvore);

    return;
}
