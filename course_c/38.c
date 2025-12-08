#include <stdio.h>

int main() {
    int valor_inteiro = 1;
    float valor_real = 1.1;
    char valor_char = 103;

    int* ponteiro_inteiro;
    float* ponteiro_real;
    char* ponteiro_char;

    printf("Valor inteiro - antes: %d\n", valor_inteiro);
    printf("Valor real - antes: %.2f\n", valor_real);
    printf("Valor char - antes:  %c ou %d\n", valor_char, valor_char);

    ponteiro_inteiro = &valor_inteiro;
    ponteiro_real = &valor_real;
    ponteiro_char = &valor_char;

    printf("Valor inteiro - após: %d\n", valor_inteiro);
    printf("Valor real - após: %.2f\n", valor_real);
    printf("Valor char - após:  %c ou %d\n", valor_char, valor_char);

    return 0;
}