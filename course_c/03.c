#include <stdio.h>

int main() {
    int valor1, valor2, valor3, soma = 0;

    printf("Informe o valor1: \n");
    scanf("%d", &valor1);

    printf("Informe o valor2: \n");
    scanf("%d", &valor2);

    printf("Informe o valor3: \n");
    scanf("%d", &valor3);

    soma = valor1 + valor2 + valor3;

    printf("A soma dos valores informados é: %d \n", soma);

    return 0;
}