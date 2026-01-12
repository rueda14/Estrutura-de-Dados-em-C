// pilha_pop.c
// Exemplo completo de pop (remoção no topo) em pilha baseada em array.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* pilha_criar(int capacidade) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->dados = (int*)malloc(sizeof(int) * capacidade);
    if (!p->dados) {
        free(p);
        return NULL;
    }

    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

void pilha_destruir(Pilha *p) {
    if (!p) return;
    free(p->dados);
    free(p);
}

bool pilha_vazia(const Pilha *p) {
    return p->topo == -1;
}

// POP (O(1))
bool pilha_pop(Pilha *p, int *out) {
    // Se estiver vazia, não dá pra remover
    if (pilha_vazia(p)) return false;

    // Captura o valor do topo
    *out = p->dados[p->topo];

    // Remove logicamente: só decrementa o topo
    p->topo--;

    return true;
}

void pilha_imprimir(const Pilha *p) {
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("<- Base\n");
}

int main(void) {
    Pilha *p = pilha_criar(5);
    if (!p) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    // Monta pilha
    p->dados[0] = 10;  // (vamos fazer manualmente só pra variar)
    p->dados[1] = 20;
    p->dados[2] = 30;
    p->topo = 2;       // topo aponta para 30

    printf("Antes:\n");
    pilha_imprimir(p);

    int x;
    if (pilha_pop(p, &x)) {
        printf("Pop removeu: %d\n", x);
    } else {
        printf("Pop falhou: pilha vazia.\n");
    }

    printf("Depois:\n");
    pilha_imprimir(p);

    // Esvaziando até testar erro
    pilha_pop(p, &x);
    pilha_pop(p, &x);
    if (!pilha_pop(p, &x)) {
        printf("Pop falhou: pilha vazia (confirmado).\n");
    }

    pilha_destruir(p);
    return 0;
}
