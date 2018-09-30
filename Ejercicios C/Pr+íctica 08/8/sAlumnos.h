#ifndef SALUMNOS_H_INCLUDED
#define SALUMNOS_H_INCLUDED
#define NOMBRE 50

typedef struct {
    int legajo;
    char nombre[NOMBRE];
    float altura;
    short nota;
} eAlumno;
/*  legajo  4 bytes
    nombre  50 bytes
    float   4 bytes
    short   2 bytes
*/

void cargarListadoDeAlumnos(eAlumno[], int);

void mostrarListadoDeAlumnos(eAlumno[], int);

void mostrarAlumno(eAlumno);

eAlumno cargarAlumno();

void ordenarAlumnos(eAlumno[], int);

#endif // STRUCT_ALUMNOS_H_INCLUDED
