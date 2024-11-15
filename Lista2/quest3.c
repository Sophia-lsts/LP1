/*Faça um programa em C que receba do usuário o tamanho de uma string e chame uma função para alocar dinamicamente essa string. Em seguida o usuário deverá informar o conteúdo
dessa string e o programa deve imprimir a string sem suas vogais.*/

#include <stdio.h>
#include <stdlib.h>

char* aloc(int tamanho){

    char *ptr = (char*)malloc((sizeof(char) * tamanho) + 1);

    return ptr;
}

int main(){

    int tam;
    char *stringAloc;

    printf("Digite o tamanho da sua string:\n");
    scanf("%d",&tam);
    getchar();

    stringAloc = aloc(tam);

    printf("Digite sua string:\n");
    fgets(stringAloc,tam+1,stdin); //antes tinha colocado só tam, mas tem que ser +1 porque o fgets coloca o \0 no último caracter


    while(*stringAloc != '\0'){
        if(*stringAloc != 'a' && *stringAloc != 'e' && *stringAloc != 'i' && *stringAloc != 'o' && *stringAloc != 'u') printf("%c",*stringAloc);
        *stringAloc++;
    }

    printf("\n");

    return 0;
 
}