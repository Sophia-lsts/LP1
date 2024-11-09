#include <stdio.h>

//falta implementar lógica das quinas pra evitar erros

enum casas {Vazio = 0, Outros = 1, naoRevelado = 2};

int M[5][5] = {Outros,Outros,Outros,Outros,Vazio,
               Vazio,Vazio,Outros,Vazio,Vazio,
               Vazio,Vazio,Vazio,Outros,Outros,
               Vazio,Vazio,Outros,Outros,Outros,
               Outros,Outros,Outros,Outros,Outros};

int revelados[5][5] = {naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                       naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                       naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                       naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado,
                       naoRevelado,naoRevelado,naoRevelado,naoRevelado,naoRevelado};

int verificaCoordenada(int linha, int coluna){
    if(linha > 4 || linha < 0 || coluna > 4 || coluna < 0) return 1;
    else return 0;
}

void revela(int linha, int coluna){
    int i, j;

    if (verificaCoordenada(linha, coluna)) return;
    if (revelados[linha][coluna] == 0) return;

    if (M[linha][coluna] == Vazio) {
        revelados[linha][coluna] = Vazio;
    } else {
        return;
    }

    for (i = linha - 1; i <= linha + 1; i++) {
        for (j = coluna - 1; j <= coluna + 1; j++) {
            if (verificaCoordenada(i, j) == 0 && revelados[i][j] != 0) {
                revela(i, j);
            }
        }
    }
}

int main(){
    int i, j, lin, col;

    printf("linha: ");
    scanf("%d", &lin);
    printf("coluna: ");
    scanf("%d", &col);

    revela(lin, col);

    for (i = 0; i < 5; i++) {
        printf("\n");
        for (j = 0; j < 5; j++) {
            if(revelados[i][j] != naoRevelado) printf(" %d ", revelados[i][j]);
            else printf("   ");
        }
    }

    return 0;
}
