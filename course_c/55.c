#include <stdio.h>

int main() {
    int numero = 42;
    float nota = 7.9;
    char letra = 'd';
    double outra_nota = 19.4;

    printf("A variável 'numero' tem o valor %d e ocupa %ld bytes em memória\n", numero, sizeof(numero));
    printf("A variável 'nota' tem o valor %.2f e ocupa %ld bytes em memória\n", nota, sizeof(nota));
    printf("A variável 'letra' tem o valor %c e ocupa %ld bytes em memória\n", letra, sizeof(letra));
    printf("A variável 'outra_nota' tem o valor %.2f e ocupa %ld bytes em memória\n", outra_nota, sizeof(outra_nota));

    return 0;
}
