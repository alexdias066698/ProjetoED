#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passagens.h"

Passagem* inicializaPassagem() {
    return NULL;
}

void registarPassagem(Passagem** lista, int codSensor, int codVeiculo, const char* data, int tipoRegisto) {
    Passagem* novaPassagem = (Passagem*)malloc(sizeof(Passagem));
    novaPassagem->codSensor = codSensor;
    novaPassagem->codVeiculo = codVeiculo;
    strcpy(novaPassagem->data, data);
    novaPassagem->tipoRegisto = tipoRegisto;
    novaPassagem->proxima = *lista;
    *lista = novaPassagem;
}

void listarPassagens(Passagem* lista) {
    Passagem* atual = lista;
    while (atual != NULL) {
        printf("%d %d %s %d\n", atual->codSensor, atual->codVeiculo, atual->data, atual->tipoRegisto);
        atual = atual->proxima;
    }
}
