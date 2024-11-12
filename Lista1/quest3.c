/*Analise o programa C abaixo, identificando possíveis erros e explicando sua saída(se for bem definida)*/

#include <stdio.h>

int main(){
    int vet[5] = {10,
                  20,
                  30,
                  40,
                  50};

    int *p = vet; //ponteiro pro início do array vet[0]

    *(p+2) = *(p+4) + 5; //em vet[2] vira 55
    p++; //avança o ponteiro 1 posição no array
    *(p+1) = *p * 2;//ponteiro estava em vet[1] vai para vet[2], e nele guarda o valor para onde ele aponta atualmente(vet[1])
    //multiplicado por 2, ou seja, vet[2] que antes era 55 agr é 40(20*2)

    //output 10 20 40 40 50
    for(int i = 0;i<5;i++){
        printf("%d ",vet[i]);
    }

    return 0;
}