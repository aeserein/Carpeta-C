#include <stdio.h>
#include <stdlib.h>
#include "estructuraGenerica.h"
#define CANTIDAD 10

int main() {

    eGenerica listadoGenerico[CANTIDAD];
    eGen_init(listadoGenerico,CANTIDAD);

    printf( "\n \t muestro el array... esta vacio");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();

    eGen_alta(listadoGenerico,CANTIDAD);
    eGen_alta(listadoGenerico,CANTIDAD);
    printf( "\n \t cargo dos elementos y muestro el array");
    eGen_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();
    eGen_modificacion(listadoGenerico, CANTIDAD, 1);

    printf( "\n \t muestro el array con los borrados y vacios");
    eGen_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();


    return 0;
}
