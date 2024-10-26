#include <stdio.h>

typedef enum {Baixo, Medio, Alto} niveis;

void imprime(int n){

    switch(n){
        case 0:
            n = Baixo;
            printf("Menor prioridade, ocorrência sem emergência.\n");
            break;
        case 1:
            n = Medio;
            printf("Prioridade média, necessário atenção média, possível emergência.\n");
            break;
        case 2:
            n = Alto;
            printf("Riscos altos, enviar ambulância imediatamente.\n");
            break;
        default:
            printf("Número de prioridade não existe.\n");
            break;
    }

}

int main(){

    int num;

    printf("Digite um número:\n");
    scanf("%d", &num);

    imprime(num);

}