#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[5];
    int *ponteiro;

    ponteiro = (int*)malloc(sizeof(vetor));

    for(int i = 0; i < 5; i++){
        printf("Informe o valor %d de 5: ", i + 1);
        scanf("%d", &ponteiro[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("Valor na posição %d do vetor: %d\n", i, ponteiro[i]);
    }

    free(ponteiro);
    ponteiro + NULL;

    return 0;
}