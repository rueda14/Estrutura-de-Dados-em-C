// pilha_push.c
// Exemplo completo de push (inserção no topo) em pilha baseada em array.

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

bool pilha_cheia(const Pilha *p) {
    return p->topo == p->capacidade - 1;
}

// PUSH (O(1))
bool pilha_push(Pilha *p, int x) {
    // Se não houver espaço, falha
    if (pilha_cheia(p)) return false;

    // Incrementa o topo (vai para a próxima posição livre)
    p->topo++;

    // Coloca o valor exatamente no topo
    p->dados[p->topo] = x;

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
    Pilha *p = pilha_criar(3);
    if (!p) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    // Fazendo pushes
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    // Tentando exceder a capacidade
    if (!pilha_push(p, 40)) {
        printf("Push falhou: pilha cheia.\n");
    }

    pilha_imprimir(p);

    pilha_destruir(p);
    return 0;
}
