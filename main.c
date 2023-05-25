#include "arvore_dinamica.h"
#include <stdio.h>
int main() {
    arvbin jogadores = {0};
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
                tree_dados dados;
                printf("\n");
                printf("Nome: ");
                scanf_s("%s", dados.nome, sizeof(dados.nome));
                printf("Posicao: ");
                scanf_s("%s", dados.posicao, sizeof(dados.posicao));
                printf("Idade: ");
                scanf_s("%i", &dados.idade);
                printf("Habilidade: ");
                scanf_s("%d", &dados.habilidade);
                printf("Camisa: ");
                scanf_s("%d", &dados.camisa);


                inserirJogador(&jogadores, &dados);
                break;
            }

            case 2: {
                printf("\n");
                printf("Nome do jogador a buscar: ");
                char nomeBusca[100];
                scanf_s("%s", nomeBusca, sizeof(nomeBusca));

                struct no_arvbin *jogadorEncontrado = buscarJogador(jogadores, nomeBusca);

                if (jogadorEncontrado != NULL) {
                    printf("Jogador encontrado:\n");
                    printf("Nome: %s\n", jogadorEncontrado->dado.nome);
                    printf("Posicao: %s\n", jogadorEncontrado->dado.posicao);
                    printf("Idade: %d\n", jogadorEncontrado->dado.idade);
                    printf("Habilidade: %d\n", jogadorEncontrado->dado.habilidade);
                    printf("Camisa: %d\n", jogadorEncontrado->dado.camisa);
                } else {
                    printf("Jogador nao encontrado.\n");
                }
                break;
            }

            case 3:
                printf("\n");
                listarJogadores(jogadores);
                break;

            case 4: {
                printf("\n");
                printf("Nome do jogador a excluir: ");
                char nomeExclusao[100];
                scanf_s("%s", nomeExclusao, sizeof(nomeExclusao));

                excluirJogador(&jogadores, nomeExclusao);
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

    liberarMemoria(jogadores);

    return 0;
}
