#include "exec.h"


int main()
{
    int aux;
    system("clear||cls");
    printf ("Termos de barganha com o Tinhoso. Disponivel em www.666.com.br\nAperte ENTER para aceitar e continuar\n");
    setbuf(stdin, NULL);
    getchar();
    setbuf(stdin, NULL);
    system("clear||cls");
    printf ("Bem vindo ao ordenador do Tinhoso!!\n  let's play a game!\n");
    setbuf(stdin, NULL);
    getchar();
    setbuf(stdin, NULL);
    system("clear||cls"); //Brincadeira


    printf ("MENU Pre-Inicial:\n\nQualquer Valor - Testar separadamente os ordenadores.\n8 - Gererar tabela com variaçoes do QuickSort testadas com varios tamanhos de entradas.\nDigite:");
    scanf("%d",&aux); // chaviamento para escolher qual Forma o codigo vai rodar
    setbuf(stdin, NULL);
    if(aux == 8)
    {
        execucao_tabela();  //Gerar Tabela para Comparar os codigos
    }else{
        execucao_normal();  //Formar de testar o codigo.
    }


    system("clear||cls");//Brincadeira
    printf ("muito obrigado,\nAS 3:00 AM IREI BUSCAR SUA ALMA, QUE VOCE ME VENDEU PARA USAR ESSE CODIGO!!.  \n     BY:TINHOSO");
    setbuf(stdin, NULL);
    getchar();
    setbuf(stdin, NULL);
    return 0;
}
