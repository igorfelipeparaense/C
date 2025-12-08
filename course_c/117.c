#include <stdio.h>

int busca_linear(int vetor[], int key, int size ){
    for(int i = 0; i < size; i++){
        if(vetor[i] == key){
            return i;
        }
        return -1;
    }
}

int main(){
    int vetor[6] = {1, 3, 5, 8, 12, 42};
    int key = 5;
    int ret = busca_linear(vetor, key, 6);

    printf("O elemento %d está na posição %d\n", key, ret);

    return 0;
}