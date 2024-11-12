/*Faça uma função em C que:
- Recebe 3 parâmetros: um vetor de inteiros, um número inteiro n passado por valor e outro número x passado como ponteiro.
- Retorna um número inteiro.
- Decompõe o número n em fatores primos e armazena-os nas posições do vetor. O conteúdo de x deve receber o número de fatores
primos encontrados. Caso o número de fatores encontrados seja maior que 10, a função deve retornar 1, do contrário deve 
retornar 0. 
obs: quis dar uma inovada pra ir gerando os primos conforme vai chegando no número n*/

#include <stdio.h>
#define MAX 30

int primos(int numero){

    int numTeste = 2; //valores de números primos

    while(numTeste<numero){
        for(int i=2;i<numTeste;i++)    
            if(numTeste%i == 0) numTeste++;
        return numTeste;
    }

}

int decomporFatores(int vect[], int n, int *x){

    int primo = 2;
    int i = 0;

    while(primo < n){
        vect[i] = primos(n);
        (*x)++;
        i++;
    }

    if(*x>10) return 1;
    else return 0;
}

int main(){
    int quantPrimos;
    int arr[MAX];

    decomporFatores(arr,50,&quantPrimos);

    printf("%d",quantPrimos);
}