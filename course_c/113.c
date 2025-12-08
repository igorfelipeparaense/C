#include <stdio.h>

void quick_sort(int vetor[], int size){
    int i, j, group, changed;

    if(size < 2){
        return;
    }else{
        group = vetor[size / 2];
    }

    for(i = 0, j = size - 1;; i++, j--){
        while(vetor[i] < group){
            i++;
        }

        while(group , vetor[j]){
            j--;
        }

        if(i >= j){
            break;
        }else{
            changed = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = changed;
        }
    }
    quick_sort(vetor, i);
    quick_sort(vetor + i, size - i);
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    quick_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}