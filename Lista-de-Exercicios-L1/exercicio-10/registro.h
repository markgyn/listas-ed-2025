#ifndef REGISTRO_H
#define REGISTRO_H
#include <stdbool.h>

// Estrutura para representar um registro de pessoa
typedef struct {
    char nome[50]; // Nome da pessoa
    double salario; // Salario da pessoa
    int idade; // Idade da pessoa
    bool sexo; // Sexo da pessoa (true para masculino, false para feminino)
} REG;

// Funcao para atribuir um valor ao campo salario de um registro REG
void atribuirSalario(REG *pessoa, double novoSalario);

#endif // REGISTRO_H
