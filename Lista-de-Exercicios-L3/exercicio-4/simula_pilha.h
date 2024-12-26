#ifndef SIMULA_PILHA_H
#define SIMULA_PILHA_H

#include <stdbool.h>

#define MAX 100  // Tamanho máximo da estrutura

typedef struct {
    int itens[MAX];
    int tamanho;  // Número de elementos na estrutura
} SimulaPilha;

// Funções do TAD
void inicializaSimulaPilha(SimulaPilha *sp);
void empilhaSimulado(SimulaPilha *sp, int item);
bool desempilhaSimulado(SimulaPilha *sp);
void imprimeEstado(SimulaPilha *sp);

#endif
