#ifndef CARROS_H
#define CARROS_H

typedef struct veiculo {
    char matricula[10];
    char marca[50];
    char modelo[50];
    int ano;
    int numContribuinte; // NIF do dono
    int codVeiculo;
    struct veiculo* proximo;
} Veiculo;

// Funções para manipular veículos
Veiculo* inicializaVeiculo();
void registarVeiculo(Veiculo** lista, const char* matricula, const char* marca, const char* modelo, int ano, int numContribuinte, int codVeiculo);
void listarVeiculos(Veiculo* lista);
void listarVeiculosOrdenados(Veiculo* lista);

#endif
