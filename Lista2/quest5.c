/*Faça um programa em C que aloque dinamicamente uma matriz de inteiros de dimensões definidas pelo usuário e a leia. Em seguida,
implemente uma função que receba um valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso o valor não esteja na matriz.*/

#include <stdio.h>
#include <stdlib.h>

int encontraValor(int num, int **matriz, int m, int n){


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(num == matriz[i][j]) return 1;
        }
    }

    return 0;

}

int main(){

    int lin,col,valor;
    int **ptr = NULL;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d",&lin);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d",&col);

    ptr = malloc(lin * sizeof(int *));
    for(int i=0;i<lin;i++){
        ptr[i] = malloc(col * sizeof(int));
        for(int j=0;j<col;j++){
            scanf("%d", &ptr[i][j]);
        }
    }

    printf("Digite um valor a ser encontrado na matriz: ");
    scanf("%d",&valor);

    if(encontraValor(valor,ptr,lin,col)) printf("O valor está na matriz.\n");
    else printf("O valor não está na matriz.\n");

}