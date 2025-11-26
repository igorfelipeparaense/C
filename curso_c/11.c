#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Informe um número:\n");
    scanf("%d", &numero);

    while(numero != 0) {
        soma = soma + numero;
        printf("Informe um número:\n");
        scanf("%d", &numero);
    }

    printf("A soma é %d \n", soma);

    return 0;
}