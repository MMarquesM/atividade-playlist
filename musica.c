#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

struct Musica {
    char titulo[100];
    char artista[100];
    float duracao;
};

Musica* musica_criar(const char* titulo, const char* artista, float duracao) {
    Musica* musica = malloc(sizeof(Musica));

    if (musica == NULL) {
        return NULL;
    }

    strcpy(musica->titulo, titulo);
    strcpy(musica->artista, artista);
    musica->duracao = duracao;

    return musica;
}

void musica_consultar(const Musica* musica, char* titulo, char* artista, float* duracao) {
    if (titulo != NULL) {
        strcpy(titulo, musica->titulo);
    }

    if (artista != NULL) {
        strcpy(artista, musica->artista);
    }

    if (duracao != NULL) {
        *duracao = musica->duracao;
    }
}

void musica_imprimir(const Musica* musica) {
    printf("Titulo: %s\n", musica->titulo);
    printf("Artista: %s\n", musica->artista);
    printf("Duracao: %.2f minutos\n", musica->duracao);
}

void musica_destruir(Musica* musica) {
    free(musica);
}