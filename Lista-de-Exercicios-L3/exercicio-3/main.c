#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100  // Tamanho maximo da pilha

typedef struct {
    char itens[MAX];
    int topo;
} PilhaChar;

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

// Funcao para verificar se uma substring segue o formato xCy
bool verificaFormatoXCYPilha(const char *str, int *pos) {
    PilhaChar pilha;
    inicializaPilhaChar(&pilha);

    // Armazena os caracteres de x
    while (str[*pos] != 'C' && str[*pos] != '\0') {
        empilhaChar(&pilha, str[*pos]);
        (*pos)++;
    }

    // Verifica se encontrou o 'C'
    if (str[*pos] != 'C') {
        return false;
    }

    // Avanca para a segunda parte de y
    (*pos)++;
    while (!pilhaCharVazia(&pilha) && str[*pos] != '\0' && str[*pos] != 'D') {
        if (desempilhaChar(&pilha) != str[*pos]) {
            return false;
        }
        (*pos)++;
    }

    // Verifica se a pilha esta vazia
    return pilhaCharVazia(&pilha);
}

// Funcao para verificar se a string segue o formato aDbDcD...z
bool verificaFormatoCompleto(const char *str) {
    int pos = 0;
    int n = strlen(str);

    if (n == 0) return false;

    // Itera pelas subsequencias xCy separadas por D
    while (pos < n) {
        if (!verificaFormatoXCYPilha(str, &pos)) {
            return false;
        }

        // Verifica se ha um 'D' apos a subsequencia
        if (str[pos] == 'D') {
            pos++;
        } else if (str[pos] != '\0') {
            return false;
        }
    }

    return true;
}

int main() {
    char str[200];
    int escolha;

    do {
        printf("\n--- Verificacao de Formato aDbDcD...z ---\n");
        printf("1. Verificar se uma string esta no formato aDbDcD...z.\n");
        printf("2. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite a string: ");
                scanf("%s", str);

                if (verificaFormatoCompleto(str)) {
                    printf("A string '%s' esta no formato correto.\n", str);
                } else {
                    printf("A string '%s' nao esta no formato correto.\n", str);
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
