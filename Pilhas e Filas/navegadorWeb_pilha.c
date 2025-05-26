#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pagina {
    char url[100];
    struct Pagina* prox;
};
// Função para acessar uma nova página (push)
void acessarPagina(struct Pagina **topo, const char *endereco) {
    struct Pagina *nova = (struct Pagina *)malloc(sizeof(struct Pagina));
    strcpy(nova->url, endereco);
    nova->prox = *topo;
    *topo = nova;
}
// Função para voltar para a página anterior (pop)
void voltarPagina(struct Pagina **topo) {
    if (*topo == NULL) {
        printf("Nenhuma página para voltar.\n");
        return;
    }
    struct Pagina *temp = *topo;
    *topo = temp->prox;
    free(temp);
}
// Função para exibir a página atual (peek)
void exibirPaginaAtual(struct Pagina *topo) {
    if (topo == NULL) {
        printf("Nenhuma página aberta.\n");
    } else {
        printf("Página atual: %s\n", topo->url);
    }
}
// Função para mostrar o histórico (todos os nós da pilha)
void mostrarHistorico(struct Pagina *topo) {
    if(topo == NULL) {
        printf("Histórico vazio.\n");
        return;
    }
    printf("Histórico de páginas visitadas:\n");
    while (topo != NULL) {
        printf(" - %s\n", topo->url);
        topo = topo->prox;
    }
}
int main() {
    struct Pagina *pilha = NULL;
    int opcao;
    char url[100];
    do {
        printf("\nMenu:\n");
        printf("1. Acessar nova página\n");
        printf("2. Voltar para a página anterior\n");
        printf("3. Exibir página atual\n");
        printf("4. Mostrar histórico\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                printf("Digite o endereço da nova página: ");
                fegts(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // Remove o caractere de nova linha
                acessarPagina(&pilha, url);
                break;
            case 2:
                voltarPagina(&pilha);
                break;
            case 3:
                exibirPaginaAtual(pilha);
                break;
            case 4:
                mostrarHistorico(pilha);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    while (opcao != 0);
    while (pilha != NULL) {
        voltarPagina(&pilha);
    }
    return 0;   
}