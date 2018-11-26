#ifndef ESTRUCTURAPELICULA_H_INCLUDED
#define ESTRUCTURAPELICULA_H_INCLUDED

#include "estructuraDirector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ingresos.h"
#include "strings.h"
#include "flow.h"
#define TAM 50
#define ALTA 1
#define VACIO 0
#define BAJA -1

typedef struct {
    char titulo[TAM];
    int anio;
    char nacionalidad[TAM];
    int director;
    //------------
    int id;
    int estado;
} pelicula;

int pelicula_init(pelicula[],int limite);

void pelicula_hardcode(pelicula arrayPeliculas[]);
int pelicula_estaVacioEsteArray(pelicula[], int);

//////////////////////////////////////////////////////////////////

int pelicula_buscarPorId(pelicula[] ,int limite, int id);
int pelicula_siguienteId(pelicula[] ,int limite);
int pelicula_buscarLugarLibre(pelicula listado[],int limite);

//////////////////////////////////////////////////////////////////

void pelicula_ListaHeader();
void pelicula_listaRenglon();
void pelicula_cierreLista();


//////////////////////////////////////////////////////////////////

void pelicula_mostrarUno(pelicula);
void pelicula_mostrarUnoConDirector(pelicula, director[], int);
void pelicula_mostrarListado(pelicula lista[] ,int limite);
void pelicula_mostrarListadoConDirectores(pelicula listaPel[],int lenPel, director listaDir[], int lenDir);

//////////////////////////////////////////////////////////////////

void pelicula_mostrarMasViejas(pelicula[], int, director[], int);
void pelicula_mostrarPeliculasPorDirector(pelicula[], int, director[], int);
void pelicula_mostrarCuantasDirigio(pelicula[], int, director[], int);
void pelicula_mostrarElQueMasDirigio(pelicula[], int, director[], int);

//////////////////////////////////////////////////////////////////

void pelicula_alta(pelicula[] ,int, director[], int);
void pelicula_baja(pelicula[] ,int, int, director[], int);
void pelicula_borrarPeliculasPorDirector(pelicula[], int, int);
void pelicula_modificar(pelicula[], int, director[], int);

//////////////////////////////////////////////////////////////////

void pelicula_ordenarPorID(pelicula[], int);

#endif // ESTRUCTURAPELICULA_H_INCLUDED
