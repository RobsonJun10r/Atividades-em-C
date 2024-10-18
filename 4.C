#include <stdio.h>
#include <stdlib.h>

typedef struct Livro {
    int codigo;
    struct Livro* proximo;
} Livro;

Livro* inicio = NULL;

void adicionarLivro(int codigo) {
    Livro* novo = (Livro*)malloc(sizeof(Livro));
    novo->codigo = codigo;
    novo->proximo = inicio;
    inicio = novo;
}

void exibirLivros() {
    Livro* temp = inicio;
    while (temp) {
        printf("Livro: %d\n", temp->codigo);
        temp = temp->proximo;
    }
}

void removerLivro(int codigo) {
    if (inicio) {
        if (inicio->codigo == codigo) {
            Livro* temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        } else {
            Livro* temp = inicio;
            while (temp->proximo && temp->proximo->codigo != codigo) {
                temp = temp->proximo;
            }
            if (temp->proximo) {
                Livro* toRemove = temp->proximo;
                temp->proximo = toRemove->proximo;
                free(toRemove);
            }
        }
    }
}

int main() {
    adicionarLivro(1001);
    adicionarLivro(1002);
    exibirLivros();
    removerLivro(1001);
    exibirLivros();
    return 0;
}
