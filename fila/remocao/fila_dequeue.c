// fila_dequeue.c
// Dequeue (remoção no início) em fila circular: O(1).

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

bool fila_vazia(const Fila *f) {
    return f->size == 0;
}

void fila_imprimir(const Fila *f) {
    printf("Fila: ");
    for (int i = 0; i < f->size; i++) {
        int idx = (f->inicio + i) % f->capacidade;
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

// DEQUEUE (O(1))
bool fila_dequeue(Fila *f, int *out) {
    // Se estiver vazia, não dá para remover
    if (fila_vazia(f)) return false;

    // O elemento removido é sempre o do início
    *out = f->dados[f->inicio];

    // Avança o início circularmente
    f->inicio = (f->inicio + 1) % f->capacidade;

    // Diminui tamanho
    f->size--;

    return true;
}

int main(void) {
    Fila *f = fila_criar(5);
    if (!f) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    // Monta fila: 10, 20, 30
    f->dados[0] = 10;
    f->dados[1] = 20;
    f->dados[2] = 30;
    f->inicio = 0;
    f->fim = 3;    // próxima posição livre
    f->size = 3;

    printf("Antes:\n");
    fila_imprimir(f);

    int x;
    if (fila_dequeue(f, &x)) {
        printf("Dequeue removeu: %d\n", x);
    } else {
        printf("Dequeue falhou: fila vazia.\n");
    }

    printf("Depois:\n");
    fila_imprimir(f);

    // Esvaziando e testando erro
    fila_dequeue(f, &x);
    fila_dequeue(f, &x);
    if (!fila_dequeue(f, &x)) {
        printf("Dequeue falhou: fila vazia (confirmado).\n");
    }

    fila_destruir(f);
    return 0;
}
