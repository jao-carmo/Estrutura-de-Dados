#include <stdio.h>
struct Produto {
    char nome[30];
    float preco;
};
int main() {
    struct Produto produtos[3];
    struct Produto *ptr = produtos;
    //preenchendo os dados usando o ponteiro
    //produto 1
    printf("Digite o nome do produto 1: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 1: ");
    scanf("%f", &ptr->preco);
    ptr++; //avança o ponteiro para o próximo produto
    //produto 2
    printf("Digite o nome do produto 2: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 2: ");
    scanf("%f", &ptr->preco);
    ptr++; //avança o ponteiro para o próximo produto
    //produto 3
    printf("Digite o nome do produto 3: ");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 3: ");
    scanf("%f", &ptr->preco);
    //exibindo os dados
    printf("\n=== Lista de Produtos ===\n");
    for(int i = 0; i < 3; i++) {
        printf("Produto %d: %s, Preco: %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
    return 0;
}