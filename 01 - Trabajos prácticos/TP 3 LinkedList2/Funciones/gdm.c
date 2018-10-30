#include "gdm.h"

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
        strcpy(puntero->nombre, " ");
        puntero->edad = -1;
        puntero->altura = -1;
    }
    return puntero;
}

persona* nuevaPersonaFull(int id, char nombre[NOMBRE], int edad, float altura) {
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

int setNombre(persona* puntero, char *nombre) {
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

int setEdad(persona *puntero, int edad) {
    int debug = 0;
    if (puntero!=NULL) {
        puntero->edad = edad;
        debug = 1;
    }
    return debug;
}

int setEdadBetween(persona *puntero, int edad, int min, int max) {
    int debug = 0;
    if (puntero!=NULL && edad>=min && edad<=max) {
        puntero->edad = edad;
        debug = 1;
    }
    return debug;
}

int getEdad(persona *puntero) {
    int edad = -1;
    if (puntero!=NULL) {
        edad = puntero->edad;
    }
    return edad;
}

//////////////////////////////////////////////////////////////////////////////////////////

int setAltura(persona *puntero, float altura) {
    int debug = 0;
    if (puntero!=NULL) {
        puntero->altura = altura;
        debug = 1;
    }
    return debug;
}

int setAlturaBetween(persona *puntero, float altura, float max, float min) {
    int debug = 0;
    if (puntero!=NULL && altura>=min && altura<=max) {
        puntero->altura = altura;
        debug = 1;
    }
    return debug;
}

float getAltura(persona *puntero) {
    float altura = -1;
    if (puntero!=NULL) {
        altura = puntero->altura;
    }
    return altura;
}

//////////////////////////////////////////////////////////////////////////////////////////

int cargarDatos(persona *puntero, int id, char *nombre, int edad, float altura) {
    int debug = 0;
    if (puntero!=NULL) {
        puntero->id = id;
        strcpy(puntero->nombre, nombre);
        puntero->edad = edad;
        puntero->altura = altura;
        debug = 1;
    }
    return debug;
}

int cargarDatosExceptoID(persona *puntero, char *nombre, int edad, float altura) {
    int debug = 0;
    if (puntero!=NULL) {
        strcpy(puntero->nombre, nombre);
        puntero->edad = edad;
        puntero->altura = altura;
        debug = 1;
    }
    return debug;
}

int modificarNombre(persona *puntero) {
    if (puntero!=NULL) {
        char nombre[NOMBRE];
        getString(nombre, "Ingrese nombre:   ", NOMBRE);
        strcpy(puntero->nombre, nombre);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////

int buscarPorID(persona *puntero, int limite, int id) {
    int retorno = -1;
    int i;
    if(limite>0 && puntero!=NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(puntero->id == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int tieneDatosEstaPersona(persona *puntero) {
    int tieneDatos = 0;
    while (puntero!=NULL) {
        if (puntero->id==-1) {
            break;
        }
        if (stricmp(puntero->nombre, " ") &&
            puntero->altura!=-1 &&
            puntero->edad!=-1) {

            tieneDatos = 1;
        }
    }
    return tieneDatos;
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

void mostrarUno(persona *puntero) {
    printf("ID: %d    ", puntero->id);
    printf("NOMBRE: %s    ", puntero->nombre);
    printf("EDAD: %d    ", puntero->edad);
    printf("ALTURA: %.2f\n", puntero->altura);
}

void mostrarArray(persona *puntero, int limite) {
    short f;
    if(limite>0 && puntero!=NULL) {

        for(f=0; f<limite; f++) {
            if (puntero->id>=0) {
                mostrarUno(puntero+f);
            }
        }
    }
}

void mostrarArrayFull(persona *puntero, int limite) {
    short f;
    if(limite > 0 && puntero!=NULL) {

        for(f=0; f<limite; f++) {
            printf("F %d", f);
            mostrarUno(puntero+f);
        }
    }
}
