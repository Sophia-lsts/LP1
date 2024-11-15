/*
Faça um programa em C que:
- Aloque dinamicamente um array de 5 números inteiros;
- Peça para o usuário digitar os 5 números no espaço alocado;
- Mostre os 5 números alocados na tela;
- Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int arr[5] = {1,2,3,4,5};
    int TAM = sizeof(arr)/sizeof(int);
    int *ptr = (int*)malloc((sizeof(int) * TAM));
    int *inicio = ptr;

    for(int i=0;i<TAM;i++) {
        *ptr = arr[i];
        *ptr++;
    }

    ptr = inicio;

    while(TAM > 0){
        printf("%d\n",*ptr);
        TAM--;
        if(TAM>0) *ptr++;  
    }

    //vc pode voltar ptr pro inicio com ptr = inicio e liberar memória tbm

    free(inicio);

    return 0;

}