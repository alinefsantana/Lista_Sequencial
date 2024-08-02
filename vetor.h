#pragma once

typedef struct {
    int *valor;
    int tam_max;
    int size;
} vetor;

void criarLista(vetor *lista, int tam_max);
int vazia(vetor *lista);
int cheia(vetor *lista);
int verificaTamanho(vetor *lista);
int verificaValor(vetor *lista, int pos);
void modificaValor(vetor *lista, int pos, int val);
void insereValor(vetor *lista, int pos, int val);
void removeValor(vetor *lista, int pos);
