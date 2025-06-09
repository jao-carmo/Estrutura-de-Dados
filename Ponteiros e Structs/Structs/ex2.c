#include <stdio.h>
//Definindo a estrutura chamada 'Pessoa'
struct Pessoa {
    char nome[50]; // Atributo 'nome' do tipo string (array de caracteres)
    int idade; // Atributo 'idade' do tipo inteiro
    float altura; // Atributo 'altura' do tipo float
};

int main() {
    struct Pessoa pessoa[3]; // Declara um array de 3 estruturas 'Pessoa'
    int i; // Variável de controle para o loop
    // Loop para ler os dados de cada pessoa
    for (i = 0; i < 3; i++) {
        printf("\n--- Pessoa %d ---\n", i + 1); // Solicita o nome
        printf("Digite o nome: ");
        scanf(" %[^\n]", pessoa[i].nome); // Lê o nome (inclui espaços)
        printf("Digite a idade: ");
        scanf("%d", &pessoa[i].idade); // Lê a idade
        printf("Digite a altura: ");
        scanf("%f", &pessoa[i].altura); // Lê a altura
    }
    //Exibição dos dados coletados
    printf("\n\n====== Lista de Pessoas Cadastradas ======\n");
    for (i = 0; i < 3; i++) {
        printf("\nPessoa %d:\n", i + 1); // Exibe o número da pessoa
        printf("Nome: %s\n", pessoa[i].nome); // Exibe o nome
        printf("Idade: %d\n", pessoa[i].idade); // Exibe a idade
        printf("Altura: %.2f\n", pessoa[i].altura); // Exibe a altura com duas casas decimais
    }
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}