#include <stdio.h>

int main() {
    int numero, soma = 0;

    do  {
        printf("Informe um número:\n");
        scanf("%d", &numero);

        soma = soma + numero;
    }
    while(numero != 0);

    printf("A soma é %d \n", soma);

    return 0;
}