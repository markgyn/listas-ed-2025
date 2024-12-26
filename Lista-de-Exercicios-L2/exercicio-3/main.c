#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Tamanho máximo da fila de processos

// exercicio 3
// Existem partes de sistemas operacionais que cuidam da ordem em que os programas devem ser
// executados. Por exemplo, em um sistema de computação de tempo compartilhado (“time-shared”) existe
// a necessidade de manter um conjunto de processos em uma fila, esperando para serem executados.
// Escreva um programa que seja capaz de ler uma série de solicitações para:
// a. Incluir novos processos na fila de processo;
// b. Retirar da fila o processo com o maior tempo de espera;
// c. Imprimir o conteúdo da lista de processo em determinado momento.
// Assuma que cada processo é representado por um registro composto por um número identificador do
// processo.

// Estrutura para representar um processo
typedef struct {
    int id;            // Identificador do processo
    int tempoEspera;   // Tempo de espera do processo
} Processo;

// Estrutura para a Fila de Processos
typedef struct {
    Processo processos[MAX];
    int inicio, fim;
} FilaProcessos;

// Função para inicializar a fila
void inicializaFila(FilaProcessos *fila) {
    fila->inicio = 0;
    fila->fim = 0;
}

// Função para verificar se a fila está vazia
bool filaVazia(FilaProcessos *fila) {
    return fila->inicio == fila->fim;
}

// Função para verificar se a fila está cheia
bool filaCheia(FilaProcessos *fila) {
    return (fila->fim + 1) % MAX == fila->inicio;
}

// Função para adicionar um processo na fila
bool incluirProcesso(FilaProcessos *fila, int id, int tempoEspera) {
    if (filaCheia(fila)) {
        printf("Fila de processos cheia!\n");
        return false;
    }
    fila->processos[fila->fim].id = id;
    fila->processos[fila->fim].tempoEspera = tempoEspera;
    fila->fim = (fila->fim + 1) % MAX;
    return true;
}

// Função para remover o processo com o maior tempo de espera
bool retirarProcessoMaiorEspera(FilaProcessos *fila) {
    if (filaVazia(fila)) {
        printf("Fila de processos vazia!\n");
        return false;
    }

    // Encontrar o processo com o maior tempo de espera
    int posMaior = fila->inicio;
    int i = fila->inicio;
    while (i != fila->fim) {
        if (fila->processos[i].tempoEspera > fila->processos[posMaior].tempoEspera) {
            posMaior = i;
        }
        i = (i + 1) % MAX;
    }

    // Remover o processo com o maior tempo de espera
    printf("Removendo processo com maior espera: ID=%d, Tempo de Espera=%d\n",
           fila->processos[posMaior].id, fila->processos[posMaior].tempoEspera);

    // Mover os elementos seguintes uma posição para trás
    i = posMaior;
    while (i != fila->fim) {
        fila->processos[i] = fila->processos[(i + 1) % MAX];
        i = (i + 1) % MAX;
    }

    fila->fim = (fila->fim - 1 + MAX) % MAX;
    return true;
}

// Função para imprimir o conteúdo da fila de processos
void imprimirFila(FilaProcessos *fila) {
    if (filaVazia(fila)) {
        printf("Fila de processos vazia!\n");
        return;
    }

    int i = fila->inicio;
    printf("Lista de processos:\n");
    while (i != fila->fim) {
        printf("ID: %d, Tempo de Espera: %d\n", fila->processos[i].id, fila->processos[i].tempoEspera);
        i = (i + 1) % MAX;
    }
}

// Função principal para testar o programa
int main() {
    FilaProcessos fila;
    inicializaFila(&fila);

    int opcao;
    do {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Incluir novo processo\n");
        printf("2 - Retirar processo com maior tempo de espera\n");
        printf("3 - Imprimir lista de processos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id, tempoEspera;
            printf("Digite o ID do processo: ");
            scanf("%d", &id);
            printf("Digite o tempo de espera do processo: ");
            scanf("%d", &tempoEspera);
            incluirProcesso(&fila, id, tempoEspera);
        } else if (opcao == 2) {
            retirarProcessoMaiorEspera(&fila);
        } else if (opcao == 3) {
            imprimirFila(&fila);
        }
    } while (opcao != 0);

    return 0;
}
