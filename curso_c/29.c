#include <stdio.h>

void mensagem() {
    printf("Bem-vindo!\n");
}

int soma(int num1, int num2) {
    int res = num1 + num2;
    return res;
}

void proximo_char(char caractere) {
    printf("%c \n", caractere + 1);
}

int main() {
    printf("Olá...\n");

    mensagem();

    // int retorno = soma(4, 6);
    // printf("Retorno = %d \n", retorno);
    printf("Retorno = %d \n", soma(4, 6));

    char cara = 'a';
    proximo_char(cara);

    return 0;
}