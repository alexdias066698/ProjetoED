#ifndef DISTANCIAS_H
#define DISTANCIAS_H

typedef struct distancia {
    int codSensor1;
    int codSensor2;
    float distancia; // Distância entre os sensores (em km)
    struct distancia* proxima;
} Distancia;

// Funções para manipular distâncias entre sensores
Distancia* inicializaDistancia();
void registarDistancia(Distancia** lista, int codSensor1, int codSensor2, float distancia);
void listarDistancias(Distancia* lista);
float obterDistancia(Distancia* lista, int codSensor1, int codSensor2);

#endif
