#include <stdio.h>
#include <stdlib.h>
struct No {
    int valor;
    struct No *prox; // Ponteiro para o próximo nó
}; 
void imprimirLista(struct No *head) {
    struct No *atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor); // Imprimindo o valor do nó atual
        atual = atual->prox; // Avançando para o próximo nó
    }
    printf("NULL\n"); // Indicando o final da lista
}

struct No* inserirNoFim(struct No *head, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = NULL;
    if (head == NULL) {
        return novo;
    }
    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    return head;
}
int main() {
    struct No *lista = NULL;
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);
    imprimirLista(lista);
    return 0;
}