//Alocação Dinâmica
#include <stdio.h>
#include <stdlib.h> // Para malloc e free
struct ponto {
    float x;
    float y;
};
typedef struct ponto Ponto; // Cria um alias para struct ponto

int main() {
    Ponto *p = (Ponto *) malloc(sizeof(Ponto)); // Aloca memória para um ponto
    p->x = 1;
    p->y = 5;
    printf("Ponto: (%.2f, %.2f)\n", p->x, p->y); // Imprime o ponto
    free(p);
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}