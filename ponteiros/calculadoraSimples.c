#include <stdio.h>
#include <stdlib.h>

int calculaSoma(int n1, int n2){

    return n1 + n2;

}

int calculaSub(int n1, int n2){

    return n1 - n2;

}

int calculaMult(int n1, int n2){

    return n1 * n2;

}

int calculaDiv(int n1, int n2){

    if(n2 == 0){
        printf("Erro na divisão, divisor igual a 0.");
        return 0;
    }

    return n1/n2;

}

int main(){

    int (*arr[4])(int, int) = {calculaSoma , calculaSub , calculaMult, calculaDiv};
    //array de ponteiros para funções, precisa especificar os tipos dos parâmetros que vão ser passados.
    int valor;
    int op;
    int number1;
    int number2;

    printf("Digite seu primeiro número:\n");
    scanf("%d", &number1);
    printf("Digite seu segundo número:\n");
    scanf("%d", &number2);

    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("Digite a operação que deseja:\n");
    scanf("%d", &op);

    while(op > 4 || op < 1){
        printf("Essa opção de operação não existe.\n");
        printf("Digite novamente:\n");
        scanf("%d", &op);
    }

    op--;

    switch(op){
        case 0:
            valor = arr[0](number1,number2); //somente na chamada da função atráves do array passa os parâmetros e atribui a valor
            printf("%d", valor);
            break;
        case 1:
            valor = arr[1](number1,number2);
            printf("%d", valor);
            break;
        case 2:
            valor = arr[2](number1,number2);
            printf("%d", valor);
            break;
        case 3:
            valor = arr[3](number1,number2);
            printf("%d", valor);
            break;
    }

    return 0;

}