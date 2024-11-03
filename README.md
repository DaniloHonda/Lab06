# Laboratório 06 - Implementação de Listas Encadeadas com Alocação Dinâmica de Memória
---
Danilo Yui Honda - 10419625

Raphael Grizante da Silva - 10416979

---
Este laboratório tem como objetivo exemplificar o uso da alocação dinâmica de memória em sistemas operacionais através da implementação de listas encadeadas como estrutura de dados.

## Descrição da Estrutura de Dados

Uma **lista encadeada** é uma estrutura de dados que representa uma sequência de objetos do mesmo tipo, armazenados na memória RAM do computador. Cada elemento é armazenado em uma célula da lista. O primeiro elemento é armazenado na primeira célula, o segundo na segunda célula, e assim por diante.

### Estrutura da célula

A definição da célula da lista encadeada é a seguinte:

```c
struct reg {
    int conteudo; 
    struct reg *prox; 
}; 

typedef struct reg celula;
```

## Declaração de uma célula

Para declarar uma célula ou um ponteiro para uma célula, podemos utilizar:

```c
celula c;
celula *p;
```

## Funcionalidades

### 1. Criação de Três Instâncias da Célula
O código cria três instâncias do objeto `celula`, representando três valores na lista encadeada.

### 2. Função para Imprimir Todos os Valores da Lista
Esta função percorre a lista encadeada e imprime os valores armazenados em cada célula.

### 3. Cálculo da Quantidade de Memória Gasta por Cada Instância
Cada instância da célula ocupa uma quantidade de memória, calculada pela soma dos tamanhos dos campos `int conteudo` e `struct reg *prox`. Dependendo do compilador e do sistema, o valor pode variar.

### 4. Função para Remover Elementos da Lista
Esta função remove os elementos da lista encadeada. Ela percorre a lista, removendo e liberando a memória de cada célula.

### 5. Função para Liberar Memória
A função de remoção de elementos é incrementada com a liberação da memória alocada para cada célula. Isso é feito utilizando a função `free()` da biblioteca `stdlib.h`.

### 6. Cálculo do Número Máximo de Elementos na Lista
Considerando a memória disponível no computador, podemos calcular o número máximo de elementos que podem ser armazenados na lista encadeada. Esse cálculo é baseado na quantidade de memória ocupada por cada célula.

## Testes

![image](https://github.com/user-attachments/assets/ff093cb9-37c3-42a2-be9e-6304a1a2f2b5)

