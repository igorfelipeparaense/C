#include <stdio.h>

int busca_binaria(int vetor[], int key, int size ){
    int start = 0;
    int end = size - 1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(key == vetor[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return - 1;
}

int main(){
    int vetor[6] = {1, 3, 5, 8, 12, 42};
    int key = 5;
    int ret = busca_binaria(vetor, key, 6);

    printf("O elemento %d está na posição %d\n", key, ret);

    return 0;
}