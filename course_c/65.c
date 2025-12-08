#include <stdio.h>

int binario(int n){
    if(n == 0){
        return n;
    }else{
        return (n % 2 + 10 * binario(n / 2));
    }
}

int main() {
    int n = 5;
    printf("O número %d em binário é %d\n", n, binario(n));

    return 0;
}
