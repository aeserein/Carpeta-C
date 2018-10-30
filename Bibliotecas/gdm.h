#ifndef GDM_H_INCLUDED
#define GDM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresos.h"
#include "strings.h"
#define NOMBRE 20
#define ALTA 1
#define VACIO 0
#define BAJA -1

typedef struct {
    int id;
    char nombre[20];
    int edad;
    float altura;
} persona;

persona* nuevaPersona();
persona* nuevaPersonaVacia();
persona* nuevaPersonaVaciaConID(int id);
persona* nuevaPersonaConValores(int id, char nombre[], int edad, float altura);

//////////////////////////////////////////////////////////////////////////////////////////

persona* nuevoArrayDePersonas(int cuantasPersonas);
persona* cambiarTamanhoDeArrayDePersonas(persona *punteroOriginal, int cantidadOriginal, int cuantasPersonas);

//////////////////////////////////////////////////////////////////////////////////////////

int setID(persona*, int id);
int setIDBetween(persona *puntero, int id, int min, int max);
int getID(persona*);

//////////////////////////////////////////////////////////////////////////////////////////

int setNombre(persona *puntero, char nombre[]);
char* getNombre(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int setEdad(persona *puntero, int edad);
int setEdadBetween(persona *puntero, int edad, int min, int max);
int getEdad(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int setAltura(persona *puntero, float altura);
int setAlturaBetween(persona *puntero, float altura, float max, float min);
float persona_getAltura(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int cargarDatos(persona *puntero, int *id, char *nombre, int *edad, float *altura);
int cargarDatosExceptoID(persona *puntero, char *nombre, int edad, float altura);
int modificarNombre(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int buscarPorID(persona *puntero, int limite, int id);
int tieneDatosEstaPersona(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int removerPersona(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

void mostrarUno(persona *puntero);
void mostrarArray(persona *puntero, int limite);
void mostrarArrayFull(persona *puntero, int limite);

#endif // GDM_ESTRUCTURA_H_INCLUDED
