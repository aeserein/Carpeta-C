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
} persona;

persona* nuevaPersona();
persona* nuevaPersonaConValores(int, char[], int);
persona* nuevaPersonaVacia();

//////////////////////////////////////////////////////////////////////////////////////////

short persona_setID(persona*, int);
int persona_getID(persona*);

//////////////////////////////////////////////////////////////////////////////////////////

void mostrarPersona(persona*);

#endif // GDM_ESTRUCTURA_H_INCLUDED
