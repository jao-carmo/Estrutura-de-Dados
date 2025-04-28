#include <stdio.h>

void buscaElemento(int v[], int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        if (v[i] == valor) {
            printf("%d", valor);
            return;
        }
    }
    printf("-1");
}

int main() {
    int v[] = {1,2,3,4,5};
    buscaElemento(v, 5, 1);
    return 0;
}