#include <stdio.h>

int function(int arr[], int n, int *x){

    while(n != *arr){
        if(n % *arr) {
            n %= *arr;
            *x += 1;
        }
        else {
            *arr++;
        }
    }

    if(*x > 10) return 1; 
    else return 0;
}


int main(){
    int fatores;
    int arr1[30] = {2,3,5,7,11,13,17,19,23,29};

    function(arr1, 39, &fatores);

    printf("%d", fatores);

}