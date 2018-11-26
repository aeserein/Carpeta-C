#ifndef ESTRUCTURADIRECTOR_H_INCLUDED
#define ESTRUCTURADIRECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresos.h"
#include "strings.h"
#include "flow.h"
#define TAM 50
#define ALTA 1
#define VACIO 0
#define BAJA -1

typedef struct {
    char nombre[TAM];
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
    char pais[TAM];
    //------------
    int id;
    int estado;
} director;

int director_init(director[],int limite);
void director_hardcode(director[]);
int director_estaVacioEsteArray(director[], int);

//////////////////////////////////////////////////////////////////

int director_buscarPorId(director[] ,int limite, int id);
int director_siguienteId(director[] ,int limite);
int director_buscarLugarLibre(director listado[],int limite);

//////////////////////////////////////////////////////////////////

void director_ListaHeader();
void director_listaRenglon();
void director_cierreLista();

//////////////////////////////////////////////////////////////////

void director_mostrarUno(director);
void director_mostrarUnoConHeader(director);
void director_mostrarNombreDirector(director);
void director_mostrarListado(director[] ,int limite);

//////////////////////////////////////////////////////////////////

void director_alta(director[] ,int limite);
int director_baja(director[] ,int limite, int id);
void director_modificacion(director[] ,int limite, int id);

void director_ordenarPorID(director[] ,int);

#endif // ESTRUCTURADIRECTOR_H_INCLUDED
