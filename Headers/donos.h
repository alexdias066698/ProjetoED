#ifndef DONOS_H
#define DONOS_H

typedef struct dono {
    int numContribuinte;
    char nome[100];
    char codPostal[10];
    struct dono* proximo;
} Dono;

// Funções para manipular donos
Dono* inicializaDono();
void registarDono(Dono** lista, int numContribuinte, const char* nome, const char* codPostal);
void listarDonos(Dono* lista);
void listarDonosPorNome(Dono* lista);

#endif
