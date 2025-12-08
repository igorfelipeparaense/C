#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int level, value1, value2, op, result;
}Calculate;

void toPlay();
void showInfo(Calculate calc);
int add(int response, Calculate calc);
int decrease(int response, Calculate calc);
int multiply(int response, Calculate calc);

int points = 0;

int main(){
    srand(time(NULL));
    toPlay();

    return 0;
}

void toPlay(){
    Calculate calc;
    int level;

    printf("Informe o nível de dificuldade desejado [1 | 2 | 3 | 4]:\n");
    scanf("%d", &level);

    calc.level = level;
    calc.op = rand() % 3;

    if(calc.level == 1){
        calc.value1 = rand() % 11;
        calc.value2 = rand() % 11;
    }else if(calc.level == 2){
        calc.value1 = rand() % 101;
        calc.value2 = rand() % 101;
    }else if(calc.level == 3){
        calc.value1 = rand() % 1001;
        calc.value2 = rand() % 1001;
    }else if(calc.level == 4){
        calc.value1 = rand() % 10001;
        calc.value2 = rand() % 10001;
    }else{
        calc.value1 = rand() % 100001;
        calc.value2 = rand() % 100001;
    }

    int response;
    printf("Informe o resultado para a seguinte operação: \n");

    if(calc.op == 0){
        printf("%d + %d \n", calc.value1, calc.value2);
        scanf("%d", &response);

        if(add(response, calc)){
            points += 1;
            printf("Você tem %d ponto(s).\n", points);
        }
    }else if(calc.op == 1){
        printf("%d - %d \n", calc.value1, calc.value2);
        scanf("%d", &response);

        if(decrease(response, calc)){
            points += 1;
            printf("Você tem %d ponto(s).\n", points);
        }
    }else if(calc.op == 2){
        printf("%d * %d \n", calc.value1, calc.value2);
        scanf("%d", &response);

        if(multiply(response, calc)){
            points += 1;
            printf("Você tem %d ponto(s).\n", points);
        }
    }else{
        printf("A operação %d não é reconhecida.\n", calc.op);
    }

    showInfo(calc);

    printf("Deseja continuar jogando? [1 - sim | 0 - não]\n");
    int continueGame;
    scanf("%d", &continueGame);

    if(continueGame){
        toPlay();
    }else{
        printf("Você finalizou com %d ponto(s).\n", points);
        printf("Até a próxima.\n");
        exit(0);
    }
}

void showInfo(Calculate calc){
    char op[25];

    if(calc.op == 0){
        sprintf(op, "Somar");
    }else if(calc.op == 1){
        sprintf(op, "Diminuir");
    }else if(calc.op == 2){
        sprintf(op, "Multiplicar");
    }else{
        sprintf(op, "Operação desconhecida");
    }
    printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperação: %s \n\n", calc.value1, calc.value2, calc.level, op);
}

int add(int response, Calculate calc){
    int result = calc.value1 + calc.value2;
    calc.result = result;
    int acert = 0;

    if(response == calc.result){
        printf("Resposta correta!\n");
        acert = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d + %d = %d\n", calc.value1, calc.value2, calc.result);

    return acert;
}

int decrease(int response, Calculate calc){
    int result = calc.value1 - calc.value2;
    calc.result = result;
    int acert = 0;

    if(response == calc.result){
        printf("Resposta correta!\n");
        acert = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d - %d = %d\n", calc.value1, calc.value2, calc.result);

    return acert;
}

int multiply(int response, Calculate calc){
    int result = calc.value1 * calc.value2;
    calc.result = result;
    int acert = 0;

    if(response == calc.result){
        printf("Resposta correta!\n");
        acert = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d * %d = %d\n", calc.value1, calc.value2, calc.result);

    return acert;
}