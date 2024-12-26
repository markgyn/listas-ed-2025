#include <stdio.h>
#include "realtype.h"

// Funcao para criar um numero real a partir de uma entrada
RealType criaReal(int left, int right) {
    RealType r;
    r.left = left;
    r.right = right;
    return r;
}

// Funcao para converter a estrutura RealType de volta para um numero real
double converteParaDouble(RealType r) {
    double parteFracionaria = r.right / 100.0; // Supoe que 'right' tem dois digitos
    return r.left + parteFracionaria;
}

// Funcao para somar dois numeros reais representados pela estrutura RealType
RealType somaReal(RealType r1, RealType r2) {
    RealType resultado;
    resultado.left = r1.left + r2.left;
    resultado.right = r1.right + r2.right;

    // Ajustar a parte fracionaria
    if (resultado.right >= 100) {
        resultado.left += 1;
        resultado.right -= 100;
    }

    return resultado;
}

// Funcao para subtrair dois numeros reais representados pela estrutura RealType
RealType subtraiReal(RealType r1, RealType r2) {
    RealType resultado;
    resultado.left = r1.left - r2.left;
    resultado.right = r1.right - r2.right;

    // Ajustar a parte fracionaria
    if (resultado.right < 0) {
        resultado.left -= 1;
        resultado.right += 100;
    }

    return resultado;
}

// Funcao para multiplicar dois numeros reais representados pela estrutura RealType
RealType multiplicaReal(RealType r1, RealType r2) {
    double numero1 = converteParaDouble(r1);
    double numero2 = converteParaDouble(r2);

    double produto = numero1 * numero2;

    RealType resultado;
    resultado.left = (int) produto;
    resultado.right = (int) ((produto - resultado.left) * 100);

    return resultado;
}
