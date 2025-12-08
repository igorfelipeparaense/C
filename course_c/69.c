#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char valor_string[5];
    double valor_double;

    strcpy(valor_string, "4.5");

    valor_double = atof(valor_string);

    printf("O valor é %.2f\n", valor_double);

    return 0;
}