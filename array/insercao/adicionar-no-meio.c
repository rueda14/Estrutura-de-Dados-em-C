// adicionar_no_meio.c
// Inserção em posição (meio) com deslocamento para a direita.

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define CAPACIDADE 10

void imprime(const int v[], size_t n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i + 1 < n) printf(", ");
    }
    printf("]\n");
}

// Insere "valor" em v[pos], deslocando para a direita.
// Regras:
// - 0 <= pos <= n (pos==n equivale a inserir no fim)
// - precisa haver capacidade (n < cap)
bool adicionar_no_meio(int v[], size_t *n, size_t cap, size_t pos, int valor) {
    if (*n >= cap) return false;   // sem espaço
    if (pos > *n) return false;    // posição inválida

    // Desloca do fim para a direita, começando no último elemento
    // Ex.: se n=5, último índice é 4, vai para 5.
    for (size_t i = *n; i > pos; i--) {
        v[i] = v[i - 1];
    }

    // Coloca o valor na posição desejada
    v[pos] = valor;

    // Atualiza tamanho
    (*n)++;

    return true;
}

int main(void) {
    int v[CAPACIDADE] = {10, 20, 30, 40, 50};
    size_t n = 5;

    size_t pos = 2;  // inserir no "meio" (índice 2)
    int valor = 999;

    printf("Antes: ");
    imprime(v, n);

    if (adicionar_no_meio(v, &n, CAPACIDADE, pos, valor)) {
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha ao inserir (capacidade cheia ou pos invalida).\n");
    }

    return 0;
}
