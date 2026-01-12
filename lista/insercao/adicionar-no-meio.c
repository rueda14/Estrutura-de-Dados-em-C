// lista_add_depois_do_no.c
// Inserção após um nó conhecido (O(1)).

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

// Insere novo nó logo após "prev" (O(1))
bool lista_add_depois(Lista *L, No *prev, int x) {
    if (prev == NULL) return false; // não dá pra inserir sem nó anterior

    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return false;

    novo->valor = x;

    // Encadeamento:
    // novo aponta para o que prev apontava
    novo->prox = prev->prox;

    // prev passa a apontar para novo
    prev->prox = novo;

    // Se prev era o tail, agora o novo vira tail
    if (L->tail == prev) {
        L->tail = novo;
    }

    L->size++;
    return true;
}

// Busca linear (só para obter "prev" no exemplo)
No* lista_busca(const Lista *L, int alvo) {
    for (No *p = L->head; p != NULL; p = p->prox) {
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

    // Lista: 10 -> 20 -> 40
    lista_add_fim(&L, 10);
    lista_add_fim(&L, 20);
    lista_add_fim(&L, 40);

    printf("Antes: ");
    lista_imprimir(&L);

    // Queremos inserir 30 após o nó que tem valor 20
    No *prev = lista_busca(&L, 20);
    lista_add_depois(&L, prev, 30);

    printf("Depois: ");
    lista_imprimir(&L);

    lista_destruir(&L);
    return 0;
}
