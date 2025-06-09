#include <stdio.h>
// Definindo a estrutura Endereco  
struct Endereco {
    char rua[50]; // Atributo 'rua' do tipo string (array de caracteres)
    int numero; // Atributo 'numero' do tipo inteiro
};
// Definindo a estrutura Pessoa, que contém um campo do tipo Endereco
struct Pessoa {
    char nome[50]; // Atributo 'nome' do tipo string (array de caracteres)
    int idade; // Atributo 'idade' do tipo inteiro
    struct Endereco endereco; // Atributo 'endereco' do tipo Endereco
};
int main() {
    struct Pessoa p; // Declara uma variável do tipo Pessoa
    // Solicitando e lendo o nome da pessoa (sem espaços)
    printf("Digite o nome: ");
    scanf("%s", p.nome); // Lê o nome (sem espaços)
    // Solicitando e lendo a idade da pessoa
    printf("Digite a idade: ");
    scanf("%d", &p.idade); // Lê a idade
    // Solicitando e lendo o nome da rua (sem espaços)
    printf("Digite o nome da rua: ");
    scanf("%s", p.endereco.rua); // Lê o nome da rua (sem espaços)
    // Solicitando e lendo o número da residência
    printf("Digite o numero da casa: ");
    scanf("%d", &p.endereco.numero); // Lê o número da casa
    // Exibindo os dados coletados
    printf("\n--- Dados Cadastrados ---\n");
    printf("Nome: %s\n", p.nome); // Exibe o nome
    printf("Idade: %d\n", p.idade); // Exibe a idade
    printf("Enedereço: Rua %s, N° %d\n", p.endereco.rua, p.endereco.numero); // Exibe o endereço completo
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}