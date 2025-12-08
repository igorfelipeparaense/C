#include <stdio.h>

struct st_aluno{
    char matricula[10];
    char curso[100];
    char nome[100];
};

int main() {
    struct st_aluno alunos[5];

    for(int i = 0; i < 5; i++){
        printf("Cadastro %d de 5:\n", i + 1);

        printf("Informe o nome do aluno: ");
        fgets(alunos[i].nome, 100, stdin);
    
        printf("Informe a matrícula: ");
        fgets(alunos[i].matricula, 10, stdin);

        printf("Informe o curso: ");
        fgets(alunos[i].curso, 100, stdin);
    }

    printf("---------------------------\n");

    for(int i = 0; i < 5; i++){
        printf("Dados %d de 5:\n", i + 1);
        printf("Nome: %s", alunos[i].nome);
        printf("Matrícula: %s", alunos[i].matricula);
        printf("Curso: %s", alunos[i].curso);
        printf("---------------------------\n");
    }

    return 0;
}
