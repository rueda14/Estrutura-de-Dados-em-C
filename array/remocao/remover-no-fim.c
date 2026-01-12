// remover_no_fim.c
// Remover no fim é O(1): basta diminuir o tamanho.

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

// Remove o último elemento e coloca em *removido.
// Retorna false se o array estiver vazio.
bool remover_no_fim(int v[], size_t *n, int *removido) {
    (void)v; // v não precisa ser mexido para remover do fim (só o tamanho)
    if (*n == 0) return false;

    // Último índice é n-1
    *removido = v[*n - 1];

    // "Encurta" o array
    (*n)--;

    return true;
}

int main(void) {
    int v[] = {10, 20, 30, 40};
    size_t n = 4;

    printf("Antes: ");
    imprime(v, n);

    int x;
    if (remover_no_fim(v, &n, &x)) {
        printf("Removido: %d\n", x);
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha: array vazio.\n");
    }

    return 0;
}
