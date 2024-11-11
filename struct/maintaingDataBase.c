#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int num_p;
    char nome_p[50];
    int quant_p;
    } armz;

armz total[50] = {
    {50, "Vela de ignição", 10},
    {51, "Filtro de óleo", 20}
};

void clean(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int newNum(int p){

    int a = 0;
    int b = 0;
    int i;
    int número;
    int qtd;
    char nome[50];

    do{
        a = 0;
        b = 0;

        printf("Digite um novo número de peça:\n");
        scanf("%d", &número);

        printf("Digite um novo nome de peça:\n");
        getchar();
        fgets(nome, sizeof(nome)/ sizeof(nome[0]) ,stdin);

        printf("Digite a quantidade desejada:\n");
        scanf("%d", &qtd);

        nome[strcspn(nome, "\n")] = 0;

        for(i=0;i<p;i++){
            if(número == total[i].num_p){
                printf("Você digitou um número de peça que já tem no armazém.\n");
                clean();
                break;
            }
            else if(i == p-1){
                a = 1;
            }
        }

        for(i=0;i<p;i++){
            if(strcasecmp(nome, total[i].nome_p) == 0){
                printf("Você digitou um nome de peça que já tem no armazém.\n");
                clean();
                break;
            }
            else if(i == p-1){
                b = 1;
            }
        }

    }
    while((a != 1) || (b != 1));

    total[p].num_p = número;
    total[p].quant_p = qtd;
    strcpy(total[p].nome_p, nome);
    p++;

    return p;

}

void showP(int p){

    int a = -1;
    int i;
    int num;

    do{
    printf("Digite o número da peça que deseja ver:\n");
    scanf("%d", &num);

        for(i=0;i<p;i++){
            if((num == total[i].num_p)){
                a = i;
                break;
            }
            else if(i == p-1){
                printf("A peça com número que digitou não está no armazém. Tente novamente.\n");
                clean();
            }
            else{
                continue;
            }
        }

    }
    while(a == -1);

    printf("Peça encontrada, Nome: %s, Quantidade: %d.\n",total[a].nome_p, total[a].quant_p);
}

void modify(int p){

    int a = -1;
    int num;
    int i;

    do{
    printf("Digite o número da peça que deseja ver:\n");
    scanf("%d", &num);

        for(i=0;i<p;i++){
            if((num == total[i].num_p)){
                a = i;
                break;
            }
            else if(i == p-1){
                printf("A peça com número que digitou não está no armazém. Tente novamente.\n");
                clean();
            }
            else{
                continue;
            }
        }
    }
    while(a == -1);

    printf("Para quanto você deseja modificar de quantidade desse produto?\n");
    scanf("%d", &total[a].quant_p);

}

void prtEverything(int p){

    int i;

    printf("------------------------------ESTOQUE DO ARMAZÉM------------------------------\n\n");
    for(i=0;i<p;i++){
        printf("Número da peça: %d ,", total[i].num_p);
        printf("Nome da peça: %s ,", total[i].nome_p);
        printf(" Quantidade dessa peça: %d\n", total[i].quant_p);
        printf("------------------------------------------------------------------------------\n");
    }

}

int menu(){

    int p;

    printf("MENU\n");

    do{
    printf("Opções:\n");
    printf("1 - Adicionar uma nova peça ao seu estoque e suas informações.\n");
    printf("2 - Buscar peça pelo número.\n");
    printf("3 - Alterar quantidade no estoque de um produto.\n");
    printf("4 - Vizualizar todo o estoque.\n");
    printf("5 - Sair.\n");
    printf("Digite o número de sua opção: ->");
    scanf("%d", &p);

        if(p > 5 || p < 1){
            printf("Digite uma opção válida:\n");
            clean();
        }
    }
    while(p > 5 || p < 1);

    return p;

}

void close(){
    printf("Obrigado por usar o mini sistema de armazém");
    exit(0);
}

int main(){

    int op;
    char segue;
    int TAM = 2;

    
    do {

    op = menu();
    clean();

        switch(op){
            case 1:
                TAM = newNum(TAM);
                break;
            case 2:
                showP(TAM);
                break;
            case 3:
                modify(TAM);
                break;
            case 4:
                prtEverything(TAM);
                break;
            case 5:
                close();
        }

    printf("Deseja realizar outra operação? Digite s para sim ou qualquer outra tecla para não.\n");
    getchar();
    scanf("%c", &segue);
    clean();
    
    } 
    while(segue == 's');

    printf("Obrigado por usar o mini sistema de armazém");

}