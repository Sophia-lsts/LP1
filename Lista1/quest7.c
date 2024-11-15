/*Faça uma função em C que receba duas string como parâmetros e verifique se a segunda string ocorre dentro da primeira. Use aritmética de 
ponteiros para acessar os caracteres das strings.*/

#include <stdio.h>

int strIntoAnother(char *array1, char *array2){

    int *inicio = array2;

    while(*array1 != '\0'){ //louvai e vai
        if(*array1 == *array2){ 
            array1++;
            array2++;
            if(*array2 == '\0') return 1;
        }
        else {
            array1++;
            array2 = inicio;
        }
    }

    return 0;

}

int main(){

    char arr1[15] = "louvai";
    char arr2[10] = "vai";

    if(strIntoAnother(arr1,arr2)) printf("A string 2 está contida na primeira");
    else printf("Não está contida.");

}