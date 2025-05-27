//duplamente encadeada cirucular
#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *anteriro;
    struct No *proximo;
};

void enfileirar(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anteriro = NULL;

    if(*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
        novo->proximo = novo; // Circular
        novo->anteriro = novo; // Circular
    } else {
        novo->proximo = *inicio; // Novo aponta para o início
        novo->anteriro = *fim; // Novo aponta para o fim
        (*fim)->proximo = novo; // Fim aponta para o novo
        (*inicio)->anteriro = novo; // Início aponta para o novo
    }

    printf("Valor %d adicionado à fila.\n", valor);
}

void desenfileirar(struct No **inicio, struct No **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum elemento para remover.\n");
        return;
    }

    struct No *removido = *inicio;
    printf("Removendo valor %d da fila.\n", removido->valor);

    if (*inicio == *fim) { // Se há apenas um elemento
        *inicio = NULL;
        *fim = NULL;
    } else {
        *inicio = removido->proximo; // Atualiza o início
        (*fim)->proximo = *inicio; // Fim aponta para o novo início
        (*inicio)->anteriro = *fim; // Novo início aponta para o fim
    }

    free(removido); // Libera a memória do nó removido
}

void mostrarFila(struct No *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    struct No *atual = inicio;
    printf("Fila: ");
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != inicio);
    printf("\n");
}
//remove o primeiro nó da lista que contenha o valor especifico
void removerPorValor(struct No **inicio, struct No **fim, int valor) {
    if(*inicio == NULL) {
        printf("Fila vazia! Nenhum elemento para remover.\n");
        return;
    }

    struct No *atual = *inicio;
    int encontrado = 0;

    do {
        if (atual->valor == valor) {
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    } while (atual != *inicio);

    if (!encontrado) {
        printf("Valor %d não encontrado na fila.\n", valor);
        return;
    }

    //agora vamos remover o no encontrado
    if (atual == *inicio && atual == *fim) {
        // Se for o único nó
        *inicio = NULL;
        *fim = NULL;
    } else if (atual == *inicio) {
        // Se for o primeiro nó
        *inicio = atual->proximo;
        (*fim)->proximo = *inicio; // Fim aponta para o novo início
        (*inicio)->anteriro = *fim; // Novo início aponta para o fim
    } else if (atual == *fim) {
        // Se for o último nó
        *fim = atual->anteriro;
        (*inicio)->anteriro = *fim; // Início aponta para o novo fim
        (*fim)->proximo = *inicio; // Fim aponta para o início
    } else {
        // Se for um nó do meio
        atual->anteriro->proximo = atual->proximo;
        atual->proximo->anteriro = atual->anteriro;
    }

    printf("Valor %d removido da fila.\n", valor);
    free(atual); // Libera a memória do nó removido
}

int main() {
    struct No *inicio = NULL;
    struct No *fim = NULL;
    int opcao, valor;
    do {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar fila\n");
        printf("4. Remover por valor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&inicio, &fim, valor);
                break;
            case 2:
                desenfileirar(&inicio, &fim);
                break;
            case 3:
                mostrarFila(inicio);
                break;
            case 4:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                removerPorValor(&inicio, &fim, valor);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}