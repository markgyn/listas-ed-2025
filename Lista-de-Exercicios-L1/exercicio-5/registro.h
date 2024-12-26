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

// Funcao para carregar registros de funcionarios de um arquivo
int carregarFuncionarios(const char *nomeArquivo, Funcionario funcionarios[], int tamanhoMaximo);

// Funcao para carregar registros de estudantes de um arquivo
int carregarEstudantes(const char *nomeArquivo, Estudante estudantes[], int tamanhoMaximo);

// Funcao para conceder aumento de 10% a funcionarios que tenham um estudante correspondente
void concederAumento(Funcionario funcionarios[], int numFuncionarios, Estudante estudantes[], int numEstudantes);

// Funcao para salvar os dados dos funcionarios em um arquivo apos o aumento
void salvarFuncionarios(const char *nomeArquivo, Funcionario funcionarios[], int numFuncionarios);

#endif // REGISTRO_H
