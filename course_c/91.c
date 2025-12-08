#include <stdio.h>
#include <string.h>

int main(){
    char str1[20], str2[20];

    srtcpy(str1, "Laranja");
    srtcpy(str2, "Laranja");

    if(strcmp(str1, str2)){
        printf("Não são iguais.\n");
    }else{
        printf("São iguais.\n");
    }

    return 0;
}