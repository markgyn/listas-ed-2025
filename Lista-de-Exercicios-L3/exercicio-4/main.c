#include <stdio.h>
#include "simula_pilha.h"

int main() {
    SimulaPilha sp;
    inicializaSimulaPilha(&sp);

    int opcao, valor;

    do {
        printf("\n--- Simulacao de Operacoes Empilha/Desempilha ---\n");
        printf("1. Empilhar (Push)\n");
        printf("2. Desempilhar (Pop)\n");
        printf("3. Mostrar estado atual\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
            scanf("%d", &valor);
            empilhaSimulado(&sp, valor);
            break;

            case 2:
                if (!desempilhaSimulado(&sp)) {
                    printf("Underflow detectado.\n");
                }
            break;

            case 3:
                imprimeEstado(&sp);
            break;

            case 4:
                printf("Encerrando o programa.\n");
            break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
