//Passagem por ponteiro
#include <stdio.h>
#include <stdlib.h> // Para malloc e free
struct Pessoa {
    char nome[100]; // Atributo 'nome' do tipo string (array de caracteres)
    int idade; // Atributo 'idade' do tipo inteiro
    float altura; // Atributo 'altura' do tipo float
};
void atualizarIdade(struct Pessoa *p) { // Passa o ponteiro da estrutura
    p->idade += 1; // Atualiza a idade usando o ponteiro
}
int main() {
    struct Pessoa pessoa; // Declara uma variável do tipo Pessoa
    strcpy(pessoa.nome, "Ana Paula"); // Atribui o nome "Ana Paula"
    pessoa.idade = 25;
    pessoa.altura = 1.65;
    printf("Antes (por ponteiro): %d anos\n", pessoa.idade); // Imprime a idade antes da atualização
    atualizarIdade(&pessoa); // Chama a função para atualizar a idade passando o endereço
    printf("Depois (por ponteiro): %d anos\n", pessoa.idade); // Imprime a idade depois da atualização
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso 
}