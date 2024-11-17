/*Crie um programa em C que declare uma estrutura(registro) para o cadastro de alunos, no qual:
- Deverão ser armazenados para cada aluno: matrícula, sobrenome (apenas um), e ano de nascimento;
- Ao início do programa, o usuário deverá informar o número de alunos que serão armazenados;
- O programa deverá alocar dinamicamente a quantidade necessária de memória para armazenar os registros dos alunos;
- O programa deverá pedir ao usuário que entre com as informações dos alunos;
- Ao final, mostrar os dados armazenados e liberar a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    typedef struct{
        int matrícula;
        char sobrenome[20];
        int anoNasc;
    } Cadastro;

    int numeroAlunos;
    char string[20];
    Cadastro *total;

    printf("Digite o número de alunos que serão armazenados: ");
    scanf("%d",&numeroAlunos);

    total = (Cadastro *)malloc(numeroAlunos * sizeof(Cadastro));

    printf("Digite as informações dos alunos em ordem: Matrícula, Sobrenome, Ano de Nascimento\n");

    for(int i=0;i<numeroAlunos;i++){
        scanf("%d", &total[i].matrícula);
        scanf("%s", total[i].sobrenome);
        scanf("%d", &total[i].anoNasc);
        printf("\n");
    }

    system("clear");

    for(int i=0;i<numeroAlunos;i++){
        printf("%d ", total[i].matrícula);
        printf("%s ", total[i].sobrenome);
        printf("%d", total[i].anoNasc);
        printf("\n");
    }

    free(total);

}