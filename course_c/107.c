#include <stdio.h>
#include <stdlib.h>

struct st_no{
    int value;
    struct st_no *next;
};

typedef struct st_no no;

int empty(no *list){
    if(list->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

void start(no *list){
    list->next = NULL;
}

void release(no *list){
    if(!empty(list)){
        no *nextNo, *current;
        current = list->next;

        while(current != NULL){
            nextNo = current->next;
            free(current);
            current = nextNo;
        }
    }
}

void show(no *list){
    if(empty(list)){
        printf("Lista está vazia.\n\n");
        return;
    }
    no *temp;
    temp = list->next;

    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

void insertStart(no *list){
    no *new = (no*)malloc(sizeof(no));
    if(!new){
        printf("Sem memória disponível.\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &new->value);

    no *oldHead = list->next;

    list->next = new;
    new->next = oldHead;
}

void insertLast(no *list){
    no *new = (no*)malloc(sizeof(no));
    if(!new){
        printf("Sem memória disponível.\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &new->value);

    new->next = NULL;

    if(empty(list)){
        list->next = new;
    }else{
        no *temp = list->next;

        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
    }
}

void option(no *list, int opt){
    switch(opt){
        case 0:
            release(list);
            break;
        case 1:
            show(list);
            break;
        case 2:
            insertStart(list);
            break;
        case 3:
            insertLast(list);
            break;
        case 4:
            start(list);
            break;
        default:
            printf("Comando inválido.\n\n");
    }
}

int menu(){
    int opt;

    printf("Selecione a opção: \n\n");
    printf("[0] - Sair:\n");
    printf("[1] - Exibir:\n");
    printf("[2] - Adicionar nó no início:\n");
    printf("[3] - Adicionar nó no fim:\n");
    printf("[4] - Zerar a lista:\n");
    printf("Opção:\n");
    scanf("%d", &opt);

    return opt;
}

int main(){
    no *list = (no*)malloc(sizeof(no));

    if(!list){
        printf("Sem memória disponível.\n");
        exit(1);
    }
    start(list);
    int opt;

    do{
        opt=menu();
        option(list, opt);
    }while(opt);

    free(list);

    return 0;
}