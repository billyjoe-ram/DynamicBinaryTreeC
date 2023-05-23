//
// Created by giovane on 23/05/2023.
//

#ifndef DYNAMICBINARYTREE_ARVORE_DINAMICA_H
#define DYNAMICBINARYTREE_ARVORE_DINAMICA_H


typedef struct Jogador {
    char nome[100];
    char posicao[100];
    int idade;
    int habilidade;
    int camisa;
    struct Jogador *esquerda;
    struct Jogador *direita;
} Jogador;

void inserirJogador(Jogador **raiz, Jogador *novoJogador);

Jogador *buscarJogador(Jogador *raiz, const char *nome);

void listarJogadores(Jogador *raiz);

void excluirJogador(Jogador **raiz, const char *nome);

void liberarMemoria(Jogador *raiz);

#endif //DYNAMICBINARYTREE_ARVORE_DINAMICA_H
