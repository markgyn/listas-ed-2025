#ifndef MATRIZ_H
#define MATRIZ_H

#define MAX 10  // Define o tamanho máximo da matriz

// Estrutura para representar uma matriz quadrada
typedef struct {
    int n; // Tamanho da matriz
    double m[MAX][MAX]; // Elementos da matriz
} TMatriz;

// Função para somar duas matrizes
TMatriz somarMatrizes(TMatriz a, TMatriz b);

// Função para multiplicar duas matrizes
TMatriz multiplicarMatrizes(TMatriz a, TMatriz b);

// Função para calcular a inversa de uma matriz
int calcularInversa(TMatriz *matriz, TMatriz *inversa);

// Função para imprimir uma matriz
void imprimirMatriz(TMatriz matriz);

#endif // MATRIZ_H
