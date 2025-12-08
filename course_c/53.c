#include <stdio.h>
#include <string.h>

struct st_contato {
    char nome[100];
    char telefone[20];
    char email[100];
    int ano_nascimento;
};

struct st_agenda {
    struct st_contato contatos[100];
}agenda;

int main() {
    for(int i =0; i < 3; i++){
        printf("Informe o nome: ");
        fgets(agenda.contatos[i].nome, 100, stdin);
    
        printf("Informe o telefone: ");
        fgets(agenda.contatos[i].telefone, 20, stdin);
    
        printf("Informe o email: ");
        fgets(agenda.contatos[i].email, 100, stdin);
    
        printf("Informe o ano de nascimento: ");
        scanf("%d", &agenda.contatos[i].ano_nascimento);
        getchar();
    }

    printf("======= Agenda de Contato =======\n");
    for(int i = 0; i < 3; i++){
        printf("======= Contato %d =======\n", (i + 1));
        printf("Nome: %s", agenda.contatos[i].nome);
        printf("Telefone: %s", agenda.contatos[i].telefone);
        printf("Email: %s", agenda.contatos[i].email);
        printf("Ano de nascimento: %d\n", agenda.contatos[i].ano_nascimento);
    }

    return 0;
}
