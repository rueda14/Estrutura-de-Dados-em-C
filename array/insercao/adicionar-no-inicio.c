// adicionar_no_inicio.c
// Inserção no início é um caso particular de "inserir no meio" com pos=0.

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

bool adicionar_no_inicio(int v[], size_t *n, size_t cap, int valor) {
    if (*n >= cap) return false;

    // Desloca tudo uma posição para a direita (do fim para o começo)
    for (size_t i = *n; i > 0; i--) {
        v[i] = v[i - 1];
    }

    // Coloca o valor na primeira posição
    v[0] = valor;

    // Atualiza tamanho
    (*n)++;
    return true;
}

int main(void) {
    int v[CAPACIDADE] = {10, 20, 30};
    size_t n = 3;

    printf("Antes: ");
    imprime(v, n);

    if (adicionar_no_inicio(v, &n, CAPACIDADE, 777)) {
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha: array cheio.\n");
    }

    return 0;
}
