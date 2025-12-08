#include <stdio.h>

struct st_pessoa{
    char endereco[200];
    char nome[100];
    int idade;
};

int main() {
    struct st_pessoa pessoa;

    printf("Informe o nome: ");
    fgets(pessoa.nome, 100, stdin);

    printf("Informe a idade: ");
    scanf("%d", &pessoa.idade);
    getchar();

    printf("Informe o endereço: ");
    fgets(pessoa.endereco, 200, stdin);

    printf("Dados da pessoa:\n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereço: %s\n", pessoa.endereco);

    return 0;
}
