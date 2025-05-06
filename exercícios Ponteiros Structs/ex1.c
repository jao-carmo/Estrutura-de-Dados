//Crie uma struct chamada Aluno com os campos nome (string de até 40
//caracteres) e nota (float).
//Escreva um programa que use um ponteiro para essa struct para
//armazenar e imprimir os dados de um único aluno.
//Pergunta: Qual é a sintaxe correta para acessar os campos da struct
//usando o ponteiro?
#include <stdio.h>

struct Aluno {
    char nome[40]; 
    float nota; 
};
typedef struct Aluno Aluno;
int main() {
    Aluno aluno;
    Aluno *p = &aluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a nota do aluno: ");
    scanf("%f", &p->nota); 
    printf("\n--- Dados do Aluno ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Nota: %.2f\n", p->nota);

    return 0;
}
// A sintaxe correta para acessar os campos da struct usando o ponteiro é:
// p->nome para acessar o campo nome e p->nota para acessar o campo nota.