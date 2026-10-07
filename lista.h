#ifndef LISTA_H
#define LISTA_H

#include "musica.h"

typedef struct Lista Lista;

Lista* lista_criar();

void lista_inserir_inicio(Lista* lista, Musica* musica);

void lista_inserir_fim(Lista* lista, Musica* musica);

void lista_inserir_posicao(Lista* lista, Musica* musica, int posicao);

Musica* lista_remover_inicio(Lista* lista);

Musica* lista_remover_fim(Lista* lista);

Musica* lista_remover_posicao(Lista* lista, int posicao);

Musica* lista_consultar_inicio(const Lista* lista);

Musica* lista_consultar_posicao(const Lista* lista, int posicao);

int lista_quantidade(const Lista* lista);

void lista_destruir(Lista* lista);

#endif