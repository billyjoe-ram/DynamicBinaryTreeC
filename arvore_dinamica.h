//
// Created by giovane on 23/05/2023.
//

#ifndef DYNAMICBINARYTREE_ARVORE_DINAMICA_H
#define DYNAMICBINARYTREE_ARVORE_DINAMICA_H
typedef struct {
    char nome[100];
    char posicao[100];
    int idade;
    int habilidade;
    int camisa;
} tree_dados;

typedef struct no_arvbin *arvbin;

struct no_arvbin {
    arvbin esquerda;
    tree_dados dado;
    arvbin direita;
};


void inserirJogador(arvbin *no, tree_dados *dados);

//void inserirJogador(Jogador **raiz, Jogador *novoJogador);

struct no_arvbin *buscarJogador(arvbin raiz, const char *nome);

void listarJogadores(arvbin raiz);

void excluirJogador(arvbin *raiz, const char *nome);

void liberarMemoria(arvbin raiz);

#endif //DYNAMICBINARYTREE_ARVORE_DINAMICA_H
