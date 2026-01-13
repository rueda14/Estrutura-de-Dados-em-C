# PILHA (STACK)

A pilha é uma estrutura de dados do tipo LIFO (Last In, First Out), o que significa que o último elemento inserido é o primeiro a ser removido.
Uma analogia comum é uma pilha de pratos: você sempre coloca e remove pratos pelo topo.

Essa característica torna a pilha extremamente eficiente para cenários em que o controle de ordem é importante, mas ao mesmo tempo limita o acesso aos dados.

## CARACTERÍSTICAS PRINCIPAIS

### Acesso restrito
Os elementos só podem ser acessados pelo topo da pilha.

### Inserção e remoção eficientes
Inserir no topo (push) → O(1)
Remover do topo (pop) → O(1)

### Sem acesso direto aos elementos internos
Não é possível acessar diretamente um elemento no meio da pilha.

### Não é indicada para buscas frequentes
Qualquer tentativa de busca exige percorrer a pilha elemento por elemento.

## OPERAÇÕES CLÁSSICAS

As operações fundamentais de uma pilha são:

### push(x)
Insere o elemento x no topo da pilha.

### pop()
Remove e retorna o elemento que está no topo da pilha.

### peek()
(opcional, dependendo da implementação)
Consulta o elemento do topo sem removê-lo.

## BUSCA EM PILHA: COMO FUNCIONA NA PRÁTICA?

A pilha não possui um mecanismo de busca nativo eficiente, como acontece em arrays ordenados ou árvores.
Por isso, o método mais comum é a busca sequencial desempilhando.

### Busca sequencial desempilhando

Nesse método, os elementos são removidos um a um do topo usando pop() até que:

- o elemento procurado seja encontrado, ou
- a pilha fique vazia.

ATENÇÃO: esse processo destrói a pilha original.

### Solução com pilha auxiliar

Para preservar os dados, utiliza-se uma pilha auxiliar:

- Desempilha um elemento da pilha original
- Verifica se ele é o valor procurado
- Empilha esse elemento na pilha auxiliar
- Ao final da busca, restaura todos os elementos para a pilha original

Esse processo mantém o comportamento LIFO, mas a complexidade continua sendo O(n).

## O QUE VOCÊ ENCONTRARÁ NESTA PASTA

Esta pasta contém implementações completas em C, focadas nos conceitos fundamentais da pilha:

- Inserção no topo (push)
- Remoção do topo (pop)
- Busca sequencial desempilhando (com restauração da pilha)

### Organização dos arquivos

pilha/
├── busca/
│   └── busca-sequencial-desempilhando.c
│
├── insercao/
│   └── pilha_push.c
│
└── remocao/
    └── pilha_pop.c

Cada arquivo é independente, comentado de forma didática e pensado para estudo, prática e revisão de conceitos clássicos de Estruturas de Dados.
