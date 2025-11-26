#include <stdio.h>

int main() {
    int numero, soma = 0;

    for(int i = 0; i < 5; i++) {
        printf("Informe um número:\n");
        scanf("%d", &numero);

        soma = soma + numero;
    }

    printf("A soma é %d \n", soma);

    return 0;
}