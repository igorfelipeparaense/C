#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor_a, valor_b;

    valor_a = abs(5);
    printf("O valor absoluto de %d é %d\n", valor_a, valor_a);
    
    valor_b = abs(-10);
    printf("O valor absoluto de %d é %d\n", valor_b, valor_b);

    return 0;
}