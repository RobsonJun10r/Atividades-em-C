#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
    float preco;
    struct Produto* proximo;
} Produto;

Produto* inicio = NULL;

void inserirProduto(float preco) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    novo->preco = preco;
    novo->proximo = NULL;

    if (!inicio || inicio->preco > preco) {
        novo->proximo = inicio;
        inicio = novo;
    } else {
        Produto* temp = inicio;
        while (temp->proximo && temp->proximo->preco < preco) {
            temp = temp->proximo;
        }
        novo->proximo = temp->proximo;
        temp->proximo = novo;
    }
}

void exibirProdutos() {
    Produto* temp = inicio;
    while (temp) {
        printf("Produto: %.2f\n", temp->preco);
        temp = temp->proximo;
    }
}

void removerProduto(float preco) {
    if (inicio) {
        if (inicio->preco == preco) {
            Produto* temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        } else {
            Produto* temp = inicio;
            while (temp->proximo && temp->proximo->preco != preco) {
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

int main() {
    inserirProduto(10.99);
    inserirProduto(5.49);
    exibirProdutos();
    removerProduto(10.99);
    exibirProdutos();
    return 0;
}
