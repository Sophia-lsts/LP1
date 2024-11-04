#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define lin 5

void timer(/*parametro encontrou bomba ou ganhou*/){

    int segundos = 0;

    while(/*parametro encontrou bomba ou ganhou verdadeiro*/ segundos < 20){ // segundos < 20 só de teste
        printf("Your time: %d\r",segundos);
        fflush(stdout);

        sleep(1);




        segundos++;
    };

}

typedef struct {
    int branco;
} nada;

nada M[lin][lin];

/*void preencheCampo(){
    int i;
    int j;


    srand(time(NULL));



}*/

void testeRecursao(int i, int j){

    if(M[i][j].branco == 0){
        M[i][j].branco = 0;

        testeRecursao(i-1,j+1);
        testeRecursao(i-1,j-1);
        testeRecursao(i-1, j);
        testeRecursao(i, j-1);
        testeRecursao(i, j+1);
        testeRecursao(i+1, j+1);
        testeRecursao(i+1, j-1);
        testeRecursao(i+1, j);
    }

}

int main(){

    //timer();
    int i;
    int j;
    int linha, coluna;

    for(i=0;i<lin;i++){
        for(j=0;j<lin;j++){
            scanf("%d", &M[i][j].branco);
        }
    }

    for(i=0;i<lin;i++){
        printf("\n");
        for(j=0;j<lin;j++){
            printf(" %d ", M[i][j].branco);
        }
    }

    printf("/nlin");
    scanf("%d", &linha);
    printf("/ncol");
    scanf("%d", &coluna);

    testeRecursao(linha, coluna);

    for(i=0;i<lin;i++){
        printf("\n");
        for(j=0;j<lin;j++){
            printf(" %d ", M[i][j].branco);
        }
    }

    return 0;

}
