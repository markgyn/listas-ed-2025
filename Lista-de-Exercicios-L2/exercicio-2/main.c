#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Tamanho máximo da fila

// exercicio 2
// Considere a implementação de filas usando arranjos “circulares”. Escreva uma função
// FuraFila(TipoFila* pFila, TipoItem x) que insere um item na primeira posição da fila. O
// detalhe é que seu procedimento deve ser O(1), ou seja, não pode movimentar os outros itens da fila.
// (observe que neste caso, estaremos desrepeitando o conceito de FILA – primeiro a entrar é o primeiro a
// sair).


typedef int TipoItem;  // Tipo de item para a fila

// Estrutura para a Fila Circular
typedef struct {
    TipoItem itens[MAX];
    int inicio, fim;
} Fila;

// Função para inicializar a fila
void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Função para verificar se a fila está vazia
bool filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Função para verificar se a fila está cheia
bool filaCheia(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

// Função para enfileirar um item (inserir no final da fila)
bool enfileira(Fila *f, TipoItem item) {
    if (filaCheia(f)) {
        printf("Fila cheia\n");
        return false;
    }
    f->itens[f->fim] = item;
    f->fim = (f->fim + 1) % MAX;
    return true;
}

// Função para desenfileirar um item (remover do início da fila)
TipoItem desenfileira(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia\n");
        exit(1);  // Termina o programa em caso de erro
    }
    TipoItem item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return item;
}

// Função para furar a fila (inserir um item na primeira posição)
bool furaFila(Fila *f, TipoItem x) {
    if (filaCheia(f)) {
        printf("Fila cheia\n");
        return false;
    }

    // Ajusta o início para a posição "anterior" de forma circular
    f->inicio = (f->inicio - 1 + MAX) % MAX;
    f->itens[f->inicio] = x;

    return true;
}

// Função para imprimir a fila (para visualização)
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

    printf("Fila original:\n");
    imprimeFila(&f);

    // Furando a fila com o elemento 99
    furaFila(&f, 99);

    printf("Fila apos furar a fila com o elemento 99:\n");
    imprimeFila(&f);

    return 0;
}
