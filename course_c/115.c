#include <stdio.h>

void create_heap(int vetor[], int start, int end){
    int pai = vetor[start];
    int filho = start * 2 + 1;

    while(filho <= end){
        if(filho < end){
            if(vetor[filho] < vetor[filho + 1]){
                filho = filho + 1;
            }
        }

        if(pai < vetor[filho]){
            vetor[start] = vetor[filho];
            start = filho;
            filho = 2 * start + 1;
        }else{
            filho = end + 1;
        }
    }
    vetor[start] = pai;
}

void heap_sort(int vetor[], int size){
    int changed;
    int mid = (size - 1) / 2;

    for(int i = mid; i >= 0; i--){
        create_heap(vetor, i, size - 1);
    }

    for(int i = size - 1; i >= 1; i--){
        changed = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = changed;

        create_heap(vetor, 0, i - 1);
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    heap_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}