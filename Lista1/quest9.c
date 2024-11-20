/*Escreva uma função em C que receba um número real passado como parâmetro, retorne a parte inteira e a parte fracionária desse número.
Essa função deve obedecer ao protótipo:
void frac(float num, int *parteInteira, int *parteFracionaria);*/

#include <stdio.h>

void frac(float num, int *parteInteira, int *parteFracionaria) {
    *parteInteira = (int)num;

    float fracionaria = (num - *parteInteira) * 100000;

    *parteFracionaria = (int)(fracionaria);  
}

int main() {
    float número = 8.0 / 3.5;  
    int inteiro;
    int parteDecimal;

    frac(número, &inteiro, &parteDecimal);

    printf("parte inteira: %d\n", inteiro);
    printf("parte fracionária: %d\n", parteDecimal);

    return 0;
}
