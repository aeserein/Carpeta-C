#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "amb.h"
#include "extras.h"
#include "funciones/ingresos.h"
#include "funciones/flow.h"

void extras(alumno lista[], short tam) {
    short opcion;
    system("cls");

    do {
        printf("1. Mostrar alumnos aprobados\n");
        printf("2. Mostrar los alumnos que se llaman Ju%cn\n", 160);
        printf("3. Mostrar alumnos por letra\n");
        printf("4. Mostrar alumno/s con la mejor nota\n");
        printf("5. Mostrar el m%cs mediocre\n" , 160);
        printf("   -----------------------------------------------\n");
        printf("6. Atr%cs\n\n", 160);
        opcion = getShort("Ingrese opcion:\t");

        switch(opcion) {
            case 1 : {
                mostrarAprobados(lista, tam);
                pausaYClear();
                break;
            }
            case 2 : {
                mostrarJuanes(lista, tam);
                pausaYClear();
                break;
            }
            case 3 : {
                mostrarAlumnosPorLetra(lista, tam);
                pausaYClear();
                break;
            }
            case 4 : {
                mostrarMejorNota(lista, tam);
                pausaYClear();
                break;
            }
            case 5 : {
            }
        }

    } while (opcion!=6);

}

void mostrarAprobados(alumno lista[], short tam) {
    short f;
    encabezadoDeLista();
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nota>=6 && lista[f].bEstado==1) {
            mostrarAlumno(lista, f);
        }
    }
}

void mostrarJuanes(alumno lista[], short tam) {
    short f;
    encabezadoDeLista();
    for (f=0 ; f<tam ; f++) {
        if(!strcmp(lista[f].nombre,"Juan") || !strcmp(lista[f].nombre,"Juán") ) {
            mostrarAlumno(lista, f);
        }
    }
}

void mostrarAlumnosPorLetra(alumno lista[], short tam) {
    char letra;
    short f;

    fflush(stdin);
    scanf("%c" , &letra);
    letra = toupper(letra);
    printf("Alumnos con la letra %c\n\n", letra);

    encabezadoDeLista();
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nombre[0]==letra) {
            mostrarAlumno(lista, f);
        }
    }
}

void mostrarMejorNota(alumno lista[], short tam) {
    short f;
    short mejorNota = 0;
    for (f=0 ; f<tam ; f++) {
        if (lista[f].nota>mejorNota) mejorNota=lista[f].nota;
    }
    encabezadoDeLista();
    for (f=0 ; f<tam ; f++) {
        if(lista[f].nota==mejorNota) {
            mostrarAlumno(lista, f);
        }
    }
}

void elMasMediocre(alumno lista[], short tam) {
    for ( ; tam>0 ; tam--) {
        if (lista[tam-1].legajo==1000 && !strcmp(lista[tam-1].nombre, "Pepe") && lista[tam-1].nota==5 && lista[tam-1].altura==1.75) {
            encabezadoDeLista();
            mostrarAlumno(lista, tam-1);
            break;
        }
    }
}
