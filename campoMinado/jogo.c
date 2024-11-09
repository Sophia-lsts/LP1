#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define tamCampo 5

enum casas {Vazio = 0, umaProx = 1, duasProx = 2, tresProx = 3, quatroProx = 4, naoRevelado = 4, Bomba = 5};

int M[tamCampo][tamCampo];
int revelados[tamCampo][tamCampo] = {naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                                    naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                                    naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                                    naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                                    naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado};

void clean(){
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

/*void timer(parametro encontrou bomba ou ganhou)

    int segundos = 0;

    while(parametro encontrou bomba ou ganhou verdadeiro segundos < 20){ // segundos < 20 só de teste
        printf("Your time: %d\r",segundos);
        fflush(stdout);

        sleep(1);

        segundos++;
    };
*/

int verificaCoordenadas(int linha, int coluna) {
    if (linha < 0 || linha >= tamCampo || coluna < 0 || coluna >= tamCampo) return 0; 
    //else if(M[i][j] != 0 || revelados[i][j] != -1) return 0;
    return 1; 
}

void verificaVizinhos(int linha, int coluna){

    int i,j;
    int quantBomb = 0;


    for (i = linha - 1; i <= linha + 1; i++) {
        for (j = coluna - 1; j <= coluna + 1; j++) {
            if(i == linha && j == coluna) continue;
            if(M[i][j] == Bomba && verificaCoordenadas(i,j) == 1) quantBomb++;
        }
    }

    switch(quantBomb){
        case 0:
            M[linha][coluna] = Vazio;
            break;
        case 1:
            M[linha][coluna] = umaProx;
            break;
        case 2:
            M[linha][coluna] = duasProx;
            break;
        case 3:
            M[linha][coluna] = tresProx;
            break;
        case 4:
            M[linha][coluna] = quatroProx;
            break;
        default:
            M[linha][coluna] = Vazio;
            break;
    }
    

}

void preencheCampo(){

    int i;
    int j;

     for (int i = 0; i < tamCampo; i++) {
        for (int j = 0; j < tamCampo; j++) {
            if(M[i][j] != Bomba) verificaVizinhos(i,j);
        }
     }

}

void plantaBomba(){

    int quantBombT = 0;
    int linBomb;
    int colBomb;

    srand(time(NULL));

    while(quantBombT < 3){

        do{
            linBomb = ((rand() % tamCampo)); //antes tava mod 5 + 1, o que poderia gerar índice fora da matriz
            colBomb = ((rand() % tamCampo));
            }
        while((M[linBomb][colBomb] == Bomba)); //não plantar 2 bombas no mesmo lugar
    
        quantBombT++;
        M[linBomb][colBomb] = Bomba;
        
    }

}

void revela(int linha, int coluna){

    if (!verificaCoordenadas(linha, coluna)) return;

    if (M[linha][coluna] == Vazio) {
        revelados[linha][coluna] = Vazio;
    } else {
        return;
    }

    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
                if(!verificaCoordenadas(i,j)) continue;
                if (revelados[i][j] != Vazio) revela(i, j);
            }
        }
    
}

int main(){

    //timer();
    int linha, coluna;

    plantaBomba();
    preencheCampo();

    do{
        printf("lin  ");
        scanf("%d", &linha);
        printf("col  ");
        scanf("%d", &coluna);
        if(verificaCoordenadas(linha,coluna) == 0) {
            printf("Digite coordenadas válidas\n");
            sleep(1);
            clean();
            }
    }
    while(verificaCoordenadas(linha,coluna) == 0);

    switch(M[linha][coluna]){
        case Bomba:
            printf("Você selecionou um local com bomba.\nVocê perdeu");
            exit(1);
        case Vazio:
            revela(linha,coluna);
            break;
        default:
            revelados[linha][coluna] = M[linha][coluna];
    }

    printf("\n   |");
    for (int i = 0; i < tamCampo; i++) printf(" %d |",i);
    printf("\n-------------------------");
    for (int i = 0; i < tamCampo; i++) {
        printf("    \n");
        printf(" %d |",i);
        for (int j = 0; j < tamCampo; j++) {
            if(j == tamCampo -1){
                if(revelados[i][j] != naoRevelado){
                    printf(" %d |\n", revelados[i][j]);
                    printf("------------------------");
                }
                else {
                    printf("   |\n");
                    printf("------------------------");
                }
            }
            else if (revelados[i][j] == naoRevelado){
                 printf("   |"); 
                 }// n foi revelado
            else {
                printf(" %d |", revelados[i][j]);
            }
        }
    }

    printf("\n\n");

    return 0;

}
