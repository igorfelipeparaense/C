#include <stdio.h>

int maior_valor(int vetor[], int qtd) {
    int maior = 0;

    for(int i = 0; i < qtd; i++) {
        if(i == 0) {
            maior = vetor[i];
        }
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    return maior;
}

int main() {
    int vetor[10] = {1, 6, 8, 15, 24, 32, 47, 88, 4, 2};
    
    int maior = maior_valor(vetor, 10);
    printf("O maior valor do vetor é %d \n", maior);


    return 0;
}
