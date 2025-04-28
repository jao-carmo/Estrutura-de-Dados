#include <stdio.h>

int main() {
    char aluno[3][20] = {"Joao", "Pedro", "Yasmin"};
    char materias[3][20] = {"Portugues", "Matematica", "Geografia"};
    int mat[3][3];

    for(int i = 0; i < 3; i++) {
        printf("Aluno: %s \n", aluno[i]);
        for(int j = 0; j < 3; j++) {
            printf("Matéria: %s \nNota:", materias[j]);
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        float media = 0;
        printf("Aluno: %s \n", aluno[i]);
        for(int j = 0; j < 3; j++) {
            media += mat[i][j];
        }
        printf("Média: %.2f\n", media / 3);
    }

    for(int j = 0; j < 3; j++) {
        float media = 0;
        printf("Matéria: %s \n", materias[j]);
        for(int i = 0; i < 3; i++) {
            media += mat[i][j];
        }
        printf("Média: %.2f\n", media / 3);
    }
}
