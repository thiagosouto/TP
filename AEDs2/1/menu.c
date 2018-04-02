#include "menu.h"
#include "insertion.h"
#include "quick.h"

void defineTamanho(int *tamanho)
{
    int i = 0;

        printf ("\nEscolha o tamanho do vetor que vai ordenar.");
        printf("\n10, 100, 1000, 10000, 100000 ou 1000000");
        printf("\nEscreva o tamanho desejado: ");
        scanf("%d", tamanho);
        setbuf(stdin, NULL);

        if(*tamanho != 10 && *tamanho != 100 && *tamanho != 1000 && *tamanho != 10000 && *tamanho != 100000 && *tamanho != 1000000) //verificar se o tamanho do vetor e realmente os predefinidos
        {
            i = 1;
            do{

                printf("\n O tamanho tem que ser 10, 100, 1000, 10000, 100000 ou 1000000\n");
                printf("\nEscreva o tamanho desejado: ");
                scanf("%d", tamanho);
                setbuf(stdin, NULL);
                if(*tamanho == 10 || *tamanho == 100 || *tamanho == 1000 || *tamanho == 10000 || *tamanho == 100000 || *tamanho == 1000000) //caso tenha colocado o valor certo sair do loop
                {
                    i = 0;
                }

            }while ( i == 1 );
        }


    return ;
}

void defineQuick(int *vetor, int *tamanho)
{

    clock_t c_nomal, c_mediana, c_mesclado, c_tudojunto;    //variavel para guardar o tempo de execução do valor
    double tempo_exec = 0;                                  //variavel para converter em segundo o tempo
    int metodo;
    printf ("\n\nEscolha qual o QUICKSORT voce quer usar:");
    printf("\n1 - Normal\n2 - Mediana de 3 elementos \n3 - com Insertion Sort\n4 - mesclado os dois modos\n9 - SAIR  ");
    printf("\nQual seu metodo: ");
    scanf("%d", &metodo);
    while (1) //loop para nao deixar o programa fechar caso o usuario erro o valor de entrada
    {
        switch(metodo){  //menu de qual metodo de ordenação vai usar
            case 1:

                c_nomal = clock();
                quickSort(vetor, 0, (*tamanho)-1);
                tempo_exec = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;
                printf("\nOrdenado pelo QUICK SORT normal:\n");
                imprimeVetor(vetor, tamanho);
                gravaVetorOrdenado(vetor, tamanho,tempo_exec);
                printf("\nO quickSort executou em %f segundos\n Aperte ENTER para continuar", tempo_exec);
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;

            break;
            case 2:

                c_mediana = clock();
                quickSortMediana(vetor, 0, (*tamanho)-1);
                tempo_exec = ((double)clock() - c_mediana) / CLOCKS_PER_SEC;
                printf("\nOrdenado pelo QUICK SORT usando mediana no pivo:\n");
                imprimeVetor(vetor, tamanho);
                gravaVetorOrdenado(vetor, tamanho,tempo_exec);
                printf("\nO quickSort usando mediana dos 3 elementos do meio como pivo executou em %f segundos\n Aperte ENTER para continuar", tempo_exec);
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;

            break;

            case 3:

                c_mesclado = clock();
                quickSortInsertion(vetor, 0, (*tamanho)-1);
                insertionSort(vetor,(*tamanho));
                tempo_exec = ((double)clock() - c_mesclado) / CLOCKS_PER_SEC;
                printf("\nOrdenado pelo QUICK SORT quando esta quase ordenado usa o inserion:\n");
                imprimeVetor(vetor, tamanho);
                gravaVetorOrdenado(vetor, tamanho,tempo_exec);
                printf("\nO quickSort ate quase acabar e terminando com InsertionSort, executou em %f segundos\n Aperte ENTER para continuar", tempo_exec);
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;

            break;

            case 4:

                c_tudojunto= clock();
                quickSortMesclado(vetor, 0, (*tamanho)-1);
                insertionSort(vetor,(*tamanho));
                tempo_exec = ((double)clock() - c_tudojunto) / CLOCKS_PER_SEC;
                printf("\nOrdenado pelo QUICK SORT juntou mediana no pivo com inserion no final:\n");
                imprimeVetor(vetor, tamanho);
                gravaVetorOrdenado(vetor, tamanho,tempo_exec);
                printf("\nO quickSort com a mediana dos tres elementos do meio ate quase acabar e terminando com InsertionSort, executou em %f segundos\n Aperte ENTER para continuar", tempo_exec);
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;

            break;

            case 9:

                return;

            break;

            default:

                printf("\nEscolha um numero certo!\n Aperte ENTER para tentar de novo");
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
            break;
            }
        }
        return;
    }

void defineVetor(int *vetor, int *tamanho)
{
    if(*tamanho > 1000000)    //verificação para o ver se o tamanho e realmente certo
    {
        printf("\nTa muito grande, diminua o tamanho desejado!");
        setbuf(stdin, NULL);
        getchar();
        setbuf(stdin, NULL);
        *tamanho = -1;
        return;
    }

    int tipo;

    while(1)        //loop para se caso o usuario digite errado nao continue o programa
    {
        printf ("\nEscolha qual o tipo de vetor quer usar");
        printf("\n1 - Decrescente\n2 - Crescente\n3 - Aleatorio");
        printf("\nEscreva o tipo: ");
        scanf("%d", &tipo);  //menu para decidir qual tipo de vetor vai ser feito
        setbuf(stdin, NULL);

        switch(tipo){
            case 1:
                vetorDecrescente(vetor, tamanho,0);
                printf("\n Aperte ENTER para continuar\n");
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;
            break;

            case 2:
                vetorCrescente(vetor, tamanho,0);
                printf("\n Aperte ENTER para continuar\n");
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;
            break;

            case 3:
                vetorRandom(vetor, tamanho,0);
                printf("\n Aperte ENTER para continuar\n");
                setbuf(stdin, NULL);
                getchar();
                setbuf(stdin, NULL);
                return;
            break;

            default:
                printf("\nIsso nao pode!\n");

            }
        }
    }

void imprimeVetor(int *vetor, int *tamanho)
{
    int i = 0,aux = 25;
    if(*tamanho < 1000)
    {
        aux = 10;
    }
    printf("O vetor é:\n");
    while(i < *tamanho){
        printf("%d, ", *(vetor+i));
        if(i % aux == 0 && i != 0) //imprimir o vetor mais ordenado na tela
        {
            printf("\n");
        }
        i++;
      }
      return;
    }

void vetorRandom(int *vetor, int *tamanho, int chave)
{
    int i;

    srand(time(NULL));
    if(chave == 0)
    {
        printf("\nCriamos um vetor Aleatorio de %i posicao.", *tamanho);
    }

    for(i = 0; i < *tamanho; i++)
    {
        *(vetor+i) = rand() % *tamanho;
    }

    if(chave == 0)
    {
        imprimeVetor(vetor, tamanho);
        gravaVetorOriginal(vetor, tamanho);
    }
    return;
}

void vetorCrescente(int *vetor, int *tamanho, int chave)
{
    int i;

    if(chave == 0)  //chave para nao deixar imprimir na tela quando tiver processando tabela
    {
        printf("\nCriamos um vetor Crecente de %i posicao.", *tamanho);
    }
    for(i = 0; i < *tamanho; i++){
        *(vetor+i) = i;
    }
    if(chave == 0){
        imprimeVetor(vetor, tamanho);
        gravaVetorOriginal(vetor, tamanho);
    }
    return;
}

void vetorDecrescente(int *vetor, int *tamanho, int chave)
{
    int i, j;
    if(chave == 0)
    {
        printf("\nCriamos um vetor decrescente de %i posicao.", *tamanho);
    }
    for(i = *tamanho, j=0; i >= 0; i--,j++)
    {
        *(vetor+j) = i;
    }
    if(chave == 0)
    {
        imprimeVetor(vetor, tamanho);
        gravaVetorOriginal(vetor, tamanho);
    }
    return;
}

void gravaVetorOrdenado(int *vetor, int *tamanho, double tempo_exec)
{
    FILE *arquivo;
    int i = 0,aux = 25;
    if(*tamanho < 1000)
    {
        aux = 10;
    }
    if(*tamanho == 10)  //define qual tamanho do vetor e cria um vetor proprio para cada tamanho
    {
    arquivo = fopen("vetorOrdenadode10.txt", "wt");

    }else if(*tamanho == 100){
        arquivo = fopen("vetorOrdenadode100.txt", "wt");

    }else if(*tamanho == 1000){
        arquivo = fopen("vetorOrdenadode1000.txt", "wt");

    }else if(*tamanho == 10000){
        arquivo = fopen("vetorOrdenadode10000.txt", "wt");

    }else if(*tamanho == 100000){
        arquivo = fopen("vetorOrdenadode100000.txt", "wt");

    }else if(*tamanho == 1000000){
        arquivo = fopen("vetorOrdenadode1000000.txt", "wt");
    }



    if (arquivo == NULL)
    {
        printf("\nERRO, o vetor nao foi criado!");
        return;
    }

    for(i = 0; i < *tamanho; i++)
    {
        fprintf(arquivo, "%d ", *(vetor+i));
        if(i % aux == 0 && i != 0) //imprimir o vetor mais ordenado na tela
        {
            fprintf(arquivo,"\n");
        }
    }

    fprintf(arquivo, "\nA função foi executada em %.9f segundos\n", tempo_exec);
    printf("\nUm vetor com os valores foi criado!");
    fclose(arquivo);
    return;
}

void gravaVetorOriginal(int *vetor, int *tamanho)
{
    FILE *arquivo;
    int i = 0,aux = 25;
    if(*tamanho < 1000)
    {
        aux = 10;
    }

    if(*tamanho == 10)
        arquivo = fopen("vetorOriginalde10.txt", "wt");
    else if(*tamanho == 100)
        arquivo = fopen("vetorOriginalde100.txt", "wt");
    else if(*tamanho == 1000)
        arquivo = fopen("vetorOriginalde1000.txt", "wt");
    else if(*tamanho == 10000)
        arquivo = fopen("vetorOriginalde10000.txt", "wt");
    else if(*tamanho == 100000)
        arquivo = fopen("vetorOriginalde100000.txt", "wt");
    else if(*tamanho == 1000000)
        arquivo = fopen("vetorOriginalde1000000.txt", "wt");

    if (arquivo == NULL){
        printf("\nO Arquivo nao foi criado!");
        return;
    }

    for(i = 0; i < *tamanho; i++){
        fprintf(arquivo, "%d ", *(vetor+i));
        if(i % aux == 0 && i != 0) //imprimir o vetor mais ordenado na tela
        {
            fprintf(arquivo,"\n");
        }
    }

    printf("\nTambem foi criado um arquivo com esses valores!");
    fclose(arquivo);
}

double desvio_padrao(double *vetor_tempo ,double media_tempo, int tamanho)
{
    double desvio_pa = 0,desvio_pa2 = 0;
    int i;
    for(i = 0; i < tamanho; i++) //faz o calculo para achar o desvio padrao
        {
            vetor_tempo[i] = vetor_tempo[i] - media_tempo;
            vetor_tempo[i] = vetor_tempo[i] * vetor_tempo[i];
            desvio_pa += vetor_tempo[i];
        }
        desvio_pa = desvio_pa / tamanho;
        desvio_pa2 = sqrt(desvio_pa);

    return desvio_pa2;
}

void Tab_quick(FILE *arquivo,int tipo, int repeticao)
{
    int tamanho;




    int i, j;
    double vetor_tempo[6][repeticao];
    double media_tempo[6] = {0};
    double mediana_tempo[6] = {0};
    double devPadrao_tempo[6] = {0} ;


    clock_t c_nomal;


    for(j= 0; j < 6; j++) //loop para rodar vetores de 10 a 1000000
    {
        if(j == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }


        if(tamanho >= 100000 || repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
        {
            printf ("\nCalculando tabela do QuickSort com entrada de tamanho %d rodando %d vezes. Ja rodamos:\n",tamanho,repeticao);
        }else{
            printf ("\nCalculando tabela do QuickSort com entrada de tamanho %d rodando %d vezes...\n",tamanho,repeticao);
        }

        for(i = 0; i < repeticao; i++) //loop para rodar com o vetor de tamanho ja definido N vezes
        {

            int vetor[tamanho];

            if(tamanho >= 100000 || repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
            {
                printf(" %d, ", i);
            }


            if(tipo == 1){  //chave para definir qual o tipo de vetor vai ser feito
                vetorCrescente(vetor, &tamanho,1);
            }else if(tipo == 2){
                vetorDecrescente(vetor, &tamanho,1);
            }else if(tipo == 3){
                vetorRandom(vetor, &tamanho,1);
            }


            c_nomal = clock();
            quickSort(vetor, 0, tamanho-1);
            vetor_tempo[j][i] = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;  //calcula o tempó


            media_tempo[j] += vetor_tempo[j][i];


        }

        media_tempo[j] = media_tempo[j]/repeticao; //calcula as medidas
        quickSortDOUBLE(vetor_tempo[j],0, repeticao -1);
        mediana_tempo[j] = vetor_tempo[j][((repeticao-1)/2)+1];

        devPadrao_tempo[j] = desvio_padrao(vetor_tempo[j],media_tempo[j],repeticao);


    }
    if(tipo == 1){  //imprime na tela e no arquivo

        fprintf(arquivo,"\t\t Tabela do QUICKSORT Rodando %d Vetores Crescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT Rodando %d Vetores Crescente\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 2){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT Rodando %d Vetores Decrescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT Rodando %d Vetores Decrescentes\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 3){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT Rodando %d Vetores Aleatorio\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT Rodando %d Vetores Aleatorio\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }




    for (i = 0; i < 6 ; i++)
    {
        if(i == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho == 10){
            printf(" %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho>10 && tamanho <=100000){
            printf(" %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho == 1000000){
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else {
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }
    }
    printf("\n");
    fprintf(arquivo,"\n");
    return;
}

void Tab_quickMediana(FILE *arquivo,int tipo,int repeticao)
{
    int tamanho; //mesma coisa da funçao anterior so que dessa vez usando o quick sort pelo metodo da mediana




    int i, j;
    double vetor_tempo[6][repeticao];
    double media_tempo[6] = {0};
    double mediana_tempo[6] = {0};
    double devPadrao_tempo[6] = {0} ;


    clock_t c_nomal;


    for(j= 0; j < 6; j++)
    {
        if(j == 0 )
        {
                tamanho= 10;
        }else{
                tamanho *= 10;
        }

        if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
        {
                printf ("\nCalculando tabela do QuickSort com mediana entre os 3 elementos do meio com entrada de tamanho %d rodando %d vezes. Ja rodamos:\n",tamanho,repeticao);
        }else{
                printf ("\nCalculando tabela do QuickSort com mediana entre os 3 elementos do meio com entrada de tamanho %d rodando %d vezes...\n",tamanho,repeticao);
        }

        for(i = 0; i < repeticao; i++) //loop para rodar com o vetor de tamanho ja definido N vezes
        {

            int vetor[tamanho];

            if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
            {
                printf(" %d, ", i);
            }

            if(tipo == 1){
                vetorCrescente(vetor, &tamanho,1);
            }else if(tipo == 2){
                vetorDecrescente(vetor, &tamanho,1);
            }else if(tipo == 3){
                vetorRandom(vetor, &tamanho,1);
            }


            c_nomal = clock();
            quickSortMediana(vetor, 0, tamanho-1);
            vetor_tempo[j][i] = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;


            media_tempo[j] += vetor_tempo[j][i];


        }

        media_tempo[j] = media_tempo[j]/repeticao;
        quickSortDOUBLE(vetor_tempo[j],0, repeticao -1);
        mediana_tempo[j] = vetor_tempo[j][((repeticao-1)/2)+1];

        devPadrao_tempo[j] = desvio_padrao(vetor_tempo[j],media_tempo[j],repeticao);


    }
    if(tipo == 1){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM MEDIANA Rodando %d Vetores Crescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM MEDIANA Rodando %d Vetores Crescente\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 2){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM MEDIANA Rodando %d Vetores Decrescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM MEDIANA Rodando %d Vetores Decrescentes\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 3){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM MEDIANA Rodando %d Vetores Aleatorio\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM MEDIANA Rodando %d Vetores Aleatorio\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }




    for (i = 0; i < 6 ; i++)
    {
        if(i == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho == 10){
            printf(" %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho>10 && tamanho <=100000){
            printf(" %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho == 1000000){
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else {
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }
    }
    printf("\n");
    fprintf(arquivo,"\n");
    return;
}

void Tab_quickInsertion(FILE *arquivo,int tipo,int repeticao)
{
    int tamanho;//mesma coisa da funçao anterior so que dessa vez usando o quick sort pelo metodo do insertion




    int i, j;
    double vetor_tempo[6][repeticao];
    double media_tempo[6] = {0};
    double mediana_tempo[6] = {0};
    double devPadrao_tempo[6] = {0} ;


    clock_t c_nomal;


    for(j= 0; j < 6; j++)
    {
        if(j == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
        {
            printf ("\nCalculando tabela do QuickSort e quando esta quase acabando usamos o InsertionSort com entrada de tamanho %d rodando %d vezes. Ja rodamos:\n",tamanho,repeticao);
        }else{
            printf ("\nCalculando tabela do QuickSort e quando esta quase acabando usamos o InsertionSort com entrada de tamanho %d rodando %d vezes...\n",tamanho,repeticao);
        }

        for(i = 0; i < repeticao; i++) //loop para rodar com o vetor de tamanho ja definido N vezes
        {

            int vetor[tamanho];
            if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
            {
                printf(" %d, ", i);
            }

            if(tipo == 1){
                vetorCrescente(vetor, &tamanho,1);
            }else if(tipo == 2){
                vetorDecrescente(vetor, &tamanho,1);
            }else if(tipo == 3){
                vetorRandom(vetor, &tamanho,1);
            }


            c_nomal = clock();
            quickSortInsertion(vetor, 0, tamanho-1);
            insertionSort(vetor,tamanho);
            vetor_tempo[j][i] = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;


            media_tempo[j] += vetor_tempo[j][i];


        }

        media_tempo[j] = media_tempo[j]/repeticao;
        quickSortDOUBLE(vetor_tempo[j],0, repeticao -1);
        mediana_tempo[j] = vetor_tempo[j][((repeticao-1)/2)+1];

        devPadrao_tempo[j] = desvio_padrao(vetor_tempo[j],media_tempo[j],repeticao);


    }
    if(tipo == 1){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM INSERTION Rodando %d Vetores Crescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM INSERTION Rodando %d Vetores Crescente\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 2){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM INSERTION Rodando %d Vetores Decrescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM INSERTION Rodando %d Vetores Decrescentes\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 3){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT COM INSERTION Rodando %d Vetores Aleatorio\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT COM INSERTION Rodando %d Vetores Aleatorio\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }




    for (i = 0; i < 6 ; i++)
    {
        if(i == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho == 10){
            printf(" %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho>10 && tamanho <=100000){
            printf(" %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho == 1000000){
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else {
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }
    }
    printf("\n");
    fprintf(arquivo,"\n");
    return;
}

void Tab_quickMesclado(FILE *arquivo,int tipo,int repeticao)
{
    int tamanho;//mesma coisa da funçao anterior so que dessa vez usando o quick sort pelo metodo da mediana e insertion junto


    int i, j;
    double vetor_tempo[6][repeticao];
    double media_tempo[6] = {0};
    double mediana_tempo[6] = {0};
    double devPadrao_tempo[6] = {0} ;


    clock_t c_nomal;


    for(j= 0; j < 6; j++)
    {

        if(j == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
        {
            printf ("\nCalculando tabela do QuickSort com mediana entre os 3 elementos do meio e quando esta quase acamando usamos o InsertionSort com entrada de tamanho %d rodando %d vezes. Ja rodamos:\n",tamanho,repeticao);
        }else{
            printf ("\nCalculando tabela do QuickSort com mediana entre os 3 elementos do meio e quando esta quase acamando usamos o InsertionSort com entrada de tamanho %d rodando %d vezes...\n",tamanho,repeticao);
        }

        for(i = 0; i < repeticao; i++) //loop para rodar com o vetor de tamanho ja definido N vezes
        {

            int vetor[tamanho];
            if(tamanho >= 100000 && repeticao >=100) //if para saber se o codigo esta andando ou nao em casos muito grandes pois e com muita repetição
            {
                printf(" %d, ", i);
            }

            if(tipo == 1){
                vetorCrescente(vetor, &tamanho,1);
            }else if(tipo == 2){
                vetorDecrescente(vetor, &tamanho,1);
            }else if(tipo == 3){
                vetorRandom(vetor, &tamanho,1);
            }


            c_nomal = clock();
            quickSortMesclado(vetor, 0, tamanho-1);
            insertionSort(vetor,tamanho);
            vetor_tempo[j][i] = ((double)clock() - c_nomal) / CLOCKS_PER_SEC;

            media_tempo[j] += vetor_tempo[j][i];


        }

        media_tempo[j] = media_tempo[j]/repeticao;
        quickSortDOUBLE(vetor_tempo[j],0, repeticao -1);
        mediana_tempo[j] = vetor_tempo[j][((repeticao-1)/2)+1];

        devPadrao_tempo[j] = desvio_padrao(vetor_tempo[j],media_tempo[j],repeticao);


    }
    if(tipo == 1){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Crescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Crescente\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 2){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Decrescente\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Decrescentes\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }else if(tipo == 3){

        fprintf(arquivo,"\t\t Tabela do QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Aleatorio\n", repeticao);
        fprintf(arquivo,"Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

        printf("\t\t Tabela do tempo QUICKSORT MESCLADO COM INSERTION Rodando %d Vetores Aleatorio\n", repeticao);
        printf("Tamanho\t\t\t\t|Media\t\t\t\t|mediana\t\t\t|desv. padrao \n");

    }




    for (i = 0; i < 6 ; i++)
    {
        if(i == 0 )
        {
            tamanho= 10;
        }else{
            tamanho *= 10;
        }

        if(tamanho == 10){
            printf(" %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%.9f\t\t\t|%.9f\t\t\t|%.9f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho>10 && tamanho <=100000){
            printf(" %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else if(tamanho == 1000000){
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }else {
            printf(" %d\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
            fprintf(arquivo," %d\t\t\t\t|%f\t\t\t|%f\t\t\t|%f\n",tamanho,media_tempo[i],mediana_tempo[i],devPadrao_tempo[i]);
        }
    }
    printf("\n");
    fprintf(arquivo,"\n");
    return;
}
