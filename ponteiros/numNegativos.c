/*Implemente uma função que receba como parâmetro um array de números reais de 
tamanho N e retorne quantos numeros negativos há nesse array. Essa função ao deve
obedecer ao protótipo:
int negativos(float *vet, int N);*/

#include <stdio.h>

int negativos(float *vet, int N){

    int negativos = 0;

    for(int i = 0; i < N ; i++){
        if(*vet < 0) negativos++;
        *vet++;
    }

    return negativos;
}

int main(){

    float arr[] = {3.14,2.25,8.80,5.30,1.78,-2.56,-5.75};
    int tam = sizeof(arr) / sizeof(float);
    int quant;

    quant = negativos(arr, tam);

    printf("%d\n", quant);

    return 0;

}
