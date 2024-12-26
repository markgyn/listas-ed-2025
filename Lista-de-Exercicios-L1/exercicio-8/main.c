#include <stdio.h>
#include "rational.h"

int main() {
    // exercicio 8:
    // Um metodo alternativo para implementar a funcao equal citada na questao anterior seria multiplicar o denominador de cada numero
    // pelo numerador do outro e testar a igualdade dos dois produtos. Escreva uma funcao equal2 para implementar esse algoritmo.
    // Qual dos dois metodos e preferivel?

    RATIONAL r1 = {2, 4}; // Representa 2/4
    RATIONAL r2 = {1, 2}; // Representa 1/2

    // Testando a igualdade com a funcao equal (metodo de simplificacao)
    if (equal(r1, r2)) {
        printf("r1 e r2 sao iguais (usando equal com simplificacao).\n");
    } else {
        printf("r1 e r2 sao diferentes (usando equal com simplificacao).\n");
    }

    // Testando a igualdade com a funcao equal2 (multiplicacao cruzada)
    if (equal2(r1, r2)) {
        printf("r1 e r2 sao iguais (usando equal2 com multiplicacao cruzada).\n");
    } else {
        printf("r1 e r2 sao diferentes (usando equal2 com multiplicacao cruzada).\n");
    }

    return 0;
}
