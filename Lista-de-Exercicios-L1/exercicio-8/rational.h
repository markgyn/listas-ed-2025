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

int equal(RATIONAL r1, RATIONAL r2); // Verifica igualdade simplificando
int equal2(RATIONAL r1, RATIONAL r2); // Verifica igualdade multiplicando cruzado

#endif // RATIONAL_H
