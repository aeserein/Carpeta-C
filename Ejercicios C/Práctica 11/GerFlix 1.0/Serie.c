#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include <string.h>

/*  int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
*/

void inicializarSeriesEstado(eSerie series[], int cant) {
    int i;

    for(i=0; i<cant; i++) {
        series[i].estado = 0;
    }
}

void inicializarSeriesHardCode(eSerie series[]) {
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++) {
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void mostrarNombreDeSerie(eSerie unaSerie) {
    printf("%10s\n", unaSerie.nombre);
}

void mostrarSerie(eSerie lista) {
     printf("%7d\t", lista.idSerie);
     printf("%20s\t", lista.nombre);
     printf("%20s\t", lista.genero);
     printf("%5d\n", lista.cantidadTemporadas);
}

void mostrarListadoSeries(eSerie lista[], int limite) {
    int i;
    if(limite > 0 && lista != NULL) {

        printf("%7s\t%20s\t%20s\t%5s" , "ID" , "Nombre" , "Genero" , "Temps");
        for(i=0; i<limite; i++) {

            if(lista[i].estado==1) {
                mostrarSerie(lista[i]);
            }
        }
    }
}

int retornarIndiceSerie(eSerie listado[], int cantidad, eSerie unaSerie) {
    int f;
    int retorno = -1;

    for (f=0; f<cantidad ; f++) {
        if (listado[f].idSerie==unaSerie.idSerie) {
            retorno = f;
            break;
        }
    }
    return retorno;
}

int retornarIndiceSerieInt(eSerie listado[], int cantidad, int idSerie) {
    int f;
    int retorno = -1;

    for (f=0; f<cantidad ; f++) {
        if (listado[f].idSerie==idSerie) {
            retorno = f;
            break;
        }
    }
    return retorno;
}
