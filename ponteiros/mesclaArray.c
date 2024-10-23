#include <stdio.h>

void mesclaArray(int *a1, int *a2, int *a3, int tam1, int tam2){

    while(tam1 != 0){
        *a3 = *a1;
        *a3++;
        *a1++;
        tam1--;
    }

    while(tam2 != 0){
        *a3 = *a2;
        *a3++;
        *a2++;
        tam2--;
    }

}

int main(){

    int i = 0;
    int arr1[3] = {1 , 2 , 3};
    int arr2[5] = {4 , 1, 7, 2, 12};
    int arr3[8];
    int tam3;

    mesclaArray(arr1,arr2,arr3,3,5);

    for(i=0;i<8;i++){
        printf("%d ", arr3[i]);
    }

    return 0;
}