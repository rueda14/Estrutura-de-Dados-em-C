// arvore_inserir_como_folha.c
// Inserção "como folha" em árvore binária genérica:
// dado um pai, insere em esq/dir se estiver vazio.

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

// Insere como folha: se lado == 'E', tenta inserir à esquerda, senão à direita.
// Retorna true se inseriu; false se já estava ocupado ou pai NULL.
bool inserir_como_folha(No *pai, char lado, int valor) {
    if (!pai) return false;

    if (lado == 'E') {
        if (pai->esq != NULL) return false;  // já tem filho esquerdo
        pai->esq = no_criar(valor);          // cria e liga
        return pai->esq != NULL;
    } else {
        if (pai->dir != NULL) return false;  // já tem filho direito
        pai->dir = no_criar(valor);
        return pai->dir != NULL;
    }
}

void dfs_pre(No *r) {
    if (!r) return;
    printf("%d ", r->valor);
    dfs_pre(r->esq);
    dfs_pre(r->dir);
}

void destruir(No *r) {
    if (!r) return;
    destruir(r->esq);
    destruir(r->dir);
    free(r);
}

int main(void) {
    // Cria raiz
    No *r = no_criar(10);

    // Insere folhas escolhendo manualmente o pai e o lado
    inserir_como_folha(r, 'E', 5);       // 5 vira filho esquerdo de 10
    inserir_como_folha(r, 'D', 15);      // 15 vira filho direito de 10
    inserir_como_folha(r->esq, 'E', 2);  // 2 vira filho esquerdo de 5

    printf("DFS pre-ordem: ");
    dfs_pre(r);
    printf("\n");

    destruir(r);
    return 0;
}
