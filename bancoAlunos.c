#include <stdio.h>
#include <string.h>
#define TAM 20

typedef struct{ //os arrays serão a partir dessa struct

    char nome[20];
    int matricula;
    float nota;

} Aluno;

Aluno banco[TAM]; //declarando globalmente para poder modificar na função e funcionar pras outras

//para adicionar preciso posicionar corretamente no array, em ordem de matrícula
//vou adicionar nome do aluno novo e sua nota
void add(int p){

    char name[20];

    printf("Digite o nome do novo aluno:");
    scanf("%s", name);
    strcpy(banco[p].nome,name);

    do{
    printf("Digite uma nota entre 0 e 10:");
    scanf("%f", &banco[p].nota);
    }
    while(banco[p].nota > 10 || banco[p].nota < 0);

    printf("Os dados do aluno que você inseriu foi:\n");
    printf("Nome: %s\n", banco[p].nome);
    printf("Nota correspondente: %.2f\n", banco[p].nota);

}


void exibe(int p){

    int i;

    for(i=1;i<p;i++){
        printf("Aluno(a): %s, Matrícula: %d, Nota: %.2f\n", banco[i].nome, banco[i].matricula, banco[i].nota);
    }

}


//pesquisar pelo número da matrícula, vão ser geradas automático 001, 002...
void pesquisa(int p){

    int n;

    do{
        printf("Digite o número da matrícula do aluno que deseja procurar:\n");
        scanf("%d", &n);
        if(n > p || n < 1){
            printf("Digite um número de matrícula que esteja cadastrado.");
        }
    }
    while(n > p || n < 1);

    printf("Aluno(a) encontrado.\n");
    printf("Nome: %s\n", banco[n].nome);
    printf("Nota correspondente: %.2f", banco[n].nota);

}

int main(){

    int op;
    int matrícula = 1; //contador p matricula
    char segue = 's';

    banco[1].matricula = 1; //inicializando banco da struct matricula no indice 1 com 1 pq (na minha cabe)

    do{

        do{
    printf("Digite a opção do que deseja realizar:\n");
    printf("1 - Adicionar novo aluno\n");
    printf("2 - Exibir todos os alunos cadastrados\n");
    printf("3 - Pesquisar algum aluno pela matrícula\n");
    scanf("%d", &op);
    }
    while(op > 4 || op < 1);

    switch(op){
        case 1:
            add(matrícula);
            matrícula++;
            banco[matrícula].matricula = banco[matrícula-1].matricula + 1; 
            break;
        case 2:
            exibe(matrícula);
            break;
        case 3:
            pesquisa(matrícula);
            break;
    }

    printf("\nDeseja continuar? Digite s se sim ou qualquer outra tecla se não\n");
    getchar();
    scanf("%c", &segue);

    system("cls");

    }
    while(segue == 's');

}