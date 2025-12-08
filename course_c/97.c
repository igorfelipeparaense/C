#include <stdio.h>
#include <time.h>

int main(){
    time_t tempo_bruto;
    struct tm *info;

    time(&tempo_bruto);

    info = localtime(&tempo_bruto);

    printf("Data e hora local %s\n", asctime(info));

    return 0;
}