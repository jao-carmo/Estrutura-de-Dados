#include <stdio.h>
#include <stdlib.h>
struct No {
    int valor;
    struct No *prox; // Ponteiro para o próximo nó
};
//explicando passo a passo
struct No* inserirFinal(struct No *head, int novoValor) {
     //1. Alocando memória para o novo nó
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    //2. Atribuindo o valor ao novo nó
    novoNo->valor = novoValor;
    //3. O novo nó sera o ultimo, portanto, 'prox' deve ser NULL
    novoNo->prox = NULL;
    //4. Se a lista estiver vazia, o novo nó se torna o head
    if (head == NULL) {
        return novoNo;
    }
    //5. Caso contrário, percorremos a lista até encontrar o último nó
    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox; // Avançando para o próximo nó
    }
    //6. O próximo do último nó agora aponta para o novo nó
    atual->prox = novoNo;
    //7. Retornamos o head da lista
    return head;
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
    lista = inserirFinal(lista, 10); // Inserindo o primeiro nó
    lista = inserirFinal(lista, 20); // Inserindo o segundo nó
    lista = inserirFinal(lista, 30); // Inserindo o terceiro nó
    //Agora vamos inserir o valor 40 no final -> queremos [10/*] -> [20/*] -> [30/*] -> [40/*] -> NULL
    lista = inserirFinal(lista, 40); // Inserindo o quarto nó
    //Imprimindo a lista
    imprimirLista(lista); // Exibindo a lista encadeada
    return 0; // Retornando 0 para indicar que o programa terminou com sucesso
}