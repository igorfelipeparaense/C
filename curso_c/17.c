#include <stdio.h>

int main() {
    char opcao;

    printf("Informe uma opção:\n");
    printf("a - Saldo da conta\n");
    printf("b - Extrato da conta\n");
    printf("c - Limite da conta\n");

    scanf("%c", &opcao);

    if (opcao == 'a') {
        printf("Seu saldo é...\n");
    } else if (opcao == 'b') {
        printf("Extrato da conta...\n");
    } else if (opcao == 'c') {
        printf("Seu limite é...\n");
    } else {
        printf("Opção desconhecida\n");
    }

    return 0;
}