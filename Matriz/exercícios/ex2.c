#include <stdio.h>

int main() {
    int mat[3][3];
    int soma = 0;
    int media = 0;
    int diagonal = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("digite 9 valores: ");
            scanf("%d", &mat[i][j]);
            soma += mat[i][j];
            if( i == j) {
                diagonal += mat[i][j];
            }
        }
    }
    printf("A soma de todos os elementos: %d\n", soma);
    printf("Média: %d\n", media = (soma / 9));
    printf("A soma da diagonal principal: %d\n", diagonal);
}