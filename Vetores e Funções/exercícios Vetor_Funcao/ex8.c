#include <stdio.h>

float media = 0;
float mediaNotas(float notas[], int qtd) {
    for(int i = 0; i < qtd; i++) {
        media += notas[i];
    }
    media = (media / qtd);
    printf("media das notas: %.2f", media);
}

int main() {
    float v[4];
    printf("Digite 4 notas\n");
    for (int i = 0; i < 4; i++) {
        scanf("%g", &v[i]);
    }
    mediaNotas(v,4);
}