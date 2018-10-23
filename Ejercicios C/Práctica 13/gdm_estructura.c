#include "gdm_estructura.h"

persona* nuevaPersona() {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));
    return puntero;
}

persona* nuevaPersonaConValores(int id, char nombre[NOMBRE], int edad) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));
    if (puntero!=NULL) {
        puntero->id = id;
        strcpy(puntero->nombre, nombre);
        puntero->edad = edad;
    }
    return puntero;
}

persona* nuevaPersonaVacia() {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));

    puntero->id = -1;
    strcpy(puntero->nombre, " ");
    puntero->edad = -1;
    return puntero;
}

//////////////////////////////////////////////////////////////////////////////////////////

void mostrarPersona(persona *puntero) {
    printf("%d\n%s\n%d\n", puntero->id, puntero->nombre, puntero->edad);
}
