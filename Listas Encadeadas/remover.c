#include <stdio.h>
#include <stdlib.h>
struct No {
    int valor;
    struct No *prox; // Ponteiro para o próximo nó
};
struct No* removerElemento(struct No *head, int valorRemover) {
    // Caso 1: Lista vazia
    if (head == NULL) {
        printf("Lista vazia. Nao ha nada para remover.\n");
        return NULL;
    }
    // Caso 2: verifiar se o valor está no primeiro nó
    if (head->valor == valorRemover) {
        struct No *temp = head; // Armazenando o nó a ser removido
        head = head->prox; // Atualizando o head para o próximo nó
        free(temp); // Liberando a memória do nó removido
        return head; // Retornando o novo head da lista
    }
    // Caso 3: Percorrendo a lista para encontrar o nó a ser removido
    struct No *anterior = head;
    struct No *atual = head->prox;
    while(atual != NULL && atual->valor != valorRemover) {
        anterior = atual; // Avançando o nó anterior
        atual = atual->prox; // Avançando o nó atual
    }
    // Caso 4: Se o nó atual for NULL, o valor não foi encontrado
    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista.\n", valorRemover);
        return head; // Retornando o head sem alterações
    }
    // Caso 5: Removendo o nó encontrado
    anterior->prox = atual->prox; // Atualizando o ponteiro do nó anterior
    free(atual); // Liberando a memória do nó removido
    return head; // Retornando o head da lista

}
// Função para imprimir a lista encadeada
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
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    if (head == NULL) {
        return novoNo;
    }
    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novoNo;
    return head;
}
int main() {
    struct No *lista = NULL;
    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);
    lista = inserirNoFim(lista, 40);
    imprimirLista(lista);
    lista = removerElemento(lista, 30);
    lista = removerElemento(lista, 99);
    lista = removerElemento(lista, 10);
    imprimirLista(lista);
    return 0;
}