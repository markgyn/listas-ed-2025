#include <stdio.h>
#include "rational.h"

int main() {
    // exercicio 6:
    // Usando a representacao de numeros racionais apresentada abaixo, escreva rotinas para somar, subtrair e dividir dois numeros do tipo RATIONAL.
    // typedef struct {
    //     int numerator;
    //     int denominator;
    // } RATIONAL;

    RATIONAL r1 = {1, 2}; // Representa 1/2
    RATIONAL r2 = {3, 4}; // Representa 3/4

    // Somando dois numeros racionais
    RATIONAL resultadoSoma = somaRacional(r1, r2);
    printf("Soma: ");
    imprimeRacional(resultadoSoma);

    // Subtraindo dois numeros racionais
    RATIONAL resultadoSubtracao = subtraiRacional(r1, r2);
    printf("Subtracao: ");
    imprimeRacional(resultadoSubtracao);

    // Dividindo dois numeros racionais
    RATIONAL resultadoDivisao = divideRacional(r1, r2);
    printf("Divisao: ");
    imprimeRacional(resultadoDivisao);

    return 0;
}
