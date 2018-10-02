#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main() {

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    mostrarListadoSeries(listaDeSeries, TAMSERIE);
    printf("\n\n");
    mostrarListadoUsuarios(listaDeUsuarios, TAMUSUARIO);
    printf("\n\n");
    mostrarListadoUsuariosConSerie(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
    printf("\n\n");
    mostrarCantUsuariosQueMiranCadaSerie(listaDeUsuarios, TAMUSUARIO);
/*
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.
*/




    return 0;
}
