#include <stdio.h>
#include <stdlib.h>
struct No {
    int valor;
    struct No *prox; // Ponteiro para o próximo nó
};
struct No* buscarElemento(struct No *head, int valorBuscar) {
    struct No *atual = head; // Começando do head da lista
    while (atual != NULL) { // Percorrendo a lista
        if (atual->valor == valorBuscar) { // Verificando se o valor atual é o que estamos buscando
            return atual; // Retornando o nó encontrado
        }
        atual = atual->prox; // Avançando para o próximo nó
    }
    return NULL; // Retornando NULL se o valor não for encontrado
}
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

    struct No *resultado = buscarElemento(lista, 20);
    if(resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultado->valor, (void*)resultado);
    } else {
        printf("Valor 20 nao encontrado na lista.\n");
    }
    resultado = buscarElemento(lista, 99);
    if(resultado != NULL) {
        printf("Elemento %d encontrado na lista no endereco %p.\n", resultado->valor, (void*)resultado);
    } else {
        printf("Valor 99 nao encontrado na lista.\n");
    }
    return 0;
}