#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {
    Jogador* raiz = NULL;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Inserir jogador\n");
        printf("2. Buscar jogador\n");
        printf("3. Listar jogadores\n");
        printf("4. Excluir jogador\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf_s("%d", &opcao);

        switch (opcao) {
        case 1: {
            printf("\n");
            Jogador* novoJogador = (Jogador*)malloc(sizeof(Jogador));
            printf("Nome: ");
            scanf_s("%s", novoJogador->nome, sizeof(novoJogador->nome));
            printf("Posicao: ");
            scanf_s("%s", novoJogador->posicao, sizeof(novoJogador->posicao));
            printf("Idade: ");
            scanf_s("%d", &novoJogador->idade);
            printf("Habilidade: ");
            scanf_s("%d", &novoJogador->habilidade);
            printf("Camisa: ");
            scanf_s("%d", &novoJogador->camisa);

            novoJogador->esquerda = NULL;
            novoJogador->direita = NULL;

            inserirJogador(&raiz, novoJogador);
            break;
        }

        case 2: {
            printf("\n");
            printf("Nome do jogador a buscar: ");
            char nomeBusca[100];
            scanf_s("%s", nomeBusca, sizeof(nomeBusca));

            Jogador* jogadorEncontrado = buscarJogador(raiz, nomeBusca);

            if (jogadorEncontrado != NULL) {
                printf("Jogador encontrado:\n");
                printf("Nome: %s\n", jogadorEncontrado->nome);
                printf("Posicao: %s\n", jogadorEncontrado->posicao);
                printf("Idade: %d\n", jogadorEncontrado->idade);
                printf("Habilidade: %d\n", jogadorEncontrado->habilidade);
                printf("Camisa: %d\n", jogadorEncontrado->camisa);
            }
            else {
                printf("Jogador nao encontrado.\n");
            }
            break;
        }

        case 3:
            printf("\n");
            listarJogadores(raiz);
            break;

        case 4: {
            printf("\n");
            printf("Nome do jogador a excluir: ");
            char nomeExclusao[100];
            scanf_s("%s", nomeExclusao, sizeof(nomeExclusao));

            excluirJogador(&raiz, nomeExclusao);
            break;
        }

        case 0:
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }

        printf("\n");

    } while (opcao != 0);

    liberarMemoria(raiz);

    return 0;
}
