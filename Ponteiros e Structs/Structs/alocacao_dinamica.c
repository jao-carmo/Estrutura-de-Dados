//Alocaçao Dinâmica
#include <stdio.h>
#include <stdlib.h>

struct ponto {
    float x;
    float y;
};

typedef struct ponto Ponto; // Define um novo tipo chamado Ponto baseado na estrutura ponto

int main() {
    Ponto *p = (Ponto *)malloc(sizeof(Ponto)); // Aloca memória para um ponto
    p->x = 1; // Atribui o valor 1.0 ao campo x do ponto
    p->y = 5; // Atribui o valor 2.0 ao campo y do ponto
    printf("Ponto: (%.2f, %.2f)\n", p->x, p->y); // Imprime o ponto formatado com duas casas decimais
    free(p); // Libera a memória alocada para o ponto
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}