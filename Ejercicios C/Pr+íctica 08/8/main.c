#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sAlumnos.h"
#define NOMBRE 50
#define T 4

/*  REHACER EL EJERCICIO DE LOS ALUMNOS
 *  Para máximos, mínimos, etc, guardar lo que se busca en una variable y pasar por el array de alumnos con un for buscando la condicion
 *  Intentar no crear nuevas variables al pedo
 *  En modificar el nombre, eliminar la opcion de ingresar legajo como nuevo alumno
 *  Tratar de agregar nuevas huevadas a la funcion de modificar cosas
 */

int main() {

    eAlumno miAlumno = {1000, "Juan", 1.70, 100}; //Por extensión se puede definir en la declaracion y en el mismo orden
    eAlumno otroAlumno;

    mostrarAlumno(miAlumno);
    printf("\n\n");
    printf("%d", miAlumno); //La primera variable está al comienzo de la estructura
    printf("\n\n");
    printf("%d", sizeof(miAlumno)); //Sumatoria de todos los bytes que ocupa la estructura. Redondea de a cuatro

    miAlumno = cargarAlumno();
    mostrarAlumno(miAlumno);

    otroAlumno = miAlumno; // Copio todos los datos de una estructura a otra

    mostrarAlumno(otroAlumno);
    printf("\n---------------------------------------------------------------------------");

    eAlumno miListaDeAlumnos[T]; // Array de tipo eAlumno

    cargarListadoDeAlumnos(miListaDeAlumnos, T);
    mostrarListadoDeAlumnos(miListaDeAlumnos, T);
    printf("\n");
    printf("\n---------------------------------------------------------------------------");
    printf("\n-------------------------Ordenar alumnos-----------------------------------");
    printf("\n---------------------------------------------------------------------------");
    ordenarAlumnos(miListaDeAlumnos, T);

    printf("\n");
    return 0;

}
