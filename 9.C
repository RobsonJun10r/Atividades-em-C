#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
    int codigo;
    struct Produto* proximo;
} Produto;

Produto* inicio = NULL;

void adicionarProduto(int codigo) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    novo->codigo = codigo;
    novo->proximo = inicio;
    inicio = novo;
}

void removerProduto(int codigo) {
    if (inicio) {
        if (inicio->codigo == codigo) {
            Produto* temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        } else {
            Produto* temp = inicio;
            while (temp->proximo && temp->proximo->codigo != codigo) {
                temp = temp->proximo;
            }
            if (temp->proximo) {
                Produto* toRemove = temp->proximo;
                temp->proximo = toRemove->proximo;
                free(toRemove);
            }
        }
    }
}

void exibirProdutos() {
    Produto* temp = inicio;
    while (temp) {
        printf("Produto: %d\n", temp->codigo);
        temp = temp->proximo;
    }
}

int main() {
    adicionarProduto(1001);
    adicionarProduto(1002);
    exibirProdutos();
    removerProduto(1001);
    exibirProdutos();
    return 0;
}
