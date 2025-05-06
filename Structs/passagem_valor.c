//Passagem por valor
#include <stdio.h>
#include <stdlib.h> // Para malloc e free
struct Pessoa {
    char nome[100]; // Atributo 'nome' do tipo string (array de caracteres)
    int idade; // Atributo 'idade' do tipo inteiro
    float altura; // Atributo 'altura' do tipo float
};
void atualizarIdade(struct Pessoa p) {
    p.idade += 1;
}
int main() {
    struct Pessoa pessoa; // Declara uma variável do tipo Pessoa
    strcpy(pessoa.nome, "Ana Paula"); // Atribui o nome "Ana Paula"
    pessoa.idade = 25;
    pessoa.altura = 1.65;
    printf("Antes (por valor): %d anos\n", pessoa.idade); // Imprime a idade antes da atualização
    atualizarIdade(pessoa); // Chama a função para atualizar a idade
    printf("Depois (por valor): %d anos\n", pessoa.idade); // Imprime a idade depois da atualização
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}