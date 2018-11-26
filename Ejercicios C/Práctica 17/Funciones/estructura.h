#ifndef estructura_H_INCLUDED
#define estructura_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flow.h"
#define NOMBRE 128

typedef struct {
    int id;
    char variableString[NOMBRE];
    int variableInt;
    float variableFloat;
} Estructura;

Estructura* estructura_new();
Estructura* estructura_newParametros(int *id, char* variableString, int *variableInt, float *variableFloat);
int estructura_delete(Estructura *puntero);

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setId(Estructura* this, int id);
int estructura_getId(Estructura* this);

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableString(Estructura* this, char* variableString);
char* estructura_getVariableString(Estructura* this);

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableInt(Estructura* this, int variableInt);
int estructura_getVariableInt(Estructura* this);

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableFloat(Estructura* this, float variableFloat);
float estructura_getVariableFloat(Estructura* this);

/////////////////////////////////////////////////////////////////////////////////////

int estructura_print(Estructura *puntero);
int estructura_printOne(Estructura *puntero);
void estructura_printFromStack(int *id, char *variableString, int *variableInt, float *variableFloat);
int estructura_DEBUG_printMemory(Estructura *puntero);

/////////////////////////////////////////////////////////////////////////////////////

void list_header(void);
void list_end(void);

/////////////////////////////////////////////////////////////////////////////////////

int sortByID(void *e1, void *e2);
int sortByString(void *e1, void *e2);
int sortByInt(void *e1, void *e2);
int sortByFloat(void *e1, void *e2);

int intMasDe10(void *elemento);
int filtrarPorLetra(void *elemento, char letra);
int filtrarLimiteVariableInt(void *elemento, int limite);

#endif // estructura_H_INCLUDED
