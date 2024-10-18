#include <stdio.h>
#include <stdlib.h>

typedef struct Visitante {
    int id;
    struct Visitante* proximo;
} Visitante;

Visitante* inicio = NULL;

void inserirVisitante(int id) {
    Visitante* novo = (Visitante*)malloc(sizeof(Visitante));
    novo->id = id;
    novo->proximo = NULL;

    if (!inicio) {
        inicio = novo;
    } else {
        Visitante* temp = inicio;
        while (temp->proximo) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void removerVisitante() {
    if (inicio) {
        Visitante* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

void exibirVisitantes() {
    Visitante* temp = inicio;
    while (temp) {
        printf("Visitante: %d\n", temp->id);
        temp = temp->proximo;
    }
}

int main() {
    inserirVisitante(1);
    inserirVisitante(2);
    exibirVisitantes();
    removerVisitante();
    exibirVisitantes();
    return 0;
}
