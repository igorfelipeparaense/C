#include <stdio.h>
#include <ctype.h>

/*
isalnum() verifica se o caractere é alfanumérico (abc123)
isalpha() verifica se o caractere e alfabético (abc...)
isdigit() verifica se o caractere é um dígito decimal (0123...)
ispunct() verifica se o caractere é uma pontuação (?!.)
isspace() verifica se é um espaço ( )
isupper() verifica se é maiúscula
islower() verifica se é minúscula
tolower() converte para minúscula
toupper() converte para maiúscula
*/

int main(){
    char teste = '4';

    if(isalnum(teste)){
        printf("É alfanúmerico.\n");
    }else{
        printf("Não é alfanúmerico.\n");
    }

    if(isalpha(teste)){
        printf("É alfabético.\n");
    }else{
        printf("Não é alfabético.\n");
    }

    if(isdigit(teste)){
        printf("É dígito.\n");
    }else{
        printf("Não é dígito.\n");
    }

    if(islower(teste)){
        printf("É minúsculo.\n");
    }else{
        printf("Não é minúsculo.\n");
    }

    if(isupper(teste)){
        printf("É maiúsculo.\n");
    }else{
        printf("Não é maiúsculo.\n");
    }

    if(ispunct(teste)){
        printf("É pontuação.\n");
    }else{
        printf("Não é pontuação.\n");
    }

    if(isspace(teste)){
        printf("É espaço.\n");
    }else{
        printf("Não é espaço.\n");
    }

    printf("A letra %c em maiúsculo é %c\n", teste, toupper(teste));
    printf("A letra %c em minúsculo é %c\n", teste, tolower(teste));

    return 0;
}