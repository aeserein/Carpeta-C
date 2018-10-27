#ifndef GDM_ESTRUCTURA_H_INCLUDED
#define GDM_ESTRUCTURA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE 20

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

int persona_setAltura(persona *puntero, float altura);
float persona_getAltura(persona *puntero);

//////////////////////////////////////////////////////////////////////////////////////////

int removerPersona(persona *puntero);
int removerArrayDePersonas(persona *puntero, int cantidad);

//////////////////////////////////////////////////////////////////////////////////////////

void mostrarPersona(persona*);

#endif // GDM_ESTRUCTURA_H_INCLUDED
