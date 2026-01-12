// lista_busca_linear.c
// Busca linear em lista encadeada simples: percorre nó a nó.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Nó da lista
typedef struct No {
    int valor;           // dado armazenado
    struct No *prox;     // ponteiro para o próximo nó
} No;

// Estrutura da lista (com ponteiro para início e fim)
typedef struct {
    No *head;            // primeiro nó
    No *tail;            // último nó (ajuda em O(1) no fim)
    size_t size;         // quantidade de nós
} Lista;

// Cria lista vazia
Lista lista_criar(void) {
    Lista L;
    L.head = NULL;
    L.tail = NULL;
    L.size = 0;
    return L;
}

// Adiciona no fim (usaremos em main para montar a lista)
bool lista_add_fim(Lista *L, int x) {
    No *novo = (No*)malloc(sizeof(No));
    if (!novo) return false;

    novo->valor = x;
    novo->prox = NULL;

    if (L->head == NULL) {
        // Lista vazia: head e tail apontam pro mesmo nó
        L->head = novo;
        L->tail = novo;
    } else {
        // Lista já tem elementos: tail->prox recebe novo, e tail vira novo
        L->tail->prox = novo;
        L->tail = novo;
    }

    L->size++;
    return true;
}

// Busca linear: retorna ponteiro pro nó encontrado, ou NULL
No* lista_busca_linear(const Lista *L, int alvo) {
    No *atual = L->head;        // começa no primeiro nó

    while (atual != NULL) {     // enquanto houver nós
        if (atual->valor == alvo) {
            return atual;       // achou o alvo
        }
        atual = atual->prox;    // anda para o próximo nó
    }

    return NULL;                // não achou
}

// Libera memória da lista inteira
void lista_destruir(Lista *L) {
    No *atual = L->head;
    while (atual != NULL) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

int main(void) {
    Lista L = lista_criar();

    // Monta a lista: 10 -> 20 -> 30 -> 40
    lista_add_fim(&L, 10);
    lista_add_fim(&L, 20);
    lista_add_fim(&L, 30);
    lista_add_fim(&L, 40);

    int alvo = 30;

    No *encontrado = lista_busca_linear(&L, alvo);

    if (encontrado) {
        printf("Achou %d no endereco %p\n", encontrado->valor, (void*)encontrado);
    } else {
        printf("Nao achou %d\n", alvo);
    }

    lista_destruir(&L);
    return 0;
}
