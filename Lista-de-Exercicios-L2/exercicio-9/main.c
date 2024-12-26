#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10  // Tamanho máximo do deque

// exercicio 9
// Um deque é um conjunto de itens a partir do qual podem ser eliminados e inseridos itens em ambas as
// extremidades. Chame as duas extremidades de um deque esq e dir. Como um deque pode ser
// representado como um vetor em C? Escreva quatro funções em C,
// RemoveDireira, RemoveEsquerda, InsereDireita, InsereEsquerda,
// para remover e inserir elementos nas extremidades esquerda e direita de um deque. Certifique-se de que
// as funções funcionem corretamente para o deque vazio e detectem o estouro e o underflow (tentativa de
// remoção quando a fila está vazia). Quais as desvantagens dessa implementação com relação a
// implementação por encadeamento/alocação dinâmica?

typedef int TipoItem;  // Tipo de item para o deque
TipoItem deque[MAX];
int esq = -1, dir = -1;

// Função para verificar se o deque está vazio
bool dequeVazio() {
    return esq == -1 && dir == -1;
}

// Função para verificar se o deque está cheio
bool dequeCheio() {
    return (esq == 0 && dir == MAX - 1) || (esq == dir + 1);
}

// Função para inserir um elemento na direita do deque
void insereDireita(TipoItem item) {
    if (dequeCheio()) {
        printf("Deque cheio, não é possível inserir na direita\n");
        return;
    }

    if (dequeVazio()) {  // Primeiro elemento inserido
        esq = dir = 0;
    } else if (dir == MAX - 1) {  // Envolve circularidade
        dir = 0;
    } else {
        dir++;
    }

    deque[dir] = item;
}

// Função para inserir um elemento na esquerda do deque
void insereEsquerda(TipoItem item) {
    if (dequeCheio()) {
        printf("Deque cheio, não é possível inserir na esquerda\n");
        return;
    }

    if (dequeVazio()) {  // Primeiro elemento inserido
        esq = dir = 0;
    } else if (esq == 0) {  // Envolve circularidade
        esq = MAX - 1;
    } else {
        esq--;
    }

    deque[esq] = item;
}

// Função para remover um elemento da direita do deque
TipoItem removeDireita() {
    if (dequeVazio()) {
        printf("Deque vazio, não é possível remover da direita\n");
        exit(1);
    }

    TipoItem item = deque[dir];
    if (esq == dir) {  // Deque fica vazio
        esq = dir = -1;
    } else if (dir == 0) {  // Envolve circularidade
        dir = MAX - 1;
    } else {
        dir--;
    }

    return item;
}

// Função para remover um elemento da esquerda do deque
TipoItem removeEsquerda() {
    if (dequeVazio()) {
        printf("Deque vazio, não é possível remover da esquerda\n");
        exit(1);
    }

    TipoItem item = deque[esq];
    if (esq == dir) {  // Deque fica vazio
        esq = dir = -1;
    } else if (esq == MAX - 1) {  // Envolve circularidade
        esq = 0;
    } else {
        esq++;
    }

    return item;
}

// Função para imprimir o deque (para visualização)
void imprimeDeque() {
    if (dequeVazio()) {
        printf("Deque está vazio.\n");
        return;
    }

    printf("Deque: ");
    int i = esq;
    while (true) {
        printf("%d ", deque[i]);
        if (i == dir) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Função principal para teste
int main() {
    insereDireita(10);
    insereDireita(20);
    insereEsquerda(5);
    insereEsquerda(3);

    imprimeDeque();

    removeDireita();
    imprimeDeque();

    removeEsquerda();
    imprimeDeque();

    return 0;
}
