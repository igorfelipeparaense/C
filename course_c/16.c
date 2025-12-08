#include <stdio.h>

int main() {
    float media, nota1, nota2;

    printf("Qual a primeira nota?\n");
    scanf("%f", &nota1);

    printf("Qual a segunda nota?\n");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    printf("Sua média é %.2f\n", media);

    return 0;
}