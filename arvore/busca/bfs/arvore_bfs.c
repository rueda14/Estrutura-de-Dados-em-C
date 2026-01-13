// arvore_bfs.c
// BFS (busca em largura) por níveis usando uma fila de ponteiros para nó.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* no_criar(int x) {
    No *n = (No*)malloc(sizeof(No));
    if (!n) return NULL;
    n->valor = x;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// --------- Fila simples (circular) de No* ----------
typedef struct {
    No **dados;      // vetor de ponteiros para No
    int inicio;
    int fim;
    int size;
    int cap;
} Fila;

Fila* fila_criar(int cap) {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (!f) return NULL;

    f->dados = (No**)malloc(sizeof(No*) * cap);
    if (!f->dados) { free(f); return NULL; }

    f->inicio = 0;
    f->fim = 0;
    f->size = 0;
    f->cap = cap;
    return f;
}

void fila_destruir(Fila *f) {
    if (!f) return;
    free(f->dados);
    free(f);
}

bool fila_vazia(const Fila *f) { return f->size == 0; }
bool fila_cheia(const Fila *f) { return f->size == f->cap; }

bool fila_enqueue(Fila *f, No *x) {
    if (fila_cheia(f)) return false;
    f->dados[f->fim] = x;
    f->fim = (f->fim + 1) % f->cap;
    f->size++;
    return true;
}

bool fila_dequeue(Fila *f, No **out) {
    if (fila_vazia(f)) return false;
    *out = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->cap;
    f->size--;
    return true;
}

// BFS: imprime nós por nível
void bfs_por_niveis(No *raiz) {
    if (!raiz) return;

    // Capacidade da fila: para exemplo didático, basta "um número grande"
    // (em produção, usar fila dinâmica real ou calcular nós).
    Fila *f = fila_criar(100);
    if (!f) return;

    fila_enqueue(f, raiz);

    while (!fila_vazia(f)) {
        No *atual;
        fila_dequeue(f, &atual);

        printf("%d ", atual->valor);

        if (atual->esq) fila_enqueue(f, atual->esq);
        if (atual->dir) fila_enqueue(f, atual->dir);
    }

    fila_destruir(f);
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    // Mesma árvore do exemplo anterior:
    //        10
    //       /  \
    //      5    15
    //     / \     \
    //    2   7     20
    No *r = no_criar(10);
    r->esq = no_criar(5);
    r->dir = no_criar(15);
    r->esq->esq = no_criar(2);
    r->esq->dir = no_criar(7);
    r->dir->dir = no_criar(20);

    printf("BFS por niveis: ");
    bfs_por_niveis(r);
    printf("\n");

    destruir(r);
    return 0;
}
