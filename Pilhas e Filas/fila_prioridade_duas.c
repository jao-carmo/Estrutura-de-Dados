#include <stdio.h>
#include <stdlib.h>
// strutura do paciente
struct Paciente {
    char nome[30];
    int idade;
    struct Paciente *prox;
};
// Inserir paciente na fila correta (prioritaria ou comum)
void inserirPaciente(struct Paciente **inicioPrioritaria, struct Paciente **fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente));
    printf("Digite o nome do paciente: ");
    scanf("%s", novo->nome);
    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);
    
    novo->prox = NULL;

    // Prioridade: idade >= 60
    if (novo->idade >= 60) {
        // Insere na fila prioritária
        if (*inicioPrioritaria == NULL) {
            *inicioPrioritaria = novo;
            *fimPrioritaria = novo;
        } else {
            (*fimPrioritaria)->prox = novo;
            *fimPrioritaria = novo;
        }
        printf("Paciente PRIORITÁRIO inserido.\n");
    } else {
        // Insere na fila comum
        if (*inicioComum == NULL) {
            *inicioComum = novo;
            *fimComum = novo;
        } else {
            (*fimComum)->prox = novo;
            *fimComum = novo;
        }
        printf("Paciente COMUM inserido.\n");
    }
}

// Atender paciente (fila prioritário primeiro)
void atenderPaciente(struct Paciente **inicioPrioritaria, struct Paciente ** fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {
    struct Paciente *temp;
    
    // Verifica se há pacientes na fila prioritária
    if (*inicioPrioritaria != NULL) {
        temp = *inicioPrioritaria;
        printf("Atendendo paciente PRIORITÁRIO: %s, Idade: %d\n", temp->nome, temp->idade);
        *inicioPrioritaria = temp->prox;
        if (*inicioPrioritaria == NULL) {
            *fimPrioritaria = NULL; // Se a fila ficou vazia, atualiza o fim
        }
        free(temp); // Libera a memória do paciente atendido
    } else if (*inicioComum != NULL) { // Se não houver prioritários, atende os comuns
        temp = *inicioComum;
        printf("Atendendo paciente COMUM: %s, Idade: %d\n", temp->nome, temp->idade);
        *inicioComum = temp->prox;
        if (*inicioComum == NULL) {
            *fimComum = NULL; // Se a fila ficou vazia, atualiza o fim
        }
        free(temp); // Libera a memória do paciente atendido
    } else {
        printf("Nenhum paciente para atender.\n");
        return;
    }
}

void mostrarFila(const char *titulo, struct Paciente *inicio) {
    printf("\n%s", titulo);

    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    while (inicio != NULL) {
        printf("- %s (idade: %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

int main() {
    struct Paciente *inicioPrioritaria = NULL, *fimPrioritaria = NULL;
    struct Paciente *inicioComum = NULL, *fimComum = NULL;

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Mostrar fila prioritária\n");
        printf("4. Mostrar fila comum\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
                break;
            case 2:
                atenderPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
                break;
            case 3:
                mostrarFila("Fila de pacientes PRIORITÁRIOS:", inicioPrioritaria);
                break;
            case 4:
                mostrarFila("Fila de pacientes COMUNS:", inicioComum);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    while (inicioPrioritaria != NULL || inicioComum != NULL) {
        atenderPaciente(&inicioPrioritaria, &fimPrioritaria, &inicioComum, &fimComum);
    }
    return 0;
}