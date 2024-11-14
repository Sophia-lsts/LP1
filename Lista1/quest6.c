/*Faça uma função em C que:
- Recebe 3 parâmetros: um vetor de inteiros, um número inteiro n passado por valor e outro número x passado como ponteiro.
- Retorna um número inteiro.
- Decompõe o número n em fatores primos e armazena-os nas posições do vetor. O conteúdo de x deve receber o número de fatores
primos encontrados. Caso o número de fatores encontrados seja maior que 10, a função deve retornar 1, do contrário deve 
retornar 0. 
obs: quis dar uma inovada pra ir gerando os primos conforme vai chegando no número n*/

#include <stdio.h>
#define MAX 30

int primos(int lastP){

    if (lastP < 2) return 2; //menor fator primo
    lastP++;

    while (1) {
        int i, yesno = 1;

        for (i = 2; i * i <= lastP; i++) { //i representa os divisores enquanto seu quadrado for menor que o primo a ser testado,só encontra divisores até a raiz do número
            if (lastP % i == 0) { //se for divisível por algum não é
                yesno = 0;
                break;
            }
        }

        if (yesno) return lastP; //se for já volta
        lastP++; //se não incrementa aq e faz td dnv
    }
}

int decomporFatores(int vect[], int n, int *x){

    int i = 0;
    int menorFator;

    menorFator = 2;
    while(n != 1 && menorFator <= n){
        if(n % menorFator == 0) { //sempre começa testando pelo menos fator primo, o 2
            vect[i] = menorFator;
            n /= menorFator;
            i++;
            for(int j=0;j<i;j++){
                if(j == i-1) (*x)++;
                else if(menorFator == vect[j]) break;
                else continue;
            }
        }
        else menorFator = primos(menorFator);
    }

    if(*x>10) return 1;
    else return 0;
}

int main(){
    int quantPrimos = 0;
    int arr[MAX];

    decomporFatores(arr,2310,&quantPrimos); //testar números no lugar do 210

    printf("Quantidade de fatores primos diferentes encontrados: %d\n", quantPrimos);
    printf("Os diferentes fatores primos foram:");
    for(int i=0;i<quantPrimos;i++) printf(" %d ",arr[i]);
    
}