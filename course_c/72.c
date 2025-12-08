#include <stdio.h>
#include <stdlib.h>

int main(){
    time_t t;
    
    srand((unsigned) time(&t));

    for(int i = 0; i < 6; i++){
        printf("%d\n", rand() % 61);
    }

    return 0;
}