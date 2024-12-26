#include <stdio.h>
#include "conjunto.h"

int main() {
    // exercicio 14:
    // Voce devera implementar um tipo abstrato de dados TConjunto para representar conjuntos de numeros inteiros.
    // Seu tipo abstrato devera armazenar os elementos do conjunto e o seu tamanho n.
    // O TAD deve possuir as operacoes:
    // a. criar um conjunto vazio;
    // b. ler os dados de um conjunto;
    // c. fazer a uniao de dois conjuntos;
    // d. fazer a intersecao de dois conjuntos;
    // e. verificar se dois conjuntos sao iguais;
    // f. imprimir um conjunto.

    TConjunto A, B, uniao, intersecao;
    criarConjunto(&A);
    criarConjunto(&B);

    // Ler o primeiro conjunto
    printf("Ler o conjunto A:\n");
    lerConjunto(&A);

    // Ler o segundo conjunto
    printf("Ler o conjunto B:\n");
    lerConjunto(&B);

    // Imprimir os dois conjuntos
    printf("Conjunto A: ");
    imprimirConjunto(A);
    printf("Conjunto B: ");
    imprimirConjunto(B);

    // União dos conjuntos
    uniao = uniaoConjuntos(A, B);
    printf("Uniao de A e B: ");
    imprimirConjunto(uniao);

    // Interseção dos conjuntos
    intersecao = intersecaoConjuntos(A, B);
    printf("Intersecao de A e B: ");
    imprimirConjunto(intersecao);

    // Verificar se os conjuntos são iguais
    if (conjuntosIguais(A, B)) {
        printf("Os conjuntos A e B sao iguais.\n");
    } else {
        printf("Os conjuntos A e B sao diferentes.\n");
    }

    return 0;
}
