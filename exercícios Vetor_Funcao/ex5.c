#include <stdio.h>

int main() {
    int vetor[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }
    for (int i = 0; i < 5; i++) {
        printf("%d", vetor[i]);
    }
}