#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones\strings.h"
#include "funciones\ingresos.h"
#include "funciones\flow.h"
#define DIR 10
#define NOMBRE 61

void cargaSecuencial(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {

    short f;

    for (f=0 ; f<T ; f++) {
        legajo[f] = ingresarInt("Ingresar legajo:\t");
        ingresarString(nombre[f], "Ingresar nombre:\t", NOMBRE);
        primerasLetrasMayusculas(nombre[f]);
        nota[f] = ingresarInt("Ingresar nota:\t");
        altura[f] = ingresarFloat("Ingresar altura:\t");
    }

}

void cargaAleatoria(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short posicion) {
    if (posicion<DIR) {
        legajo[posicion] = ingresarInt("Ingresar legajo:\t");
        ingresarString(nombre[posicion], "Ingresar nombre:\t", NOMBRE);
        primerasLetrasMayusculas(nombre[posicion]);
        nota[posicion] = ingresarInt("Ingresar nota:\t");
        altura[posicion] = ingresarFloat("Ingresar altura:\t");
    } else {
        printf("Espacio insuficiente, no puede ingresar m%cs alumnos." , 160);
    }

}

void mostrarAlumnos(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {

    short f;

    printf("\n");
    printf("%4s \t %15s \t %2s \t %s", "Legajo" , "Nombre" , "Nota" , "Altura");
    printf("\n");

    for (f=0 ; f<T ; f++) {
        printf("%4d\t" , legajo[f]);
        printf("%15s\t" , nombre[f]);
        printf("%2d\t", nota[f]);
        printf("%.2f\t", altura[f]);
        printf("\n");
    }
}

void ordenarAlumnos(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short columnas) {
    int f;
	int i;
	int legajoAux;
	int notaAux;
	float alturaAux;
	short bHizoSwap = 0;
	for (f=0 ; f<columnas-1 ; f++) {
		for (i=f+1 ; i<columnas ; i++) {
			bHizoSwap = ordenarDosStrings_Bandera(nombre[f], nombre[i]);
			if (bHizoSwap) {

                legajoAux = legajo[f];
                legajo[f] = legajo [i];
                legajo[i] = legajoAux; //swap de legajo

                notaAux = nota[f];
                nota[f] = nota[i];
                nota[i] = notaAux; //swap de nota

                alturaAux = altura[f];
                altura[f] = altura[i];
                altura[i] = alturaAux;

			}
		}
	}
}

void mostrarJuanes(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {
    short f;
    for (f=0 ; f<T ; f++) {
        if ( !stricmp(nombre[f], "juan") ) {
            printf("%4d\t" , legajo[f]);
            printf("%15s\t" , nombre[f]);
            printf("%2d\t", nota[f]);
            printf("%.2f\t", altura[f]);
            printf("\n");
        }
    }
}

void mostrarAprobados(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {
    short f;
    for (f=0 ; f<T ; f++) {
        if ( nota[f]>=6 ) {
            printf("%4d\t" , legajo[f]);
            printf("%15s\t" , nombre[f]);
            printf("%2d\t", nota[f]);
            printf("%.2f\t", altura[f]);
            printf("\n");
        }
    }
}

void mostrarNombresConP(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {
    short f;
    for (f=0 ; f<T ; f++) {
        if ( nombre[f][0]=='P') {
            printf("%4d\t" , legajo[f]);
            printf("%15s\t" , nombre[f]);
            printf("%2d\t", nota[f]);
            printf("%.2f\t", altura[f]);
            printf("\n");
        }
    }
}

void mostrarMejorNota(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {
    short f;
    short mejorNota = 0;
    short indiceMejorNota;
    for (f=0 ; f<T ; f++) {
        if ( nota[f]>mejorNota ) {
            mejorNota = nota[f];
            indiceMejorNota = f;
        }
    }
    printf("%4d\t" , legajo[indiceMejorNota]);
    printf("%15s\t" , nombre[indiceMejorNota]);
    printf("%2d\t", nota[indiceMejorNota]);
    printf("%.2f\t", altura[indiceMejorNota]);
    printf("\n");
}

void mostrarElMasMediocre(int legajo[], char nombre[][NOMBRE], int nota[], float altura[], short T) {
    short f;
    for (f=0 ; f<T ; f++) {
        if ( legajo[f]==1000 && !stricmp(nombre[f],"Pepe") && nota[f]==5 && altura[f]==1.75 ) {
            printf("%4d\t" , legajo[f]);
            printf("%15s\t" , nombre[f]);
            printf("%2d\t", nota[f]);
            printf("%.2f\t", altura[f]);
            printf("\n");
        }
    }
}

int modificarNota(int legajo[], int nota[], char nombre[][NOMBRE], short T) {
    short legajoACambiar;
    short indexACambiar;
    legajoACambiar = ingresarInt("Ingresar legajo:\t");
    for (  ; T>0 ; T--) {
        if ( legajoACambiar==legajo[T-1] ) {
            indexACambiar = T-1;
            break;
        } else {
            printf("\nEse legajo no est%c en el sistema.\n", 160);
            printf("%cDesea ingresarlo como nuevo alumno? S/N\t" , 168);
            return (siONo());
        }
    }
    printf("\n");
    printf("%d\t%s\t%d" , legajo[indexACambiar] , nombre[indexACambiar], nota[indexACambiar]);
    nota[indexACambiar] = ingresarInt("Ingrese nueva nota:\t");
    printf("\nNota cambiada\n");
    printf("\n");
    printf("%d\t%s\t%d" , legajo[indexACambiar] , nombre[indexACambiar], nota[indexACambiar]);
    return 0;
}


void programa() {

    int legajo[DIR];
    char nombre[DIR][NOMBRE];   // [filas][columnas]
    int nota[DIR];
    float altura[DIR];

    int opcion;
    short auxCarga = 0;

    do {
        printf("1. Ingresar un alumno.\n");
        printf("2. Mostrar todos los alumnos (test).\n");
        printf("3. Ordenar y mostrar los alumnos.\n" , 160);
        printf("4. Mostrar los alumnos aprobados.\n" , 160);
        printf("5. Mostrar los alumnos que se llaman Ju%cn.\n" , 160);
        printf("6. Mostrar los alumnos que empiezan con 'P'\n");
        printf("7. Mostrar alumno/s con la mejor nota.\n");
        printf("8. Mostrar el alumno m%cs mediocre.\n" , 160);
        printf("9. Modificar la nota de un alumno.\n");
        printf("   ------------------------------------------------------\n");
        printf("10. Salir\n\n");
        opcion = ingresarInt("Seleccione opcion:\t");

        switch (opcion) {
            case 1 : {
                printf("\n  **Cargar alumno**\n\n");
                cargaAleatoria(legajo, nombre, nota, altura, auxCarga);
                if (auxCarga<10) {
                    auxCarga++;
                }
                break;
            }
            case 2 : {
                printf("\n  **Lista de alumnos**\n\n");
                mostrarAlumnos(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 3 : {
                printf("\n  **Lista ordenada de alumnos**\n\n");
                ordenarAlumnos(legajo, nombre, nota, altura, auxCarga);
                mostrarAlumnos(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 4 : {
                printf("\n  **Lista de alumnos aprobados**\n\n");
                mostrarAprobados(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 5 : {
                printf("\n  **Lista de alumnos que se llaman Ju%cn**\n\n" , 160);
                mostrarJuanes(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 6 : {
                printf("\n  **Lista de alumnos con la letra 'P'**\n\n");
                mostrarNombresConP(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 7 : {
                printf("\n  **Mejor alumno**\n\n");
                mostrarMejorNota(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 8 : {
                printf("\n  ** El m%cs mediocre!!! **\n\n" , 160);
                mostrarElMasMediocre(legajo, nombre, nota, altura, auxCarga);
                break;
            }
            case 9 : {
                if (auxCarga!=0){
                    printf("\n  **Modificar nota (por legajo)**\n\n" , 160);
                    if ( modificarNota(legajo, nota, nombre, auxCarga) ) {
                        cargaAleatoria(legajo, nombre, nota, altura, auxCarga);
                        if (auxCarga<10) {
                            auxCarga++;
                        }
                    }
                } else {
                    printf("\nNo ha ingresado ning%cn alumno a%cn.\n" , 163, 163);
                    printf("%cDesea ingresar un alumno nuevo? S/N\t" , 168);
                    if (siONo()) {
                        printf("\n\n");
                        cargaAleatoria(legajo, nombre, nota, altura, auxCarga);
                        auxCarga++;
                    }
                }
            }
            case 10 : {
                break;
            }
            default : {
                printf("Opci%cn inv%clida" , 162 , 160);
            }
        }

        if (opcion!=10) {
           pausaYClear();
        }

    } while (opcion!=10);

    printf("\n");
    //fin
}
