#include <stdio.h>

typedef struct{
    char remedio[30];
    float unidades_t;
    float valor_r;
} Remedio;

Remedio remedios[] = {
    {"Tylenol", 0, 6.50},
    {"Amoxicilina", 0, 20.80},
    {"Nimesulida", 0, 5.00},
    {"Prednisona", 0, 7.80},
    {"Celestamine", 0, 53.60}
};

void total(){

    int i;

    for(i=0;i<5;i++){
        printf("%s teve %.0f unidades vendidas que vendido ao valor de %.2f resultou em %.2f de quantia.\n", remedios[i].remedio, remedios[i].unidades_t, remedios[i].valor_r, remedios[i].unidades_t * remedios[i].valor_r);
    }

}

void maisVendido(){

    int u = 0;
    int v = 0;
    int i;

    for(i=0;i<5;i++){
        if(remedios[i].unidades_t > remedios[u].unidades_t){
            u = i;
        }
    }

        printf("O remédio mais vendido foi %s com %.0f unidades.\n", remedios[u].remedio, remedios[u].unidades_t);

    for(i=0;i<5;i++){
        if(remedios[i].unidades_t * remedios[i].valor_r > remedios[v].unidades_t * remedios[v].valor_r){
            v = i;
        }
    }

    printf("O remédio com maior arrecadamento de vendas foi %s.\n", remedios[v].remedio);

}

void compra(){

    int opção;
    int i;
    float uni;

    printf("Comprar:\n");
    for(i=0;i<5;i++){
        printf("%d - %s %.2f\n",i, remedios[i].remedio, remedios[i].valor_r);
    }

    printf("Qual remédio deseja?\n");
    scanf("%d", &opção);
    printf("Quantas unidades?\n");
    scanf("%f", &uni);

    switch(opção){
        case 0:
            remedios[0].unidades_t += uni;
            break;
        case 1:
            remedios[1].unidades_t += uni;
            break;
        case 2:
            remedios[2].unidades_t += uni;
            break;
        case 3:
            remedios[3].unidades_t += uni;
            break;
        case 4:
            remedios[4].unidades_t += uni;
            break;
    }

}

void menu(){

    printf("Farmácia UNEB\n");
    printf("O que deseja fazer hoje?\n");
    printf("1 - Comprar\n");
    printf("2 - Mais vendidos\n");
    printf("3 - Total Vendas\n");
    printf("4 - Sair\n");

}

int main(){

    char cont;
    int op;

    do{

    menu();

    do{
    printf("Digite sua opção:\n");
    scanf("%d", &op);
        if(op > 4 || op < 1){
            printf("Essa opção não existe!\n");
        }
    }
    while(op > 4 || op < 1);

    system("clear");

    switch(op){
        case 1:
            compra();
            break;
        case 2:
            maisVendido();
            break;
        case 3:
            total();
            break;
        case 4:
            printf("Obrigado por usar a Farmácia UNEB!");
            return 0;
        }

    printf("Você deseja fazer outra operação?\n");
    getchar();
    scanf("%c", &cont);

    system("clear");

    }
    while(cont == 's');

    return 0;

}