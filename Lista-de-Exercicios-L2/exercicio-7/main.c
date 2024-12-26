#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// exercicio 7
// Implemente uma fila de inteiros em C, usando uma implementação por arranjos (um vetor queue[100]),
// onde queue[0] e queue[1] são usados para representar a posição inicial e final da fila respectivamente e
// queue[2] a queue[99] são usados para conter os elementos do vetor. Demonstre como inicializar esse
// vetor de modo a representar a fila vazia e escreva funções Desenfileira, Enfileira e Vazia para tal
// implementação

int queue[MAX];

// Função para inicializar a fila
void inicializaFila() {
    queue[0] = 2;  // Posição inicial da fila (início)
    queue[1] = 2;  // Posição final da fila (fim)
}

// Função para verificar se a fila está vazia
bool filaVazia() {
    return queue[0] == queue[1];
}

// Função para enfileirar um elemento
bool enfileira(int item) {
    int proxPosicao = (queue[1] + 1) % MAX;
    if (proxPosicao == queue[0]) {  // Verifica se a fila está cheia
        printf("Fila cheia, não é possível enfileirar\n");
        return false;
    }
    queue[queue[1]] = item;
    queue[1] = proxPosicao;  // Incrementa o índice final de forma circular
    return true;
}

// Função para desenfileirar um elemento
int desenfileira() {
    if (filaVazia()) {
        printf("Fila vazia, não é possível desenfileirar\n");
        return -1;  // Retorno de erro
    }
    int item = queue[queue[0]];
    queue[0] = (queue[0] + 1) % MAX;  // Incrementa o índice inicial de forma circular
    return item;
}

// Função para imprimir a fila (para verificação)
void imprimeFila() {
    if (filaVazia()) {
        printf("Fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    int i = queue[0];
    while (i != queue[1]) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Função principal para teste
int main() {
    inicializaFila();

    // Teste de enfileiramento
    enfileira(10);
    enfileira(20);
    enfileira(30);

    imprimeFila();

    // Teste de desenfileiramento
    desenfileira();
    imprimeFila();

    desenfileira();
    imprimeFila();

    return 0;
}
