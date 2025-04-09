#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carros.h"

Veiculo* inicializaVeiculo() {
    return NULL;
}

void registarVeiculo(Veiculo** lista, const char* matricula, const char* marca, const char* modelo, int ano, int numContribuinte, int codVeiculo) {
    Veiculo* novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));
    strcpy(novoVeiculo->matricula, matricula);
    strcpy(novoVeiculo->marca, marca);
    strcpy(novoVeiculo->modelo, modelo);
    novoVeiculo->ano = ano;
    novoVeiculo->numContribuinte = numContribuinte;
    novoVeiculo->codVeiculo = codVeiculo;
    novoVeiculo->proximo = *lista;
    *lista = novoVeiculo;
}

void listarVeiculos(Veiculo* lista) {
    Veiculo* atual = lista;
    while (atual != NULL) {
        printf("%s %s %s %d %d\n", atual->matricula, atual->marca, atual->modelo, atual->ano, atual->codVeiculo);
        atual = atual->proximo;
    }
}

void listarVeiculosOrdenados(Veiculo* lista) {
    Veiculo* atual = lista;
    Veiculo* array[100];
    int i = 0;

    while (atual != NULL) {
        array[i++] = atual;
        atual = atual->proximo;
    }

    // Ordenar por matrícula
    for (int j = 0; j < i - 1; j++) {
        for (int k = j + 1; k < i; k++) {
            if (strcmp(array[j]->matricula, array[k]->matricula) > 0) {
                Veiculo* temp = array[j];
                array[j] = array[k];
                array[k] = temp;
            }
        }
    }

    // Imprimir a lista ordenada
    for (int j = 0; j < i; j++) {
        printf("%s %s %s\n", array[j]->matricula, array[j]->marca, array[j]->modelo);
    }
}
