#include <stdio.h>

int somar(int a, int b) {
    printf("%d", a + b);
}

int main() {
    int num1 = 0;
    int num2 = 0;
    printf("Digite dois números: \n");
    scanf("%d\n%d", &num1, &num2);
    somar(num1, num2);
}