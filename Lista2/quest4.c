/*Analisando o código abaixo, crie uma função em C que desaloque a matriz M alocada.*/

#include <stdio.h>
#include <stdlib.h>

void liberaMemoria(int **matriz,int first){

    int *ptr = *matriz;

    for(int i = 0; i < first; i++) {
        free(ptr);
        *ptr++;
    }
}

int main(){

    //o código analisando é essa parte do main

    int m=0, n=0;
    int **M = NULL;
    M = malloc (m * sizeof ( int *)); //alocando m ponteiros do tipo inteiro
    for(int i = 0; i < m; i++){
        M[i] = malloc ( n * sizeof(int)); //alocando n inteiros para cada unidade de m
        for(int j = 0; j < n; j++){
            M[i][j] = 0; //preenchendo a matriz com zeros
        }
    }

    liberaMemoria(M,m);

}