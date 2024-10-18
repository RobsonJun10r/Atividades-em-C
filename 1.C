#include <stdio.h>
#include <stdlib.h>

typedef struct Pedido {
    int numero;
    struct Pedido* proximo;
} Pedido;

Pedido* inicio = NULL;

void adicionarPedido(int numero) {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
    novo->numero = numero;
    novo->proximo = NULL;
    if (!inicio) {
        inicio = novo;
    } else {
        Pedido* temp = inicio;
        while (temp->proximo) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

void exibirPedidos() {
    Pedido* temp = inicio;
    while (temp) {
        printf("Pedido: %d\n", temp->numero);
        temp = temp->proximo;
    }
}

void removerPedido() {
    if (inicio) {
        Pedido* temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

int main() {
    adicionarPedido(1);
    adicionarPedido(2);
    exibirPedidos();
    removerPedido();
    exibirPedidos();
    return 0;
}
