//Array Dinâmico(com malloc) Um vetor criado em tempo de execução usando malloc().
//Pode ser ajustado conforme o tamanho que precisamos
#include <stdio.h>
#include <stdlib.h> // Para malloc e free
int main() {
    int *vetor;
    int n = 0;
    int tamanho = 5; // Tamanho inicial do vetor

    vetor = malloc(tamanho * sizeof(int)); // Aloca memória para o vetor

    vetor[n++] = 15; // Adiciona 15 ao vetor
    vetor[n++] = 25; // Adiciona 25 ao vetor
    vetor[n++] = 5; // Adiciona 5 ao vetor   

    printf("Vetor não ordenado (Array Dinâmico):\n");
    for (int i = 0; i < n; i++) {
        printf("Posição %d: %d\n", i, vetor[i]);
    }

    free(vetor); // Libera a memória alocada

    return 0;
}