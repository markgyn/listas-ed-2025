#include <stdio.h>
#include "funcionario.h"

int main() {
    // exercicio 11:
    // Uma industria faz a folha mensal de pagamentos de seus empregados baseada no seguinte:
    // Existe uma tabela com os dados do funcionario contendo:
    // - Ficha: Numero de inscricao (numerico), Nome (literal), Classe (numerico), Horas normais (numerico), Horas extras (numerico).
    // O algoritmo deve processar a tabela e emitir, para cada funcionario, o contracheque com o formato:
    //
    // NUMERO DE INSCRICAO:
    // NOME:
    // SALARIO HORAS NORMAIS:
    // SALARIO HORAS EXTRAS:
    // DEDUCAO INSS:
    // SALARIO LIQUIDO:
    //
    // O salario de referencia deve ser lido previamente.
    // O salario referente as horas extras e calculado adicionando 30% ao salario-hora normal.
    // O desconto do INSS e de 11% do salario bruto (salario correspondente as horas normais trabalhadas + horas extras).
    // Existem duas classes de funcionarios:
    // - Classe 1: 1,3 vezes o salario de referencia.
    // - Classe 2: 1,9 vezes o salario de referencia.

    Funcionario funcionarios[2]; // Suponha que temos 2 funcionarios para este exemplo
    double salarioReferencia;

    // Entrada do salario de referencia
    printf("Digite o salario de referencia: ");
    scanf("%lf", &salarioReferencia);

    // Dados do primeiro funcionario
    funcionarios[0].inscricao = 1;
    snprintf(funcionarios[0].nome, sizeof(funcionarios[0].nome), "Joao Silva");
    funcionarios[0].classe = 1;
    funcionarios[0].horasNormais = 160; // 160 horas normais
    funcionarios[0].horasExtras = 20; // 20 horas extras

    // Dados do segundo funcionario
    funcionarios[1].inscricao = 2;
    snprintf(funcionarios[1].nome, sizeof(funcionarios[1].nome), "Ana Maria");
    funcionarios[1].classe = 2;
    funcionarios[1].horasNormais = 160; // 160 horas normais
    funcionarios[1].horasExtras = 15; // 15 horas extras

    // Processar e imprimir o contracheque de cada funcionario
    for (int i = 0; i < 2; i++) {
        imprimirContracheque(funcionarios[i], salarioReferencia);
    }

    return 0;
}
