#include <stdio.h>
#include <string.h>
#include "registro.h"

int main() {
    // exercicio 5:
    // Escreva uma funcao semelhante a do exercicio anterior, mas pressupondo que os registros dos funcionarios e estudantes
    // sejam mantidos em dois arquivos externos classificados, em vez de em dois vetores classificados.

    Funcionario funcionarios[100];
    Estudante estudantes[100];
    int numFuncionarios, numEstudantes;
    char caminhoFuncionarios[256], caminhoEstudantes[256];
    int opcao;

    // Perguntar ao usuario se ele deseja usar os caminhos padrao ou fornecer os caminhos manualmente
    printf("Escolha uma opcao:\n");
    printf("1 - Usar caminhos padrao (Caminho Completo especificado)\n");
    printf("2 - Fornecer os caminhos dos arquivos manualmente\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        // Caminhos padrao especificados
        strcpy(caminhoFuncionarios,
               "C:\\Users\\marco\\CLionProjects\\Lista-de-Exercicios-L1\\exercicio-5\\funcionarios.txt");
        strcpy(caminhoEstudantes,
               "C:\\Users\\marco\\CLionProjects\\Lista-de-Exercicios-L1\\exercicio-5\\estudantes.txt");
    } else if (opcao == 2) {
        // Permitir que o usuario insira os caminhos
        printf("Digite o caminho para o arquivo de funcionarios: ");
        scanf("%s", caminhoFuncionarios);
        printf("Digite o caminho para o arquivo de estudantes: ");
        scanf("%s", caminhoEstudantes);
    } else {
        printf("Opcao invalida. Encerrando o programa.\n");
        return 1;
    }

    // Carregar dados dos arquivos
    numFuncionarios = carregarFuncionarios(caminhoFuncionarios, funcionarios, 100);
    if (numFuncionarios == 0) {
        printf("Erro ao carregar os dados dos funcionarios. Verifique o caminho do arquivo.\n");
        return 1;
    }

    numEstudantes = carregarEstudantes(caminhoEstudantes, estudantes, 100);
    if (numEstudantes == 0) {
        printf("Erro ao carregar os dados dos estudantes. Verifique o caminho do arquivo.\n");
        return 1;
    }

    // Conceder aumento
    concederAumento(funcionarios, numFuncionarios, estudantes, numEstudantes);

    // Salvar os dados atualizados dos funcionarios
    salvarFuncionarios(
        "C:\\Users\\marco\\CLionProjects\\Lista-de-Exercicios-L1\\exercicio-5\\funcionarios_atualizados.txt",
        funcionarios, numFuncionarios);

    return 0;
}
