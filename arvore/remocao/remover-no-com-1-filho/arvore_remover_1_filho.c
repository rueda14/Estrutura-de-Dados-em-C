// arvore_remover_1_filho.c
// Remove nó com EXATAMENTE 1 filho em BST: ajusta ponteiros.

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

// Remove nó alvo se ele tiver exatamente 1 filho.
// Retorna raiz atualizada.
No* bst_remover_1_filho(No *r, int alvo, bool *ok) {
    if (!r) { *ok = false; return NULL; }

    if (alvo < r->valor) {
        r->esq = bst_remover_1_filho(r->esq, alvo, ok);
        return r;
    }
    if (alvo > r->valor) {
        r->dir = bst_remover_1_filho(r->dir, alvo, ok);
        return r;
    }

    // Achou o nó r == alvo
    bool tem_esq = (r->esq != NULL);
    bool tem_dir = (r->dir != NULL);

    // Exatamente 1 filho => XOR
    if (tem_esq ^ tem_dir) {
        No *filho = tem_esq ? r->esq : r->dir;
        free(r);
        *ok = true;
        return filho; // "sobe" o filho no lugar do nó removido
    }

    *ok = false; // não era caso de 1 filho
    return r;
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    // Vamos criar uma BST onde o nó 15 tem um único filho (20).
    // Inserindo: 10, 5, 15, 20
    No *r = NULL;
    int v[] = {10, 5, 15, 20};
    int n = (int)(sizeof(v)/sizeof(v[0]));
    for (int i = 0; i < n; i++) r = bst_inserir(r, v[i]);

    printf("Antes (em-ordem): ");
    emordem(r);
    printf("\n");

    bool ok;
    r = bst_remover_1_filho(r, 15, &ok); // 15 tem 1 filho (20)
    printf("Remover no 15 (1 filho): %s\n", ok ? "OK" : "FALHOU");

    printf("Depois (em-ordem): ");
    emordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
