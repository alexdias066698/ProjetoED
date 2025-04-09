#include <stdio.h>
#include <stdlib.h>
#include "distancias.h"

Distancia* inicializaDistancia() {
    return NULL;
}

void registarDistancia(Distancia** lista, int codSensor1, int codSensor2, float distancia) {
    Distancia* novaDistancia = (Distancia*)malloc(sizeof(Distancia));
    novaDistancia->codSensor1 = codSensor1;
    novaDistancia->codSensor2 = codSensor2;
    novaDistancia->distancia = distancia;
    novaDistancia->proxima = *lista;
    *lista = novaDistancia;
}

void listarDistancias(Distancia* lista) {
    Distancia* atual = lista;
    while (atual != NULL) {
        printf("Distância entre sensor %d e sensor %d: %.2f km\n", atual->codSensor1, atual->codSensor2, atual->distancia);
        atual = atual->proxima;
    }
}

float obterDistancia(Distancia* lista, int codSensor1, int codSensor2) {
    Distancia* atual = lista;
    while (atual != NULL) {
        if ((atual->codSensor1 == codSensor1 && atual->codSensor2 == codSensor2) || 
            (atual->codSensor1 == codSensor2 && atual->codSensor2 == codSensor1)) {
            return atual->distancia;
        }
        atual = atual->proxima;
    }
    return -1; // Retorna -1 se a distância não for encontrada
}
