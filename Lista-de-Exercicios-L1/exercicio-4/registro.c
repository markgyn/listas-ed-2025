#include <stdio.h>
#include <string.h>
#include "registro.h"

// Funcao que concede aumento de 10% para funcionarios correspondentes a estudantes com indice de graduacao > 3.0
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
