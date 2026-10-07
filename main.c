#include <stdio.h>

#include "musica.h"
#include "lista.h"

void adiciona_musica(Lista* lista, Musica* musica) {
    lista_inserir_fim(lista, musica);
}

void adiciona_musica_posicao(Lista* lista, Musica* musica, int posicao) {
    lista_inserir_posicao(lista, musica, posicao);
}

void remove_musica(Lista* lista, int posicao) {
    Musica* musica = lista_remover_posicao(lista, posicao);

    if (musica != NULL) {
        printf("Musica removida:\n");
        musica_imprimir(musica);
        musica_destruir(musica);
    }
}

void tempo_restante(Lista* lista, int proxima_posicao) {
    float tempo = 0;

    int quantidade = lista_quantidade(lista);

    for (int i = proxima_posicao; i < quantidade; i++) {
        Musica* musica = lista_consultar_posicao(lista, i);

        if (musica != NULL) {
            float duracao;

            musica_consultar(musica, NULL, NULL, &duracao);

            tempo += duracao;
        }
    }

    printf("Tempo restante: %.2f minutos\n", tempo);
}

void play(Lista* lista, int* proxima_posicao) {
    int quantidade = lista_quantidade(lista);

    if (*proxima_posicao >= quantidade) {
        printf("Nao existem mais musicas para tocar.\n");
        return;
    }

    Musica* musica = lista_consultar_posicao(lista, *proxima_posicao);

    printf("\nTocando musica:\n");

    musica_imprimir(musica);

    (*proxima_posicao)++;
}

void musicas_reproduzidas(int proxima_posicao) {
    printf("Musicas reproduzidas: %d\n", proxima_posicao);
}

int main() {

    Lista* playlist = lista_criar();

    int proxima_posicao = 0;

    Musica* musica1 = musica_criar("Heroes", "David Bowie", 3.32);
    Musica* musica2 = musica_criar("Lencol Dobrado", "Joao Gustavo e Murilo", 3.10);
    Musica* musica3 = musica_criar("Firestone", "Kygo", 4.33);
    Musica* musica4 = musica_criar("See You Again", "Tyler, The Creator", 3.00);
    Musica* musica5 = musica_criar("Ao Vivo e a Cores", "Matheus, Kauan e Anitta", 3.20);
    Musica* musica6 = musica_criar("Bring Me to Life", "Evanescence", 3.56);
    Musica* musica7 = musica_criar("Don't You Worry Child", "Swedish House Mafia", 3.32);
    Musica* musica8 = musica_criar("505", "Arctic Monkeys", 4.13);
    Musica* musica9 = musica_criar("Let Down", "Radiohead", 4.59);
    Musica* musica10 = musica_criar("End of Beginning", "Djo", 2.39);

    adiciona_musica(playlist, musica1);
    adiciona_musica(playlist, musica2);
    adiciona_musica(playlist, musica3);
    adiciona_musica(playlist, musica4);
    adiciona_musica(playlist, musica5);
    adiciona_musica(playlist, musica6);
    adiciona_musica(playlist, musica7);
    adiciona_musica(playlist, musica8);
    adiciona_musica(playlist, musica9);
    adiciona_musica(playlist, musica10);

    printf("Quantidade inicial de musicas: %d\n",
           lista_quantidade(playlist));

    printf("\nPrimeira musica:\n");

    Musica* primeira = lista_consultar_inicio(playlist);

    if (primeira != NULL) {
        musica_imprimir(primeira);
    }

    printf("\nMusica na posicao 3:\n");

    Musica* musica_posicao = lista_consultar_posicao(playlist, 3);

    if (musica_posicao != NULL) {
        musica_imprimir(musica_posicao);
    }

    tempo_restante(playlist, proxima_posicao);

    play(playlist, &proxima_posicao);
    play(playlist, &proxima_posicao);
    play(playlist, &proxima_posicao);

    musicas_reproduzidas(proxima_posicao);

    tempo_restante(playlist, proxima_posicao);

    printf("\nAdicionando uma nova musica na posicao 2...\n");

    Musica* nova_musica =
        musica_criar("Save Your Tears", "The Weeknd", 3.35);

    adiciona_musica_posicao(playlist, nova_musica, 2);

    printf("Quantidade de musicas: %d\n",
           lista_quantidade(playlist));

    printf("\nRemovendo a musica da posicao 4...\n");

    remove_musica(playlist, 4);

    printf("\nQuantidade final de musicas: %d\n",
           lista_quantidade(playlist));

    printf("Posicao da proxima musica a ser reproduzida: %d\n",
           proxima_posicao);

    lista_destruir(playlist);

    return 0;
}