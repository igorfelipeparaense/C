#include <stdio.h>

int somatorio(int n){
    if(n < 0){
        printf("O valor precisa ser positivo.\n");
        return 0;
    }else if(n <= 1){
        return n;
    }else{
        return n + somatorio(n - 1);
    }
}

int main() {
    int n = 5;
    printf("A soma dos %d primeiros números é %d\n", n, somatorio(n));

    return 0;
}
