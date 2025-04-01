#include <stdio.h>

int main() {
    float notas[3][3];

    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("Digite a nota da matéria %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    printf("\nBoletim completo:\n");

    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", notas[i][j]);
        }
        printf("\n");
    }

    printf("\nMedia de cada aluno:\n");

    for (int i = 0; i < 3; i++) {
        float soma = 0;

        for (int j = 0; j < 3; j++) {
            soma += notas[i][j];
        }

        float media = soma / 3.0;
        printf("Aluno %d: %.2f\n", i + 1, media);
    }

    return 0;
}