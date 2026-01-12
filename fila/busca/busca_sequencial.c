// busca_sequencial.c
// Busca sequencial em fila circular (array), SEM remover elementos.

#include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free
#include <stdbool.h> // bool

typedef struct {
    int *dados;       // array interno
    int inicio;       // índice do primeiro elemento
    int fim;          // índice da próxima posição livre (onde entra no enqueue)
    int size;         // quantidade de elementos na fila
    int capacidade;   // tamanho máximo
} Fila;

// Cria fila com capacidade
Fila* fila_criar(int capacidade) {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dados = (int*)malloc(sizeof(int) * capacidade);
    if (!f->dados) {
        free(f);
        return NULL;
    }

    f->inicio = 0;         // começa no 0
    f->fim = 0;            // próxima posição livre também 0
    f->size = 0;           // vazia
    f->capacidade = capacidade;
    return f;
}

// Destrói fila
void fila_destruir(Fila *f) {
    if (!f) return;
    free(f->dados);
    free(f);
}

// Verifica vazia/cheia
bool fila_vazia(const Fila *f) { return f->size == 0; }
bool fila_cheia(const Fila *f) { return f->size == f->capacidade; }

// Enqueue (usado no main para montar exemplo)
bool fila_enqueue(Fila *f, int x) {
    if (fila_cheia(f)) return false;

    f->dados[f->fim] = x;                          // coloca no fim
    f->fim = (f->fim + 1) % f->capacidade;         // avança circularmente
    f->size++;                                     // aumenta tamanho
    return true;
}

// Imprime do início ao fim (ordem FIFO)
void fila_imprimir(const Fila *f) {
    printf("Fila (inicio -> fim): ");
    for (int i = 0; i < f->size; i++) {
        int idx = (f->inicio + i) % f->capacidade; // acessa circularmente
        printf("%d ", f->dados[idx]);
    }
    printf("\n");
}

// Busca sequencial: retorna posição lógica (0..size-1), ou -1 se não achar.
// "posição lógica" = 0 é o primeiro da fila.
int fila_busca_sequencial(const Fila *f, int alvo) {
    for (int i = 0; i < f->size; i++) {
        int idx = (f->inicio + i) % f->capacidade; // índice real no array
        if (f->dados[idx] == alvo) {
            return i; // achou na posição lógica i
        }
    }
    return -1;
}

int main(void) {
    Fila *f = fila_criar(10);
    if (!f) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    // Monta fila: 10, 20, 30, 40
    fila_enqueue(f, 10);
    fila_enqueue(f, 20);
    fila_enqueue(f, 30);
    fila_enqueue(f, 40);

    fila_imprimir(f);

    int alvo = 30;
    int pos = fila_busca_sequencial(f, alvo);

    if (pos != -1) {
        printf("Achou %d na posicao logica %d da fila.\n", alvo, pos);
    } else {
        printf("Nao achou %d.\n", alvo);
    }

    fila_destruir(f);
    return 0;
}
