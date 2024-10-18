#include <stdio.h>
#include <stdlib.h>

typedef struct Compromisso {
    int horario;
    struct Compromisso* proximo;
} Compromisso;

Compromisso* inicio = NULL;

void inserirCompromisso(int horario) {
    Compromisso* novo = (Compromisso*)malloc(sizeof(Compromisso));
    novo->horario = horario;
    novo->proximo = NULL;

    if (!inicio || inicio->horario > horario) {
        novo->proximo = inicio;
        inicio = novo;
    } else {
        Compromisso* temp = inicio;
        while (temp->proximo && temp->proximo->horario < horario) {
            temp = temp->proximo;
        }
        novo->proximo = temp->proximo;
        temp->proximo = novo;
    }
}

void exibirCompromissos() {
    Compromisso* temp = inicio;
    while (temp) {
        printf("Compromisso: %d\n", temp->horario);
        temp = temp->proximo;
    }
}

void removerCompromisso(int horario) {
    if (inicio) {
        if (inicio->horario == horario) {
            Compromisso* temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        } else {
            Compromisso* temp = inicio;
            while (temp->proximo && temp->proximo->horario != horario) {
                temp = temp->proximo;
            }
            if (temp->proximo) {
                Compromisso* toRemove = temp->proximo;
                temp->proximo = toRemove->proximo;
                free(toRemove);
            }
        }
    }
}

int main() {
    inserirCompromisso(10);
    inserirCompromisso(15);
    exibirCompromissos();
    removerCompromisso(10);
    exibirCompromissos();
    return 0;
}
