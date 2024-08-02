#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

void criarLista(vetor *lista, int tam_max) {
    lista->valor = malloc(tam_max * sizeof(int));
    lista->tam_max = tam_max;
    lista->size = 0;
}

int vazia(vetor *lista) {
    return lista->size == 0;
}

int cheia(vetor *lista) {
    return lista->size == lista->tam_max;
}

int verificaTamanho(vetor *lista) {
    return lista->size;
}

int verificaValor(vetor *lista, int pos) {
    if (pos < 1 || pos > lista->size) {
        printf("Posicao invalida!\n");
        return -1;  
    }
    return lista->valor[pos - 1];  
}

void modificaValor(vetor *lista, int pos, int val) {
    if (pos < 1 || pos > lista->size) {
        printf("Posicao invalida!\n");
        return;  
    }
    lista->valor[pos - 1] = val; 
}

void insereValor(vetor *lista, int pos, int val) {
    if (cheia(lista)) {
        printf("Lista cheia!\n");
        return;
    }
    if (pos < 1 || pos > lista->size + 1) {
        printf("Posicao invalida!\n");
        return;
    }
    for (int i = lista->size; i >= pos; i--) {
        lista->valor[i] = lista->valor[i - 1];
    }
    lista->valor[pos - 1] = val;
    lista->size++;
}

void removeValor(vetor *lista, int pos) {
    if (pos < 1 || pos > lista->size) {
        printf("Posicao invalida!\n");
        return;
    }
    for (int i = pos - 1; i < lista->size - 1; i++) {
        lista->valor[i] = lista->valor[i + 1];
    }
    lista->size--; 
}
