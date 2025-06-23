//Bubble Sort ele é diferente do QuickSort, SelectionSort e InsertionSort, pois é um algoritmo de ordenação estável. O Bubble Sort é geralmente mais lento que esses algoritmos em listas grandes, mas é fácil de entender e implementar. A complexidade do Bubble Sort é O(n^2) no pior caso, o que o torna ineficiente para listas grandes.
#include <stdio.h>
#define TAM 5
int main() {
    int numeros[TAM] = {50, 10, 30, 20, 40};
    int i, j, temp;
    // Bubble Sort
    for (i = 0; i < TAM - 1; i++) {
        for (j = 0; j < TAM - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
    // imprimindo o vetor ordenado
    printf("Vetor ordenado: ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    return 0;
}