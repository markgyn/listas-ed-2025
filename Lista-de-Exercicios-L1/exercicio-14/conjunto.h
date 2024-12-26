#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX 20  // Tamanho máximo do conjunto

// Estrutura para representar um conjunto de inteiros
typedef struct {
    int elementos[MAX]; // Array de elementos do conjunto
    int tamanho; // Tamanho atual do conjunto
} TConjunto;

// Funções para operações com conjuntos
void criarConjunto(TConjunto *conjunto);

void lerConjunto(TConjunto *conjunto);

TConjunto uniaoConjuntos(TConjunto a, TConjunto b);

TConjunto intersecaoConjuntos(TConjunto a, TConjunto b);

int conjuntosIguais(TConjunto a, TConjunto b);

void imprimirConjunto(TConjunto conjunto);

#endif // CONJUNTO_H
