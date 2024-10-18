#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente {
    int id;
    struct Paciente* proximo;
} Paciente;

Paciente* inicio = NULL;

void adicionarPaciente(int id) {
    Paciente* novo = (Paciente*)malloc(sizeof(Paciente));
    novo->id = id;
    novo->proximo = NULL;
    if (!inicio) {
        inicio = novo;
    } else {
        Paciente* temp = inicio;
        while (temp->proximo) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void removerPaciente() {
    if (inicio) {
        Paciente* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

void exibirPacientes() {
    Paciente* temp = inicio;
    while (temp) {
        printf("Paciente: %d\n", temp->id);
        temp = temp->proximo;
    }
}

int main() {
    adicionarPaciente(1);
    adicionarPaciente(2);
    exibirPacientes();
    removerPaciente();
    exibirPacientes();
    return 0;
}
