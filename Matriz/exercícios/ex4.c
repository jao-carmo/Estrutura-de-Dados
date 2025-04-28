#include <stdio.h>

int main() {
    char mat[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat[i][j] = ' ';
        }
    }
    for (int jogada = 0; jogada < 9; jogada++) {
        int linha, coluna;
        char jogador;

        printf("\nJogador (X ou O): ");
        scanf(" %c", &jogador);

        printf("Informe a linha (0 a 2): ");
        scanf("%d", &linha);

        printf("Informe a coluna (0 a 2): ");
        scanf("%d", &coluna);

        if (mat[linha][coluna] == ' ') {
            mat[linha][coluna] = jogador;
        } else {
            printf("Posição ocupada! Tente novamente.\n");
            jogada--;
            continue;
        }

        printf("\n   0   1   2\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i);
            for (int j = 0; j < 3; j++) {
                printf(" %c ", mat[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("  ---+---+---\n");
        }
    }
    return 0;
}
