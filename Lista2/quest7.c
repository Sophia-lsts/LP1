/*Crie um programa em C que faça o cadastro de produtos de um estoque, com as seguintes informações para cada produto:
- Código de identificação do produto: representado por um valor inteiro;
- Nome do produto: com até 50 caracteres;
- Quantidade disponível no estoque: representado por um número inteiro;
- Preço de venda: represetado por um valor real;

a) Defina uma estrutura, denominada produto, que tenha os campos apropriados para guardar as informações do produto.
b) Crie um conjunto de N produtos (com N sendo fornecido pelo usuário) e peça ao usuário para entrar com as informações de cada produto.
c) Encontre o produto com maior preço de venda.
d) Encontre o produto com a maior quantidade disponível no estoque.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int quantProdutos;
    float maiorPreço;
    char string[50];

    typedef struct{
        int codigoID;
        char nomeProduto[50];
        int quantidade;
        float preço;
    } infos;

    printf("Digite quantos produtos terão o estoque:\n");
    scanf("%d", &quantProdutos);

    infos produtos[quantProdutos];

    printf("Digite as informações de cada produto: Código, Nome, Quantidade, Preço\n");
    for(int i=0;i<quantProdutos;i++){
        scanf("%d", produtos[i].codigoID);
        fgets(string,50,stdin);
        strcpy(produtos[i].nomeProduto, string);
        scanf("%d", produtos[i].quantidade);
        scanf("%f\n", produtos[i].preço);
    }

    maiorPreço = produtos[0].preço;

    for(int i=1;i<quantProdutos;i++){
        if(produtos[i].preço > maiorPreço) {
             maiorPreço = produtos[i].preço;
             strcpy(string, produtos[i].nomeProduto);
        }
    }

    printf("O produto com maior preço é %s custando %.2f \n",string, maiorPreço);

    quantProdutos = produtos[0].quantidade;

    for(int i=1;i<quantProdutos;i++){
        if(produtos[i].quantidade > quantProdutos) {
             quantProdutos = produtos[i].quantidade;
             strcpy(string, produtos[i].nomeProduto);
        }
    }

    printf("O produto com maior quantidade disponível no estoque é %s com %d unidades.", string, quantProdutos);

    return 0;

}   