//Exclusão de um Elemento no Vetor Não Ordenado
#include <stdio.h>
#define TAMANHO 10
int main() {
    int vetor[TAMANHO] = {10,30,20};
    int n = 3;
    int valor = 30;

    int posicao = -1; //Variável para armazenar a posição do valor a excluir(incialmente -1 = não encontrado)
    //Pesquisa para encontrar a posição do valor
    for (int i = 0; i<n; i++) {
        if (vetor[i] == valor) {
            posicao = i;
            break;
        }
    }
    //Verifica se encontrou o valor para excluir
    if (posicao != -1) {
        for (int i = posicao; i < n - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        n--;
        printf("Valor %d excluído.\n", valor);
    }
    //Exibe o vetor atualizado
    printf("Elemetos do vetor após a exclusão:\n");
    for (int i = 0; i<n; i++) {
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    return 0;
}