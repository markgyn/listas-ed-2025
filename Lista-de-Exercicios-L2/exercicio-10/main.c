#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ESTACIONAMENTO 10

typedef struct {
    char placa[8];
} Carro;

Carro estacionamento[MAX_ESTACIONAMENTO];
int topo = 0;  // Número de carros atualmente no estacionamento

// Função para verificar se o estacionamento está cheio
bool estacionamentoCheio() {
    return topo == MAX_ESTACIONAMENTO;
}

// Função para verificar se o estacionamento está vazio
bool estacionamentoVazio() {
    return topo == 0;
}

// Função para verificar se o carro já está estacionado
int posicaoCarro(char *placa) {
    for (int i = 0; i < topo; i++) {
        if (strcmp(estacionamento[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1;
}

// Função para adicionar um carro no estacionamento
void chegadaCarro(char *placa) {
    if (estacionamentoCheio()) {
        printf("Estacionamento cheio, carro %s aguardando vaga.\n", placa);
    } else {
        strcpy(estacionamento[topo].placa, placa);
        topo++;
        printf("Carro %s estacionado.\n", placa);
    }
}

// Função para remover um carro do estacionamento
void partidaCarro(char *placa) {
    int pos = posicaoCarro(placa);
    if (pos == -1) {
        printf("Carro %s não está no estacionamento.\n", placa);
        return;
    }

    printf("Carro %s saindo do estacionamento, movendo %d carro(s) para remover.\n", placa, topo - pos - 1);

    // Remover o carro e reorganizar os outros
    for (int i = pos; i < topo - 1; i++) {
        strcpy(estacionamento[i].placa, estacionamento[i + 1].placa);
    }
    topo--;
}

// Função para imprimir o estado atual do estacionamento
void imprimeEstacionamento() {
    if (estacionamentoVazio()) {
        printf("Estacionamento está vazio.\n");
        return;
    }

    printf("Estacionamento:\n");
    for (int i = 0; i < topo; i++) {
        printf("%d: %s\n", i + 1, estacionamento[i].placa);
    }
}

int main() {
    char comando;
    char placa[8];

    while (true) {
        printf("Digite o comando (C para chegada, P para partida, S para sair): ");
        scanf(" %c", &comando);
        if (comando == 'S') break;

        printf("Digite a placa do carro: ");
        scanf("%s", placa);

        if (comando == 'C') {
            chegadaCarro(placa);
        } else if (comando == 'P') {
            partidaCarro(placa);
        } else {
            printf("Comando inválido.\n");
        }

        imprimeEstacionamento();
    }

    return 0;
}
