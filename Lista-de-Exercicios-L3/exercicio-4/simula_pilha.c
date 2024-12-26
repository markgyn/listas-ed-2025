#include "simula_pilha.h"
#include <stdio.h>

// Inicializa a estrutura simulada
void inicializaSimulaPilha(SimulaPilha *sp) {
    sp->tamanho = 0;
}

// Simula a operação de empilhar
void empilhaSimulado(SimulaPilha *sp, int item) {
    if (sp->tamanho >= MAX) {
        printf("Nao e possivel empilhar. Estrutura cheia.\n");
        return;
    }
    sp->itens[sp->tamanho] = item;
    sp->tamanho++;
    printf("Empilhado: %d\n", item);
}

// Simula a operação de desempilhar
bool desempilhaSimulado(SimulaPilha *sp) {
    if (sp->tamanho <= 0) {
        printf("Underflow! Tentativa de desempilhar em uma estrutura vazia.\n");
        return false;
    }
    int item = sp->itens[sp->tamanho - 1];
    sp->tamanho--;
    printf("Desempilhado: %d\n", item);
    return true;
}

// Imprime o estado atual da estrutura
void imprimeEstado(SimulaPilha *sp) {
    if (sp->tamanho == 0) {
        printf("Estrutura vazia.\n");
        return;
    }
    printf("Estado atual (base para o topo): ");
    for (int i = 0; i < sp->tamanho; i++) {
        printf("%d ", sp->itens[i]);
    }
    printf("\n");
}
