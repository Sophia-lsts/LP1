/*Analise o programa em C abaixo, identificando possíveis erros e explicando sua saída (se for bem definida).*/

#include <stdio.h>

void troca(int ** pp, int * q){ //tradução ponteiro para ponteiro pa, ponteiro pb(q)
    int * temp = *pp; //ponteiro temp aponta para *pa
    * pp = q; //pa(pp) aponta para b
    q = temp; //q recebe endereço do ponteiro temp que aponta para pa, que aponta para b
}

int main(){
    int a = 5, b = 10;
    int * pa = &a;
    int * pb = &b;

    troca(&pa,pb); 

    //os valores não mudam, os ponteiros só trocam pra onde apontam
    //logo, output a = 5, b = 10
    // *pa = 10, *pb = 5

    printf("a = %d, b = %d\n",a,b);
    printf("*pa = %d, *pb = %d\n", *pa,*pb);
}