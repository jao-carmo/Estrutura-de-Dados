//Ex2. Correção de Código
//Analise o código abaixo e corrija o erro:
struct Pessoa {
    int idade;
    float altura;
};

int main () {
    struct Pessoa *p;
    p->idade = 20;
    p->altura = 1.75;
}

// O erro está no uso do ponteiro p. Ele não foi alocado a nenhum endereço de memória.
// O que está faltando no código:

#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    int idade;
    float altura;
};

int main () {
    struct Pessoa *p = (struct Pessoa *)malloc(sizeof(struct Pessoa));
    p->idade = 20;
    p->altura = 1.75;

    printf("Idade: %d\n", p->idade);
    printf("Altura: %.2f\n", p->altura);
    free(p);
    return 0;
}