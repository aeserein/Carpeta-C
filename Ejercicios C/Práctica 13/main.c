#include <stdio.h>
#include <stdlib.h>
#include "gdm_estructura.h"
#define CANTIDAD 10

int main() {

    int *pPersona;
    int *pAux;
    short f;

    pPersona = nuevaPersonaVacia();

    for (f=0 ; f<CANTIDAD ; f++) {
        *(pPersona+f) = f*3;
    }

    pAux = agrandarArray(pPersona);
    if (pAux!=NULL) {
        pPersona = pAux;
        for (f=CANTIDAD ; f<CANTIDAD+5 ; f++) {
            *(pPersona+f) = f*3;
        }
        for (f=0 ; f<CANTIDAD+5 ; f++){
            printf("%d\n", *(pPersona+f));
        }
    }
    return 0;
}

int* agrandarArray(punteroOriginal) {
    int *nuevoPuntero;
    nuevoPuntero = (int*)realloc(punteroOriginal, sizeof(persona)*CANTIDAD+5);
    return nuevoPuntero;
}
