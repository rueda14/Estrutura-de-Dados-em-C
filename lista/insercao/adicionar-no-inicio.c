// lista_add_inicio.c
// Inserção no início em O(1): novo->prox = head; head = novo.

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

void lista_imprimir(const Lista *L) {
    printf("Lista: ");
    for (No *p = L->head; p != NULL; p = p->prox) {
        printf("%d ", p->valor);
    }
    printf("\n");
}

bool lista_add_inicio(Lista *L, int x) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return false;

    novo->valor = x;

    // Liga o novo nó antes do head atual
    novo->prox = L->head;

    // Atualiza head para ser o novo nó
    L->head = novo;

    // Se a lista era vazia, tail também precisa apontar pro novo
    if (L->tail == NULL) {
        L->tail = novo;
    }

    L->size++;
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

    // Adiciona no início: fica 30 -> 20 -> 10
    lista_add_inicio(&L, 10);
    lista_add_inicio(&L, 20);
    lista_add_inicio(&L, 30);

    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
