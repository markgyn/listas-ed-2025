#include <stdio.h>
#include "registro.h"

int main() {
    // exercicio 10:
    // Escrever uma funcao para atribuir um valor ao campo de nome SALARIO do registro REG, descrito no exercicio anterior.
    // Escreva tambem um programa (funcao main) para utilizar a funcao criada.

    REG pessoa;

    // Atribuindo valores iniciais
    snprintf(pessoa.nome, sizeof(pessoa.nome), "Ana Maria");
    pessoa.idade = 28;
    pessoa.sexo = false; // false para feminino

    // Usando a funcao para atribuir o salario
    atribuirSalario(&pessoa, 5000.00);

    // Imprimindo os valores do registro
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Sexo: %s\n", pessoa.sexo ? "Masculino" : "Feminino");
    printf("Salario: %.2f\n", pessoa.salario);

    return 0;
}
