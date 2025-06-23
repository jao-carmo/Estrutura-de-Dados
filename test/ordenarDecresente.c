#include <stdio.h>

void ordenarDecresente(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (v[i] < v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int vetor[10];
    printf("Digite 10 numeros inteiros:\n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }
    ordenarDecresente(vetor, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}