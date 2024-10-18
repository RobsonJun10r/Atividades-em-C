#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    int matricula;
    struct Aluno* proximo;
} Aluno;

Aluno* inicio = NULL;

void adicionarAluno(int matricula) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->matricula = matricula;
    novo->proximo = inicio;
    inicio = novo;
}

void exibirAlunos() {
    Aluno* temp = inicio;
    while (temp) {
        printf("Aluno: %d\n", temp->matricula);
        temp = temp->proximo;
    }
}

int buscarAluno(int matricula) {
    Aluno* temp = inicio;
    while (temp) {
        if (temp->matricula == matricula) {
            return 1; // Aluno encontrado
        }
        temp = temp->proximo;
    }
    return 0; // Aluno não encontrado
}

int main() {
    adicionarAluno(101);
    adicionarAluno(102);
    exibirAlunos();
    printf("Aluno 101 %s\n", buscarAluno(101) ? "encontrado" : "não encontrado");
    return 0;
}
