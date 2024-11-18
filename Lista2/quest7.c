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
    int maiorQuant;
    char string1[50] = "";
    char string2[50] = "";

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
        scanf("%d", &produtos[i].codigoID);
        getchar(); //limpar o \n natural do scanf
        fgets(produtos[i].nomeProduto,50,stdin); //diferente do scanf("%s"), ele não ignora os caracteres \n ou espaços em branco
        produtos[i].nomeProduto[strcspn(produtos[i].nomeProduto, "\n")] = '\0'; //isso é obrigatório?
        scanf("%d", &produtos[i].quantidade);
        scanf("%f", &produtos[i].preço);
        printf("\n");
    }

    maiorPreço = produtos[0].preço;
    strcpy(string1, produtos[0].nomeProduto); //pq esses strcpy são necessários
    maiorQuant = produtos[0].quantidade;
    strcpy(string2, produtos[0].nomeProduto);

    for(int i=1;i<quantProdutos;i++){
        if(produtos[i].preço > maiorPreço) {
             maiorPreço = produtos[i].preço;
             strcpy(string1, produtos[i].nomeProduto);
        }
    }

    printf("O produto com maior preço é %s custando %.2f \n",string1, maiorPreço);

    for(int i=1;i<quantProdutos;i++){
        if(produtos[i].quantidade > maiorQuant) {
             maiorQuant = produtos[i].quantidade;
             strcpy(string2, produtos[i].nomeProduto);
        }
    }

    printf("O produto com maior quantidade disponível no estoque é %s com %d unidades.\n",string2, maiorQuant);

    return 0;

}   