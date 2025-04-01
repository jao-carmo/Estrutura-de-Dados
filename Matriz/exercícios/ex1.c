//Crie uma matriz 2x2. Peça ao usuário para digitar os 4 valores
//da matriz. Ao final, exiba a matriz linha por linha.

#include <stdio.h>

int main() {
    int matriz[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("digite 4 valores: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}