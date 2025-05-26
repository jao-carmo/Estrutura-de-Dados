#include <stdio.h>
#include <stdlib.h>
// definição da estrutura de nó da pilha
struct No {
    int valor;
    struct No* prox;
};
// função push para adicionar um elemento à pilha
void push(struct No **topo, int valor) {
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}
// função pop para remover um elemento da pilha
int pop(struct No **topo) {
    if (*topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // ou outro valor de erro
    }
    struct No *temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}
// função peek para obter o valor do elemento no topo da pilha
int peek(struct No *topo) {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
        return -1; // ou outro valor de erro
    }
    return topo->valor;
}
// imprimindo a pilha
void imprimirPilha(struct No *topo) {
    printf("Topo da pilha:\n");
    while (topo != NULL) {
        printf("%d\n", topo->valor);
        topo = topo->prox;
    }
    printf("NULL\n");
}

int main() {
    struct No *pilha = NULL;

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    imprimirPilha(pilha);

    //consultar o topo sem remover
    printf("Valor no topo(peek): %d\n", peek(pilha));

    //remover o elemento do topo
    int valorRemovido = pop(&pilha);
    printf("Valor removido (pop): %d\n", valorRemovido);

    //consulta novamente após a remoção
    printf("Novo topo(peek): %d\n", peek(pilha));

    imprimirPilha(pilha);
    return 0;
}