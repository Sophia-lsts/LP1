/*Escreva uma função em C que receba um número real passado como parâmetro, retorne a parte inteira e a parte fracionária desse número. Essa função deve obedecer ao protótipo:
void frac(float num, int *parteInteira, int *parteFracionaria);*/

//Dúvida: como a parte fracionária fica com valor int?

#include <stdio.h>

void frac(float num, int *parteInteira, int *parteFracionaria){

}

int main(){

    float número = 1/3;
    int inteiro;
    float parteDecimal;

    frac(número,&inteiro,&parteDecimal);

    return 0;
}