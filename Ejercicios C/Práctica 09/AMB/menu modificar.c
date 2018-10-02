#ifndef MENU_MODIFICAR_C_INCLUDED
#define MENU_MODIFICAR_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "amb.h"
#include "funciones/ingresos.h"
#include "funciones/strings.h"
#include "funciones/flow.h"

#define LISTA 10
#define NOMBRE 20

void modificarDatos(alumno lista[], short tam){
    system("cls");
    short opcion;

    do {
        mostrarListaDeAlumnos(lista, tam);
        printf("\n1. Modificar nombre\n");
        printf("2. Modificar nota\n");
        printf("3. Modificar altura\n");
        printf("   -------------------------\n");
        printf("4. Atr%cs\n\n", 160);
        opcion = getShort("Ingrese opcion:\t");

        switch(opcion) {
            case 1 : {
                modificarNombre(lista, tam);
                break;
            }
            case 2 : {
                modificarNota(lista, tam);
                break;
            }
            case 3 : {
                modificarAltura(lista, tam);
                break;
            }
            case 4 : { break; }
            default : {
                printf("Opci%cn inv%clida" , 162, 160);
            }
        }
        if (opcion!=4) {
            pausaYClear();
        }
    } while (opcion!=4);
}

void modificarNombre(alumno lista[], short tam) {
    int legajo;
    short encontro = 0;

    legajo = getIntBetween(1000,9999,"\nLegajo (4 cifras):\t");
    tam--;
    for ( ; tam>=0 ; tam--) {
        if (lista[tam].bEstado==1 && legajo==lista[tam].legajo) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {

        encabezadoDeLista();
        mostrarAlumno(lista, tam);

        getString(lista[tam].nombre,"\nIngrese nuevo nombre:\t", NOMBRE);

        printf("\nNombre modificado con %cxito\n\n", 130);
        encabezadoDeLista();
        mostrarAlumno(lista, tam);

    } else {
        printf("\nNo se encontr%c el legajo %d\n" , 162, legajo);
    }

}

void modificarNota(alumno lista[], short tam) {
    int legajo;
    short encontro = 0;

    legajo = getIntBetween(1000,9999,"Legajo (4 cifras):\t");
    tam--;
    for ( ; tam>=0 ; tam--) {
        if (lista[tam].bEstado==1 && legajo==lista[tam].legajo) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {

        encabezadoDeLista();
        mostrarAlumno(lista, tam);

        lista[tam].nota = getShortBetween(1,10,"\nIngrese nueva nota:\t");

        printf("\nNota modificada con %cxito\n\n", 130);
        encabezadoDeLista();
        mostrarAlumno(lista, tam);

    } else {
        printf("\nNo se encontr%c el legajo %d\n" , 162, legajo);
    }

}

void modificarAltura(alumno lista[], short tam) {
    int legajo;
    short encontro = 0;

    legajo = getIntBetween(1000,9999,"Legajo (4 cifras):\t");
    tam--;
    for ( ; tam>=0 ; tam--) {
        if (lista[tam].bEstado==1 && legajo==lista[tam].legajo) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {
        encabezadoDeLista();
        mostrarAlumno(lista, tam);

        lista[tam].altura = getFloatBetween(0.5,2.5,"\nIngrese nueva altura:\t");

        printf("\nNota modificada con %cxito\n\n", 130);
        encabezadoDeLista();
        mostrarAlumno(lista, tam);
    } else {
        printf("\nNo se encontr%c el legajo %d\n" , 162, legajo);
    }

}

#endif // MENU_MODIFICAR_C_INCLUDED
