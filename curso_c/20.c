#include <stdio.h>

int main() {
    int num1, num2;
    float res;

    printf("Informe o num1:\n");
    scanf("%d", &num1);

    printf("Informe o num2:\n");
    scanf("%d", &num2);

    res = num1 + num2;
    printf("A soma é %d\n", (int)res);

    res = num2 - num1;
    printf("A subtração é %d\n", (int)res);

    res = num1 * num2;
    printf("A multiplicação é %d\n", (int)res);

    res = (float)num1 / (float)num2;
    printf("A divisão é %f\n", (float)res);

    res = num1 * num1;
    printf("O quadrado de num1 é %d\n", (int)res);

    if (num1 % num2 == 0) {
        printf("%d é par\n", num1);
    } else {
        printf("%d é impar\n", num1);
    }

    return 0;
}