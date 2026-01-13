# FILA (QUEUE)

A fila é uma estrutura de dados do tipo FIFO (First In, First Out), o que significa que
o primeiro elemento inserido é o primeiro a ser removido.
Uma analogia comum é uma fila de atendimento: quem chega primeiro, sai primeiro.

Esse comportamento torna a fila ideal para cenários que exigem processamento ordenado,
mas limita o acesso direto aos elementos internos.

## CARACTERÍSTICAS PRINCIPAIS

### Ordem de processamento
Os elementos são processados exatamente na ordem em que foram inseridos.

### Inserção e remoção em extremidades opostas
A inserção ocorre sempre no final da fila, enquanto a remoção ocorre sempre no início.

### Operações eficientes
Inserir no fim (enqueue) → O(1)
Remover do início (dequeue) → O(1)

### Acesso sequencial
Não existe acesso direto a elementos no meio da fila.
Qualquer acesso exige percorrer a fila do início ao fim.

### Estrutura indicada para controle de fluxo
Filas são amplamente utilizadas para gerenciar tarefas, eventos e buffers de dados.

## OPERAÇÕES CLÁSSICAS

As operações fundamentais de uma fila são:

### enqueue(x)
Insere o elemento x no final da fila.

### dequeue()
Remove e retorna o elemento que está no início da fila.

### front() ou peek()
(opcional, dependendo da implementação)
Consulta o primeiro elemento da fila sem removê-lo.

## BUSCA EM FILA: COMO FUNCIONA NA PRÁTICA?

A fila não possui um mecanismo de busca nativo eficiente.
Por isso, a busca mais comum é a busca sequencial.

### Busca sequencial

Nesse método, os elementos são percorridos do início ao fim da fila até que:
- o elemento procurado seja encontrado, ou
- a fila termine.

Esse processo não altera a ordem da fila, mas possui complexidade O(n).

## O QUE VOCÊ ENCONTRARÁ NESTA PASTA

Esta pasta contém implementações completas em C dos principais mecanismos de funcionamento de filas,
com foco em inserção, remoção e busca.

### Organização dos arquivos

fila/
├── busca/
│   └── busca-sequencial.c
├── insercao/
│   └── fila_enqueue.c
└── remocao/
    └── fila_dequeue.c

Cada arquivo é independente, comentado de forma didática e pensado para estudo,
prática e revisão dos conceitos fundamentais de Estruturas de Dados.
