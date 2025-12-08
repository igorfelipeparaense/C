#include <stdio.h>

void bubble_sort(int vetor[], int size){
    int next = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < (size - 1); j++){
            if(vetor[j] > vetor[j + 1]){
                next = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j  + 1] = next;
            }
        }
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    bubble_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}