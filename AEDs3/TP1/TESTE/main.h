#ifndef incruthia
#define incruthia

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#endif

//-------------------------------/---------------------------------------


#ifndef definicao
#define definicao



#endif


//-------------------------------/---------------------------------------


#ifndef strukt
#define strukt

//E definido as struct do codigo

typedef struct Bomba{

//Sao as barras de bomba, que contem todas as caracteristicas da bomba.
    int id;
    char* tipo;
    int tamanho;
    int x_inicial;
    int y_inicial;
    int x_final;
    int y_final;

}Bomba;

typedef struct Composicao{
//aqui e definido qual e a composicao da mala da bomba

    int* Az; //Az[0] = 1Az Az[1] = 2Az Az[2] = 3Az
    int* Vm; //Vm[0] = 1Vm Vm[1] = 2Vm Vm[2] = 3Vm
    int* Am; //Am[0] = 1Am Am[1] = 2Am Am[2] = 3Am
    int* Vd; //Vd[0] = 1Vd Vd[1] = 2Vd Vd[2] = 3Vd

    int quantidade_de_bombas;

}Composicao;

typedef struct Mala {
//Definindo o que e a caixa da bomba
    char* configuracao;

    Composicao composicao_padrao;
    Composicao composicao_final;

    Bomba *bomba;

    int isValido;

}Mala;

#endif


//-------------------------------/---------------------------------------
