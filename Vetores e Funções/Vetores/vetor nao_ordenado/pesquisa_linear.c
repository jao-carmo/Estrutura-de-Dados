//Pesquisa Linear em Vetor Não Ordenado
#include <stdio.h>
#define TAMANHO 10

int main() {
    int vetor[TAMANHO] = {10, 30, 20};
    int n = 3;
    int valor = 30;

    int encontrado = -1;    //Variável para armazenar a posição do valor(inicialmente - 1 = não encontrado)

    //Pesquisa linear: percorre o vetor do começo ao fim
    for (int i = 0; i<n; i++) {
        if (vetor[i] == valor) {
            encontrado = i;
            break;
        }
    }

    //Mostrando o resultado da pesquisa
    if (encontrado != -1) {
        printf("Valor %d encontrado na posição %d.\n", valor, encontrado);
    } else {
        printf("Valor %d não encontrado.\n", valor);
    }
    
    return 0;
}