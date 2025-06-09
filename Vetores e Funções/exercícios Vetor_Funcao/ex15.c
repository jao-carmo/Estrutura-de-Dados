#include <stdio.h>
void inserir(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
    printf("Digite o valor da posição %d: ", i);
    scanf("%d", &v[i]);
}
}

void mostrar(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
    printf("%d ", v[i]);
}
    printf("\n");
}

int somar(int v[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
    soma += v[i];
}
    return soma;
}

float media(int v[], int tamanho) {
    return somar(v, tamanho) / (float)tamanho;
}

int main() {
int vetor[5];
int opcao;
do {
    printf("\n1 - Inserir valores\n");
    printf("2 - Mostrar vetor\n");
    printf("3 - Somar elementos\n");
    printf("4 - Calcular média\n");
    printf("5 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
switch(opcao) {
    case 1: inserir(vetor, 5); break;
    case 2: mostrar(vetor, 5); break;
    case 3: printf("Soma: %d\n", somar(vetor, 5)); break;
    case 4: printf("Média: %.2f\n", media(vetor, 5)); break;
    case 5: printf("Saindo...\n"); break;
    default: printf("Opção inválida.\n");
}
} while(opcao != 5);
    return 0;
}