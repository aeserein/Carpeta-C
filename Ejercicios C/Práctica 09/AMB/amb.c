#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amb.h"
#include "extras.h"
#include "menu modificar.h"
#include "funciones/ingresos.h"
#include "funciones/strings.h"
#include "funciones/flow.h"
#define LISTA 10
#define NOMBRE 20
#define VACIO 0
#define ALTA 1
#define BAJA -1

void menu() {
    printf("1. Alta de alumno\n");
    printf("2. Mostrar lista\n");
    printf("3. Baja de alumno\n");
    printf("4. Modificar datos\n");
    printf("5. Extras\n");
    printf("   ----------------------\n");
    printf("6. Salir\n\n");
}

void encabezadoDeLista() {
    printf("\n%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
}

void inicializarLista(alumno lista[], short tam) {
    /*
        bEstado = 0     ->  Slot vacío
        bEstado = 1     ->  Slot ocupado
        bEstado = -1    ->  Slot ocupado, pero reemplazable
    */
    for ( ; tam>0 ; tam--) {
        lista[tam-1].bEstado = 0;
    }
}

void mostrarAlumno(alumno lista[], short dir) {
    printf("%4d\t" , lista[dir].legajo);
    printf("%15s\t" , lista[dir].nombre);
    printf("%6hi\t" , lista[dir].nota);
    printf("%8.2f" , lista[dir].altura);
    printf("\n");
}

void ordenarAlumnos(alumno lista[], short tam) {
    short f, i;
    alumno alumnoAux;
    for (f=0 ; f<tam-1 ; f++) {
        for (i=f+1 ; i<tam ; i++) {
            if (stricmp(lista[f].nombre,lista[i].nombre)== 1) {
                alumnoAux = lista[f];
                lista[f] = lista[i];
                lista[i] = alumnoAux;
            }
        }
    }
}

void mostrarListaDeAlumnos(alumno lista[], short tam) {
    short f;
    encabezadoDeLista();
    for (f=0 ; f<tam ; f++) {
        if (lista[f].bEstado==1){
            mostrarAlumno(lista, f);
        }
    }
}

short buscarLibre(alumno lista[], short tam) {
    short index = -1;
    short f;
    for (f=0 ; f<tam ; f++) {
        if (lista[f].bEstado==0) {
            index = f;
            break;
        }
    }
    return index;
}

void cargarAlumno(alumno lista[], short indice) {
    printf("\n");
    lista[indice].legajo = getIntBetween(1000, 9999, "Legajo (4 cifras):\t");

    getString(lista[indice].nombre,"Nombre:\t\t\t",NOMBRE);
    primerasLetrasMayusculas(lista[indice].nombre);

    lista[indice].nota = getShortBetween(1, 10, "Nota (1-10):\t\t");
    lista[indice].altura = getFloatBetween(0.5, 2.5, "Altura (0.50-2.50):\t");

    lista[indice].bEstado = 1;
}

void hardcodeAlumno(alumno lista[]) {
    int legajo[4] = {1000, 1001, 1002, 1003};
    char nombre[4][NOMBRE] = {"Pepe Mediocre", "Ricardo Ruben", "Macri Comunista", "McHelicoptero"};
    short nota[4] = {1, 2, 3, 4};
    float altura[4] = {1.11, 1.22, 1.33, 1.44};

    short f;
    for (f=0 ; f<4 ; f++) {
        lista[f].legajo = legajo[f];
        strcpy(lista[f].nombre, nombre[f]);
        lista[f].nota = nota[f];
        lista[f].altura = altura[f];
        lista[f].bEstado = ALTA;
    }

}

void darAlumnoDeBaja(alumno lista[], short tam) {
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

        printf("\n");
        if (pregunta("Dar de baja?\t")) {
            lista[tam].bEstado = BAJA;
            printf("\n\nAlumno dado de baja\n");
        }

    } else {
        printf("\nNo se encontr%c el legajo %d\n" , 162, legajo);
    }

}

void programa() {

    alumno listaDeAlumnos[LISTA];
    short opcion;
    short indice;

    inicializarLista(listaDeAlumnos, LISTA);
    hardcodeAlumno(listaDeAlumnos);
    do {

        menu();

        opcion = getShort("Ingrese opcion:\t");
        switch (opcion) {
            case 1 : {
                indice = buscarLibre(listaDeAlumnos, LISTA);
                cargarAlumno(listaDeAlumnos, indice);
                pausaYClear();
                break;
            }
            case 2 : {
                ordenarAlumnos(listaDeAlumnos, LISTA);
                mostrarListaDeAlumnos(listaDeAlumnos, LISTA);
                pausaYClear();
                break;
            }
            case 3 : {
                darAlumnoDeBaja(listaDeAlumnos, LISTA);
                pausaYClear();
                break;
            }
            case 4 : {
                modificarDatos(listaDeAlumnos, LISTA);
                system("cls");
                break;
            }
            case 5 : {
                extras(listaDeAlumnos, LISTA);
                system("cls");
                break;
            }
            case 6 : { break; } // Terminar programa
            default : {
                printf("\nOpci%cn inv%clida\n" , 162, 160);
                pausaYClear();
            }
        }

    } while (opcion!=6);
}
