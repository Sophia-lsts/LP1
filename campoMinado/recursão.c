#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lin 5

int M[lin][lin];
int revelados[lin][lin];

/* int verificaCoordenadas(int i, int j) {
    if (i < 0 || i >= lin || j < 0 || j >= lin || M[i][j] != 0 || revelados[i][j] != -1) {
        return 0; 
    }
    return 1; 
} */

/*void testeRecursao(int i, int j) {
    if (!verificaCoordenadas(i, j)) return;

    revelados[i][j] = M[i][j];

    if (M[i][j] == 0) {
        testeRecursao(i-1, j);
        testeRecursao(i+1, j);
        testeRecursao(i, j-1);
        testeRecursao(i, j+1);
        testeRecursao(i-1, j-1);
        testeRecursao(i-1, j+1);
        testeRecursao(i+1, j-1);
        testeRecursao(i+1, j+1);
    }
}*/

int main() {

    int i, j;
    int linha, coluna;

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < lin; j++) {
            scanf("%d", &M[i][j]);
            revelados[i][j] = -1;
        }
    }

    printf("Digite a linha e a coluna: ");
    scanf("%d %d", &linha, &coluna);

    //testeRecursao(linha, coluna);

    revelados[linha][coluna] = M[linha][coluna];

    printf("   | 0   1   2   3   4\n");
    printf("------------------------");
    for (int i = 0; i < lin; i++) {
        printf("    \n");
        printf(" %d |",i);
        for (int j = 0; j < lin; j++) {
            if(j == lin -1){
                if(revelados[i][j] != -1){
                    printf(" %d |\n");
                    printf("------------------------");
                }
                else {
                    printf("   |\n");
                    printf("------------------------");
                }
            }
            else if (revelados[i][j] == -1){
                 printf("   |"); 
                 }// n foi revelado
            else {
                printf(" %d |", revelados[i][j]);
            }
        }
    }

    return 0;
}
