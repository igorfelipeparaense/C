#include <stdio.h>

int soma(int num1, int num2);

int main() {
    int n1, n2, ret;
    
    printf("Informe o primeiro número:\n");
    scanf("%d", &n1);
    
    printf("Informe o segundo número:\n");
    scanf("%d", &n2);
    
    ret = soma(n1, n2);
    printf("A soma de %d com %d é %d\n", n1, n2, ret);
    
    return 0;
}

int soma(int num1, int num2) {
    return num1 + num2;
}