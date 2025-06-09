//Lista Encadeada(Cada elemento aponta para o próximo.)
#include <stdio.h>
#include <stdlib.h> // Para malloc e free
typedef struct No {
    int valor;
    struct No* proximo;
} No;
void inserir_inicio(No** cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No)); // Aloca memória para o novo nó
    novo->valor = valor; // Define o valor do novo nó
    novo->proximo = *cabeca; // O próximo do novo nó é o atual cabeçalho
    *cabeca = novo; // Atualiza o cabeçalho para o novo nó
}
void imprimir(No *inicio) {
    No* atual = inicio; // Começa do início da lista
    while (atual != NULL) { // Enquanto não chegar ao final da lista
        printf("%d -> ", atual->valor); // Imprime o valor do nó atual
        atual = atual->proximo; // Move para o próximo nó
    }
    printf("NULL\n"); // Indica o final da lista
}
int main() {
    No *lista = NULL; // Inicializa a lista como vazia
    inserir_inicio(&lista, 30); // Insere 30 no início
    inserir_inicio(&lista, 20); // Insere 20 no início
    inserir_inicio(&lista, 10); // Insere 10 no início
    imprimir(lista); // Imprime a lista
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}