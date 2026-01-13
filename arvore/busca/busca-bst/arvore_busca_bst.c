// arvore_busca_bst.c
// Busca em BST: compara e desce para esquerda/direita.

#include <stdio.h>
#include <stdlib.h>

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

// Insere em BST (iterativo) - usado para montar exemplo
No* bst_inserir(No *raiz, int x) {
    if (!raiz) return no_criar(x);

    No *atual = raiz;

    while (1) {
        if (x < atual->valor) {
            if (atual->esq) {
                atual = atual->esq;
            } else {
                atual->esq = no_criar(x);
                break;
            }
        } else if (x > atual->valor) {
            if (atual->dir) {
                atual = atual->dir;
            } else {
                atual->dir = no_criar(x);
                break;
            }
        } else {
            // x == atual->valor: ignorar duplicata (regra escolhida)
            break;
        }
    }

    return raiz;
}

// Busca BST: retorna ponteiro do nó, ou NULL.
No* bst_busca(No *raiz, int alvo) {
    No *atual = raiz;

    while (atual != NULL) {
        if (alvo == atual->valor) {
            return atual;                 // achou
        } else if (alvo < atual->valor) {
            atual = atual->esq;           // vai para esquerda
        } else {
            atual = atual->dir;           // vai para direita
        }
    }

    return NULL;
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    No *r = NULL;

    // Insere valores na BST
    int valores[] = {10, 5, 15, 2, 7, 20};
    int n = (int)(sizeof(valores)/sizeof(valores[0]));

    for (int i = 0; i < n; i++) {
        r = bst_inserir(r, valores[i]);
    }

    int alvo = 7;
    No *p = bst_busca(r, alvo);

    if (p) printf("Achou %d no endereco %p\n", p->valor, (void*)p);
    else   printf("Nao achou %d\n", alvo);

    destruir(r);
    return 0;
}
