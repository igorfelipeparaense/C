#include <stdio.h>

#define TAMFILA 10

int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;

void list_elementos(){
    printf("\n=======FILA ATUAL=======");
    for(int i = 0; i < TAMFILA; i++){
        printf("-");
        printf("|%d", fila[i]);
        printf("-");
    }
    printf("\nHead: %d", head);
    printf("Tail: %d\n", tail);
    printf("\n\n");
}

void enqueue(){
    int val;
    if(tail < TAMFILA){
        printf("Informe o elemento para adicionar a fila: ");
        scanf("%d", &val);
        fila[tail] = val;
        tail = tail + 1;
        list_elementos();
    }else{
        printf("A fila está cheia.\n");
    }
}

void dequeue(){
    if(head < tail){
        fila[head] = 0;
        head = head + 1;
        list_elementos();
    }else{
        printf("A fila está cheia.\n");
    }
}

void clear(){
    for(int i = 0; i < TAMFILA; i++){
        fila[i] = 0;
    }
    head = 0;
    tail = 0;
}

int main(){
    int opcao = 0;

    do{
        printf("Selecione a opção: \n\n");
        printf("[1] - Inserir (enqueue):\n");
        printf("[2] - Remover (dequeue):\n");
        printf("[3] - Listar:\n");
        printf("[4] - Limpar a Fila:\n");
        printf("[5] - Sair:\n");
        printf("Opção:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                list_elementos();
                break;
            case 4:
                clear();
                break;
            case 5:
                break;
            default:
                printf("Opção inválida.\n");
        }
    }while(opcao != 5);

    return 0;
}