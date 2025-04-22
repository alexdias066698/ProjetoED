#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donos.h"
#include "carros.h"
#include "passagens.h"
#include "sensores.h"
#include "distancias.h"

// Função de Menu
void menu() {
    printf("Escolha uma opcao:\n");
    printf("1 - Registar Dono\n");
    printf("2 - Listar Donos\n");
    printf("3 - Registar Veiculo\n");
    printf("4 - Listar Veiculos\n");
    printf("5 - Registar Passagem\n");
    printf("6 - Listar Passagens\n");
    printf("7 - Listar Sensores\n");
    printf("8 - Listar Distancias\n");
    printf("9 - Calcular Distancia Percorrida\n");
    printf("10 - Calcular Velocidade Media\n");
    printf("11 - Exportar para CSV\n");
    printf("12 - Exportar para XML\n");
    printf("0 - Sair\n");
}

// Função para calcular a distância percorrida por um veículo
void calcularDistanciaPercorrida(Passagem* listaPassagens, Distancia* listaDistancias) {
    Passagem* atual = listaPassagens;
    float distanciaTotal = 0.0;

    while (atual != NULL) {
        float distancia = obterDistancia(listaDistancias, atual->codSensor, atual->codSensor + 1);
        if (distancia != -1) {
            distanciaTotal += distancia;
        }
        atual = atual->proxima;
    }

    printf("Distância total percorrida: %.2f km\n", distanciaTotal);
}

// Função para calcular a velocidade média dos veículos
void calcularVelocidadeMedia(Passagem* listaPassagens) {
    Passagem* atual = listaPassagens;
    while (atual != NULL) {
       
        float distancia = 10.0;
        float tempo = 10.0; 
        float velocidade = distancia / tempo;
        printf("Veículo %d, Velocidade: %.2f km/h\n", atual->codVeiculo, velocidade);
        atual = atual->proxima;
    }
}

// Função para exportar dados para CSV
void exportarParaCSV(Dono* listaDonos, Veiculo* listaVeiculos, Passagem* listaPassagens) {
    FILE* file = fopen("dados.csv", "w");
    if (file != NULL) {
        fprintf(file, "ID,Dono,Veiculo,Passagem\n");
        Dono* donoAtual = listaDonos;
        while (donoAtual != NULL) {
            fprintf(file, "%d,%s\n", donoAtual->numContribuinte, donoAtual->nome);
            donoAtual = donoAtual->proximo;
        }
        fclose(file);
        printf("Dados exportados para dados.csv\n");
    }
}

// Função para exportar dados para XML
void exportarParaXML(Dono* listaDonos, Veiculo* listaVeiculos, Passagem* listaPassagens) {
    FILE* file = fopen("dados.xml", "w");
    if (file != NULL) {
        fprintf(file, "<dados>\n");
        Dono* donoAtual = listaDonos;
        while (donoAtual != NULL) {
            fprintf(file, "  <dono>\n    <id>%d</id>\n    <nome>%s</nome>\n  </dono>\n", donoAtual->numContribuinte, donoAtual->nome);
            donoAtual = donoAtual->proximo;
        }
        fprintf(file, "</dados>\n");
        fclose(file);
        printf("Dados exportados para dados.xml\n");
    }
}

// Função principal
int main() {
    
    Dono* listaDonos = inicializaDono();
    Veiculo* listaVeiculos = inicializaVeiculo();
    Passagem* listaPassagens = inicializaPassagem();
    Sensor* listaSensores = inicializaSensor();
    Distancia* listaDistancias = inicializaDistancia();

    registarDono(&listaDonos, 12345678, "José Martins", "6200");
    registarVeiculo(&listaVeiculos, "22-HT-66", "Opel", "Corsa", 2008, 12345678, 1);
    registarSensor(&listaSensores, 1, "Maia-Norte", "32º S, 22’, 56’’ 4ºW, 02’, 24’’");
    registarDistancia(&listaDistancias, 1, 3, 245.5);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                int numContribuinte;
                char nome[100], codPostal[10];
                printf("Numero Contribuinte: ");
                scanf("%d", &numContribuinte);
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Codigo Postal: ");
                scanf(" %[^\n]", codPostal);
                registarDono(&listaDonos, numContribuinte, nome, codPostal);
                break;
            }
            case 2:
                listarDonos(listaDonos);
                break;
            case 3: {
                char matricula[10], marca[50], modelo[50];
                int ano, numContribuinte, codVeiculo;
                printf("Matricula: ");
                scanf(" %[^\n]", matricula);
                printf("Marca: ");
                scanf(" %[^\n]", marca);
                printf("Modelo: ");
                scanf(" %[^\n]", modelo);
                printf("Ano: ");
                scanf("%d", &ano);
                printf("Numero Contribuinte: ");
                scanf("%d", &numContribuinte);
                printf("Codigo Veiculo: ");
                scanf("%d", &codVeiculo);
                registarVeiculo(&listaVeiculos, matricula, marca, modelo, ano, numContribuinte, codVeiculo);
                break;
            }
            case 4:
                listarVeiculos(listaVeiculos);
                break;
            case 5: {
                int codSensor, codVeiculo, tipoRegisto;
                char data[30];
                printf("Codigo Sensor: ");
                scanf("%d", &codSensor);
                printf("Codigo Veiculo: ");
                scanf("%d", &codVeiculo);
                printf("Data (formato dd-mm-aaaa hh:mm:ss): ");
                scanf(" %[^\n]", data);
                printf("Tipo de Registo (0 para entrada, 1 para saída): ");
                scanf("%d", &tipoRegisto);
                registarPassagem(&listaPassagens, codSensor, codVeiculo, data, tipoRegisto);
                break;
            }
            case 6:
                listarPassagens(listaPassagens);
                break;
            case 7:
                listarSensores(listaSensores);
                break;
            case 8:
                listarDistancias(listaDistancias);
                break;
            case 9:
                calcularDistanciaPercorrida(listaPassagens, listaDistancias);
                break;
            case 10:
                calcularVelocidadeMedia(listaPassagens);
                break;
            case 11:
                exportarParaCSV(listaDonos, listaVeiculos, listaPassagens);
                break;
            case 12:
                exportarParaXML(listaDonos, listaVeiculos, listaPassagens);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}
