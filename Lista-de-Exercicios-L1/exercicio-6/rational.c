#include <stdio.h>
#include "rational.h"

// Funcao auxiliar para calcular o maior divisor comum (MDC) usando o algoritmo de Euclides
int mdc(int a, int b) {
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

// Funcao para simplificar um numero racional
RATIONAL simplificaRacional(RATIONAL r) {
    int divisor = mdc(r.numerator, r.denominator);
    r.numerator /= divisor;
    r.denominator /= divisor;
    return r;
}

// Funcao para somar dois numeros racionais
RATIONAL somaRacional(RATIONAL r1, RATIONAL r2) {
    RATIONAL resultado;
    resultado.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    resultado.denominator = r1.denominator * r2.denominator;
    return simplificaRacional(resultado);
}

// Funcao para subtrair dois numeros racionais
RATIONAL subtraiRacional(RATIONAL r1, RATIONAL r2) {
    RATIONAL resultado;
    resultado.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    resultado.denominator = r1.denominator * r2.denominator;
    return simplificaRacional(resultado);
}

// Funcao para dividir dois numeros racionais
RATIONAL divideRacional(RATIONAL r1, RATIONAL r2) {
    RATIONAL resultado;
    resultado.numerator = r1.numerator * r2.denominator;
    resultado.denominator = r1.denominator * r2.numerator;
    return simplificaRacional(resultado);
}

// Funcao para imprimir um numero racional
void imprimeRacional(RATIONAL r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}
