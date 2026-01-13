// arvore_remover_2_filhos.c
// Remove nó com 2 filhos em BST usando sucessor (menor da direita).

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

// Encontra o menor nó (mais à esquerda) em uma subárvore
No* menor_no(No *r) {
    No *atual = r;
    while (atual && atual->esq) {
        atual = atual->esq;
    }
    return atual;
}

// Remove nó alvo se ele tiver 2 filhos.
// (Implementamos somente esse caso neste arquivo.)
No* bst_remover_2_filhos(No *r, int alvo, bool *ok) {
    if (!r) { *ok = false; return NULL; }

    if (alvo < r->valor) {
        r->esq = bst_remover_2_filhos(r->esq, alvo, ok);
        return r;
    }
    if (alvo > r->valor) {
        r->dir = bst_remover_2_filhos(r->dir, alvo, ok);
        return r;
    }

    // Achou o nó r == alvo
    if (r->esq && r->dir) {
        // Pega sucessor: menor na subárvore direita
        No *suc = menor_no(r->dir);

        // Copia o valor do sucessor para o nó atual
        r->valor = suc->valor;

        // Agora precisamos remover o sucessor na subárvore direita.
        // O sucessor não tem filho esquerdo (por definição).
        // Aqui, fazemos uma remoção auxiliar "BST geral" simplificada só para remover suc->valor.
        int valor_sucessor = suc->valor;

        // Remove valor_sucessor da subárvore direita (caso folha ou 1 filho)
        No *sub = r->dir;
        No *pai = NULL;

        while (sub && sub->valor != valor_sucessor) {
            pai = sub;
            if (valor_sucessor < sub->valor) sub = sub->esq;
            else sub = sub->dir;
        }

        // sub aponta para o nó sucessor
        if (sub) {
            No *filho = sub->dir; // sucessor pode ter filho direito
            if (pai == NULL) {
                // sucessor era a raiz da subárvore direita
                r->dir = filho;
            } else if (pai->esq == sub) {
                pai->esq = filho;
            } else {
                pai->dir = filho;
            }
            free(sub);
        }

        *ok = true;
        return r;
    }

    *ok = false; // não era 2 filhos
    return r;
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    // Vamos montar BST:
    //        10
    //       /  \
    //      5    15
    //          / \
    //         12  20
    // Remover 15 (tem 2 filhos: 12 e 20)
    No *r = NULL;
    int v[] = {10, 5, 15, 12, 20};
    int n = (int)(sizeof(v)/sizeof(v[0]));
    for (int i = 0; i < n; i++) r = bst_inserir(r, v[i]);

    printf("Antes (em-ordem): ");
    emordem(r);
    printf("\n");

    bool ok;
    r = bst_remover_2_filhos(r, 15, &ok);
    printf("Remover no 15 (2 filhos): %s\n", ok ? "OK" : "FALHOU");

    printf("Depois (em-ordem): ");
    emordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
