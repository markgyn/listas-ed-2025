#include <stdio.h>
#include <string.h>
#include "registro.h"

// Funcao para carregar registros de funcionarios de um arquivo
int carregarFuncionarios(const char *nomeArquivo, Funcionario funcionarios[], int tamanhoMaximo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (count < tamanhoMaximo && fscanf(arquivo, "%49s %49s %lf",
                                           funcionarios[count].sobrenome, funcionarios[count].primeiroNome,
                                           &funcionarios[count].salario) == 3) {
        count++;
    }

    fclose(arquivo);
    return count;
}

// Funcao para carregar registros de estudantes de um arquivo
int carregarEstudantes(const char *nomeArquivo, Estudante estudantes[], int tamanhoMaximo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int count = 0;
    while (count < tamanhoMaximo && fscanf(arquivo, "%49s %49s %f",
                                           estudantes[count].sobrenome, estudantes[count].primeiroNome,
                                           &estudantes[count].indiceGraduacao) == 3) {
        count++;
    }

    fclose(arquivo);
    return count;
}

// Funcao para conceder aumento de 10% para funcionarios correspondentes a estudantes com indice de graduacao > 3.0
void concederAumento(Funcionario funcionarios[], int numFuncionarios, Estudante estudantes[], int numEstudantes) {
    for (int i = 0; i < numEstudantes; i++) {
        // Verifica se o indice de graduacao do estudante eh maior que 3.0
        if (estudantes[i].indiceGraduacao > 3.0) {
            // Procura por um funcionario com o mesmo sobrenome e primeiro nome
            for (int j = 0; j < numFuncionarios; j++) {
                if (strcmp(estudantes[i].sobrenome, funcionarios[j].sobrenome) == 0 &&
                    strcmp(estudantes[i].primeiroNome, funcionarios[j].primeiroNome) == 0) {
                    // Concede aumento de 10% ao funcionario
                    funcionarios[j].salario *= 1.10;
                    printf("Funcionario %s %s recebeu aumento. Novo salario: %.2f\n",
                           funcionarios[j].primeiroNome, funcionarios[j].sobrenome, funcionarios[j].salario);
                }
            }
        }
    }
}

// Funcao para salvar os dados dos funcionarios em um arquivo apos o aumento
void salvarFuncionarios(const char *nomeArquivo, Funcionario funcionarios[], int numFuncionarios) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        fprintf(arquivo, "%s %s %.2f\n", funcionarios[i].sobrenome, funcionarios[i].primeiroNome,
                funcionarios[i].salario);
    }

    fclose(arquivo);
}
