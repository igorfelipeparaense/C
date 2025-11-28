#include <stdio.h>

void incrementa(int* contador) {
    printf("Antes de incrementar.\n");
    printf("O contador vale %d \n", (*contador));
    printf("O endereço de memória é %d \n", contador);

    printf("Depois de incrementar.\n");
    printf("O contador vale %d \n", ++(*contador));
    printf("O endereço de memória é %d \n", contador);
}

int main() {
    int contador = 10;

    printf("Antes de incrementar.\n");
    printf("O contador vale %d \n", contador);
    printf("O endereço de memória é %d \n", &contador);

    incrementa(&contador);

    printf("Depois de incrementar.\n");
    printf("O contador vale %d \n", contador);
    printf("O endereço de memória é %d \n", &contador);

    return 0;
}
