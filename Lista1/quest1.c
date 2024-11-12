/*Analise o programa em C abaixo, identificando possíveis erros e explicando sua saída(se for definida).*/

/*
#include <stdio.h>

int main(){

    float x = 5.365235, y;
    int * p;

    p = &x; //ponteiro de tipo int para variável de tipo float pode dar erro
    y = *p; //tenta atribuir o valor do ponteiro tipo int para float, undefined behavior

    printf("valor de p: %p\n", p); //printa endereço de memória de X
    printf("valor de y: %f\n", y); // número aleatório

    return 0;

}*/