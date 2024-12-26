#ifndef COMPLEXO_H
#define COMPLEXO_H

// Definicao da estrutura para representar um numero complexo
typedef struct {
    double real;   // Parte real
    double imag;   // Parte imaginaria
} Complexo;

// Funcao para calcular o modulo (abs) de um numero complexo
double absComplexo(Complexo c);

// Funcao para somar dois numeros complexos
Complexo somaComplexo(Complexo c1, Complexo c2);

// Funcao para multiplicar dois numeros complexos
Complexo multiplicaComplexo(Complexo c1, Complexo c2);

// Funcao para negar (inverter) um numero complexo
Complexo negaComplexo(Complexo c);

// Funcao para imprimir um numero complexo no formato "a + bi"
void imprimeComplexo(Complexo c);

#endif // COMPLEXO_H
