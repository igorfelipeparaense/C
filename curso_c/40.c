#include <stdio.h>

int main() {
    int inteiros[5];

    for(int i = 0; i < 5; i++) {
        printf("Informe o valor %d de 5: ", i + 1);
        scanf("%d", &inteiros[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("O dobro de %d é %d\n", *(inteiros + i), *(inteiros + i) * *(inteiros + i));
    }

    return 0;
}
