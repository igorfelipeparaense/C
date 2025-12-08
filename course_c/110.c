#include <stdio.h>

void insert_sort(int vetor[], int size){
    int changed;

    for(int i = 1; i < size; i++){
        int next = i;

        while((next != 0) && (vetor[next] < vetor[next - 1])){
            changed = vetor[next];
            vetor[next] = vetor[next - 1];
            vetor[next - 1] = changed;
            next--;
        }
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    insert_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}