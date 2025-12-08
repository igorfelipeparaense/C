#include <stdio.h>

void select_sort(int vetor[], int size){
    int minor, changed;

    for(int i = 0; i < (size - 1); i++){
        minor = 1;
        for(int j = (i + 1); j < size; j++){
            if(vetor[j] < vetor[minor]){
                minor = j;
            }
        }
        if(i != minor){
            changed = vetor[i];
            vetor[i] = vetor[minor];
            vetor[minor] = changed;
        }
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    select_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}