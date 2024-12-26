#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100  // Tamanho maximo da pilha

// Estrutura da pilha para caracteres
typedef struct {
    char itens[MAX];
    int topo;
} PilhaChar;

// Funcoes da pilha
void inicializaPilhaChar(PilhaChar *p) {
    p->topo = -1;
}

bool pilhaCharVazia(PilhaChar *p) {
    return p->topo == -1;
}

bool pilhaCharCheia(PilhaChar *p) {
    return p->topo == MAX - 1;
}

void empilhaChar(PilhaChar *p, char c) {
    if (pilhaCharCheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = c;
}

char desempilhaChar(PilhaChar *p) {
    if (pilhaCharVazia(p)) {
        printf("Pilha vazia!\n");
        return '\0';  // Retorna nulo se a pilha estiver vazia
    }
    return p->itens[p->topo--];
}

// Funcao para verificar se a string segue o formato xCy
bool verificaFormatoXCYPilha(const char *str) {
    PilhaChar pilha;
    inicializaPilhaChar(&pilha);

    int i = 0;
    int n = strlen(str);

    // Verifica onde esta o caractere 'C'
    while (i < n && str[i] != 'C') {
        empilhaChar(&pilha, str[i]);
        i++;
    }

    // Se nao encontrou o 'C' ou esta no inicio/final, formato invalido
    if (i == n || i == 0 || i == n - 1) {
        return false;
    }

    // Avanca apos o 'C'
    i++;

    // Verifica se a segunda parte e o inverso da pilha
    while (i < n) {
        if (pilhaCharVazia(&pilha) || desempilhaChar(&pilha) != str[i]) {
            return false;
        }
        i++;
    }

    // Se a pilha nao estiver vazia, formato invalido
    return pilhaCharVazia(&pilha);
}

int main() {
    char str[200];
    int escolha;

    do {
        printf("\n--- Verificacao de Formato xCy ---\n");
        printf("1. Verificar se uma string esta no formato xCy.\n");
        printf("2. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite a string: ");
                scanf("%s", str);

                if (verificaFormatoXCYPilha(str)) {
                    printf("A string '%s' esta no formato xCy.\n", str);
                } else {
                    printf("A string '%s' nao esta no formato xCy.\n", str);
                }
                break;

            case 2:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 2);

    return 0;
}
