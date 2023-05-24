//
// Created by giovane on 23/05/2023.
//

#include "arvore_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inserirJogador(arvbin *no, tree_dados dados ) {
    if (!(*no)) {
        (*no) = (struct no_arvbin *) malloc(sizeof(struct no_arvbin));
        memset(*no, 0, sizeof(struct no_arvbin));
        strcpy((*no)->dado.nome, dados.nome);
        strcpy((*no)->dado.posicao, dados.posicao);
        (*no)->dado.idade = dados.idade;
        (*no)->dado.habilidade = dados.habilidade;
        (*no)->dado.camisa = dados.camisa;
        (*no)->dado.cont = 1;
    } else /*Se nao tah vazio*/ {
        int comp = strcmp(nome, (*no)->dado.nome);
        if (comp == 0) {
            (*no)->dado.cont++;
            return;
        } else if (comp < 0) {
            insere_arvore(&(*no)->esq, nome, posicao, idade, habilidade, camisa);
        } else { // > 0
            insere_arvore(&(*no)->dir, nome, posicao, idade, habilidade, camisa);
        }

    }

}


void inserirJogador(Jogador **raiz, Jogador *novoJogador) {
    if (*raiz == NULL) {
        *raiz = novoJogador;
    } else {
        if (strcmp(novoJogador->nome, (*raiz)->nome) < 0) {
            inserirJogador(&((*raiz)->esquerda), novoJogador);
        } else {
            inserirJogador(&((*raiz)->direita), novoJogador);
        }
    }
}

Jogador *buscarJogador(Jogador *raiz, const char *nome) {
    if (raiz == NULL || strcmp(nome, raiz->nome) == 0) {
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0) {
        return buscarJogador(raiz->esquerda, nome);
    } else {
        return buscarJogador(raiz->direita, nome);
    }
}

void listarJogadores(Jogador *raiz) {
    if (raiz != NULL) {
        listarJogadores(raiz->esquerda);
        printf("Nome: %s\n", raiz->nome);
        printf("Posicao: %s\n", raiz->posicao);
        printf("Idade: %d\n", raiz->idade);
        printf("Habilidade: %d\n", raiz->habilidade);
        printf("Camisa: %d\n", raiz->camisa);
        printf("\n");
        listarJogadores(raiz->direita);
    }
}

void excluirJogador(Jogador **raiz, const char *nome) {
    if (*raiz == NULL) {
        printf("Jogador nao encontrado.\n");
    } else {
        if (strcmp(nome, (*raiz)->nome) < 0) {
            excluirJogador(&((*raiz)->esquerda), nome);
        } else if (strcmp(nome, (*raiz)->nome) > 0) {
            excluirJogador(&((*raiz)->direita), nome);
        } else {
            Jogador *jogadorRemovido = *raiz;

            if ((*raiz)->esquerda == NULL) {
                *raiz = (*raiz)->direita;
            } else if ((*raiz)->direita == NULL) {
                *raiz = (*raiz)->esquerda;
            } else {
                Jogador *substituto = (*raiz)->direita;

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

void liberarMemoria(Jogador *raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}
