// adicionar_no_fim.c
// Inserção no fim de um "array dinâmico manual" com capacidade.
// O(1) se houver espaço (capacidade > tamanho).

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define CAPACIDADE 10  // Capacidade fixa para exemplo

// Imprime o array (apenas até "n")
void imprime(const int v[], size_t n) {
    printf("[");
    for (size_t i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i + 1 < n) printf(", ");
    }
    printf("]\n");
}

// Adiciona no fim se tiver espaço. Retorna true se inseriu.
bool adicionar_no_fim(int v[], size_t *n, size_t cap, int valor) {
    // Se tamanho atual já é igual à capacidade, não dá pra inserir
    if (*n >= cap) return false;

    // Coloca o valor na próxima posição livre
    v[*n] = valor;

    // Incrementa o tamanho
    (*n)++;

    return true;
}

int main(void) {
    int v[CAPACIDADE] = {10, 20, 30}; // dados iniciais
    size_t n = 3;                     // tamanho atual

    printf("Antes: ");
    imprime(v, n);

    // Tenta inserir
    if (adicionar_no_fim(v, &n, CAPACIDADE, 99)) {
        printf("Depois: ");
        imprime(v, n);
    } else {
        printf("Falha: array cheio.\n");
    }

    return 0;
}
