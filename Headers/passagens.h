#ifndef PASSAGENS_H
#define PASSAGENS_H

typedef struct passagem {
    int codSensor;
    int codVeiculo;
    char data[30];
    int tipoRegisto; // 0 para entrada, 1 para saída
    struct passagem* proxima;
} Passagem;

// Funções para manipular passagens
Passagem* inicializaPassagem();
void registarPassagem(Passagem** lista, int codSensor, int codVeiculo, const char* data, int tipoRegisto);
void listarPassagens(Passagem* lista);

#endif
