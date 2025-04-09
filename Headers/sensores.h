#ifndef SENSORES_H
#define SENSORES_H

typedef struct sensor {
    int codSensor;
    char cidade[50];
    char coordenadas[50];
    struct sensor* proximo;
} Sensor;

// Funções para manipular sensores
Sensor* inicializaSensor();
void registarSensor(Sensor** lista, int codSensor, const char* cidade, const char* coordenadas);
void listarSensores(Sensor* lista);

#endif
