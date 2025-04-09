#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sensores.h"

Sensor* inicializaSensor() {
    return NULL;
}

void registarSensor(Sensor** lista, int codSensor, const char* cidade, const char* coordenadas) {
    Sensor* novoSensor = (Sensor*)malloc(sizeof(Sensor));
    novoSensor->codSensor = codSensor;
    strcpy(novoSensor->cidade, cidade);
    strcpy(novoSensor->coordenadas, coordenadas);
    novoSensor->proximo = *lista;
    *lista = novoSensor;
}

void listarSensores(Sensor* lista) {
    Sensor* atual = lista;
    while (atual != NULL) {
        printf("Sensor %d - Cidade: %s, Localizacao: %s\n", atual->codSensor, atual->cidade, atual->coordenadas);
        atual = atual->proximo;
    }
}
