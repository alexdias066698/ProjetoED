#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donos.h"

Dono* inicializaDono() {
    return NULL;
}

void registarDono(Dono** lista, int numContribuinte, const char* nome, const char* codPostal) {
    Dono* novoDono = (Dono*)malloc(sizeof(Dono));
    novoDono->numContribuinte = numContribuinte;
    strcpy(novoDono->nome, nome);
    strcpy(novoDono->codPostal, codPostal);
    novoDono->proximo = *lista;
    *lista = novoDono;
}

void listarDonos(Dono* lista) {
    Dono* atual = lista;
    while (atual != NULL) {
        printf("%d %s %s\n", atual->numContribuinte, atual->nome, atual->codPostal);
        atual = atual->proximo;
    }
}

void listarDonosPorNome(Dono* lista) {
    Dono* atual = lista;
    Dono* array[100];
    int i = 0;

    // Armazenar donos em um array
    while (atual != NULL) {
        array[i++] = atual;
        atual = atual->proximo;
    }

    // Ordenação alfabética por nome
    for (int j = 0; j < i - 1; j++) {
        for (int k = j + 1; k < i; k++) {
            if (strcmp(array[j]->nome, array[k]->nome) > 0) {
                Dono* temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
        }
    }

    // Imprimir a lista ordenada
    for (int j = 0; j < i; j++) {
        printf("%s\n", array[j]->nome);
    }
}
