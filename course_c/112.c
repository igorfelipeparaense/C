#include <stdio.h>

void shell_sort(int vetor[], int size){
    int group = 1;

    while(group < size){
        group = 3 * group + 1;
    }

    while(group > 1){
        group /= 3;
        for(int i = group; i < size; i++){
            int changed = vetor[i];
            int j = i - group;

            while(j >= 0 && changed < vetor[j]){
                vetor[j + group] = vetor[j];
                j -= group;
            }
            vetor[j + group] = changed;
        }
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    shell_sort(vetor, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}