#include <stdio.h>

#ifndef PI
    #define PI 3.14159
#endif

int main() {
    int valor = 5;

    valor = 467;

    printf("O valor é %d\n", valor);

    #ifdef PI
        printf("PI vale %f\n", (2 * PI));
    #endif

    return 0;
}
