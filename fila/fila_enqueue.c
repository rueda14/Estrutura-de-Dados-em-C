// fila_enqueue.c
// Enqueue (inserção no fim) em fila circular: O(1).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *dados;
    int inicio;
    int fim;
    int size;
    int capacidade;
} Fila;

Fila* fila_criar(int capacidade) {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dados = (int*)malloc(sizeof(int) * capacidade);
    if (!f->dados) {
        free(f);
        return NULL;
    }

    f->inicio = 0;
    f->fim = 0;
    f->size = 0;
    f->capacidade = capacidade;
    return f;
}

void fila_destruir(Fila *f) {
    if (!f) return;
    free(f->dados);
    free(f);
}

bool fila_cheia(const Fila *f) {
    return f->size == f->capacidade;
}

void fila_imprimir(const Fila *f) {
    printf("Fila: ");
    for (int i = 0; i < f->size; i++) {
        int idx = (f->inicio + i) % f->capacidade;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

// ENQUEUE (O(1))
bool fila_enqueue(Fila *f, int x) {
    // Se a fila está cheia, não dá para inserir
    if (fila_cheia(f)) return false;

    // Coloca o elemento na posição "fim"
    f->dados[f->fim] = x;

    // Avança o "fim" circularmente (volta pro 0 se passar do último índice)
    f->fim = (f->fim + 1) % f->capacidade;

    // Atualiza o tamanho
    f->size++;

    return true;
}

int main(void) {
    Fila *f = fila_criar(3);
    if (!f) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    fila_enqueue(f, 10);
    fila_enqueue(f, 20);
    fila_enqueue(f, 30);

    // Tentando inserir quando está cheia
    if (!fila_enqueue(f, 40)) {
        printf("Enqueue falhou: fila cheia.\n");
    }

    fila_imprimir(f);

    fila_destruir(f);
    return 0;
}
