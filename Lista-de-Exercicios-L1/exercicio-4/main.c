#include <stdio.h>
#include "registro.h"

int main() {

    // exercicio 4:
    // Suponha dois vetores, um de registros de estudantes e outro de registros de funcionarios.
    // Cada registro de estudante contem variaveis que armazenam o sobrenome, o primeiro nome e um indice de pontos de graduacao.
    // Cada registro de funcionario contem variaveis que armazenam o sobrenome, o primeiro nome e um salario.
    // Ambos os vetores sao classificados em ordem alfabetica pelo sobrenome e pelo primeiro nome.
    // Dois registros com o sobrenome e o primeiro nome iguais nao aparecem no mesmo vetor.
    // Escreva uma funcao em C para conceder um aumento de 10% a todo funcionario que tenha um registro de estudante cujo indice
    // de pontos de graduacao seja maior que 3.0.

    Funcionario funcionarios[3] = {
        {"Silva", "Joao", 2000.00},
        {"Santos", "Maria", 2500.00},
        {"Costa", "Ana", 1800.00}
    };

    Estudante estudantes[3] = {
        {"Silva", "Joao", 3.5},
        {"Santos", "Maria", 2.8},
        {"Costa", "Ana", 3.2}
    };

    // Chamando a funcao para conceder aumento
    concederAumento(funcionarios, 3, estudantes, 3);

    return 0;
}
