#include <stdio.h>

int maior = 0;
int menor = 1000;
void maiorMenor(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        if(v[i] > maior)
            maior = v[i];
        if(v[i] < menor)
            menor = v[i];
    }

    printf("Maior: %d, Menor: %d\n", maior, menor);
}

int main() {
    int num[5] = {1, 2, 3, 4, 5};
    maiorMenor(num, 5);
    return 0;
}
