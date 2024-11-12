/*Analise o programa C abaixo, identificando possíveis erros e explicando sua saída(se for bem definida)*/

#include <stdio.h>

int main(){
    int x = 5, y = 10;
    int * ptr1 = &x;
    int * ptr2 = &y;

    *ptr1 = *ptr2; //*ptr1 = 10
    ptr2 = ptr1; //ptr2 aponta pra x
    *ptr2 = 20; //*ptr2 = 20

    //output x = 20, y = 10 
    printf("x = %d, y = %d\n",x,y);

    return 0;
}