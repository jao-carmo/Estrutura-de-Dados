//implementação de fila com vetor
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct Fila {
    int dados[TAM];
    int inicio;
    int fim;
};

void inicializarFila(struct Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int filaCheia(struct Fila *f) {
    return f->fim == TAM;
}

filaVazia(struct Fila *f) {
    return f->inicio == f->fim;
}

void enfilerar(struct Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar %d.\n", valor);
        return;
    }

    f->dados[f->fim] = valor;
    f->fim++;
    printf("Valor %d adicionado à fila.\n", valor);
}

void desenfilerar(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nenhum elemento para remover.\n");
        return;
    }

    int removido = f->dados[f->inicio];
    printf("Removendo valor %d da fila.\n", removido);
    f->inicio++;
}

void mostrarFila(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for(int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

int main() {
    struct Fila fila;
    inicializarFila(&fila);

    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Enfilerar\n");
        printf("2. Desenfilerar\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a adicionar à fila: ");
                scanf("%d", &valor);
                enfilerar(&fila, valor);
                break;
            case 2:
                desenfilerar(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}