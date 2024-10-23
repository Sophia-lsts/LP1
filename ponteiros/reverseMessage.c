#include <stdio.h>
#define TAM_MAX 70

void reverse(char *a, int tam){

    int i = 0;
    int aux;

    for(i=0;i<tam/2;i++){
        aux = *(&a[i]);
        *(&a[i]) = *(&a[tam - 1 - i]);
        *(&a[tam- 1 - i]) = aux;
    }

}

int main(){

    char arr[TAM_MAX];
    int size;

    printf("Enter a message: \n");
    fgets(arr, TAM_MAX, stdin);

    size = 0;

    while(arr[size] != '\0'){
        size++;
    }

    reverse(arr, size);

    printf("%s", arr);

}
