#include <stdio.h>

int main() {
    FILE *arq;
    char nome_arquivo[12];
    int conta_linhas = 0;

    printf("Informe o nome do arquivo a ser aberto: ");
    fgets(nome_arquivo, 12, stdin);

    arq = fopen(nome_arquivo, "r");
    if(arq) {
        for(char c = getc(arq); c != EOF; c = getc(arq)) {
            if(c == '\n') {
                conta_linhas = conta_linhas + 1;
                //conta_linhas++;
            }
        }
        printf("O %s possui %d linhas.\n", nome_arquivo, conta_linhas);
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }
    fclose(arq);
    arq = NULL;

    return 0;
}
