#include <stdio.h>

void ordenar(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int vetor[5] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    ordenar(vetor, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}
