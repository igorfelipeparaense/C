#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char valor_string[50];
    double valor_li;

    strcpy(valor_string, "499999925161561");

    valor_li = atol(valor_string);

    printf("O valor é %lf\n", valor_li);

    return 0;
}