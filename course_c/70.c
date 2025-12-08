#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char valor_string[5];
    int valor_int;

    strcpy(valor_string, "4");

    valor_int = atoi(valor_string);

    printf("O valor é %.2f\n", valor_int);

    return 0;
}