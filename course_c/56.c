#include <stdio.h>
#include <string.h>

union pessoa {
    char nome[100];
    int idade;
};

int main() {
    union pessoa pes;

    strcpy(pes.nome, "Joãozinho");
    printf("Dados de %s.\n", pes.nome);
    pes.idade = 39;
    printf("Ele tem %d anos.\n", pes.idade);

    printf("A variável 'pes' está ocupando %ld bytes em memória.\n", sizeof(pes));

    return 0;
}
