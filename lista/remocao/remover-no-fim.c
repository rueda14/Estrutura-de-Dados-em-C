// lista_remove_fim.c
// Remoção no fim em lista encadeada simples: O(n) para achar o penúltimo.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *head;
    No *tail;
    size_t size;
} Lista;

Lista lista_criar(void) {
    return (Lista){NULL, NULL, 0};
}

bool lista_add_fim(Lista *L, int x) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return false;
    novo->valor = x;
    novo->prox = NULL;

    if (!L->head) {
        L->head = novo;
        L->tail = novo;
    } else {
        L->tail->prox = novo;
        L->tail = novo;
    }
    L->size++;
    return true;
}

void lista_imprimir(const Lista *L) {
    printf("Lista: ");
    for (No *p = L->head; p; p = p->prox) printf("%d ", p->valor);
    printf("\n");
}

// Remove o último elemento (tail).
// Em lista simples, precisamos achar o penúltimo => O(n).
bool lista_remove_fim(Lista *L, int *out) {
    if (!L->head) return false;  // vazia

    // Caso 1: só tem 1 elemento
    if (L->head == L->tail) {
        *out = L->head->valor;
        free(L->head);
        L->head = NULL;
        L->tail = NULL;
        L->size = 0;
        return true;
    }

    // Caso 2: tem >= 2 elementos
    // Precisamos achar o penúltimo: o nó cujo prox é o tail.
    No *p = L->head;
    while (p->prox != L->tail) {
        p = p->prox;
    }

    // Agora p é o penúltimo e L->tail é o último
    *out = L->tail->valor;

    free(L->tail);         // libera o último nó
    L->tail = p;           // tail vira o penúltimo
    L->tail->prox = NULL;  // novo último aponta para NULL

    L->size--;
    return true;
}

void lista_destruir(Lista *L) {
    No *p = L->head;
    while (p) {
        No *nx = p->prox;
        free(p);
        p = nx;
    }
    *L = (Lista){NULL, NULL, 0};
}

int main(void) {
    Lista L = lista_criar();

    lista_add_fim(&L, 10);
    lista_add_fim(&L, 20);
    lista_add_fim(&L, 30);

    printf("Antes: ");
    lista_imprimir(&L);

    int x;
    if (lista_remove_fim(&L, &x)) {
        printf("Removido do fim: %d\n", x);
    }

    printf("Depois: ");
    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
