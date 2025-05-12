//Crie uma struct chamada Aluno com os campos nome (string de até 40
//caracteres) e nota (float).
//Escreva um programa que use um ponteiro para essa struct para
//armazenar e imprimir os dados de um único aluno.
//Pergunta: Qual é a sintaxe correta para acessar os campos da struct
//usando o ponteiro?
#include <stdio.h>
#include <stdlib.h>
struct Aluno {
    char nome[40]; // Atributo 'nome' do tipo string (array de caracteres)
    float nota; // Atributo 'nota' do tipo float
};

int main() {
    struct Aluno *aluno = (struct Aluno *)malloc(sizeof(struct Aluno)); // Aloca memória para um ponteiro do tipo Aluno
    if (aluno == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        printf("Erro ao alocar memória.\n");
        return 1; // Retorna 1 para indicar erro
    }
    // Solicitando e lendo o nome do aluno
    printf("Digite o nome do aluno (sem espaços): ");
    scanf("%s", aluno->nome); // Lê o nome (uma palavra apenas)
    printf("Digite a nota do aluno: ");
    scanf("%f", &aluno->nota); // Lê a nota
    // Exibindo os dados do aluno
    printf("\n=== Dados do Aluno ===\n");
    printf("Nome: %s\n", aluno->nome); // Exibe o nome
    printf("Nota: %.2f\n", aluno->nota); // Exibe a nota
    free(aluno); // Libera a memória alocada
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
// A sintaxe correta para acessar os campos da struct usando o ponteiro é:
// p->nome para acessar o campo nome e p->nota para acessar o campo nota.

