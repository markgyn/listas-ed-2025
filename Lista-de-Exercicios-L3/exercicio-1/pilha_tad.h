#ifndef PILHA_TAD_H
#define PILHA_TAD_H

#define MAX 100  // Tamanho maximo da pilha
#include <stdbool.h>

typedef int TipoItem;

typedef struct {
    TipoItem itens[MAX];
    int topo;
} Pilha;

// Funcoes basicas
void inicializaPilha(Pilha *p);
bool pilhaVazia(Pilha *p);
bool pilhaCheia(Pilha *p);
void empilha(Pilha *p, TipoItem item);
TipoItem desempilha(Pilha *p);
TipoItem topo(Pilha *p);
void imprimePilha(Pilha *p);

// Funcao para preencher a pilha
void preenchePilha(Pilha *p, int quantidade);

// Funcoes da lista de exercicios
void defineSegundoElemento(Pilha *p, TipoItem i);
void alteraSegundoElemento(Pilha *p, TipoItem i);
void defineNesimoElemento(Pilha *p, int n, TipoItem i);
void alteraNesimoElemento(Pilha *p, int n, TipoItem i);
void defineUltimoElemento(Pilha *p, TipoItem i);
void alteraUltimoElemento(Pilha *p, TipoItem i);
void defineTerceiroElementoDoFinal(Pilha *p, TipoItem i);



#endif
