//Exclusão em Vetor Ordenado
#include <stdio.h>
#define TAM 10
int main() {
    int vetor[TAM] = {5,10,20,25,30};
    int n = 5;
    int valor = 20;
    int i,j;
    int encontrado = -1;
    //Etapa 1: Procurar o valor no vetor
    for (i = 0; i < TAM; i++) {
        printf("Comparando com posição %d: %d\n", i, vetor[i]);
        if (vetor[i] == valor) {
            encontrado = i;
            printf("Valor %d encontrado na posição %d\n", valor, i);
            break;
        } else if (vetor[i] > valor) {
            printf("Valor não encontrado(interrompido pela ordenação).\n");
            break;
        }
    }
    //Etapa 2: Se encontrarmos, removemos o valor
    if (encontrado != -1) {
        //Deslocar todos os elementos seguintes para a esquerda
        for (j = encontrado; j < n -1; j++) {
            vetor[j] = vetor[j+1];
        }
        n--;
        printf("Valor %d removido do vetor.\n", valor);
    } else {
        printf("Valor %d não encontrado no vetor.\n", valor);
    }
    //Mostrar o vetor atualizado
    printf("Vetor após exclusão: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}