// arvore_dfs.c
// DFS em árvore binária: pre-ordem, em-ordem e pos-ordem.

#include <stdio.h>
#include <stdlib.h>

// Nó de árvore binária
typedef struct No {
    int valor;            // dado
    struct No *esq;       // filho esquerdo
    struct No *dir;       // filho direito
} No;

// Cria um novo nó
No* no_criar(int x) {
    No *n = (No*)malloc(sizeof(No));
    if (!n) return NULL;
    n->valor = x;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// DFS: Pré-ordem (raiz, esquerda, direita)
void dfs_preordem(No *raiz) {
    if (raiz == NULL) return;          // caso base: árvore vazia
    printf("%d ", raiz->valor);        // visita raiz
    dfs_preordem(raiz->esq);           // visita esquerda
    dfs_preordem(raiz->dir);           // visita direita
}

// DFS: Em-ordem (esquerda, raiz, direita)
// Em BST, isso imprime em ordem crescente.
void dfs_emordem(No *raiz) {
    if (raiz == NULL) return;
    dfs_emordem(raiz->esq);
    printf("%d ", raiz->valor);
    dfs_emordem(raiz->dir);
}

// DFS: Pós-ordem (esquerda, direita, raiz)
void dfs_posordem(No *raiz) {
    if (raiz == NULL) return;
    dfs_posordem(raiz->esq);
    dfs_posordem(raiz->dir);
    printf("%d ", raiz->valor);
}

// Libera memória (pós-ordem é o jeito seguro)
void destruir(No *raiz) {
    if (!raiz) return;
    destruir(raiz->esq);
    destruir(raiz->dir);
    free(raiz);
}

int main(void) {
    // Monta uma árvore manualmente:
    //        10
    //       /  \
    //      5    15
    //     / \     \
    //    2   7     20
    No *r = no_criar(10);
    r->esq = no_criar(5);
    r->dir = no_criar(15);
    r->esq->esq = no_criar(2);
    r->esq->dir = no_criar(7);
    r->dir->dir = no_criar(20);

    printf("DFS pre-ordem: ");
    dfs_preordem(r);
    printf("\n");

    printf("DFS em-ordem:  ");
    dfs_emordem(r);
    printf("\n");

    printf("DFS pos-ordem: ");
    dfs_posordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
