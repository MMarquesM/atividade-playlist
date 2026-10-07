#include <stdlib.h>

#include "lista.h"

typedef struct No {
    Musica* musica;
    struct No* proximo;
} No;

struct Lista {
    No* inicio;
    int quantidade;
};

Lista* lista_criar() {
    Lista* lista = malloc(sizeof(Lista));

    if (lista == NULL) {
        return NULL;
    }

    lista->inicio = NULL;
    lista->quantidade = 0;

    return lista;
}

void lista_inserir_inicio(Lista* lista, Musica* musica) {
    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->musica = musica;
    novo->proximo = lista->inicio;

    lista->inicio = novo;
    lista->quantidade++;
}

void lista_inserir_fim(Lista* lista, Musica* musica) {
    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->musica = musica;
    novo->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;

        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }

    lista->quantidade++;
}

void lista_inserir_posicao(Lista* lista, Musica* musica, int posicao) {
    if (posicao < 0 || posicao > lista->quantidade) {
        return;
    }

    if (posicao == 0) {
        lista_inserir_inicio(lista, musica);
        return;
    }

    No* novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->musica = musica;

    No* atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    lista->quantidade++;
}

Musica* lista_remover_inicio(Lista* lista) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    No* removido = lista->inicio;
    Musica* musica = removido->musica;

    lista->inicio = removido->proximo;
    lista->quantidade--;

    free(removido);

    return musica;
}

Musica* lista_remover_fim(Lista* lista) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    if (lista->inicio->proximo == NULL) {
        return lista_remover_inicio(lista);
    }

    No* atual = lista->inicio;

    while (atual->proximo->proximo != NULL) {
        atual = atual->proximo;
    }

    No* removido = atual->proximo;
    Musica* musica = removido->musica;

    atual->proximo = NULL;
    lista->quantidade--;

    free(removido);

    return musica;
}

Musica* lista_remover_posicao(Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->quantidade) {
        return NULL;
    }

    if (posicao == 0) {
        return lista_remover_inicio(lista);
    }

    No* atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    No* removido = atual->proximo;
    Musica* musica = removido->musica;

    atual->proximo = removido->proximo;
    lista->quantidade--;

    free(removido);

    return musica;
}

Musica* lista_consultar_inicio(const Lista* lista) {
    if (lista->inicio == NULL) {
        return NULL;
    }

    return lista->inicio->musica;
}

Musica* lista_consultar_posicao(const Lista* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->quantidade) {
        return NULL;
    }

    No* atual = lista->inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    return atual->musica;
}

int lista_quantidade(const Lista* lista) {
    return lista->quantidade;
}

void lista_destruir(Lista* lista) {
    while (lista->inicio != NULL) {
        No* removido = lista->inicio;

        lista->inicio = removido->proximo;

        musica_destruir(removido->musica);

        free(removido);
    }

    free(lista);
}