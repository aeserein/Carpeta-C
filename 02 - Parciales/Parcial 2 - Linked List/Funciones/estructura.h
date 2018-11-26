#ifndef estructura_H_INCLUDED
#define estructura_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flow.h"
#define TAM 128

typedef struct {
    int id;
    char nombre[TAM];
    char direccion[TAM];
    int horas;
    int sueldo;
} eEmpleado;

eEmpleado* empleado_new();
eEmpleado* empleado_newSinHoras(int *id, char* nombre, char *direccion);
eEmpleado* empleado_newParametros(int *id, char* nombre, char *direccion, int *horas);
int empleado_delete(eEmpleado *puntero);

/////////////////////////////////////////////////////////////////////////////////////

int empleado_setId(eEmpleado* this, int id);
int empleado_getId(eEmpleado* this);

/////////////////////////////////////////////////////////////////////////////////////

int empleado_setNombre(eEmpleado* this, char* nombre);
char* empleado_getNombre(eEmpleado* this);

int empleado_setDireccion(eEmpleado* this, char* direccion);
char* empleado_getDireccion(eEmpleado* this);

int empleado_setHoras(eEmpleado* this, int horas);
int empleado_getHoras(eEmpleado* this);

int empleado_setSueldo(eEmpleado* this, int sueldo);
int empleado_getSueldo(eEmpleado* this);

/////////////////////////////////////////////////////////////////////////////////////

int empleado_print(eEmpleado *puntero);
int empleado_printSinHoras(eEmpleado *puntero);
int empleado_printOne(eEmpleado *puntero);
void empleado_printFromStack(int*, char*, char*, int*);

/////////////////////////////////////////////////////////////////////////////////////

void list_header(void);
void list_end(void);
void list_headerSinHoras(void);
void list_endSinHoras(void);

/////////////////////////////////////////////////////////////////////////////////////

int sortByID(void *e1, void *e2);
int sortByNombre(void *e1, void *e2);

int filtrarLimite(void *elemento, float limite);

void calcularSueldo(void *elemento);
int getSueldo(void* elemento);

#endif // estructura_H_INCLUDED
