#include <stdio.h>

int main() {
    char nome[50];
    printf("Qual seu nome?\n");
    gets(nome);
    // scanf("%s", &nome);
    printf("Olá %s\n", nome);

    char letras[26];
    int contador = 0;
    for (int i = 97; i <= 122; i++) {
        letras[contador] = i;
        contador = contador + 1;
    }

    for (int i = 0; i < 26; i++) {
        printf("%d == %c\n", letras[i], letras[i]);
    }

    return 0;
}