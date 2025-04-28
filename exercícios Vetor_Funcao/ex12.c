#include <stdio.h>

int cont = 0;
int contarOcorrencias(int v[], int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        if (v[i] == valor) {
            cont++;
        }
    }
    printf("%d", cont);
}

int main() {
    int num[] = {1,1,1,2};
    contarOcorrencias(num, 4, 1);
}