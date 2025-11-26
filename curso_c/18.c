#include <stdio.h>

int main() {
    char nome[50];

    printf("Qual é o seu nome?\n");
    gets(nome);

    printf("Seu nome é %s\n", nome);

    return 0;
}