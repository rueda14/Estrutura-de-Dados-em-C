// busca_binaria.c
// Busca binária em um array ORDENADO: divide o intervalo ao meio a cada passo.

#include <stdio.h>
#include <stddef.h>

// Função: busca_binaria
// Pré-requisito: v precisa estar ordenado (crescente).
// Retorna: índice do alvo, ou -1 se não existir.
int busca_binaria(const int v[], size_t n, int alvo) {
    // "lo" e "hi" delimitam o intervalo [lo, hi] onde procuramos
    size_t lo = 0;
    size_t hi = (n == 0) ? 0 : (n - 1);

    // Caso n == 0, não há o que procurar
    if (n == 0) return -1;

    // Enquanto o intervalo for válido
    while (lo <= hi) {
        // Calcula o meio sem risco de overflow
        size_t mid = lo + (hi - lo) / 2;

        if (v[mid] == alvo) {
            return (int)mid; // Achou
        } else if (v[mid] < alvo) {
            // Alvo está à direita
            lo = mid + 1;
        } else {
            // Alvo está à esquerda
            // Cuidado: se mid==0, mid-1 estoura (size_t é unsigned)
            if (mid == 0) break;
            hi = mid - 1;
        }
    }

    // Não encontrado
    return -1;
}

int main(void) {
    // Array ORDENADO
    int v[] = {10, 20, 30, 40, 50, 60};
    size_t n = sizeof(v) / sizeof(v[0]);

    int alvo = 50;

    int idx = busca_binaria(v, n, alvo);

    if (idx != -1) {
        printf("Encontrado: %d no indice %d\n", alvo, idx);
    } else {
        printf("Nao encontrado: %d\n", alvo);
    }

    return 0;
}
