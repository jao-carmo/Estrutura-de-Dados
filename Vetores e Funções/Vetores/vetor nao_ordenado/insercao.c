//Inserção em Vetor Não Ordenado
#include <stdio.h>
#define TAMANHO 10 //Definindo o tamanho máximo do vetor

int main() {
    int vetor[TAMANHO]; //Declarando um vetor de inteiros com o espaço para 10 elementos
    int n = 0;  //Variável que guarda os elementos que ja inserimos

    //Inserindo valores
    vetor[n++] = 10;
    vetor[n++] = 30;
    vetor[n++] = 20;

    printf("Elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Posição %d: %d\n", i, vetor[i]);
    }

    return 0;
}