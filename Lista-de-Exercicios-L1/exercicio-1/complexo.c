#include <stdio.h>
#include <math.h>
#include "complexo.h"

// Funcao para calcular o modulo (abs) de um numero complexo
double absComplexo(Complexo c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

// Funcao para somar dois numeros complexos
Complexo somaComplexo(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

// Funcao para multiplicar dois numeros complexos
Complexo multiplicaComplexo(Complexo c1, Complexo c2) {
    Complexo resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

// Funcao para negar (inverter) um numero complexo
Complexo negaComplexo(Complexo c) {
    c.real = -c.real;
    c.imag = -c.imag;
    return c;
}

// Funcao para imprimir um numero complexo no formato "a + bi"
void imprimeComplexo(Complexo c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}
