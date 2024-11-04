#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define lin 5
/*

revelados tudo tem -1


*/
void timer(/*parametro encontrou bomba ou ganhou*/){

    int segundos = 0;

    while(/*parametro encontrou bomba ou ganhou verdadeiro*/ segundos < 20){ // segundos < 20 só de teste
        printf("Your time: %d\r",segundos);
        fflush(stdout);

        sleep(1);




        segundos++;
    };

}

int M[lin][lin];
int revelados[lin][lin];

void preencheCampo(){
    int i;
    int j;


    srand(time(NULL));

}

void verificaCoordenadas(int i, int j){

    if(i > 4 || i < 0 || j > 4 || j < 0) return 0;
    else if (M[i][j] != 0) {

    }
    else return 1;

}

void testeRecursao(int i, int j){

    if(M[i][j] != 0){
        revelados[i][j] = M[i][j];
    }
    else if(M[i][j] == 0){
        revelados[i][j] = 0;
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
            scanf("%d", &M[i][j]);
            revelados[i][j] = -1;
        }
    }

    for(i=0;i<lin;i++){
        printf("\n");
        for(j=0;j<lin;j++){
            printf(" %d ", M[i][j]);
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
            if(revelados[i][j] == 0){
            printf("  ");
            }

        }
    }

    return 0;

}
