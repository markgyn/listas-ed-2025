#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Tamanho máximo da pilha e da fila

// exercicio 1:
// Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes de fila e pilhas vazias, as
// operações Enfileira, Desenfileira, Empilha, Desempilha, e uma variável aux do
// TipoItem, escreva uma função que inverta a ordem dos elementos da fila.

typedef int TipoItem;  // Tipo de item para elementos da fila e pilha

// Estrutura para a Pilha
typedef struct {
    TipoItem itens[MAX];
    int topo;
} Pilha;

// Estrutura para a Fila
typedef struct {
    TipoItem itens[MAX];
    int inicio, fim;
} Fila;

// Funções para manipular a Pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

bool empilha(Pilha *p, TipoItem item) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia\n");
        return false;
    }
    p->itens[++p->topo] = item;
    return true;
}

TipoItem desempilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia\n");
        exit(1);  // Termina o programa em caso de erro
    }
    return p->itens[p->topo--];
}

// Funções para manipular a Fila
void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

bool filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

bool enfileira(Fila *f, TipoItem item) {
    if ((f->fim + 1) % MAX == f->inicio) {
        printf("Fila cheia\n");
        return false;
    }
    f->itens[f->fim] = item;
    f->fim = (f->fim + 1) % MAX;
    return true;
}

TipoItem desenfileira(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        exit(1);  // Termina o programa em caso de erro
    }
    TipoItem item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return item;
}

// Função para inverter a Fila usando uma Pilha auxiliar
void inverterFila(Fila *f) {
    Pilha p;
    inicializaPilha(&p);

    // Transferir elementos da fila para a pilha
    while (!filaVazia(f)) {
        TipoItem aux = desenfileira(f);
        empilha(&p, aux);
    }

    // Transferir de volta da pilha para a fila (ordem invertida)
    while (!pilhaVazia(&p)) {
        TipoItem aux = desempilha(&p);
        enfileira(f, aux);
    }
}

// Função para imprimir a fila
void imprimeFila(Fila *f) {
    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Função principal para teste
int main() {
    Fila f;
    inicializaFila(&f);

    // Enfileirar alguns elementos
    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    enfileira(&f, 4);
    enfileira(&f, 5);

    printf("Fila original:\n");
    imprimeFila(&f);

    // Inverter a fila
    inverterFila(&f);

    printf("Fila invertida:\n");
    imprimeFila(&f);

    return 0;
}
