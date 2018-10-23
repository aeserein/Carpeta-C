#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Funciones/ArrayEmployees.h"

void programaPrincipal(void);

void informar(employee[], int);

void menuDeListado(employee[], int);

void showSalaries(employee[], int);

short menuModificar(employee[], int, int);

void imprimirMenu(void);


#endif // PROGRAMA_H_INCLUDED
