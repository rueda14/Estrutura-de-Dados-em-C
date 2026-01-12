// remover_no_inicio.c
// Remover no início é um caso particular de remover no meio com pos=0.
// Precisa deslocar todo mundo para a esquerda.

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

bool remover_no_inicio(int v[], size_t *n, int *removido) {
    if (*n == 0) return false;

    // O removido é o primeiro
    *removido = v[0];

    // Desloca todos para a esquerda
    for (size_t i = 0; i + 1 < *n; i++) {
        v[i] = v[i + 1];
    }

    // Reduz tamanho
    (*n)--;

    return true;
}

int main(void) {
    int v[] = {10, 20, 30, 40};
    size_t n = 4;

    printf("Antes: ");
    imprime(v, n);

    int x;
    if (remover_no_inicio(v, &n, &x)) {
        printf("Removido: %d\n", x);
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha: array vazio.\n");
    }

    return 0;
}
