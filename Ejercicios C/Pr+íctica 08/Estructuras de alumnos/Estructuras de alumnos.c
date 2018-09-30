#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructuras de alumnos.h"
#include "Funciones/ingresos.h"
#include "Funciones/flow.h"
#include "Funciones/strings.h"
#define LISTA 10
#define NOMBRE 50

void inicializarLista(eAlumno lista[], short tam) {
    for ( ; tam>0 ; tam--) {
        lista[tam-1].legajo = -1;
        strcpy(lista[tam-1].nombre,"");
        lista[tam-1].nota = -1;
        lista[tam-1].altura = -1;
    }
}

void ingresarAlumno(eAlumno lista[], short tam) {
    short direccion;
    direccion = getShortBetween(1, LISTA, "Ingrese ubicacion en la lista (1-10):\t");
    while (lista[direccion-1].legajo!=-1) {
        direccion = getShortBetween(1, LISTA, "Esa ubicacion se encuentra ocupada. Intente nuevamente:\t");
    }
    printf("\nAlumno %d:\n", direccion);
    lista[direccion-1].legajo = getIntBetween(1000, 9999, "Legajo (4 digitos):\t");
    getString(lista[direccion-1].nombre, "Nombre:\t", NOMBRE);
    primerasLetrasMayusculas(lista[direccion-1].nombre);
    lista[direccion-1].nota = getShortBetween(1, 10, "Nota (1-10):\t");
    lista[direccion-1].altura = getFloatBetween(0.5, 2.5, "Altura:\t");
}

void ordenarAlumnos(eAlumno arrayDeAlumnos[], short tam) {
    short f, i;
    eAlumno alumnoAux;
    for (f=0 ; f<tam-1 ; f++) {
        for (i=f+1 ; i<tam ; i++) {
            if (stricmp(arrayDeAlumnos[f].nombre,arrayDeAlumnos[i].nombre)== 1) {
                alumnoAux = arrayDeAlumnos[f];
                arrayDeAlumnos[f] = arrayDeAlumnos[i];
                arrayDeAlumnos[i] = alumnoAux;
            }
        }
    }
}

void mostrarLista(eAlumno lista[], short tam) {
    short f;
    printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
    for (f=0 ; f<tam ; f++) {
        if(lista[f].legajo!=-1) {
            printf("%4d\t" , lista[f].legajo);
            printf("%15s\t" , lista[f].nombre);
            printf("%6hi\t" , lista[f].nota);
            printf("%8.2f" , lista[f].altura);
            printf("\n");
        }
    }
}

void mostrarAlumnosConP(eAlumno lista[], short tam) {
    short f;
    printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nombre[0]=='P') {
            printf("%4d\t" , lista[f].legajo);
            printf("%15s\t" , lista[f].nombre);
            printf("%6hi\t" , lista[f].nota);
            printf("%8.2f" , lista[f].altura);
            printf("\n");
        }
    }
}

void mostrarAprobados(eAlumno lista[], short tam) {
    short f;
    printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nota>=6) {
            printf("%4d\t" , lista[f].legajo);
            printf("%15s\t" , lista[f].nombre);
            printf("%6hi\t" , lista[f].nota);
            printf("%8.2f" , lista[f].altura);
            printf("\n");
        }
    }
}

void mostrarJuanes(eAlumno lista[], short tam) {
    short f;
    printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
    for (f=0 ; f<tam ; f++) {
        if(!strcmp(lista[f].nombre,"Juan") || !strcmp(lista[f].nombre,"Juán") ) {
            printf("%4d\t" , lista[f].legajo);
            printf("%15s\t" , lista[f].nombre);
            printf("%6hi\t" , lista[f].nota);
            printf("%8.2f" , lista[f].altura);
            printf("\n");
        }
    }
}

void mostrarMejorNota(eAlumno lista[], short tam) {
    short f;
    short mejorNota = 0;
    for (f=0 ; f<tam ; f++) {
        if (lista[f].nota>mejorNota) mejorNota=lista[f].nota;
    }
    printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nota==mejorNota) {
            printf("%4d\t" , lista[f].legajo);
            printf("%15s\t" , lista[f].nombre);
            printf("%6hi\t" , lista[f].nota);
            printf("%8.2f" , lista[f].altura);
            printf("\n");
        }
    }
}

void elMasMediocre(eAlumno lista[], short tam) {
    for ( ; tam>0 ; tam--) {
        if (lista[tam-1].legajo==1000 && !strcmp(lista[tam-1].nombre, "Pepe") && lista[tam-1].nota==5 && lista[tam-1].altura==1.75) {
            printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
            printf("%4d\t" , lista[tam-1].legajo);
            printf("%15s\t" , lista[tam-1].nombre);
            printf("%6hi\t" , lista[tam-1].nota);
            printf("%8.2f" , lista[tam-1].altura);
            printf("\n");
            break;
        }
    }
}

void modificarNota(eAlumno lista[], short tam) {
    short legajoACambiar;
    short bandera = 0;
    legajoACambiar = getShortBetween(1000,9999,"Ingrese legajo del alumno:\t");
    tam--;
    for ( ; tam>=0 ; tam--) {
        if (lista[tam].legajo==legajoACambiar) {
            printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
            printf("%4d\t" , lista[tam].legajo);
            printf("%15s\t" , lista[tam].nombre);
            printf("%6hi\t" , lista[tam].nota);
            printf("%8.2f" , lista[tam].altura);
            printf("\n");
            bandera = 1;
            break;
        }
    }
    if (bandera) {
        lista[tam].nota = getShortBetween(1,10, "Ingrese nueva nota:\t");
        printf("\n  Nota modificada\n\n!");
        printf("%4s\t%15s\t%6s\t%8s\n", "Legajo" , "Nombre" , "Nota" , "Altura");
        printf("%4d\t" , lista[tam].legajo);
        printf("%15s\t" , lista[tam].nombre);
        printf("%6hi\t" , lista[tam].nota);
        printf("%8.2f" , lista[tam].altura);
        printf("\n");
    } else {
        printf("No se encontr%c el legajo %hi", 162, legajoACambiar);
    }

}

void programa() {

    short opcion;
    eAlumno listaDeAlumnos[LISTA];
    inicializarLista(listaDeAlumnos, LISTA);

    do {
        printf("1. Ingresar un alumno.\n");
        printf("2. Mostrar todos los alumnos.\n");
        printf("3. Mostrar los alumnos ordenados (TEST).\n");
        printf("4. Mostrar los alumnos aprobados.\n");
        printf("5. Mostrar los alumnos que se llaman Ju%cn.\n" , 160);
        printf("6. Mostrar los alumnos que empiezan con 'P'\n");
        printf("7. Mostrar alumno/s con la mejor nota.\n");
        printf("8. Mostrar el alumno m%cs mediocre.\n" , 160);
        printf("9. Modificar la nota de un alumno.\n");
        printf("   ------------------------------------------------------\n");
        printf("10. Salir\n\n");
        opcion = getInt("Seleccione opcion:\t");

        switch (opcion) {
            case 1 : {
                ingresarAlumno(listaDeAlumnos, LISTA);
                break;
            }
            case 2 : {
                mostrarLista(listaDeAlumnos, LISTA);
                break;
            }
            case 3 : {
                ordenarAlumnos(listaDeAlumnos, LISTA);
                mostrarLista(listaDeAlumnos, LISTA);
                break;
         }
            case 4 : {
                mostrarAprobados(listaDeAlumnos, LISTA);
                break;
            }
            case 5 : {
                mostrarJuanes(listaDeAlumnos, LISTA);
                break;
            }
            case 6 : {
                mostrarAlumnosConP(listaDeAlumnos, LISTA);
                break;
            }
            case 7 : {
                mostrarMejorNota(listaDeAlumnos, LISTA);
                break;
            }
            case 8 : {
                elMasMediocre(listaDeAlumnos, LISTA);
                break;
            }
            case 9 : {
                modificarNota(listaDeAlumnos, LISTA);
                break;
            }
            case 10 : {}
            default : {
                printf("Opci%cn no v%clida" , 162, 160);
            }
        }

        if (opcion!=10) {
            pausaYClear();
        }
    } while (opcion!=10);
}
