// lista_add_fim.c
// Inserção no fim em O(1) usando ponteiro "tail".

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *head;
    No *tail;     // ponteiro para o último nó
    size_t size;
} Lista;

Lista lista_criar(void) {
    Lista L = {NULL, NULL, 0};
    return L;
}

void lista_imprimir(const Lista *L) {
    printf("Lista: ");
    for (No *p = L->head; p != NULL; p = p->prox) {
        printf("%d ", p->valor);
    }
    printf("\n");
}

bool lista_add_fim(Lista *L, int x) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return false;

    novo->valor = x;
    novo->prox = NULL;          // fim da lista, então prox é NULL

    if (L->head == NULL) {
        // Lista vazia: head e tail viram o novo nó
        L->head = novo;
        L->tail = novo;
    } else {
        // Lista não vazia:
        L->tail->prox = novo;   // antigo último aponta pro novo
        L->tail = novo;         // tail agora é o novo último
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
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

int main(void) {
    Lista L = lista_criar();

    lista_add_fim(&L, 10);
    lista_add_fim(&L, 20);
    lista_add_fim(&L, 30);

    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
