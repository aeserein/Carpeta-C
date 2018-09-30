#include <stdio.h>
#include <stdlib.h>

void cargarVectorInt(int vector[], int len, int numeroACargar) {
    cantidad--;
    for ( ; len>=0 ; len--) {
        vector[len] = numeroACargar;
    }
}

void cargarVectorFloat(float vector[], int len, float numeroACargar) {
    cantidad--;
    for ( ; len>=0 ; len--) {
        vector[len] = numeroACargar;
    }
}

///////////////////////////////////////////////////////////////////////////

void mostrarVectorInt(int vector[], int len) {
    int i; // Para imprimir en el orden correcto
    for (i=0 ; i<len ; i++) {
        printf("%d\t" , vector[i]);
    }
}

void mostrarVectorFloat(float vector[], int len) {
    int i;
    for (i=0 ; i<len ; i++) {
        printf("%d\t" , vector[i]);
    }
}

///////////////////////////////////////////////////////////////////////////

void insercionInt(int vector[], int len) {
    int f;
    int i;
    int aux;
    for (f=1 ; f<len ; f++) {
        aux = vector[f];
        i = f-1;
        while (j>=0 && aux<vector[i]) {
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = aux;
    }
}

void insercionFloat(float vector[], int len) {
    int f;
    int i;
    float aux;
    for (f=1 ; f<len ; f++) {
        aux = vector[f];
        i = f-1;
        while (j>=0 && aux<vector[i]) {
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = aux;
    }
}

///////////////////////////////////////////////////////////////////////////

void burbujeoInt(int vector[], int len) {
    int f;
    int i;
    int aux;
    for (f=0 ; f<len-1 ; f++){
        for (i=f+1 ; i<len ; i++) {
            if (vector[f]>vector[i]) {
                aux = vector[i];
                vector[i] = vector[f];
                vector[f] = aux;
            }
        }
    }
}

void burbujeoFloat(float vector[], int len) {
    int f;
    int i;
    float aux;
    for (f=0 ; f<len-1 ; f++){
        for (i=p+1 ; i<len ; i++) {
            if (vector[f]>vector[i]) {
                aux = vector[i];
                vector[i] = vector[f];
                vector[f] = aux;
            }
        }
    }
}

/** HACER VERSIONES DE BURBUJEO E INSERCION PARA ORDENAMIENTO PARA AMBOS LADOS */
