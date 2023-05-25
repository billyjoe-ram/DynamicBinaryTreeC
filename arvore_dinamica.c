//
// Created by giovane on 23/05/2023.
//

#include "arvore_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirJogador(arvbin *no, tree_dados *dados) {
    if (!(*no)) {
        (*no) = (struct no_arvbin *) malloc(sizeof(struct no_arvbin));
        memset(*no, 0, sizeof(struct no_arvbin));
        strcpy((*no)->dado.nome, dados->nome);
        strcpy((*no)->dado.posicao, dados->posicao);
        (*no)->dado.idade = dados->idade;
        (*no)->dado.habilidade = dados->habilidade;
        (*no)->dado.camisa = dados->camisa;
    } else /*Se nao tah vazio*/ {
        int comp = strcmp(dados->nome, (*no)->dado.nome);
        if (comp < 0) {
            inserirJogador(&(*no)->esquerda, dados);
        } else { // > 0
            inserirJogador(&(*no)->direita, dados);
        }

    }

}


struct no_arvbin *buscarJogador(arvbin raiz, const char *nome) {
    if (raiz == NULL || strcmp(nome, raiz->dado.nome) == 0) {
        return raiz;
    }

    if (strcmp(nome, raiz->dado.nome) < 0) {
        return buscarJogador(raiz->esquerda, nome);
    } else {
        return buscarJogador(raiz->direita, nome);
    }
}

void listarJogadores(arvbin raiz) {
    if (raiz != NULL) {
        listarJogadores(raiz->esquerda);
        printf("Nome: %s\n", raiz->dado.nome);
        printf("Posicao: %s\n", raiz->dado.posicao);
        printf("Idade: %d\n", raiz->dado.idade);
        printf("Habilidade: %d\n", raiz->dado.habilidade);
        printf("Camisa: %d\n", raiz->dado.camisa);
        printf("\n");
        listarJogadores(raiz->direita);
    }
}

void excluirJogador(arvbin *raiz, const char *nome) {
    if (*raiz == NULL) {
        printf("Jogador nao encontrado.\n");
    } else {
        if (strcmp(nome, (*raiz)->dado.nome) < 0) {
            excluirJogador(&((*raiz)->esquerda), nome);
        } else if (strcmp(nome, (*raiz)->dado.nome) > 0) {
            excluirJogador(&((*raiz)->direita), nome);
        } else {
            arvbin jogadorRemovido = *raiz;

            if ((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            } else if ((*raiz)->direita == NULL) {
                *raiz = (*raiz)->esquerda;
            } else {
                arvbin substituto = (*raiz)->direita;

                while (substituto->esquerda != NULL) {
                    substituto = substituto->esquerda;
                }

                substituto->esquerda = (*raiz)->esquerda;
                *raiz = (*raiz)->direita;
            }

            free(jogadorRemovido);
            printf("Jogador excluido com sucesso.\n");
        }
    }
}

void liberarMemoria(arvbin raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}
