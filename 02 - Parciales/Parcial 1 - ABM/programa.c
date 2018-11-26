#include "programa.h"

void imprimirMenu() {
    printf("1. Alta de pelicula\n"
           "2. Modificar pelicula\n"
           "3. Baja de pelicula\n"
           "4. Nuevo director\n"
           "5. Borrar director\n"
           "6. Listar\n"
           "   --------------------\n"
           "7. Salir\n\n");
}

void listar(pelicula arrayPeliculas[], int lenPel, director arrayDirectores[], int lenDir) {
    short opcion;

    system("cls");
    printf("1. Ver todas las peliculas\n");
    printf("2. Ver lista de directores\n");
    printf("3. Ver las pel%cculas m%cs viejas\n", 161, 160);
    printf("4. Ver todas las pel%cculas con su director\n", 161);
    printf("5. Ver peliculas por director\n");
    printf("6. Ver cu%cntas pel%cculas dirigi%c un director\n", 160, 161, 162);
    printf("7. Ver director/es con m%cs pel%cculas\n", 160, 161);
    printf("   -------------------------------------------------\n");
    printf("8. Atras\n\n");

    opcion = getShortBetween(1,8, "Ingrese opcion:\t");
    switch (opcion) {
        case 1 : { //Mostrar peliculas (ID director)
            if (pelicula_estaVacioEsteArray(arrayPeliculas, CANT_PELICULAS)) {
                printf("\nNo hay pel%cculas en el sistema.\n", 161);
            } else {
                system("cls");
                printf("   1. Ver todas las peliculas\n");
                pelicula_mostrarListado(arrayPeliculas, lenPel);
            }
            break;
        }
        case 2 : { //Mostrar directores
            if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                printf("\nNo hay directores en el sistema.\n");
            } else {
                system("cls");
                printf("   2. Ver lista de directores\n");
                director_mostrarListado(arrayDirectores, lenDir);
            }
            break;
        }
        case 3 : { //Mostrar películas más viejas
            if (pelicula_estaVacioEsteArray(arrayPeliculas, CANT_PELICULAS)) {
                printf("\nNo hay pel%cculas en el sistema.\n", 161);
            } else {
                system("cls");
                printf("   3. Ver las pel%cculas m%cs viejas\n", 161, 160);
                pelicula_mostrarMasViejas(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
            }
            break;
        }
        case 4 : { //Mostrar películas con directores
            if (pelicula_estaVacioEsteArray(arrayPeliculas, CANT_PELICULAS)) {
                printf("\nNo hay pel%cculas en el sistema.\n", 161);
            } else {
                system("cls");
                printf("   4. Ver todas las pel%cculas con su director\n", 161);
                pelicula_mostrarListadoConDirectores(arrayPeliculas, lenPel, arrayDirectores, lenPel);
            }
            break;
        }
        case 5 : { //Mostrar peliculas por director
            if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                printf("\nNo hay directores en el sistema.\n");
            } else {
                system("cls");
                printf("   5. Ver peliculas por director\n");
                pelicula_mostrarPeliculasPorDirector(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
            }
            break;
        }
        case 6 : { //Mostrar cuántas dirigió un director
            if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                printf("\nNo hay directores en el sistema.\n");
            } else {
                system("cls");
                printf("   6. Ver cu%cntas pel%cculas dirigi%c un director\n", 160, 161, 162);
                pelicula_mostrarCuantasDirigio(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
            }
            break;
        }
        case 7 : { //Mostrar el director que más películas dirigió
            if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                printf("\nNo hay directores en el sistema.\n");
            } else {
                system("cls");
                printf("7. Ver director/es con m%cs pel%cculas\n", 160, 161);
                pelicula_mostrarElQueMasDirigio(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
            }
            break;
        }
    }
}

void programa(){
    pelicula arrayPeliculas[CANT_PELICULAS];
    director arrayDirectores[CANT_DIRECTORES];
    short opcion;
    int id;

    pelicula_init(arrayPeliculas, CANT_PELICULAS);
    pelicula_hardcode(arrayPeliculas);
    director_init(arrayDirectores, CANT_DIRECTORES);
    director_hardcode(arrayDirectores);
    do {
        imprimirMenu();
        opcion = getShortBetween(1,7,"Ingrese opcion:\t");

        switch (opcion) {
            case 1 : {
                if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                    printf("\nNo hay directores en el sistema para ingresar pel%cculas.\n", 161);
                } else {
                    pelicula_alta(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
                }
                pausaYClear();
                break;
            }
            case 2 : { //Modificar película
                if (pelicula_estaVacioEsteArray(arrayPeliculas, CANT_PELICULAS)) {
                    printf("\nNo hay pel%cculas en el sistema.\n", 161);
                } else {
                    pelicula_modificar(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
                }
                pausaYClear();
                break;
            }
            case 3 : { //Borrar película
                if (pelicula_estaVacioEsteArray(arrayPeliculas, CANT_PELICULAS)) {
                    printf("\nNo hay pel%cculas en el sistema.\n", 161);
                } else {
                    system("cls");
                    pelicula_mostrarListadoConDirectores(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
                    id = getIntBetween(0,CANT_PELICULAS, "\nIngrese ID de la pelicula a eliminar:\t");
                    pelicula_baja(arrayPeliculas, CANT_PELICULAS, id, arrayDirectores, CANT_DIRECTORES);
                }
                pausaYClear();
                break;
            }
            case 4 : { //Nuevo director
                director_alta(arrayDirectores, CANT_DIRECTORES);
                pausaYClear();
                break;
            }
            case 5 : { //Borrar director
                if (director_estaVacioEsteArray(arrayDirectores, CANT_DIRECTORES)) {
                    printf("\nNo hay directores en el sistema.\n");
                } else {
                    system("cls");
                    director_mostrarListado(arrayDirectores, CANT_DIRECTORES);
                    id = getIntBetween(0,CANT_DIRECTORES, "\nIngrese ID del director a eliminar:\t");
                    id = director_baja(arrayDirectores, CANT_DIRECTORES, id);
                    pelicula_borrarPeliculasPorDirector(arrayPeliculas, CANT_PELICULAS, id);
                }
                pausaYClear();
                break;
            }
            case 6 : {
                listar(arrayPeliculas, CANT_PELICULAS, arrayDirectores, CANT_DIRECTORES);
                pausaYClear();
            }
        }
    } while (opcion!=7);

}
