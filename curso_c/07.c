#include <stdio.h>

int main() {
    float nota1, nota2, nota3, nota4, media = 0;

    printf("Informe a nota1: \n");
    scanf("%f", &nota1);

    printf("Informe a nota2: \n");
    scanf("%f", &nota2);

    printf("Informe a nota3: \n");
    scanf("%f", &nota3);

    printf("Informe a nota4: \n");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

    printf("A media aritmética das notas é: %.2f.\n", media);

    return 0;
}