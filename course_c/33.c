#include <stdio.h>

void imprime_pontos(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            printf("!");
        }
        printf("\n");
    }
}

int main() {
    imprime_pontos(5);

    return 0;
}
