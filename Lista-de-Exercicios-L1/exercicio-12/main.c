#include <stdio.h>
#include "conta.h"

int main() {
    // exercicio 12:
    // Para evitar erros de digitacao de sequencias de numeros de importancia fundamental, como a matricula de um aluno, o CPF
    // do Imposto de Renda, ou o numero de conta bancaria, adiciona-se ao numero um digito verificador.
    // Escrever um algoritmo capaz de:
    // a. Ler um conjunto de registros contendo o numero da conta, digito verificador, saldo e nome do cliente.
    // O ultimo registro contem o numero de conta igual a zero.
    // b. Utilizando o esquema de verificacao, imprimir duas listas de clientes com numeros corretos e incorretos.

    Conta contas[4] = {
        {413599, 7, 987.30, "Jacinto Pereira"},
        {111118, 8, 121.99, "Campos Sales"},
        {765432, 1, 335.66, "Junia Faria"},
        {0, 0, 0.0, ""} // Registro de término
    };

    verificarContas(contas, 3);

    return 0;
}
