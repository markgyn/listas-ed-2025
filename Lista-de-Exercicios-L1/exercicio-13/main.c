#include <stdio.h>
#include "matriz.h"

int main() {
    // exercicio 13:
    // Defina um Tipo Abstrato de Dados TMatriz, para representar matrizes quadradas de tamanho n.
    // Implemente as operacoes para somar e multiplicar 2 matrizes. Implemente ainda a operacao do calculo da matriz inversa.

    TMatriz A = {3, {{1, 2, 3}, {0, 1, 4}, {5, 6, 0}}};
    TMatriz B = {3, {{-1, 1, 1}, {2, 3, 4}, {3, -2, 1}}};
    TMatriz soma, produto, inversa;

    // Somando as matrizes
    soma = somarMatrizes(A, B);
    printf("Soma das matrizes A e B:\n");
    imprimirMatriz(soma);
    printf("\n");

    // Multiplicando as matrizes
    produto = multiplicarMatrizes(A, B);
    printf("Produto das matrizes A e B:\n");
    imprimirMatriz(produto);
    printf("\n");

    // Calculando a inversa de A
    if (calcularInversa(&A, &inversa)) {
        printf("Inversa da matriz A:\n");
        imprimirMatriz(inversa);
    } else {
        printf("A matriz A nao possui inversa.\n");
    }

    return 0;
}
