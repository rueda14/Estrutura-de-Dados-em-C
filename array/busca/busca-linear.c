// busca_linear.c
// Busca linear em um array: percorre do início ao fim até encontrar o alvo.

#include <stdio.h>   // printf
#include <stddef.h>  // size_t

// Função: busca_linear
// Retorna: índice onde o alvo foi encontrado, ou -1 se não existir.
int busca_linear(const int v[], size_t n, int alvo) {
    // Percorre todas as posições de 0 até n-1
    for (size_t i = 0; i < n; i++) {
        // Se o elemento atual é o alvo, retorna o índice
        if (v[i] == alvo) {
            return (int)i;
        }
    }
    // Se terminou o laço, não achou
    return -1;
}

int main(void) {
    // Array de exemplo
    int v[] = {10, 50, 20, 40, 30};
    size_t n = sizeof(v) / sizeof(v[0]);

    int alvo = 40;

    // Chama a busca linear
    int idx = busca_linear(v, n, alvo);

    // Mostra o resultado
    if (idx != -1) {
        printf("Encontrado: %d no indice %d\n", alvo, idx);
    } else {
        printf("Nao encontrado: %d\n", alvo);
    }

    return 0; // Finaliza o programa com sucesso
}
