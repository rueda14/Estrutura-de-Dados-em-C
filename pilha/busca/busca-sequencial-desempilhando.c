// pilha_busca_sequencial_desempilhando.c
// Busca sequencial em pilha desempilhando.
// Usa pilha auxiliar para restaurar o estado original.

#include <stdio.h>   // printf
#include <stdbool.h> // bool, true, false
#include <stdlib.h>  // malloc, free

typedef struct {
    int *dados;       // array interno
    int topo;         // índice do topo (-1 indica vazia)
    int capacidade;   // tamanho máximo
} Pilha;

// Cria uma pilha com capacidade definida
Pilha* pilha_criar(int capacidade) {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (!p) return NULL;

    p->dados = (int*)malloc(sizeof(int) * capacidade);
    if (!p->dados) {
        free(p);
        return NULL;
    }

    p->topo = -1;              // começa vazia
    p->capacidade = capacidade;
    return p;
}

// Libera a pilha
void pilha_destruir(Pilha *p) {
    if (!p) return;
    free(p->dados);
    free(p);
}

// Verifica se está vazia
bool pilha_vazia(const Pilha *p) {
    return p->topo == -1;
}

// Verifica se está cheia
bool pilha_cheia(const Pilha *p) {
    return p->topo == p->capacidade - 1;
}

// Push: adiciona no topo (O(1))
bool pilha_push(Pilha *p, int x) {
    if (pilha_cheia(p)) return false;

    p->topo++;                 // move topo para cima
    p->dados[p->topo] = x;     // coloca valor no novo topo
    return true;
}

// Pop: remove do topo (O(1))
bool pilha_pop(Pilha *p, int *out) {
    if (pilha_vazia(p)) return false;

    *out = p->dados[p->topo];  // pega o valor do topo
    p->topo--;                 // "remove" diminuindo o topo
    return true;
}

// Só para depuração: imprime do topo até a base (não altera a pilha)
void pilha_imprimir(const Pilha *p) {
    printf("Topo -> ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("<- Base\n");
}

// Busca por "alvo" desempilhando e restaurando no final.
// Retorna true se encontrou; false caso contrário.
bool pilha_busca_desempilhando(Pilha *p, int alvo) {
    // Cria pilha auxiliar com mesma capacidade
    Pilha *aux = pilha_criar(p->capacidade);
    if (!aux) return false; // falha de memória (poderia tratar melhor)

    bool achou = false;
    int x;

    // Enquanto houver elementos na pilha original:
    while (!pilha_vazia(p)) {
        // Retira o topo da pilha original
        pilha_pop(p, &x);

        // Verifica se é o que queremos
        if (x == alvo) {
            achou = true;
        }

        // Guarda no auxiliar (para restaurar depois)
        pilha_push(aux, x);
    }

    // Agora a pilha original está vazia e tudo está em aux.
    // Vamos restaurar: desempilha aux e empilha de volta em p.
    while (!pilha_vazia(aux)) {
        pilha_pop(aux, &x);
        pilha_push(p, x);
    }

    // Libera a pilha auxiliar
    pilha_destruir(aux);

    return achou;
}

int main(void) {
    Pilha *p = pilha_criar(10);
    if (!p) {
        printf("Erro: sem memoria.\n");
        return 1;
    }

    // Monta a pilha: base [10, 20, 30, 40] topo
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_push(p, 40);

    printf("Pilha inicial:\n");
    pilha_imprimir(p);

    int alvo = 30;

    bool achou = pilha_busca_desempilhando(p, alvo);

    printf("Buscando %d...\n", alvo);
    printf("Resultado: %s\n", achou ? "ACHOU" : "NAO ACHOU");

    printf("Pilha depois da busca (restaurada):\n");
    pilha_imprimir(p);

    pilha_destruir(p);
    return 0;
}
