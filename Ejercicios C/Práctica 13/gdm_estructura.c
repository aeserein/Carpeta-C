#include "gdm_estructura.h"

persona* nuevaPersona() {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));
    return puntero;
}

persona* nuevaPersonaVacia() {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));

    if (puntero!=NULL) {
        puntero->id = -1;
        strcpy(puntero->nombre, " ");
        puntero->edad = -1;
        puntero->altura = -1;
    }
    return puntero;
}

persona* nuevaPersonaVaciaConID(int id) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));

    if (puntero!=NULL) {
        puntero->id = id;
    }
    return puntero;
}

persona* nuevaPersonaConValores(int id, char nombre[NOMBRE], int edad, float altura) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));
    if (puntero!=NULL) {
        puntero->id = id;
        strcpy(puntero->nombre, nombre);
        puntero->edad = edad;
        puntero->altura = altura;
    }
    return puntero;
}

//////////////////////////////////////////////////////////////////////////////////////////

persona* nuevoArrayDePersonas(int cuantasPersonas) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona)*cuantasPersonas);
    return puntero;
}

persona* cambiarTamanhoDeArrayDePersonas(persona *punteroOriginal, int cantidadOriginal, int cuantasPersonas) {
    persona *nuevoPuntero;
    nuevoPuntero = (persona*)realloc(punteroOriginal, sizeof(persona)*(cantidadOriginal+cuantasPersonas));
    if (nuevoPuntero!=NULL) {
        punteroOriginal = nuevoPuntero;
    }
    return punteroOriginal;
}

//////////////////////////////////////////////////////////////////////////////////////////

int setID(persona *puntero, int id) {
    int debug = 0;
    if (puntero!=NULL) {
        puntero->id = id;
        debug = 1;
    }
    return debug;
}

int setIDBetween(persona *puntero, int id, int min, int max) {
    int debug = 0;
    if (puntero!=NULL && id>=min && id<=max) {
        puntero->id = id;
        debug = 1;
    }
    return debug;
}

int getID(persona *puntero) {
    int id = -1;
    if (puntero!=NULL) {
        id = puntero->id;
    }
    return id;
}

//////////////////////////////////////////////////////////////////////////////////////////

int setNombre(persona* puntero, char nombre[]) {
    int debug = 0;
    if (puntero!=NULL) {
        strcpy(puntero->nombre, nombre);
        debug = 1;
    }
    return debug;
}

char* getNombre(persona* puntero) {
    if (puntero!=NULL) {
        return puntero->nombre;
    } else {
        return NULL;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////


int setAltura(persona* puntero, float altura) {
    int debug = 0;
    if (puntero!=NULL) {
        puntero->altura = altura;
        debug = 1;
    }
    return debug;
}

float getAltura(persona* puntero) {
    float altura = -1;
    if (puntero!=NULL) {
        altura = puntero->altura;
    }
    return altura;
}

//////////////////////////////////////////////////////////////////////////////////////////

int removerPersona(persona *puntero) {
    int debug = 0;
    if (puntero!=NULL) {
        free(puntero);
        debug = 1;
    }
    return debug;
}

//////////////////////////////////////////////////////////////////////////////////////////

void mostrarPersona(persona *puntero) {
    printf("ID\t%d\n", puntero->id);
    printf("NOMBRE\t%s\n", puntero->nombre);
    printf("EDAD\t%d\n", puntero->edad);
    printf("ALTURA\t%.2f\n", puntero->altura);
}
