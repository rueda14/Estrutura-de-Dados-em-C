# ARRAY (VETOR)

O array, também conhecido como vetor, é uma estrutura de dados linear que armazena
elementos do mesmo tipo em posições contíguas de memória.
Cada elemento é acessado por meio de um índice numérico.

Arrays oferecem acesso extremamente rápido aos dados, mas possuem limitações quando
o tamanho precisa variar ou quando ocorrem muitas inserções e remoções internas.

## CARACTERÍSTICAS PRINCIPAIS

### Acesso direto por índice
Cada elemento pode ser acessado diretamente por seu índice.
Essa operação possui complexidade O(1).

### Tamanho fixo
Na maioria das linguagens de baixo nível, como C, o tamanho do array é definido
no momento da criação e não pode ser alterado dinamicamente.

### Custo de inserções e remoções
Inserções e remoções no meio ou no início exigem deslocamento de elementos,
o que torna essas operações mais custosas.

### Estrutura simples e eficiente
Arrays são simples de implementar e muito eficientes quando o padrão de acesso
é predominantemente sequencial ou por índice.

## BUSCA EM ARRAYS

### Busca linear

A busca linear percorre o array elemento por elemento até que:
- o valor procurado seja encontrado, ou
- o final do array seja alcançado.

Esse método funciona em qualquer array, ordenado ou não, e possui complexidade O(n).

### Busca binária

A busca binária divide repetidamente o array ao meio, descartando metade dos elementos
a cada comparação.

Este método exige que o array esteja ordenado e possui complexidade O(log n).

## INSERÇÃO EM ARRAYS

### Inserção no fim

O elemento é adicionado na última posição disponível do array.
Quando há espaço livre, essa operação é O(1).

### Inserção no meio

Para inserir um elemento em uma posição intermediária, é necessário deslocar
os elementos à direita para abrir espaço.

Complexidade: O(n)

### Inserção no início

Todos os elementos precisam ser deslocados uma posição à direita para que o novo
elemento ocupe a primeira posição.

Complexidade: O(n)

## REMOÇÃO EM ARRAYS

### Remoção no fim

A remoção do último elemento é simples e eficiente, bastando reduzir o tamanho lógico
do array.

Complexidade: O(1)

### Remoção no meio

O elemento removido é eliminado e os elementos à direita são deslocados uma posição
para a esquerda.

Complexidade: O(n)

### Remoção no início

Todos os elementos do array são deslocados uma posição para a esquerda após a remoção
do primeiro elemento.

Complexidade: O(n)

## O QUE VOCÊ ENCONTRARÁ NESTA PASTA

Esta pasta contém implementações completas em C dos principais casos de uso de arrays,
com foco em busca, inserção e remoção.

### Organização dos arquivos

array/
├── busca/
│   ├── busca-linear.c
│   └── busca-binaria.c
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
