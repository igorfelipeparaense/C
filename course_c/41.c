#include <stdio.h>

int main() {
    FILE *arq;

    //fopen(nome-do-arquivo, forma-de-abertura-do-arquivo)
    //w - abrir o arquivo para escrita (se o arquivo já existir, será sobrescrito com um novo zerado)
    //r - abrir o arquivo para leitura (não podemos escrever no arquivo)
    //wa - abrir o arquivo para adição de conteúdo (se o arquivo já existir, o conteúdo será adicionado nas linhas abaixo)
    arq = fopen("arquivo.txt", "w");

    //sempre que finalizar a manipulação do arquivo tem que fechar o mesmo
    fclose(arq);

    return 0;
}
