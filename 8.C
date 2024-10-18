#include <stdio.h>
#include <stdlib.h>

typedef struct Pontuacao {
    int pontos;
    struct Pontuacao* proximo;
} Pontuacao;

Pontuacao* inicio = NULL;

void inserirPontuacao(int pontos) {
    Pontuacao* novo = (Pontuacao*)malloc(sizeof(Pontuacao));
    novo->pontos = pontos;
    novo->proximo = NULL;

    if (!inicio || inicio->pontos > pontos) {
        novo->proximo = inicio;
        inicio = novo;
    } else {
        Pontuacao* temp = inicio;
        while (temp->proximo && temp->proximo->pontos < pontos) {
            temp = temp->proximo;
        }
        novo->proximo = temp->proximo;
        temp->proximo = novo;
    }
}

void exibirPontuacoes() {
    Pontuacao* temp = inicio;
    while (temp) {
        printf("Pontuação: %d\n", temp->pontos);
        temp = temp->proximo;
    }
}

void removerPontuacao(int pontos) {
    if (inicio) {
        if (inicio->pontos == pontos) {
            Pontuacao* temp = inicio;
            inicio = inicio->proximo;
            free(temp);
        } else {
            Pontuacao* temp = inicio;
            while (temp->proximo && temp->proximo->pontos != pontos) {
                temp = temp->proximo;
            }
            if (temp->proximo) {
                Pontuacao* toRemove = temp->proximo;
                temp->proximo = toRemove->proximo;
                free(toRemove);
            }
        }
    }
}

int main() {
    inserirPontuacao(1500);
    inserirPontuacao(2000);
    exibirPontuacoes();
    removerPontuacao(1500);
    exibirPontuacoes();
    return 0;
}
