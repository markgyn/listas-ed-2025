#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FILA 100  // Tamanho máximo da fila
#define MAX_VETOR 10  // Tamanho máximo de cada vetor no item

// exercicio 8
// Implemente uma fila em C, onde cada item da fila consista em um vetor de números inteiros

// Estrutura para cada item da fila, que é um vetor de números inteiros
typedef struct {
    int valores[MAX_VETOR];
    int tamanho;  // Quantidade de elementos no vetor
} ItemFila;

// Estrutura para a Fila
typedef struct {
    ItemFila itens[MAX_FILA];
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
    return (f->fim + 1) % MAX_FILA == f->inicio;
}

// Função para enfileirar um item (vetor de inteiros) na fila
bool enfileira(Fila *f, int *valores, int tamanho) {
    if (filaCheia(f)) {
        printf("Fila cheia, não é possível enfileirar\n");
        return false;
    }
    // Armazenar o vetor no próximo item da fila
    f->itens[f->fim].tamanho = tamanho;
    for (int i = 0; i < tamanho; i++) {
        f->itens[f->fim].valores[i] = valores[i];
    }
    f->fim = (f->fim + 1) % MAX_FILA;
    return true;
}

// Função para desenfileirar um item da fila
ItemFila desenfileira(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia, não é possível desenfileirar\n");
        exit(1);  // Termina o programa em caso de erro
    }
    ItemFila item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    return item;
}

// Função para imprimir a fila (para visualização)
void imprimeFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Fila:\n");
    int i = f->inicio;
    while (i != f->fim) {
        printf("[");
        for (int j = 0; j < f->itens[i].tamanho; j++) {
            printf("%d", f->itens[i].valores[j]);
            if (j < f->itens[i].tamanho - 1) printf(", ");
        }
        printf("]\n");
        i = (i + 1) % MAX_FILA;
    }
}

// Função principal para teste
int main() {
    Fila f;
    inicializaFila(&f);

    // Enfileirar alguns vetores
    int vetor1[] = {1, 2, 3};
    int vetor2[] = {4, 5, 6, 7};
    int vetor3[] = {8, 9};

    enfileira(&f, vetor1, 3);
    enfileira(&f, vetor2, 4);
    enfileira(&f, vetor3, 2);

    // Imprimir a fila
    imprimeFila(&f);

    // Desenfileirar e imprimir novamente
    desenfileira(&f);
    printf("\nApós desenfileirar um elemento:\n");
    imprimeFila(&f);

    return 0;
}
