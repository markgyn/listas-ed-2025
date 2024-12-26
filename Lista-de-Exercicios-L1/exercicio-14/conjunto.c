#include "conjunto.h"
#include <stdio.h>

// Função para criar um conjunto vazio
void criarConjunto(TConjunto *conjunto) {
    conjunto->tamanho = 0;
}

// Função para ler os dados de um conjunto
void lerConjunto(TConjunto *conjunto) {
    int n, valor;
    printf("Quantos elementos deseja inserir no conjunto (max %d)? ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    conjunto->tamanho = n;
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        conjunto->elementos[i] = valor;
    }
}

// Função para verificar se um elemento já está no conjunto
int elementoJaExiste(TConjunto conjunto, int elemento) {
    for (int i = 0; i < conjunto.tamanho; i++) {
        if (conjunto.elementos[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

// Função para fazer a união de dois conjuntos
TConjunto uniaoConjuntos(TConjunto a, TConjunto b) {
    TConjunto resultado;
    criarConjunto(&resultado);

    // Adicionar elementos do primeiro conjunto
    for (int i = 0; i < a.tamanho; i++) {
        resultado.elementos[resultado.tamanho++] = a.elementos[i];
    }

    // Adicionar elementos do segundo conjunto, se não estiverem no primeiro
    for (int i = 0; i < b.tamanho; i++) {
        if (!elementoJaExiste(a, b.elementos[i])) {
            resultado.elementos[resultado.tamanho++] = b.elementos[i];
        }
    }

    return resultado;
}

// Função para fazer a interseção de dois conjuntos
TConjunto intersecaoConjuntos(TConjunto a, TConjunto b) {
    TConjunto resultado;
    criarConjunto(&resultado);

    // Adicionar elementos que estão em ambos os conjuntos
    for (int i = 0; i < a.tamanho; i++) {
        if (elementoJaExiste(b, a.elementos[i])) {
            resultado.elementos[resultado.tamanho++] = a.elementos[i];
        }
    }

    return resultado;
}

// Função para verificar se dois conjuntos são iguais
int conjuntosIguais(TConjunto a, TConjunto b) {
    if (a.tamanho != b.tamanho) return 0;

    // Verificar se todos os elementos de "a" estão em "b"
    for (int i = 0; i < a.tamanho; i++) {
        if (!elementoJaExiste(b, a.elementos[i])) {
            return 0;
        }
    }

    return 1;
}

// Função para imprimir um conjunto
void imprimirConjunto(TConjunto conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto.tamanho; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}
