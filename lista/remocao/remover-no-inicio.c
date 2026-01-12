// lista_remove_inicio.c
// Remoção no início em O(1): remove head e ajusta ponteiros.

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

// Remove o primeiro nó e devolve o valor em *out.
// O(1).
bool lista_remove_inicio(Lista *L, int *out) {
    if (!L->head) return false;          // lista vazia

    No *rem = L->head;                   // nó a remover
    *out = rem->valor;                   // salva o valor

    L->head = rem->prox;                 // head pula para o próximo

    // Se a lista ficou vazia, tail também vira NULL
    if (L->head == NULL) {
        L->tail = NULL;
    }

    free(rem);                           // libera o nó removido
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
    if (lista_remove_inicio(&L, &x)) {
        printf("Removido do inicio: %d\n", x);
    }

    printf("Depois: ");
    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
