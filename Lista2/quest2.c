/* Faça um programa em C que receba do usuário a quantidade N de números a ser digitada. Em seguida, o programa deve alocar 
dinamicamente um vetor de N inteiros, receber N números do usuário e armazenar no vetor, e mostrar o maior valor do vetor, o menor
valor do vetor e a média dos valores. */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int *ptr;
    int *inicio;
    int maior,menor;
    float media;

    printf("Digite a quantidade de números que deseja digitar:\n");
    scanf("%d", &n);

    ptr = (int*)malloc(sizeof(int) * n);
    inicio = ptr;

    for(int i=0;i<n;i++) {
        scanf("%d", ptr);
        media += *ptr;
        if(i == 0){
            maior = *ptr;
            menor = *ptr;
        }
        if(*ptr > maior) maior = *ptr;
        if(*ptr < menor) menor = *ptr;
        *ptr++;
    }

    printf("O maior valor do vetor é: %d\n", maior);
    printf("O menor valor do vetor é: %d\n", menor);
    printf("A média dos valores é: %.2f\n", media/n); //pq n funcionaria (maior+menor)/n

    free(inicio);

}