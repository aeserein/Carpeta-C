#include <stdio.h>
#include <stdlib.h>
#include "../../../Bibliotecas/array.h"
#include "../../../Bibliotecas/ingresos.h"
#include "../../../Bibliotecas/strings.h"
#include "../../../Bibliotecas/flow.h"
#define VECTOR_TAMANHO 50

int main() {

    short opcion;
    int vector[VECTOR_TAMANHO];
    int numeroAIngresar;
    short f = 0;

    do {
        printf("1. Cargar vector\n"
               "2. Ordenar vector\n"
               "3. Mostrar vector\n"
               "   -------------------\n"
               "4. Salir\n\n");

        opcion = getShortBetween(1,4, "Ingrese opcion:   ");
        switch (opcion) {
            case 1 : {
                numeroAIngresar = getInt("NUMERO:   ");
                setValue_Int(&vector[0], f, numeroAIngresar);
                f++;
                pausaYClear();
                break;
            }
            case 2 : {
                burbujeoIntCreciente(&vector[0], VECTOR_TAMANHO);
                printf("       --Vector ordenado--");
                pausaYClear();
                break;
            }
            case 3 : {
                mostrarVectorInt(&vector[0], VECTOR_TAMANHO);
                pausaYClear();
                break;
            }
            case 4 : { /*Salir*/ }
        }
    } while (opcion!=4);
    return 0;

}
