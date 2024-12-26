#include <stdio.h>
#include "pilha_tad.h"

void menu() {
    printf("\nEscolha uma operacao:\n");
    printf("0) Preencher a pilha com valores.\n");
    printf("a) Definir o segundo elemento a partir do topo.\n");
    printf("b) Alterar o segundo elemento a partir do topo.\n");
    printf("c) Definir o n-esimo elemento a partir do topo.\n");
    printf("d) Alterar o n-esimo elemento a partir do topo.\n");
    printf("e) Definir o ultimo elemento deixando a pilha vazia.\n");
    printf("f) Alterar o ultimo elemento mantendo a pilha inalterada.\n");
    printf("g) Definir o terceiro elemento a partir do final.\n");
    printf("h) Sair.\n");
    printf("Escolha: ");
}

int main() {
    Pilha p;
    inicializaPilha(&p);

    char opcao;
    TipoItem item;
    int n, quantidade;

    do {
        menu();
        scanf(" %c", &opcao);

        switch (opcao) {
            case '0':
                printf("Digite a quantidade de elementos para preencher a pilha: ");
                scanf("%d", &quantidade);
                preenchePilha(&p, quantidade);
                imprimePilha(&p);
                break;
            case 'a':
                printf("Digite o item: ");
                scanf("%d", &item);
                defineSegundoElemento(&p, item);
                imprimePilha(&p);
                break;
            case 'b':
                printf("Digite o item: ");
                scanf("%d", &item);
                alteraSegundoElemento(&p, item);
                imprimePilha(&p);
                break;
            case 'c':
                printf("Digite o valor de n e o item: ");
                scanf("%d %d", &n, &item);
                defineNesimoElemento(&p, n, item);
                imprimePilha(&p);
                break;
            case 'd':
                printf("Digite o valor de n e o item: ");
                scanf("%d %d", &n, &item);
                alteraNesimoElemento(&p, n, item);
                imprimePilha(&p);
                break;
            case 'e':
                printf("Digite o item: ");
                scanf("%d", &item);
                defineUltimoElemento(&p, item);
                imprimePilha(&p);
                break;
            case 'f':
                printf("Digite o item: ");
                scanf("%d", &item);
                alteraUltimoElemento(&p, item);
                imprimePilha(&p);
                break;
            case 'g':
                printf("Digite o item: ");
                scanf("%d", &item);
                defineTerceiroElementoDoFinal(&p, item);
                imprimePilha(&p);
                break;
            case 'h':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 'h');

    return 0;
}
