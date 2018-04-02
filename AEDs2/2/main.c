#include "menu.h"

int main(int argc, char *argv[])
{
    int aux1 = 0,aux2 = 0,i;

    for (i = 0; argv[1][i] != '\0'  ; i++) {
        aux1++;
    }
    for (i = 0; argv[2][i] != '\0'  ; i++) {
        aux2++;
    }
    char arq_arvore[aux1+5], arq_procura[aux2+5];

    for (i = 0; argv[1][i] != '\0'; i++) {
        arq_arvore[i] = argv[1][i];
    }
    for (i = 0; argv[2][i] != '\0'; i++) {
        arq_procura[i] = argv[2][i];
    }

    strcat(arq_arvore, ".txt");
    strcat(arq_procura, ".txt");


    Menu(arq_arvore,arq_procura);
    return 0;
}
