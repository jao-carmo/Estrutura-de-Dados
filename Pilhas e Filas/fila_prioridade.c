#include <stdio.h>
#include <stdlib.h>
//Estrutura do paciente
struct Paciente {
    char nome[30];
    int idade;
    struct Paciente *prox;
};
// Função para inserir paciente com ou sem prioridade
void enfilerarComPrioridade(struct Paciente **inicio, struct Paciente **fim) {
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente));
    printf("Digite o nome do paciente: ");
    scanf("%s", novo->nome);
    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);

    novo->prox = NULL;

    //PRIORIDADE: idade >= 60
    if (novo->idade >= 60) {
        //insere no inicio da fila
        novo->prox = *inicio;
        *inicio = novo;
        if (*fim == NULL) {
            *fim = novo; // Se a fila estava vazia, o novo paciente é também o fim
        }
        printf("Paciente PRIORITÁRIO inserido no início da fila.\n");
    } else {
        //insere no fim da fila (coo na fila comum)
        if(*fim == NULL) {
            *inicio = novo; // Se a fila estava vazia, o novo paciente é também o início
            *fim = novo;
        } else {
            (*fim)->prox = novo; // O fim atual aponta para o novo paciente
            *fim = novo; // O novo paciente se torna o fim da fila
        }
        printf("Paciente COMUM inserido no fim da fila.\n");
    }
}

// Atender paciente (sempre do início da fila)
void atenderPaciente(struct Paciente **inicio, struct Paciente **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    struct Paciente *temp = *inicio;
    printf("Atendendo: %s, Idade: %d\n", temp->nome, temp->idade);
    *inicio = temp->prox; // Remove o paciente do início da fila

    if (*inicio == NULL) {
        *fim = NULL; // Se a fila ficou vazia, atualiza o fim
    }

    free(temp); // Libera a memória do paciente atendido
}

// Mostrar todos os pacientes
void mostrarFila(struct Paciente *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\nFila de pacientes (prioritários primeiro):\n");
    while (inicio != NULL) {
        printf("- %s (idade: %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

int main() {
    struct Paciente *inicio = NULL, *fim = NULL;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir Paciente na fila\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar fila de pacientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            enfilerarComPrioridade(&inicio, &fim);
        } else if(opcao == 2) {
            atenderPaciente(&inicio, &fim);
        } else if(opcao == 3) {
            mostrarFila(inicio);
        } else if(opcao == 0) {
            printf("Saindo do programa....\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libera a memória restante
    while (inicio != NULL) {
        atenderPaciente(&inicio, &fim);
    }

    return 0;
}