#include <stdio.h>
#include "rational.h"

int main() {
    // exercicio 7:
    // Implemente uma funcao equal que determine se dois numeros racionais (RATIONAL da questao anterior), r1 e r2, sao iguais ou nao,
    // reduzindo primeiramente r1 e r2 a seus termos minimos e verificando em seguida a igualdade.

    RATIONAL r1 = {2, 4}; // Representa 2/4 (equivalente a 1/2 apos simplificacao)
    RATIONAL r2 = {1, 2}; // Representa 1/2

    // Verificando se os dois numeros racionais sao iguais
    if (equal(r1, r2)) {
        printf("r1 e r2 sao iguais.\n");
    } else {
        printf("r1 e r2 sao diferentes.\n");
    }

    return 0;
}
