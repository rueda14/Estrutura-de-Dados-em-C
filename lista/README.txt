# LISTA ENCADEADA (LINKED LIST)

A lista encadeada é uma estrutura de dados linear e dinâmica, composta por elementos chamados nós.
Cada nó armazena um valor e uma referência (ponteiro) para o próximo nó da lista.

Diferente dos arrays, os elementos de uma lista encadeada não ocupam posições contíguas de memória,
o que permite crescimento e redução dinâmicos sem necessidade de realocação em bloco.

## CARACTERÍSTICAS PRINCIPAIS

### Estrutura dinâmica
O tamanho da lista pode crescer ou diminuir durante a execução do programa.

### Uso de ponteiros
Cada elemento aponta para o próximo nó da lista, formando uma sequência encadeada.

### Inserções eficientes
Inserções no início ou após um nó conhecido podem ser feitas em O(1).

### Acesso sequencial
Para acessar um elemento específico, é necessário percorrer a lista desde o início.

### Custo variável de remoção
A complexidade da remoção depende da posição do nó e do tipo de lista.

## OPERAÇÕES CLÁSSICAS

As operações fundamentais em listas encadeadas incluem inserção, remoção e busca.

## BUSCA EM LISTA

### Busca linear

A busca em listas encadeadas é feita de forma sequencial, percorrendo nó a nó desde o início
até que o elemento procurado seja encontrado ou a lista termine.

Esse processo possui complexidade O(n).

## INSERÇÃO EM LISTA

### Inserção no início

O novo nó passa a apontar para o nó que era o primeiro da lista.
Em seguida, o ponteiro da lista é atualizado para o novo nó.

Complexidade: O(1)

### Inserção no meio

A inserção no meio é feita após um nó conhecido.
O novo nó aponta para o próximo do nó anterior, e o nó anterior passa a apontar para o novo.

Complexidade: O(1), considerando que o nó anterior já é conhecido.

### Inserção no fim

O novo nó é inserido após o último nó da lista.
Em listas simples, isso pode exigir percorrer toda a lista até o final.

Complexidade: O(n) sem ponteiro para o fim, ou O(1) se houver ponteiro para o último nó.

## REMOÇÃO EM LISTA

### Remoção no início

O primeiro nó é removido e o ponteiro da lista passa a apontar para o próximo nó.

Complexidade: O(1)

### Remoção no meio

A remoção é feita ajustando o ponteiro do nó anterior para ignorar o nó removido.

Complexidade: O(1), considerando que o nó anterior é conhecido.

### Remoção no fim

Em listas encadeadas simples, é necessário percorrer a lista até o penúltimo nó
para ajustar o ponteiro final.

Complexidade: O(n)

## O QUE VOCÊ ENCONTRARÁ NESTA PASTA

Esta pasta contém implementações completas em C dos principais casos de uso de listas encadeadas,
com foco em inserção, remoção e busca.

### Organização dos arquivos

lista/
├── busca/
│   └── busca-linear.c
│
├── insercao/
│   ├── adicionar-no-fim.c
│   ├── adicionar-no-meio.c
│   └── adicionar-no-inicio.c
│   
└── remocao/
    ├── remover-no-fim.c
    ├── remover-no-meio.c
    └── remover-no-inicio.c

Cada arquivo é independente, comentado de forma didática e pensado para estudo,
prática e revisão dos conceitos fundamentais de Estruturas de Dados.
