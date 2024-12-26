#include "matriz.h"
#include <stdio.h>

// Função para somar duas matrizes
TMatriz somarMatrizes(TMatriz a, TMatriz b) {
    TMatriz resultado;
    resultado.n = a.n;

    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.n; j++) {
            resultado.m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }

    return resultado;
}

// Função para multiplicar duas matrizes
TMatriz multiplicarMatrizes(TMatriz a, TMatriz b) {
    TMatriz resultado;
    resultado.n = a.n;

    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.n; j++) {
            resultado.m[i][j] = 0;
            for (int k = 0; k < a.n; k++) {
                resultado.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }

    return resultado;
}

// Função auxiliar para calcular o determinante de uma matriz
double calcularDeterminante(double mat[MAX][MAX], int n) {
    double det = 0;
    if (n == 1) {
        return mat[0][0];
    }
    double temp[MAX][MAX];
    int sinal = 1;
    for (int f = 0; f < n; f++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == f) continue;
                temp[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += sinal * mat[0][f] * calcularDeterminante(temp, n - 1);
        sinal = -sinal;
    }
    return det;
}

// Função para calcular a inversa de uma matriz
int calcularInversa(TMatriz *matriz, TMatriz *inversa) {
    int n = matriz->n;
    double det = calcularDeterminante(matriz->m, n);
    if (det == 0) {
        printf("Matriz nao possui inversa (determinante = 0).\n");
        return 0;
    }

    // Calcula a matriz inversa utilizando cofatores (simplificação)
    TMatriz cofator;
    cofator.n = n;
    double temp[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int subi = 0;
            for (int xi = 0; xi < n; xi++) {
                if (xi == i) continue;
                int subj = 0;
                for (int xj = 0; xj < n; xj++) {
                    if (xj == j) continue;
                    temp[subi][subj] = matriz->m[xi][xj];
                    subj++;
                }
                subi++;
            }
            cofator.m[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * calcularDeterminante(temp, n - 1);
        }
    }

    // Transposição e divisão pelo determinante
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inversa->m[i][j] = cofator.m[j][i] / det;
        }
    }
    inversa->n = n;

    return 1;
}

// Função para imprimir uma matriz
void imprimirMatriz(TMatriz matriz) {
    for (int i = 0; i < matriz.n; i++) {
        for (int j = 0; j < matriz.n; j++) {
            printf("%.2f ", matriz.m[i][j]);
        }
        printf("\n");
    }
}
