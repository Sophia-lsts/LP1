/*Faça uma função em C que recebe como parâmetro um array com N valores, retornando o maior elemento do array e o número de vezes que esse elemento ocorreu no array. Por exemplo,
para um array com os seguintes elementos: [5,2,15,3,7,15,8,6,15], a função deve retornar para o programa o valor 15 e o valor 3. (indicando que o número 15 ocorreu 3 vezes).
A função deve ser do tipo void*/

#include <stdio.h>

void funcao(int array[], int tamanho){

    int maiorElemento = array[0];
    int frequencia;

    for(int i=1;i<tamanho;i++){
        if(array[i]>maiorElemento) maiorElemento = array[i];
    }

    for(int i = 0;i<tamanho;i++) 
        if(array[i] == maiorElemento) frequencia++;

    printf("Maior elemento: %d\n",maiorElemento);
    printf("Frequência desse elemento: %d\n",frequencia);
}

int main(){

    int arr[10] = {1,4,6,2,18,12,7,9,18,2};
    int TAM = sizeof(arr)/sizeof(int);

    funcao(arr,TAM);

}