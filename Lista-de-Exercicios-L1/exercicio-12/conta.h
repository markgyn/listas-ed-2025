#ifndef CONTA_H
#define CONTA_H

// Estrutura para armazenar as informações de uma conta
typedef struct {
    int numeroConta; // Número da conta (sem o dígito verificador)
    int digitoVerificador; // Dígito verificador fornecido
    double saldo; // Saldo da conta
    char nome[50]; // Nome do cliente
} Conta;

// Função para calcular o dígito verificador da conta
int calcularDigitoVerificador(int numeroConta);

// Função para processar as contas e dividir em listas corretas e incorretas
void verificarContas(Conta contas[], int tamanho);

#endif // CONTA_H
