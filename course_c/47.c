#include <stdio.h>

int main() {
    FILE* arq1, *arq2;
    char caractere = 'A';

    arq1 = fopen("arq.txt", "wa");

    if (arq1) {
        while(caractere != '0') {
            printf("Informe um caractere ou 0 para sair: ");
            scanf(" %c", &caractere);

            if (caractere != '0') {
                fputc(caractere, arq1);
            }
        }

    } else {
        printf("Não foi possível criar o arquivo\n");
    }

    fclose(arq1);
    arq1 = NULL;

    arq2 = fopen("arq.txt", "r");

    if(arq2) {
        while((caractere = getc(arq2)) != EOF) {
            printf("%c\n", caractere);
        }

    } else {
        printf("Não foi possível abrir o arquivo\n");
    }

    fclose(arq2);
    arq2 = NULL;

    return 0;
}
