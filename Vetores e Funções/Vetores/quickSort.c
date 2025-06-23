//QuickShort é um algoritmo de ordenação eficiente que utiliza a técnica de divisão e conquista. ele é diferente do BubbleSort, SelectionSort e InsertionSort, pois não é um algoritmo de ordenação estável. O QuickSort é geralmente mais rápido que esses algoritmos em listas grandes, mas sua eficiência depende da escolha do pivô. A complexidade média do QuickSort é O(n log n), enquanto a pior caso é O(n^2) se o pivô for escolhido de forma ineficiente.
#include <stdio.h>
#define TAM 6

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//quickSort
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = vetor[inicio];
        int i = inicio + 1;
        int j = fim;
        while (i <= j) {
            while (i <= fim && vetor[i] <= pivo) {
                i++;
            }
            while (j >= inicio && vetor[j] > pivo) {
                j--;
            }
            if (i < j) {
                troca(&vetor[i], &vetor[j]);
                i++;
                j--;
            }
        }
        trocar(&vetor[inicio], &vetor[j]);

        quickSort(vetor, inicio, j - 1);
        quickSort(vetor, j + 1, fim);
    }
}