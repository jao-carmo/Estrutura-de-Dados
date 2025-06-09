#include <stdio.h>

int soma = 0;

void somaVetor(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    printf("soma dos vetores: %d", soma);
}

int main() {
    int vetor[6] = {1,2,3,4,5,6};
    somaVetor(vetor,6);
}