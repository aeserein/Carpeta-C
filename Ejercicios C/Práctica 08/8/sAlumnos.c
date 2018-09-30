#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sAlumnos.h"

void cargarListadoDeAlumnos(eAlumno arrayDeAlumnos[], int tamanio) {
    short f;
    for (f=0 ; f<tamanio ; f++) {
        arrayDeAlumnos[f] = cargarAlumno();
    }
}

void mostrarListadoDeAlumnos(eAlumno arrayDeAlumnos[], int tamanio) {
    printf("\n");
    short f;
    for (f=0 ; f<tamanio ; f++) {
        mostrarAlumno(arrayDeAlumnos[f]);
    }
}

void mostrarAlumno(eAlumno unAlumno) {
    printf("%d   %s   %.2f   %d \n" , unAlumno.legajo, unAlumno.nombre, unAlumno.altura, unAlumno.nota);
}

eAlumno cargarAlumno() {
    eAlumno unAlumno;
    printf("\n\nIngrese legajo:\t");
    scanf("%d" , &unAlumno.legajo);
    printf("Ingrese nombre:\t");
    fflush(stdin);
    gets(unAlumno.nombre);
    printf("Ingrese altura:\t");
    scanf("%f" , &unAlumno.altura);
    printf("Ingrese nota:\t");
    scanf("%hi" , &unAlumno.nota);
    return unAlumno;
}

void ordenarAlumnos(eAlumno arrayDeAlumnos[], int tamanio) {
    short f, i;
    eAlumno alumnoAux;
    for (f=0 ; f<tamanio-1 ; f++) {
        for (i=f+1 ; i<tamanio ; i++) {
            if ( stricmp(arrayDeAlumnos[f].nombre,arrayDeAlumnos[i].nombre)== 1) {
                alumnoAux = arrayDeAlumnos[f];
                arrayDeAlumnos[f] = arrayDeAlumnos[i];
                arrayDeAlumnos[i] = alumnoAux;
            }
        }
    }
    mostrarListadoDeAlumnos(arrayDeAlumnos, tamanio);
}
