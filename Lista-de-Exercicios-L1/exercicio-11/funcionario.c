#include "funcionario.h"
#include <stdio.h>

// Funcao para calcular o salario bruto
double calcularSalarioBruto(Funcionario func, double salarioReferencia) {
    double salarioHoraNormal;
    double salarioBruto;

    // Determinar o salario por hora de acordo com a classe
    if (func.classe == 1) {
        salarioHoraNormal = salarioReferencia * 1.3;
    } else {
        salarioHoraNormal = salarioReferencia * 1.9;
    }

    // Calcular o salario pelas horas normais
    salarioBruto = func.horasNormais * salarioHoraNormal;

    // Adicionar o valor das horas extras (com 30% de adicional)
    salarioBruto += func.horasExtras * (salarioHoraNormal * 1.3);

    return salarioBruto;
}

// Funcao para calcular o desconto do INSS (11% do salario bruto)
double calcularDescontoINSS(double salarioBruto) {
    return salarioBruto * 0.11;
}

// Funcao para imprimir o contracheque
void imprimirContracheque(Funcionario func, double salarioReferencia) {
    double salarioBruto = calcularSalarioBruto(func, salarioReferencia);
    double descontoINSS = calcularDescontoINSS(salarioBruto);
    double salarioLiquido = salarioBruto - descontoINSS;

    printf("NUMERO DE INSCRICAO: %d\n", func.inscricao);
    printf("NOME: %s\n", func.nome);
    printf("SALARIO HORAS NORMAIS: %.2f\n",
           func.horasNormais * (func.classe == 1 ? salarioReferencia * 1.3 : salarioReferencia * 1.9));
    printf("SALARIO HORAS EXTRAS: %.2f\n",
           func.horasExtras * ((func.classe == 1 ? salarioReferencia * 1.3 : salarioReferencia * 1.9) * 1.3));
    printf("DEDUCAO INSS: %.2f\n", descontoINSS);
    printf("SALARIO LIQUIDO: %.2f\n", salarioLiquido);
    printf("----------------------------------------\n");
}
