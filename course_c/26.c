#include <stdio.h>

int main() {
    int vetor[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int pares = 0;

    for (int i = 0; i < 10; i++) {
        printf("Informe o valor %d de 10:\n", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (vetor[i] % 2 ==0) {
            printf("O valor %d é par.\n", vetor[i]);
            pares = pares + 1;
        }
    }

    printf("Temos um total de %d valores pares no vetor.\n", pares);

    return 0;
}