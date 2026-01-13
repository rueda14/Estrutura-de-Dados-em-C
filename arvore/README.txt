# ÁRVORE (TREE)

A árvore é uma estrutura de dados não linear, organizada de forma hierárquica.
Diferente de arrays, listas, pilhas e filas, uma árvore permite representar relações
de dependência e hierarquia entre elementos.

Cada elemento da árvore é chamado de nó, e os nós são conectados por relações de
pai e filho. O nó superior é chamado de raiz, e os nós sem filhos são chamados de folhas.

## CARACTERÍSTICAS PRINCIPAIS

### Estrutura hierárquica
Os dados são organizados em níveis, permitindo representar relações pai-filho.

### Navegação não linear
Diferente de estruturas lineares, a árvore permite múltiplos caminhos de navegação.

### Base para estruturas avançadas
Árvores são a base para estruturas como árvores de busca, árvores balanceadas,
heaps, tries e árvores de decisão.

### Eficiência em busca e ordenação
Quando bem estruturadas, árvores permitem buscas e inserções mais eficientes
do que listas e arrays não ordenados.

## TIPOS DE BUSCA EM ÁRVORES

### Busca em profundidade (DFS)

A busca em profundidade percorre a árvore explorando um ramo até o final antes de voltar.
As formas mais comuns de DFS são:

- Pré-ordem: visita a raiz, depois a subárvore esquerda e por fim a direita
- Em-ordem: visita a subárvore esquerda, depois a raiz e por fim a direita
- Pós-ordem: visita a subárvore esquerda, depois a subárvore direita e por fim a raiz

### Busca em largura (BFS)

A busca em largura percorre a árvore nível por nível, da raiz para baixo.
Esse tipo de busca geralmente utiliza uma fila como estrutura auxiliar.

### Busca em árvore binária de busca (BST)

Em uma árvore binária de busca, cada nó segue a regra:
valores menores ficam à esquerda da raiz e valores maiores ficam à direita.

Essa propriedade permite realizar buscas mais eficientes, em média O(log n)
quando a árvore está balanceada.

## INSERÇÃO EM ÁRVORES

### Inserção como folha

A inserção sempre ocorre em um nó folha, respeitando as regras da árvore.
Em árvores genéricas, isso pode depender da posição desejada ou de regras específicas.

### Inserção em árvore binária de busca (BST)

A inserção segue a regra:
esquerda < raiz < direita

O novo elemento percorre a árvore comparando valores até encontrar uma posição vazia,
onde é inserido como folha.

### Inserção balanceada

Em árvores balanceadas, como AVL e Red-Black, após a inserção podem ser necessárias
rotações para manter o equilíbrio da árvore.

O balanceamento garante melhor desempenho em buscas, inserções e remoções.

## REMOÇÃO EM ÁRVORES

### Remoção de folha

Caso mais simples de remoção.
O nó folha é removido diretamente, ajustando o ponteiro do nó pai.

### Remoção de nó com um filho

O nó removido é substituído diretamente por seu único filho,
ajustando os ponteiros da árvore.

### Remoção de nó com dois filhos

Caso mais complexo.
O nó é substituído por seu sucessor em-ordem (menor elemento da subárvore direita)
ou por seu predecessor, mantendo as propriedades da árvore.

## O QUE VOCÊ ENCONTRARÁ NESTA PASTA

Esta pasta contém implementações completas em C dos principais conceitos relacionados
a árvores, incluindo busca, inserção e remoção.

### Organização dos arquivos

arvore/
├── busca/
│   ├── dfs/
│   ├── bfs/
│   └── busca-bst/
│
├── insercao/
│   ├── inserir-como-folha/
│   │   └── regra da árvore
│   │
│   ├── inserir-em-bst/
│   │   └── esquerda < raiz < direita
│   │
│   └── inserir-balanceada/
│       └── rotações (AVL / Red-Black)
│
└── remocao/
    ├── remover-folha/
    │   └── caso simples
    │
    ├── remover-no-com-1-filho/
    │   └── ajuste de ponteiros
    │
    └── remover-no-com-2-filhos/
        └── substituição por sucessor

Cada diretório contém exemplos independentes, comentados de forma didática,
pensados para estudo, prática e revisão dos conceitos fundamentais de
Estruturas de Dados.
