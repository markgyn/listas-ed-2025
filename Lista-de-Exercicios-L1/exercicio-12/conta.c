#include "conta.h"
#include <stdio.h>

// Função para calcular o dígito verificador da conta
int calcularDigitoVerificador(int numeroConta) {
    int peso = 2;
    int soma = 0;

    // Multiplicar cada dígito da conta pelo peso correspondente
    while (numeroConta > 0) {
        int digito = numeroConta % 10;
        soma += digito * peso;
        peso++;
        numeroConta /= 10;
    }

    // Passo III: Calcular o resto da divisão da soma por 11
    int resto = soma % 11;

    // Passo IV: Subtrair o resto de 11
    int digitoVerificador = 11 - resto;

    // Passo V: Se o resultado for 10 ou 11, o dígito verificador será 0
    if (digitoVerificador == 10 || digitoVerificador == 11) {
        digitoVerificador = 0;
    }

    return digitoVerificador;
}

// Função para processar as contas e dividir em listas corretas e incorretas
void verificarContas(Conta contas[], int tamanho) {
    printf("CONTAS DE NUMERO CORRETO\n");

    for (int i = 0; i < tamanho; i++) {
        int digitoCalculado = calcularDigitoVerificador(contas[i].numeroConta);

        if (digitoCalculado == contas[i].digitoVerificador) {
            printf("%d-%d %.2f %s\n", contas[i].numeroConta, contas[i].digitoVerificador, contas[i].saldo,
                   contas[i].nome);
        }
    }

    printf("\nCONTAS DE NUMERO ERRADO\n");

    for (int i = 0; i < tamanho; i++) {
        int digitoCalculado = calcularDigitoVerificador(contas[i].numeroConta);

        if (digitoCalculado != contas[i].digitoVerificador) {
            printf("%d-%d %.2f %s\n", contas[i].numeroConta, contas[i].digitoVerificador, contas[i].saldo,
                   contas[i].nome);
        }
    }
}
