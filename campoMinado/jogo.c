#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define lin 5

int M[lin][lin];
int revelados[lin][lin];

/*void timer(parametro encontrou bomba ou ganhou)

    int segundos = 0;

    while(parametro encontrou bomba ou ganhou verdadeiro segundos < 20){ // segundos < 20 só de teste
        printf("Your time: %d\r",segundos);
        fflush(stdout);

        sleep(1);

        segundos++;
    };
*/

void preencheCampo(){
    int i;
    int j;

    srand(time(NULL));

    for(i=0;i<lin;i++){
        for(j=0;j<lin;j++){
            M[i][j] = ((rand() % 5) + 1);
            revelados[i][j] = -1;
        }
    }

}

void plantaBomba(){

    M[0][0] = 0;
    M[0][1] = 0;
    M[1][0] = 0;
    M[1][1] = 0;

}

int verificaCoordenadas(int i, int j) {
    if (i < 0 || i >= lin || j < 0 || j >= lin || M[i][j] != 0 || revelados[i][j] != -1) {
        return 0; 
    }
    return 1; 
}

int main(){

    //timer();
    int linha, coluna;

    preencheCampo();


    printf("lin  ");
    scanf("%d", &linha);
    printf("col  ");
    scanf("%d", &coluna);

    revelados[linha][coluna] = M[linha][coluna];

    printf("   | 0   1   2   3   4\n");
    printf("------------------------");
    for (int i = 0; i < lin; i++) {
        printf("    \n");
        printf(" %d |",i);
        for (int j = 0; j < lin; j++) {
            if(j == lin -1){
                if(revelados[i][j] != -1){
                    printf(" %d |\n", M[i][j]);
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
                printf(" %d |", M[i][j]);
            }
        }
    }

    return 0;

}
