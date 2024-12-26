#ifndef REALTYPE_H
#define REALTYPE_H

// Definindo a estrutura realtype para representar numeros reais
typedef struct {
    int left; // Parte inteira do numero (à esquerda do ponto decimal)
    int right; // Parte fracionaria do numero (à direita do ponto decimal)
} RealType;

// Funcao para criar um numero real a partir de uma entrada
RealType criaReal(int left, int right);

// Funcao para converter a estrutura RealType de volta para um numero real
double converteParaDouble(RealType r);

// Funcao para somar dois numeros reais representados pela estrutura RealType
RealType somaReal(RealType r1, RealType r2);

// Funcao para subtrair dois numeros reais representados pela estrutura RealType
RealType subtraiReal(RealType r1, RealType r2);

// Funcao para multiplicar dois numeros reais representados pela estrutura RealType
RealType multiplicaReal(RealType r1, RealType r2);

#endif // REALTYPE_H
