#ifndef REGISTRO_H
#define REGISTRO_H

// Estrutura para representar um estudante
typedef struct {
    char sobrenome[50];
    char primeiroNome[50];
    float indiceGraduacao; // Indice de pontos de graduacao
} Estudante;

// Estrutura para representar um funcionario
typedef struct {
    char sobrenome[50];
    char primeiroNome[50];
    double salario;
} Funcionario;

// Funcao para conceder aumento de 10% a funcionarios que tenham um estudante correspondente
void concederAumento(Funcionario funcionarios[], int numFuncionarios, Estudante estudantes[], int numEstudantes);

#endif // REGISTRO_H
