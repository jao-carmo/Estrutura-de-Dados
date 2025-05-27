//fila circular
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

//strutura fila
struct Fila {
    int dados[TAM];
    int inicio;
    int fim;
    int quantidade;
};

void inicializarFila(struct Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int filaCheia(struct Fila *f) {
    return f->quantidade == TAM;
}

int filaVazia(struct Fila *f) {
    return f->quantidade == 0;
}  

void enfilerirar(struct Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar %d.\n", valor);
        return;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAM; // Incrementa o fim circularmente
    f->quantidade++;
    printf("Valor %d adicionado à fila.\n", valor);
}

void desenfilerar(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nenhum elemento para remover.\n");
        return;
    }

    int removido = f->dados[f->inicio];
    printf("Removendo valor %d da fila.\n", removido);
    f->inicio = (f->inicio + 1) % TAM; // Incrementa o início circularmente
    f->quantidade--;

    printf("Valor %d removido da fila.\n", removido);
}

void mostrarFila(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: ");
    int i = f->inicio;
    int count = 0;

    while(count < f->quantidade) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % TAM; // Incrementa o índice circularmente
        count++;
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
                enfilerirar(&fila, valor);
                break;
            case 2:
                desenfilerar(&fila);
                break;
            case 3:
                mostrarFila(&fila);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}