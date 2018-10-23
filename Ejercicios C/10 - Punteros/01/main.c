#include <stdio.h>
#include <stdlib.h>

void cargar(int *pVector) {
    short f;
    for (f=0 ; f<20 ; f++) {
        scanf("%d", (pVector+f));
    }
}

void mostrar(int *pVector) {
    short f;
    for (f=0 ; f<20 ; f++) {
        printf("%d\n", *(pVector+f));
    }
}

int main() {

    printf("Carga y muestra un vector de 20 enteros por punteros.\n\n");

    int vector[20];
    short f;

    for (f=0 ; f<20 ; f++) {
        vector[f] = 0;
    }
    printf("Ingresar 20 valores del vector:\n\n");
    cargar(&vector);

    printf("\nMostrar array\n");
    mostrar(&vector);

    return 0;
}

