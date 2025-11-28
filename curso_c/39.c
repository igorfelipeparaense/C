#include <stdio.h>

int main() {
    int var1, var2;

    printf("Informe o valor para var1: ");
    scanf("%d", &var1);

    printf("Informe o valor para var2: ");
    scanf("%d", &var2);

    printf("Endereço de memória var1: %p\n", &var1);
    printf("Endereço de memória var2: %p\n", &var2);

    if(&var1 > &var2) {
        printf("Var1 tem maior endereço: %d\n", var1);
    } else {
        printf("Var2 tem maior endereço: %d\n", var2);
    }

    return 0;
}
