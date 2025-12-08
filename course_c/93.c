#include <stdio.h>
#include <string.h>

int main(){
    char str1[] = "teste@gmail.com";

    printf("Usuário: %s", strtok(str1, "@"));

    return 0;
}