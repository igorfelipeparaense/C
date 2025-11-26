#include <stdio.h>

int main() {
    int numero, maior, menor = 0;

    for(int i = 0; i < 10; i++) {
        printf("Informe o valor %d de 10:\n", i + 1);
        scanf("%d", &numero);

        if(i == 0) {
            maior = numero;
            menor = numero;
        }
        if(numero > maior) {
            maior = numero;
        }
        if(numero < menor) {
            menor = numero;
        }
    }
    printf("O maior valor é %d e o menor valor é %d\n", maior, menor);
    return 0;
}