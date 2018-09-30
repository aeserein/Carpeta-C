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

void insercionIntCreciente(int vector[], int len) {
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

void insercionIntDereciente(int vector[], int len) { // Sin checkear
    int f;
    int i;
    int aux;
    for (f=1 ; f<len ; f++) {
        aux = vector[f];
        i = f-1;
        while (j>=0 && aux>vector[i]) {
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = aux;
    }
}

void insercionFloatCreciente(float vector[], int len) {
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

void insercionFloatCreciente(float vector[], int len) { // Sin checkear
    int f;
    int i;
    float aux;
    for (f=1 ; f<len ; f++) {
        aux = vector[f];
        i = f-1;
        while (j>=0 && aux>vector[i]) {
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = aux;
    }
}

///////////////////////////////////////////////////////////////////////////

void burbujeoIntCreciente(int vector[], int len) {
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

void burbujeoIntDereciente(int vector[], int len) { // Sin checkear
    int f;
    int i;
    int aux;
    for (f=0 ; f<len-1 ; f++){
        for (i=f+1 ; i<len ; i++) {
            if (vector[f]<vector[i]) {
                aux = vector[i];
                vector[i] = vector[f];
                vector[f] = aux;
            }
        }
    }
}

void burbujeoFloatCreciente(float vector[], int len) {
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

void burbujeoFloatDereciente(float vector[], int len) { //Sin checkear
    int f;
    int i;
    float aux;
    for (f=0 ; f<len-1 ; f++){
        for (i=p+1 ; i<len ; i++) {
            if (vector[f]<vector[i]) {
                aux = vector[i];
                vector[i] = vector[f];
                vector[f] = aux;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////

int calcularIndiceMinimo(int array[], int size) {
    int indice=1;
    int minimo = array[0];
    int indiceMinimo = 0;

    for ( ; indice < size ; indice++) {

       if(array[indice] < minimo) {
           minimo = array[indice];
           indiceMinimo = indice;
       }

    }
    return indiceMinimo;
}

int calcularIndiceMaximo(int array[], int size) {
    int indice=1;
    int maximo = array[0];
    int indiceMaximo = 0;

    for ( ; indice < size ; indice++) {

       if(array[indice] > maximo) {
           maximo = array[indice];
           indiceMaximo = indice;
       }

    }
    return indiceMaximo;
}
