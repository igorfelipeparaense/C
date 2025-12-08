#include <stdio.h>

void merge(int vetor[], int start1, int end1, int start2, int end2){
    int temp[50];
    int i, j, k;

    i = start1;
    j = start2;
    k = 0;

    while(i <= end1 && j <= end2){
        if(vetor[i] < vetor[j]){
            temp[k++] = vetor[i++];
        }else{
            temp[k++] = vetor[j++];
        }
    }

    while(i <= end1){
        temp[k++] = vetor[i++];
    }

    while(j <= end2){
        temp[k++] = vetor[j++];
    }

    for(i = start1, j = 0; i <= end2; i++, j++){
        vetor[i] = temp[j];
    }
}

void merge_sort(int vetor[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;

        merge_sort(vetor, start, mid);
        merge_sort(vetor, mid + 1, end);

        merge(vetor, start, mid, mid + 1, end);
    }
}

int main(){
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    merge_sort(vetor, 0, 6 - 1);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;
}