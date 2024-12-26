#include <stdio.h>
#include "complexo.h"

// exercicio 1:
// Escreva uma especificacao de tipos abstratos de dados (TAD) para os numeros complexos a + bi,
// onde:
// abs(a + bi) eh sqrt(a^2 + b^2),
// (a + bi) + (c + di) eh (a + c) + (b + d)i,
// (a + bi) * (c + di) eh (a * c - b * d) + (a * d + b * c)i e
// -(a + bi) eh (-a) + (-b)i.
//
// Entao, implemente (em C) numeros complexos, conforme especificado acima,
// usando estruturas com partes reais e complexas. Escreva rotinas para somar,
// multiplicar e negar (inverter) tais numeros.

int main() {
    Complexo c1, c2, resultado;

    // Definindo dois numeros complexos para teste
    c1.real = 3.0;
    c1.imag = 4.0;

    c2.real = 1.0;
    c2.imag = 2.0;

    // Soma dos numeros complexos
    resultado = somaComplexo(c1, c2);
    printf("Soma: ");
    imprimeComplexo(resultado);

    // Multiplicacao dos numeros complexos
    resultado = multiplicaComplexo(c1, c2);
    printf("Multiplicacao: ");
    imprimeComplexo(resultado);

    // Negacao (inversao) de um numero complexo
    resultado = negaComplexo(c1);
    printf("Negacao de c1: ");
    imprimeComplexo(resultado);

    // Calculo do modulo de c1
    double modulo = absComplexo(c1);
    printf("Modulo de c1: %.2f\n", modulo);

    return 0;
}
