#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Estrutura para representar um funcionário
typedef struct {
    int inscricao; // Número de inscrição
    char nome[50]; // Nome do funcionário
    int classe; // Classe do funcionário (1 ou 2)
    double horasNormais; // Horas normais trabalhadas
    double horasExtras; // Horas extras trabalhadas
} Funcionario;

// Função para calcular o salário bruto do funcionário
double calcularSalarioBruto(Funcionario func, double salarioReferencia);

// Função para calcular o desconto do INSS
double calcularDescontoINSS(double salarioBruto);

// Função para imprimir o contracheque de um funcionário
void imprimirContracheque(Funcionario func, double salarioReferencia);

#endif // FUNCIONARIO_H
