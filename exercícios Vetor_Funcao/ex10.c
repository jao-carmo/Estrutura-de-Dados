#include <stdio.h>

int parOuImpar(int numero) {
    if (numero % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numero;
    for (int i = 1; i <= 5; i++) {
        printf("Digite o %dº número: ", i);
        scanf("%d", &numero);

        if (parOuImpar(numero)) {
            printf("O número %d é par.\n", numero);
        } else {
            printf("O número %d é impar.\n", numero);
        }
    }
    return 0;
}
