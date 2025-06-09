#include <stdio.h>
#include <ctype.h>

int main () {
    char alunos[3][20] = {"Ana", "Carlos", "Beatriz"};
    char dias[5][10] = {"Seg", "Ter", "Qua", "Qui", "Sex"};
    char presenca[3][5];
    for (int i = 0; i < 3; i++) {
        printf("\nPresencas para %s: \n", alunos[i]);

        for (int j = 0; j < 5; j++) {
            char valor;

            do{
                printf("%s - Digite 'P' para Present ou 'F' para Falta: ", dias[j]);
                scanf(" %c", &valor);

                valor = toupper(valor);

                if (valor == 'P' || valor == 'F') {
                    presenca[i][j] = valor;
                } else {
                    printf("Entrada inválida! Use apenas P ou F.\n");
                }
            } while (valor != 'P' && valor != 'F');
        }
    }

    printf("\nTabela de Presencas:\n");

    printf("Aluno     |");
    for (int j = 0; j < 5; j++) {
        printf("%s ", dias[j]);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%-10s| ", alunos[i]);
        for (int j = 0; j < 5; j++) {
            printf(" %c ", presenca[i][j]);
        }
        printf("\n");
    }
    return 0;
}