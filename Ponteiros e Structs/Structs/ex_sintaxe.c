//Conceitos Iniciais: structs – Exemplo Sintaxe
#include <stdio.h>

struct pessoa {
    int idade; // Atributo idade do tipo inteiro
    float altura;// Atributo altura do tipo float
};

typedef struct pessoa Pessoa; // Cria um alias para struct pessoa

int main() {
    Pessoa p; // Declara uma variável do tipo Pessoa
    p.idade = 25; // Atribui valor à idade
    p.altura = 1.75; // Atribui valor à altura

    printf("Idade: %d\n", p.idade); // Imprime a idade
    printf("Altura: %.2f\n", p.altura); // Imprime a altura com duas casas decimais

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}