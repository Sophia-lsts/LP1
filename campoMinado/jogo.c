#include <stdio.h>
#include <unistd.h>

void timer(/*parametro encontrou bomba ou ganhou*/){

    int segundos = 0;

    while(/*parametro encontrou bomba ou ganhou verdadeiro*/ segundos < 20){ // segundos < 20 só de teste
        printf("Your time: %d\r",segundos);
        fflush(stdout);

        sleep(1);

        segundos++;
    };

}

int main(){

    timer();

    return 0;

}
