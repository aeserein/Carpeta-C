#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant) {
    int i;

    for (i=0; i<cant; i++) {
        usuarios[i].estado = 0;
    }
}

void inicializarUsuariosHardCode(eUsuario usuarios[]) {


    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};

    int i;

    for(i=0; i<15; i++) {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }
}

void mostrarUsuarioConID(eUsuario lista) {
     printf("\n");
     printf("%7d\t", lista.idUsuario);
     printf("%17s\t", lista.nombre);
     printf("%5d\n", lista.idSerie);
}

void mostrarUsuario(eUsuario lista) {
     printf("\n");
     printf("%7d\t", lista.idUsuario);
     printf("%17s\t", lista.nombre);
}

void mostrarListadoUsuarios(eUsuario lista[], int limite) {
    int i;
    if(limite > 0 && lista != NULL) {

        printf("%7s\t%17s\t%5s" , "ID" , "Nombre" , "Serie");
        for(i=0; i<limite; i++) {

            if(lista[i].estado==1) {
                mostrarUsuarioConID(lista[i]);
            }
        }
    }
}
////////////////////////////////////////
void mostrarListadoUsuariosConSerie(eUsuario lista[], int limite, eSerie listaSeries[], int limiteSeries) {
    int i;
    int indiceSerie;

    if(limite > 0 && lista != NULL) {

        printf("%7s\t%17s\t%10s" , "ID" , "Nombre" , "Serie");

        for(i=0; i<limite; i++) {

            if(lista[i].estado==1) {
                mostrarUsuario(lista[i]);
                indiceSerie = retornarIndiceSerieInt(listaSeries, limiteSeries, lista[i].idSerie);
                mostrarNombreDeSerie(listaSeries[indiceSerie]);
            }
        }
    }
}

int retornarIndiceUsuario(eUsuario listado[], int cantidad, eUsuario unUsuario) {
    int f;
    int retorno = -1;

    for (f=0; f<cantidad ; f++) {
        if (listado[f].idUsuario==unUsuario.idUsuario) {
            retorno = f;
            break;
        }
    }
    return retorno;
}

void mostrarCantUsuariosQueMiranCadaSerie(eUsuario listaUsuarios[], int size) {
    short f;
    short count100=0, count101=0, count102=0, count103=0;

    for (f=0 ; f<size ; f++) {
        switch (listaUsuarios[f].idSerie) {
            case 100 : count100++;
            case 101 : count101++;
            case 102 : count102++;
            case 103 : count103++;
        }
    }
    for (f=0 ; f<5 ; f++) {

    }
    //mostrarSerie();
}
