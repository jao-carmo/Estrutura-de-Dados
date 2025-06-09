#include <stdio.h>

int mediaMaiorQue(float v[], int tamanho, float media) {
    for(int i = 0; i < tamanho; i++) {
        if(v[i] > media) {
            printf("%.2f \t", v[i]);
        }
    }
}

int main() {
    float val[] = {1,2,3,4,5,6,7,8,9,10};
    mediaMaiorQue(val,10,5);
}