/*Faça uma função em C que calcule a área da superfície e volume de uma esfera de raio R. Essa função desse obederecer ao protótipo:
void calcEsfera(float R, float *area, float *volume)*/

#include <stdio.h>

void calcEsfera(float R, float *area, float *volume){

    *area = 4 * 3.14 * R * R;
    *volume = (*area * R)/3 ;

}

int main(){
    
    float raio = 5;
    float A;
    float V;

    calcEsfera(raio, &A, &V);

    printf("A área foi: %.2f\n", A);
    printf("O volume foi: %.2f\n",V);
}