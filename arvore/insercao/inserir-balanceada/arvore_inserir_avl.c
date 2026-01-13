// arvore_inserir_avl.c
// Inserção em AVL (árvore balanceada) com rotações.

#include <stdio.h>
#include <stdlib.h>

// Nó AVL: além de esq/dir, guarda altura.
typedef struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
} No;

No* no_criar(int x) {
    No *n = (No*)malloc(sizeof(No));
    if (!n) return NULL;
    n->valor = x;
    n->altura = 1;  // altura de folha = 1
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// Retorna altura do nó (0 se NULL)
int altura(No *n) {
    return n ? n->altura : 0;
}

// Máximo entre dois ints
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Atualiza altura do nó baseado nos filhos
void atualizar_altura(No *n) {
    if (!n) return;
    n->altura = 1 + max(altura(n->esq), altura(n->dir));
}

// Fator de balanceamento = altura(esq) - altura(dir)
int fb(No *n) {
    if (!n) return 0;
    return altura(n->esq) - altura(n->dir);
}

// Rotação à direita (caso LL)
No* rotacao_direita(No *y) {
    No *x = y->esq;
    No *T2 = x->dir;

    // Rotaciona
    x->dir = y;
    y->esq = T2;

    // Atualiza alturas
    atualizar_altura(y);
    atualizar_altura(x);

    return x; // nova raiz do subárvore
}

// Rotação à esquerda (caso RR)
No* rotacao_esquerda(No *x) {
    No *y = x->dir;
    No *T2 = y->esq;

    // Rotaciona
    y->esq = x;
    x->dir = T2;

    // Atualiza alturas
    atualizar_altura(x);
    atualizar_altura(y);

    return y; // nova raiz do subárvore
}

// Inserção AVL (recursiva)
No* avl_inserir(No *raiz, int x) {
    // 1) Inserção BST normal
    if (!raiz) return no_criar(x);

    if (x < raiz->valor) {
        raiz->esq = avl_inserir(raiz->esq, x);
    } else if (x > raiz->valor) {
        raiz->dir = avl_inserir(raiz->dir, x);
    } else {
        return raiz; // duplicata: ignora
    }

    // 2) Atualiza altura
    atualizar_altura(raiz);

    // 3) Calcula fator de balanceamento
    int balance = fb(raiz);

    // 4) Corrige desbalanceamentos (4 casos)

    // Caso LL: balance > 1 e x < valor da esquerda
    if (balance > 1 && x < raiz->esq->valor) {
        return rotacao_direita(raiz);
    }

    // Caso RR: balance < -1 e x > valor da direita
    if (balance < -1 && x > raiz->dir->valor) {
        return rotacao_esquerda(raiz);
    }

    // Caso LR: balance > 1 e x > valor da esquerda
    if (balance > 1 && x > raiz->esq->valor) {
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }

    // Caso RL: balance < -1 e x < valor da direita
    if (balance < -1 && x < raiz->dir->valor) {
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    // Se não precisou balancear, retorna raiz normal
    return raiz;
}

// Em-ordem para verificar ordenação
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

    // Sequência clássica que força rotações em AVL
    int v[] = {10, 20, 30, 40, 50, 25};
    int n = (int)(sizeof(v)/sizeof(v[0]));

    for (int i = 0; i < n; i++) {
        r = avl_inserir(r, v[i]);
    }

    printf("AVL em-ordem: ");
    emordem(r);
    printf("\n");

    destruir(r);
    return 0;
}
