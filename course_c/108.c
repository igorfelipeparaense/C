#include <stdio.h>
#include <stdlib.h>

struct st_tree{
    int value;
    struct st_tree *subTreeRight;
    struct st_tree *subTreeLeft;
};

typedef struct st_tree tree;

tree* createTree(){
    return NULL;
}

int isEmptyTree(tree* t){
    return t == NULL;
}

void showTree(tree* t){
    printf("<");

    if(!isEmptyTree(t)){
        printf("%d", t->value);
        showTree(t->subTreeLeft);
        showTree(t->subTreeRight);
    }
    printf(">");
}

void insertDataTree(tree** t, int num){
    if(*t == NULL){
        *t = (tree*)malloc(sizeof(tree));
        (*t)->subTreeLeft = NULL;
        (*t)->subTreeRight = NULL;
        (*t)->value = num;
    }else{
        if(num < (*t)->value){
            insertDataTree(&(*t)->subTreeLeft, num);
        }
        if(num > (*t)->value){
            insertDataTree(&(*t)->subTreeRight, num);
        }
    }
}

int isTree(tree* t, int num){
    if(isEmptyTree(t)){
        return 0;
    }

    return t->value == num || isTree(t->subTreeLeft, num) || isTree(t->subTreeRight, num);
}

int main(){
    tree *t = createTree();

    insertDataTree(&t, 12);
    insertDataTree(&t, 15);
    insertDataTree(&t, 10);
    insertDataTree(&t, 13);

    showTree(t);

    if(isEmptyTree(t)){
        printf("\n Árvore vazia.");
    }else{
        printf("\n\nÁrvore não vazia.")
    }
    
    if(isTree(t, 15)){
        printf("\n O elemento 15 pertence a árvore.\n");
    }else{
        printf("\n O elemento 15 não pertence a árvore.\n");
    }

    if(isTree(t, 22)){
        printf("\n O elemento 22 pertence a árvore.\n");
    }else{
        printf("\n O elemento 22 não pertence a árvore.\n");
    }

    free(t);

    return 0;
}