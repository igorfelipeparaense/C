#include <stdio.h>

char get_maiusculo(char caractere) {
    char maiusculo = (int)caractere - 32;

    return maiusculo;
}

int main() {
    char caractere = 'a';
    char maiusculo = get_maiusculo(caractere);
    printf("O caractere '%c' em maiúsculo é '%c' \n", caractere, maiusculo);


    return 0;
}
