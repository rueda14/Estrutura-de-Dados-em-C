// arvore_inserir_bst.c
// Inserção em BST: sempre termina inserindo como FOLHA.

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

// Insere em BST (recursivo) e retorna a raiz atualizada
No* bst_inserir(No *raiz, int x) {
    if (raiz == NULL) {
        // Chegou numa posição vazia: cria nó (entra como folha)
        return no_criar(x);
    }

    if (x < raiz->valor) {
        raiz->esq = bst_inserir(raiz->esq, x);
    } else if (x > raiz->valor) {
        raiz->dir = bst_inserir(raiz->dir, x);
    } else {
        // Duplicata: regra escolhida = ignorar
    }

    return raiz;
}

void emordem(No *r) {
    if (!r) return;
    emordem(r->esq);
    printf("%d ", r->valor);
    emordem(r->dir);
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

    for (int i = 0; i < n; i++) {
        r = bst_inserir(r, v[i]);
    }

    printf("Em-ordem (crescente): ");
    emordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
