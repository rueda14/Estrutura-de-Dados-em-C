// arvore_remover_folha.c
// Remove um nó que é FOLHA em uma BST (caso simples).

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

No* bst_inserir(No *r, int x) {
    if (!r) return no_criar(x);
    if (x < r->valor) r->esq = bst_inserir(r->esq, x);
    else if (x > r->valor) r->dir = bst_inserir(r->dir, x);
    return r;
}

void emordem(No *r) {
    if (!r) return;
    emordem(r->esq);
    printf("%d ", r->valor);
    emordem(r->dir);
}

// Remove folha "alvo" (somente se for folha).
// Retorna a raiz atualizada.
No* bst_remover_folha(No *r, int alvo, bool *ok) {
    if (!r) {
        *ok = false;
        return NULL;
    }

    if (alvo < r->valor) {
        r->esq = bst_remover_folha(r->esq, alvo, ok);
        return r;
    }
    if (alvo > r->valor) {
        r->dir = bst_remover_folha(r->dir, alvo, ok);
        return r;
    }

    // Achou o nó
    if (r->esq == NULL && r->dir == NULL) {
        // É folha: remove
        free(r);
        *ok = true;
        return NULL;
    }

    // Não é folha: não remove neste "arquivo"
    *ok = false;
    return r;
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    No *r = NULL;
    int v[] = {10, 5, 15, 2, 7, 20};
    int n = (int)(sizeof(v)/sizeof(v[0]));
    for (int i = 0; i < n; i++) r = bst_inserir(r, v[i]);

    printf("Antes (em-ordem): ");
    emordem(r);
    printf("\n");

    bool ok;
    r = bst_remover_folha(r, 2, &ok); // 2 é folha
    printf("Remover folha 2: %s\n", ok ? "OK" : "FALHOU");

    printf("Depois (em-ordem): ");
    emordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
