#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};

typedef struct reg celula;

// Defina a memória total disponível (16 GB em bytes)
#define MEMORIA_TOTAL (16L * 1024 * 1024 * 1024) // 16 GB

void imprime(celula *p) {
    while (p != NULL) {
        printf("%d -> ", p->conteudo); // Printa dado do nó
        p = p->prox; // Avança para o próximo nó
    }
    printf("NULL\n"); // Indica o fim da lista
}

void adiciona_inicio(celula **head, int valor, float *memoria) {
    celula *novo = (celula*)malloc(sizeof(celula));  // Aloca novo nó
    novo->conteudo = valor;  // Atribui valor ao nó
    novo->prox = *head;  // Faz o novo nó apontar para o antigo primeiro nó
    *head = novo;  // Atualiza a cabeça da lista para o novo nó
    *memoria += sizeof(celula);  // Atualiza o total de memória usada
}

void adiciona_final(celula **head, int valor, float *memoria) {
    celula *novo = (celula*)malloc(sizeof(celula));  // Aloca novo nó
    novo->conteudo = valor;
    novo->prox = NULL;  // prox do novo nó será NULL, indicando o final da lista

    if (*head == NULL) {
        *head = novo;  // Se a lista está vazia, o novo nó se torna o primeiro
    } else {
        celula *temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;  // Avança até o último nó
        }
        temp->prox = novo;  // Faz o último nó apontar para o novo nó
    }
    *memoria += sizeof(celula);  // Atualiza o total de memória usada
}

int conta_nos(celula *head) {
    int count = 0;
    celula *temp = head;

    while (temp != NULL) {
        count++;  // Incrementa o contador de nós
        temp = temp->prox;  // Avança para o próximo nó
    }

    return count;  // Retorna o número total de nós
}

void remove_no(celula **head, int valor) {
    celula *temp = *head;
    celula *anterior = NULL;

    // Remover o primeiro nó (cabeça da lista)
    if (temp != NULL && temp->conteudo == valor) {
        *head = temp->prox;  // Atualiza a cabeça para o próximo nó
        free(temp);  // Libera a memória do nó removido
        return;
    }

    // Procurar o nó a ser removido
    while (temp != NULL && temp->conteudo != valor) {
        anterior = temp;  // Guarda o nó anterior
        temp = temp->prox;  // Avança para o próximo nó
    }

    // Se o nó não for encontrado
    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Remover um nó no meio ou no fim
    anterior->prox = temp->prox;  // Faz o nó anterior apontar para o próximo nó
    printf("Nó %d removido com sucesso!\n\n", valor);
    free(temp);  // Libera a memória do nó removido
}

void remove_no_free(celula **head, int valor, float *memoria) {
    celula *temp = *head;
    celula *anterior = NULL;

    // Remover o primeiro nó (cabeça da lista)
    if (temp != NULL && temp->conteudo == valor) {
        *head = temp->prox;  // Atualiza a cabeça para o próximo nó
        free(temp);  // Libera a memória do nó removido
        *memoria -= sizeof(celula);  // Atualiza a memória total
        printf("Nó %d removido com sucesso!\n\n", valor);
        return;
    }

    // Procurar o nó a ser removido
    while (temp != NULL && temp->conteudo != valor) {
        anterior = temp;  // Guarda o nó anterior
        temp = temp->prox;  // Avança para o próximo nó
    }

    // Se o nó não for encontrado
    if (temp == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Remover um nó no meio ou no fim
    anterior->prox = temp->prox;  // Faz o nó anterior apontar para o próximo nó
    free(temp);  // Libera a memória do nó removido
    *memoria -= sizeof(celula);  // Atualiza a memória total
    printf("Nó %d removido com sucesso!\n\n", valor);
}

int main() {
    float memoria = 0;  // Inicializa o contador de memória
    celula *lista = NULL;  // Lista inicialmente vazia

    // Adiciona elementos à lista e atualiza a memória
    adiciona_inicio(&lista, 10, &memoria);
    adiciona_inicio(&lista, 120, &memoria);
    adiciona_inicio(&lista, 130, &memoria);
    
    adiciona_final(&lista, 213, &memoria);
    adiciona_final(&lista, 23, &memoria);
    
    // Imprime a lista
    imprime(lista);
    
    // Conta o número de nós após adicionar os elementos
    int len_lista = conta_nos(lista);
    
    // Verifica se há nós na lista antes de calcular a média
    if (len_lista > 0) {
        // Calcula e imprime a média de memória por nó
        printf("Teste de memória normal");
        printf("Memória por nó: %.2f bytes\n", memoria / len_lista);
        printf("Memória total: %.2f bytes\n", memoria);
    } else {
        printf("A lista está vazia.\n");
    }

    printf("\n");

    // Cálculo do número máximo de elementos possíveis na fila
    long memoria_disponivel = MEMORIA_TOTAL - (long)memoria; // Memória livre
    long tamanho_nó = sizeof(celula); // Tamanho do nó
    long max_elementos = memoria_disponivel / tamanho_nó; // Máximo de elementos
    printf("Máximo de elementos possíveis na fila: %ld\n\n", max_elementos);

    // Remove um nó e imprime a lista atualizada
    remove_no_free(&lista, 130, &memoria);
    imprime(lista);
    len_lista = conta_nos(lista);
    
    if (len_lista > 0) {
        printf("Teste de memória com função remove com free");
        printf("Memória por nó: %.2f bytes\n", memoria / len_lista);
        printf("Memória total: %.2f bytes\n", memoria);
    } else {
        printf("A lista está vazia.\n");
    }
    
    printf("\n");
    
    // Remove um nó e imprime a lista atualizada
    remove_no(&lista, 10);
    imprime(lista);
    len_lista = conta_nos(lista);
    
    if (len_lista > 0) {
        printf("Teste de memória com função remove sem free");
        printf("Memória por nó: %.2f bytes\n", memoria / len_lista);
        printf("Memória total: %.2f bytes\n", memoria);
    } else {
        printf("A lista está vazia.\n");
    }

    return 0;
}
