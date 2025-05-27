//Lista duplamente encadeada
#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor; struct No *anteriro;
    struct No *proximo;
};

void inserirInicio(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->anteriro = NULL;
    novo->proximo = *inicio;
    if (*inicio != NULL) {
        (*inicio)->anteriro = novo;
    } else {
        *fim = novo; // Se a lista estava vazia, o novo nó é também o fim
    }
    *inicio = novo;
    printf("Valor %d inserido no início da lista.\n", valor);
}

//inserir elemento no fim da lista
void inserirFim(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = NULL;
    if (*fim != NULL) {
        (*fim)->proximo = novo;
        novo->anteriro = *fim;
    } else {
        *inicio = novo; // Se a lista estava vazia, o novo nó é também o início
    }
    *fim = novo;
    printf("Valor %d inserido no fim da lista.\n", valor);
}

//remover elemento do inicio da lista
void removerInicio(struct No **inicio, struct No **fim) {
    if(*inicio == NULL) {
        printf("Lista vazia! Nenhum elemento para remover.\n");
        return;
    }

    struct No *temp = *inicio;
    printf("Removendo valor %d do início da lista.\n", temp->valor);
    *inicio = temp->proximo;

    if (*inicio != NULL) {
        (*inicio)->anteriro = NULL;
    } else {
        *fim = NULL; // Se a lista ficou vazia, atualiza o fim
    }

    free(temp); // Libera a memória do nó removido
}

//remover elemento do fim da lista
void removerfim(struct No **inicio, struct No **fim) {
    if (*fim == NULL) {
        printf("Lista vazia! Nenhum elemento para remover.\n");
        return;
    }

    struct No *temp = *fim;
    printf("Removendo valor %d do fim da lista.\n", temp->valor);
    *fim = temp->anteriro;

    if (*fim != NULL) {
        (*fim)->proximo = NULL;
    } else {
        *inicio = NULL; // Se a lista ficou vazia, atualiza o início
    }

    free(temp); // Libera a memória do nó removido
}
void mostrarFimAoInicio(struct No *fim) {
    if (fim == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Lista do fim ao início:\n");
    while (fim != NULL) {
        printf("%d ", fim->valor);
        fim = fim->anteriro;
    }
    printf("\n");
}
void removerPorvalor(struct No **inicio, struct No **fim, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia! Nenhum elemento para remover.\n");
        return;
    }
    struct No *atual = *inicio;
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    else if (atual == *inicio) {
        // Se for o primeiro nó
        *inicio = atual->proximo;
        if (*inicio != NULL) {
            (*inicio)->anteriro = NULL;
        } else {
            *fim = NULL; // Se a lista ficou vazia, atualiza o fim
        }
    } else if (atual == *fim) {
        // Se for o último nó
        *fim = atual->anteriro;
        if (*fim != NULL) {
            (*fim)->proximo = NULL;
        } else {
            *inicio = NULL; // Se a lista ficou vazia, atualiza o início
        }
    } else {
        // Se for um nó do meio
        atual->anteriro->proximo = atual->proximo;
        atual->proximo->anteriro = atual->anteriro;
    }
    printf("Valor %d removido da lista.\n", valor);
    free(atual); // Libera a memória do nó removido
}

//função principal com menu
int main() {
    struct No * inicio = NULL, *fim = NULL;
    int opcao, valor;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do início\n");
        printf("4. Remover do fim\n");
        printf("5. Mostrar lista do fim ao início\n");
        printf("6. Remover por valor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir no início: ");
                scanf("%d", &valor);
                inserirInicio(&inicio, &fim, valor);
                break;
            case 2:
                printf("Digite o valor a inserir no fim: ");
                scanf("%d", &valor);
                inserirFim(&inicio, &fim, valor);
                break;
            case 3:
                removerInicio(&inicio, &fim);
                break;
            case 4:
                removerfim(&inicio, &fim);
                break;
            case 5:
                mostrarFimAoInicio(fim);
                break;
            case 6:
                removerPorvalor(&inicio, &fim, valor);
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    // Libera a memória restante
    while (inicio != NULL) {
        struct No *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
    return 0;
}