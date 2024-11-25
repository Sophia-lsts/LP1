/*Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. Associe o ponteiro ao array. 
Agora, some mais um (+1) a cada posição do array usando o ponteiro (use *).*/

#include <stdio.h>

int main(){

    int arr[5] = {1,2,3,4,5};
    int *ptr = &arr[0];

    for(int i = 0; i < 5 ; i++){
        (*ptr)++;
        *ptr++;
    }

    for(int i = 0; i < 5 ; i++){
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;

}