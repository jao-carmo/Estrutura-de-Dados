#include <stdio.h>
// função que dobrar o valor de uma variável
void dobrar(int *num) {
    *num = *num * 2;
}
int main() {
    int valor = 10; // variável inicializada com 10
    printf("Valor antes da função: %d\n", valor); // imprime o valor antes de dobrar
    dobrar(&valor); // chama a função dobrar passando o endereço da variável valor
    printf("Valor depois da função: %d\n", valor); // imprime o valor depois de dobrar
    return 0; // retorna 0 para indicar que o programa terminou com sucesso
}