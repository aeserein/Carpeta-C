#include <stdio.h>
#include <stdlib.h>

void cargarVectorInt(int vector[], int cantidad, int numeroACargar) {
    cantidad--;
    for ( ; cantidad>=0 ; cantidad--) {
        vector[cantidad] = numeroACargar;
    }
}

void cargarVectorFloat(float vector[], int cantidad, float numeroACargar) {
    cantidad--;
    for ( ; cantidad>=0 ; cantidad--) {
        vector[cantidad] = numeroACargar;
    }
}

void mostrarVectorInt(int vector[], int cantidad) {
    int i; // Para imprimir en el orden correcto
    for (i=0 ; i<cantidad ; i++) {
        printf("%d\t" , vector[i]);
    }
}

void mostrarVectorFloat(float vector[], int cantidad) {
    int i;
    for (i=0 ; i<cantidad ; i++) {
        printf("%d\t" , vector[i]);
    }
}
