// remover_no_meio.c
// Remove em uma posição pos, deslocando elementos para a esquerda.

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

void imprime(const int v[], size_t n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i + 1 < n) printf(", ");
    }
    printf("]\n");
}

// Remove v[pos] e retorna o removido em *removido.
// Regras:
// - 0 <= pos < n
bool remover_no_meio(int v[], size_t *n, size_t pos, int *removido) {
    if (*n == 0) return false;       // vazio
    if (pos >= *n) return false;     // posição inválida

    // Salva o elemento removido
    *removido = v[pos];

    // Desloca tudo à direita de pos uma casa para a esquerda
    // Ex.: v[pos] = v[pos+1], ..., v[n-2] = v[n-1]
    for (size_t i = pos; i + 1 < *n; i++) {
        v[i] = v[i + 1];
    }

    // Reduz tamanho
    (*n)--;

    return true;
}

int main(void) {
    int v[] = {10, 20, 30, 40, 50};
    size_t n = 5;

    size_t pos = 2; // remove o 30
    int x;

    printf("Antes: ");
    imprime(v, n);

    if (remover_no_meio(v, &n, pos, &x)) {
        printf("Removido: %d\n", x);
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha ao remover (pos invalida ou array vazio).\n");
    }

    return 0;
}
