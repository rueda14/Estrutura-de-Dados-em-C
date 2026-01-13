// bst_remover_geral.c
// Remoção COMPLETA em BST (Árvore Binária de Busca):
// - Caso 1: remover folha
// - Caso 2: remover nó com 1 filho
// - Caso 3: remover nó com 2 filhos (substitui pelo sucessor em-ordem)
//
// Compilar:
//   gcc -Wall -Wextra -O2 bst_remover_geral.c -o bst_remover_geral
// Executar:
//   ./bst_remover_geral

#include <stdio.h>   // printf
#include <stdlib.h>  // malloc, free
#include <stdbool.h> // bool, true, false

// =========================
// Estrutura do nó (BST)
// =========================
typedef struct No {
    int valor;            // valor armazenado
    struct No *esq;       // filho esquerdo
    struct No *dir;       // filho direito
} No;

// =========================
// Funções auxiliares básicas
// =========================

// Cria um novo nó com valor x
static No* no_criar(int x) {
    No *n = (No*)malloc(sizeof(No));
    if (!n) return NULL;      // falha de memória
    n->valor = x;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// Inserção em BST (recursiva): retorna a raiz atualizada
static No* bst_inserir(No *raiz, int x) {
    if (raiz == NULL) {
        // Achou lugar vazio: cria nó (entra como folha)
        return no_criar(x);
    }

    if (x < raiz->valor) {
        // Vai para esquerda
        raiz->esq = bst_inserir(raiz->esq, x);
    } else if (x > raiz->valor) {
        // Vai para direita
        raiz->dir = bst_inserir(raiz->dir, x);
    } else {
        // Duplicata: regra escolhida = ignorar
    }

    return raiz;
}

// Percurso em-ordem (em BST imprime ordenado)
static void bst_emordem(No *raiz) {
    if (!raiz) return;
    bst_emordem(raiz->esq);
    printf("%d ", raiz->valor);
    bst_emordem(raiz->dir);
}

// Libera toda a árvore
static void bst_destruir(No *raiz) {
    if (!raiz) return;
    bst_destruir(raiz->esq);
    bst_destruir(raiz->dir);
    free(raiz);
}

// Encontra o nó com menor valor de uma subárvore (mais à esquerda)
static No* bst_minimo(No *raiz) {
    No *atual = raiz;
    while (atual != NULL && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

// =========================
// Remoção geral em BST
// =========================
//
// Remove "alvo" da BST e retorna a raiz atualizada.
// Se removeu de fato, *ok = true; caso contrário, *ok = false.
//
// Regras (casos):
// 1) Folha: esq == NULL e dir == NULL => free e retorna NULL
// 2) 1 filho: substitui o nó pelo filho (retorna ponteiro do filho)
// 3) 2 filhos: substitui pelo sucessor em-ordem:
//    - pega o menor da subárvore direita
//    - copia o valor do sucessor para o nó atual
//    - remove o sucessor na subárvore direita
//
static No* bst_remover(No *raiz, int alvo, bool *ok) {
    if (raiz == NULL) {
        // Não achou o valor
        *ok = false;
        return NULL;
    }

    // 1) Navega como busca BST até achar o alvo
    if (alvo < raiz->valor) {
        // alvo está na esquerda
        raiz->esq = bst_remover(raiz->esq, alvo, ok);
        return raiz;
    }
    if (alvo > raiz->valor) {
        // alvo está na direita
        raiz->dir = bst_remover(raiz->dir, alvo, ok);
        return raiz;
    }

    // 2) Achou o nó a remover (raiz->valor == alvo)

    // Caso 1: nó folha
    if (raiz->esq == NULL && raiz->dir == NULL) {
        free(raiz);
        *ok = true;
        return NULL; // volta NULL para o pai "desligar" o ponteiro
    }

    // Caso 2a: só filho direito (esq == NULL)
    if (raiz->esq == NULL && raiz->dir != NULL) {
        No *filho = raiz->dir; // guarda o filho
        free(raiz);            // remove o nó atual
        *ok = true;
        return filho;          // filho sobe no lugar do nó removido
    }

    // Caso 2b: só filho esquerdo (dir == NULL)
    if (raiz->esq != NULL && raiz->dir == NULL) {
        No *filho = raiz->esq;
        free(raiz);
        *ok = true;
        return filho;
    }

    // Caso 3: dois filhos (esq != NULL e dir != NULL)
    // - substitui pelo sucessor (menor da direita)
    No *sucessor = bst_minimo(raiz->dir);

    // Copia o valor do sucessor para o nó atual
    raiz->valor = sucessor->valor;

    // Remove o sucessor da subárvore direita
    // (sucessor vai ser folha ou terá apenas 1 filho direito)
    raiz->dir = bst_remover(raiz->dir, sucessor->valor, ok);

    // ok será true (já que sucessor existia)
    return raiz;
}

// =========================
// Programa de demonstração
// =========================
int main(void) {
    No *r = NULL;

    // Monta uma BST clássica:
    //        10
    //       /  \
    //      5    15
    //     / \   / \
    //    2  7  12  20
    int v[] = {10, 5, 15, 2, 7, 12, 20};
    int n = (int)(sizeof(v) / sizeof(v[0]));

    for (int i = 0; i < n; i++) {
        r = bst_inserir(r, v[i]);
    }

    printf("BST inicial (em-ordem): ");
    bst_emordem(r);
    printf("\n");

    // Teste 1: remover folha (2)
    bool ok;
    r = bst_remover(r, 2, &ok);
    printf("Remover 2 (folha): %s\n", ok ? "OK" : "FALHOU");
    printf("Depois: ");
    bst_emordem(r);
    printf("\n\n");

    // Teste 2: remover nó com 1 filho
    // Para garantir 1 filho, vamos inserir 13 e remover 12 (que ficará com 1 filho direito=13).
    r = bst_inserir(r, 13);

    printf("Inseri 13 para criar caso 1-filho em 12.\n");
    printf("Agora (em-ordem): ");
    bst_emordem(r);
    printf("\n");

    r = bst_remover(r, 12, &ok);
    printf("Remover 12 (1 filho): %s\n", ok ? "OK" : "FALHOU");
    printf("Depois: ");
    bst_emordem(r);
    printf("\n\n");

    // Teste 3: remover nó com 2 filhos (15)
    r = bst_remover(r, 15, &ok);
    printf("Remover 15 (2 filhos): %s\n", ok ? "OK" : "FALHOU");
    printf("Depois: ");
    bst_emordem(r);
    printf("\n\n");

    // Teste 4: remover valor inexistente
    r = bst_remover(r, 999, &ok);
    printf("Remover 999 (inexistente): %s\n", ok ? "OK" : "FALHOU");
    printf("Depois: ");
    bst_emordem(r);
    printf("\n");

    // Limpa memória
    bst_destruir(r);
    return 0;
}
