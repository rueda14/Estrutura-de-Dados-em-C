// lista_remove_depois.c
// Remoção "no meio" em O(1) quando você conhece o nó anterior (prev).

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

// Remove o nó logo após "prev" (O(1)).
// Ex.: remove o nó do "meio" se prev apontar para o nó anterior.
bool lista_remove_depois(Lista *L, No *prev, int *out) {
    if (prev == NULL) return false;          // precisa do anterior
    if (prev->prox == NULL) return false;    // não há "depois" para remover

    No *rem = prev->prox;                    // nó a remover
    *out = rem->valor;                       // salva valor removido

    // Ajusta o encadeamento: prev agora aponta para o próximo do removido
    prev->prox = rem->prox;

    // Se removemos o tail, tail deve virar prev
    if (L->tail == rem) {
        L->tail = prev;
    }

    free(rem);
    L->size--;
    return true;
}

// Busca (somente para achar prev no exemplo)
No* lista_busca(const Lista *L, int alvo) {
    for (No *p = L->head; p; p = p->prox) {
        if (p->valor == alvo) return p;
    }
    return NULL;
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

    // Lista: 10 -> 20 -> 30 -> 40
    lista_add_fim(&L, 10);
    lista_add_fim(&L, 20);
    lista_add_fim(&L, 30);
    lista_add_fim(&L, 40);

    printf("Antes: ");
    lista_imprimir(&L);

    // Quer remover o 30, então prev é o nó 20
    No *prev = lista_busca(&L, 20);

    int x;
    if (lista_remove_depois(&L, prev, &x)) {
        printf("Removido (depois do 20): %d\n", x);
    }

    printf("Depois: ");
    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
