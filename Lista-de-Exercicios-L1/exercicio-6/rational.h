#ifndef RATIONAL_H
#define RATIONAL_H

// Estrutura para representar um numero racional
typedef struct {
    int numerator;
    int denominator;
} RATIONAL;

// Funcoes para operacoes com numeros racionais
RATIONAL somaRacional(RATIONAL r1, RATIONAL r2);

RATIONAL subtraiRacional(RATIONAL r1, RATIONAL r2);

RATIONAL divideRacional(RATIONAL r1, RATIONAL r2);

void imprimeRacional(RATIONAL r);

#endif // RATIONAL_H
