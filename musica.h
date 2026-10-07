#ifndef MUSICA_H
#define MUSICA_H

typedef struct Musica Musica;

Musica* musica_criar(const char* titulo, const char* artista, float duracao);

void musica_consultar(const Musica* musica, char* titulo, char* artista, float* duracao);

void musica_imprimir(const Musica* musica);

void musica_destruir(Musica* musica);

#endif