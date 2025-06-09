//Array Estático
#include <stdio.h>

int main(){
    int vetor[5];
    int n = 0;

    vetor[n++] = 10; // Adiciona 10 ao vetor
    vetor[n++] = 40; // Adiciona 40 ao vetor
    vetor[n++] = 20; // Adiciona 20 ao vetor

    printf("Vetor não ordenado (Array Estático):\n");
    for(int i = 0; i < n; i++){
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    return 0; 
}