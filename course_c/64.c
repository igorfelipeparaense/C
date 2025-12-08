#include <stdio.h>

int fatorial(int n){
    if(n >= 1){
        return n * fatorial(n - 1);
    }else{
        return 1;
    }
}

int main() {
    int n = 5;
    printf("O fatorial de %d é %d\n", n, fatorial(n));

    return 0;
}
