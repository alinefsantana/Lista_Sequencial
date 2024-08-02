#include "vetor.h"
#include <stdio.h>

void switch_function(vetor *lista) {
    int opcao = 0;
    int pos, val;

    do {
        printf("Escolha sua opcao:\n"
               "#1: Inserir numero\n"
               "#2: Remover numero\n"
               "#3: Modificar numero\n"
               "#4: Verificar se lista esta vazia\n"
               "#5: Verificar se lista esta cheia\n"
               "#6: Obter tamanho da lista\n"
               "#7: Obter valor de uma posicao\n"
               "#9: Encerrar programa\n");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro de entrada. Por favor, digite um número.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Insira o valor e a posição: ");
                if (scanf("%d %d", &val, &pos) != 2) {
                    printf("Entrada inválida.\n");
                    continue;
                }
                insereValor(lista, pos, val);
                break;
            case 2:
                printf("Insira a posição para remover: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Entrada inválida.\n");
                    continue;
                }
                removeValor(lista, pos);
                break;
            case 3:
                printf("Insira a posição e o novo valor: ");
                if (scanf("%d %d", &pos, &val) != 2) {
                    printf("Entrada inválida.\n");
                    continue;
                }
                modificaValor(lista, pos, val);
                break;
            case 4:
                if (vazia(lista))
                    printf("A lista está vazia.\n");
                else
                    printf("A lista não está vazia.\n");
                break;
            case 5:
                if (cheia(lista))
                    printf("A lista está cheia.\n");
                else
                    printf("A lista não está cheia.\n");
                break;
            case 6:
                printf("Tamanho da lista: %d\n", verificaTamanho(lista));
                break;
            case 7:
                printf("Insira a posição: ");
                if (scanf("%d", &pos) != 1) {
                    printf("Entrada inválida.\n");
                    continue;
                }
                val = verificaValor(lista, pos);
                if (val != -1)
                    printf("Valor na posição %d é %d\n", pos, val);
                break;
            case 9:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 9);
}

int main() {
    int tamanho;
    vetor lista;

    printf("Bem-vindo ao criador de lista!\n"
           "Escolha o tamanho da lista: ");
    if (scanf("%d", &tamanho) != 1) {
        printf("Erro de entrada. Por favor, digite um número inteiro.\n");
        return 1; 
    }

    printf("Aguarde enquanto sua lista está sendo criada...\n");
    criarLista(&lista, tamanho);

    printf("Lista criada com sucesso!\n");
    switch_function(&lista); 

    return 0;
}
