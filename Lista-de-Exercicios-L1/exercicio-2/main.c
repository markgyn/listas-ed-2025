#include <stdio.h>
#include "realtype.h"


// exercicio 2:
// Vamos supor que um numero real seja representado por uma estrutura em C, como esta abaixo:
//
// struct realtype {
//     int left;
//     int right;
// };
//
// onde left e right representam os digitos posicionados a esquerda e a direita do ponto decimal, respectivamente.
// Se left for um inteiro negativo, o numero real representado sera negativo.
//
// a. Escreva uma rotina para inserir um numero real e criar uma estrutura representando esse numero.
// b. Escreva uma funcao que aceite essa estrutura e retorne o numero real representado por ela.
// c. Escreva rotinas add, subtract e multiply que aceitem duas dessas estruturas e definam o valor de uma terceira
//    estrutura para representar o numero que seja a soma, a diferenca e o produto, respectivamente, dos dois registros de entrada.

int main() {
    // Criando dois numeros reais usando a estrutura RealType
    RealType r1 = criaReal(12, 50); // Representa 12.50
    RealType r2 = criaReal(3, 75); // Representa 3.75

    // Somando os dois numeros
    RealType resultadoSoma = somaReal(r1, r2);
    printf("Soma: %d.%02d\n", resultadoSoma.left, resultadoSoma.right);

    // Subtraindo os dois numeros
    RealType resultadoSubtracao = subtraiReal(r1, r2);
    printf("Subtracao: %d.%02d\n", resultadoSubtracao.left, resultadoSubtracao.right);

    // Multiplicando os dois numeros
    RealType resultadoMultiplicacao = multiplicaReal(r1, r2);
    printf("Multiplicacao: %d.%02d\n", resultadoMultiplicacao.left, resultadoMultiplicacao.right);

    // Convertendo a estrutura RealType para um double
    double realConvertido = converteParaDouble(r1);
    printf("Numero real convertido de r1: %.2f\n", realConvertido);

    return 0;
}
