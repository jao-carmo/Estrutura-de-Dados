//Selection Sort
#include <stdio.h>
#define TAM 5
int main() {
    int numeros[TAM] = {50, 10, 30, 20, 40};
    int i, j, min, temp;

    // Selection Sort
    for (i = 0; i < TAM - 1; i++) {
        min = i;
        for (j = i + 1; j < TAM; j++) {
            if (numeros[j] < numeros[min]) {
                min = j;
            }
        }
        // Troca o elemento mínimo encontrado com o primeiro elemento
        if (min != i) {
            temp = numeros[i];
            numeros[i] = numeros[min];
            numeros[min] = temp;
        }
    }

    // Imprimindo o vetor ordenado
    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}