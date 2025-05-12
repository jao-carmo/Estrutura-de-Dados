#include <stdio.h>
#include <stdlib.h>
//Definindo a estrutura do nó da lista
struct No {
    int valor;
    struct No *prox; // Ponteiro para o próximo nó
};
//Função para inserir um novo nó no início da lista
struct No* inserirNoInicio(struct No *head, int novoValor) {
    struct No *novoNo = (struct No*)malloc(sizeof(struct No)); // Alocando memória para o novo nó
    novoNo->valor = novoValor; // Atribuindo o valor ao novo nó
    novoNo->prox = head; // O próximo nó do novo nó é o atual head
    return novoNo; // Retornando o novo nó como o novo head da lista
}
//Função para imprimir a lista encadeada
void imprimirLista(struct No *head) {
    struct No *atual = head;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor); // Imprimindo o valor do nó atual
        atual = atual->prox; // Avançando para o próximo nó
    }
    printf("NULL\n"); // Indicando o final da lista
}
int main() {
    struct No *lista = NULL; // Inicializando a lista como vazia
    lista = inserirNoInicio(lista, 30); // Inserindo o primeiro nó
    lista = inserirNoInicio(lista, 20); // Inserindo o segundo nó
    lista = inserirNoInicio(lista, 10); // Inserindo o terceiro nó
    //Agora vamos inserir o valor 5 no início -> queremos [5/*] -> [10/*] -> [20/*] -> [30/*] -> NULL
    lista = inserirNoInicio(lista, 5); // Inserindo o quarto nó
    //Imprimindo a lista
    imprimirLista(lista); // Exibindo a lista encadeada
    return 0; // Retornando 0 para indicar que o programa terminou com sucesso
}