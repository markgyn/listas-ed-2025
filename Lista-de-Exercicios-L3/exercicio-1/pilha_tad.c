#include "pilha_tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Funcoes basicas
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

bool pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilha(Pilha *p, TipoItem item) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->itens[++p->topo] = item;
}

TipoItem desempilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo--];
}

TipoItem topo(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}

// Funcao para preencher a pilha
void preenchePilha(Pilha *p, int quantidade) {
    if (quantidade > MAX) {
        printf("Quantidade excede o tamanho maximo da pilha (%d).\n", MAX);
        return;
    }

    inicializaPilha(p);  // Garantir que a pilha esteja inicializada
    for (int i = 0; i < quantidade; i++) {
        empilha(p, i + 1);  // Preenchendo a pilha com valores incrementais (1, 2, 3, ...)
    }
    printf("Pilha preenchida com %d elementos.\n", quantidade);
}

// Funcoes da lista de exercicios
void defineSegundoElemento(Pilha *p, TipoItem i) {
    if (p->topo < 1) {
        printf("Pilha nao tem elementos suficientes.\n");
        return;
    }
    TipoItem topo1 = desempilha(p);
    TipoItem topo2 = desempilha(p);
    empilha(p, i);
    empilha(p, topo1);
}

void alteraSegundoElemento(Pilha *p, TipoItem i) {
    if (p->topo < 1) {
        printf("Pilha nao tem elementos suficientes.\n");
        return;
    }
    TipoItem topo1 = desempilha(p);
    p->itens[p->topo] = i;
    empilha(p, topo1);
}

void defineNesimoElemento(Pilha *p, int n, TipoItem i) {
    if (n > p->topo + 1) {
        printf("A pilha nao tem %d elementos.\n", n);
        return;
    }
    Pilha temp;
    inicializaPilha(&temp);
    while (p->topo >= n) {
        empilha(&temp, desempilha(p));
    }
    p->itens[p->topo] = i;
    while (!pilhaVazia(&temp)) {
        empilha(p, desempilha(&temp));
    }
}

void alteraNesimoElemento(Pilha *p, int n, TipoItem i) {
    if (n > p->topo + 1) {
        printf("A pilha nao tem %d elementos.\n", n);
        return;
    }
    Pilha temp;
    inicializaPilha(&temp);
    for (int j = 0; j < n - 1; j++) {
        empilha(&temp, desempilha(p));
    }
    p->itens[p->topo] = i;
    while (!pilhaVazia(&temp)) {
        empilha(p, desempilha(&temp));
    }
}

void defineUltimoElemento(Pilha *p, TipoItem i) {
    while (!pilhaVazia(p)) {
        desempilha(p);
    }
    empilha(p, i);
}

void alteraUltimoElemento(Pilha *p, TipoItem i) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    Pilha temp;
    inicializaPilha(&temp);
    while (p->topo > 0) {
        empilha(&temp, desempilha(p));
    }
    p->itens[p->topo] = i;
    while (!pilhaVazia(&temp)) {
        empilha(p, desempilha(&temp));
    }
}

void defineTerceiroElementoDoFinal(Pilha *p, TipoItem i) {
    if (p->topo < 2) {
        printf("Pilha nao tem pelo menos 3 elementos.\n");
        return;
    }
    Pilha temp;
    inicializaPilha(&temp);
    for (int j = 0; j < 2; j++) {
        empilha(&temp, desempilha(p));
    }
    p->itens[p->topo] = i;
    while (!pilhaVazia(&temp)) {
        empilha(p, desempilha(&temp));
    }
}

void imprimePilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Estado atual da pilha (do topo para o final):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}
