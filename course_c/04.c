#include <stdio.h>

int main() {
    int numero, quadrado = 0;

    printf("Informe um número: \n");
    scanf("%d", &numero);

    quadrado = numero * numero;

    printf("O quadrado de %d é %d \n", numero, quadrado);

    return 0;
}