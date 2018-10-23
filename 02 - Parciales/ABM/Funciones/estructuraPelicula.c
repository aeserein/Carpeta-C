#include "estructuraPelicula.h"
#include "estructuraDirector.h"

int pelicula_init( pelicula listado[],int limite) {

    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= VACIO;
            listado[i].id= 0;
        }
    }
    return retorno;
}

void pelicula_hardcode(pelicula listado[]) {

    int id[10] = {0,1,2,3,4,5,6,7,8,9};
    char titulo[][TAM]= {"Nombre1","Nombre2","Nombre3","Nombre4","Nombre5","Nombre6","Nombre7","Nombre8","Nombre9","Nombre10"};
    int anio[10] = {1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 2010};
    char nacionalidad[][TAM] = {"Argentina", "Paraguay", "Brasil", "Chile", "Bolivia", "Peru", "Colombia", "Venezuela", "Mexico", "Estados Unidos"};
    int director[10] = {0,1,0,3,2,0,3,4,1,2};

    int i;
    for(i=0; i<10; i++) {
        listado[i].id = id[i];
        strcpy(listado[i]. titulo,titulo[i]);
        listado[i].anio = anio[i];
        strcpy(listado[i].nacionalidad, nacionalidad[i]);
        listado[i].director = director[i];
        listado[i].estado = ALTA;
    }
}

int pelicula_estaVacioEsteArray(pelicula lista[], int len) {
    int estaVacio = -1;
    int i;
    if(len > 0 && lista != NULL) {
        estaVacio = 1;
        for(i=0; i<len; i++) {
            if (lista[i].estado==ALTA) {
                estaVacio = 0;
                break;
            }
        }
    }
    return estaVacio;
}

//////////////////////////////////////////////////////////////////

int pelicula_buscarPorId(pelicula lista[] ,int limite, int id) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(lista[i].estado == ALTA && lista[i].id == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int pelicula_siguienteId(pelicula lista[],int limite) {
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -1;

        for(i=0; i<limite; i++) {
            if(lista[i].estado == ALTA && lista[i].id>retorno) {
                    retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}

int pelicula_buscarLugarLibre(pelicula lista[],int limite) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {
            if(lista[i].estado==VACIO || lista[i].estado==BAJA) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

void pelicula_ListaHeader() {
    printf("\n");
    printf("    ________________________________________________________________________\n");
    pelicula_listaRenglon();
    printf("   |  %5s |  %15s |  %3c%co |  %14s |  %14s |\n" , "ID" , "Titulo" , 'A', 164 , "Pais" , "Director");
    pelicula_cierreLista();
    pelicula_listaRenglon();
}

void pelicula_listaRenglon() {
    printf("   |        |                  |        |                 |                 |\n");
}

void pelicula_cierreLista() {
    printf("   |________|__________________|________|_________________|_________________|\n");
}

void pelicula_mostrarUno(pelicula lista) {
     printf("   |  %5d |", lista.id);
     printf("  %15.15s |", lista.titulo);
     printf("  %5d |", lista.anio);
     printf("  %14.14s |", lista.nacionalidad);
     printf("  %14d |\n", lista.director);
}

void pelicula_mostrarUnoConDirector(pelicula listaPel, director listaDir[], int lenDir) {
    short indiceDelDirector;
    printf("   |  %5d |", listaPel.id);
    printf("  %15.15s |", listaPel.titulo);
    printf("  %5d |", listaPel.anio);
    printf("  %14.14s |", listaPel.nacionalidad);

    indiceDelDirector = director_buscarPorId(listaDir, lenDir, listaPel.director);
    if (indiceDelDirector>=0) {
        director_mostrarNombreDirector(listaDir[indiceDelDirector]);
    } else {
        printf("  %14c |\n", '-');
    }
}

void pelicula_mostrarUnoConHeader(pelicula listaPel, director listaDir[], int lenDir) {
    pelicula_ListaHeader();
    short indiceDelDirector;
    printf("   |  %5d |", listaPel.id);
    printf("  %15.15s |", listaPel.titulo);
    printf("  %5d |", listaPel.anio);
    printf("  %14.14s |", listaPel.nacionalidad);
    indiceDelDirector = director_buscarPorId(listaDir, lenDir, listaPel.director);
    if (indiceDelDirector>=0) {
        director_mostrarNombreDirector(listaDir[indiceDelDirector]);
    } else {
        printf("  %14c |\n", '-');
    }
    pelicula_cierreLista();
}

void pelicula_mostrarListado(pelicula lista[],int limite) {
    int i;
    pelicula_ordenarPorID(lista, limite);
    if(limite > 0 && lista != NULL) {
        pelicula_ListaHeader();
        for(i=0; i<limite; i++) {

            if(lista[i].estado==ALTA) {
                pelicula_mostrarUno(lista[i]);
            }
        }
        pelicula_cierreLista();
    }
}

void pelicula_mostrarListadoConDirectores(pelicula listaPel[],int lenPel, director listaDir[], int lenDir) {
    int i;

    pelicula_ordenarPorID(listaPel, lenPel);
    if(lenPel > 0 && listaPel != NULL) {
        pelicula_ListaHeader();
        for(i=0; i<lenPel; i++) {

            if(listaPel[i].estado>0) {
                pelicula_mostrarUnoConDirector(listaPel[i], listaDir, lenDir);

            }
        }
        pelicula_cierreLista();
    }
}

//////////////////////////////////////////////////////////////////

void pelicula_mostrarMasViejas(pelicula listaPel[], int lenPel, director listaDir[], int lenDir) {
    int anioMinimo = 2019;
    short f;
    for (f=0 ; f<lenPel ; f++) {
        if (listaPel[f].estado==ALTA && listaPel[f].anio<anioMinimo) {
            anioMinimo = listaPel[f].anio;
        }
    }
    printf("\n\n         A%cO: %d\n", 165, anioMinimo);
    pelicula_ListaHeader();
    for (f=0 ; f<lenPel ; f++) {
        if (listaPel[f].anio == anioMinimo) {
            pelicula_mostrarUnoConDirector(listaPel[f], listaDir, lenDir);
        }
    }
    pelicula_cierreLista();
}

void pelicula_mostrarPeliculasPorDirector(pelicula listaPel[], int lenPel, director listaDir[], int lenDir) {
    int idDirector;
    short f;
    short i;

    for (f=0 ; f<lenDir ; f++) {
        if (listaDir[f].estado==ALTA) {
            printf("\n\n\n         %s:", listaDir[f].nombre);
            idDirector = listaDir[f].id;
            pelicula_ListaHeader();
            for (i=0 ; i<lenPel ; i++) {
                if (listaPel[i].estado==ALTA && listaPel[i].director==idDirector) {
                    pelicula_mostrarUnoConDirector(listaPel[i], listaDir, lenDir);
                }
            }
            pelicula_cierreLista();
        }
    }
}

void pelicula_mostrarCuantasDirigio(pelicula listaPel[], int lenPel, director listaDir[], int lenDir) {
    int idDir;
    int indice;
    int cuantas = 0;
    short f;
    director_mostrarListado(listaDir, lenDir);
    idDir = getInt("\nEscoja director (ID):   ");

    indice = director_buscarPorId(listaDir, lenDir, idDir);
    if (indice>=0) {
        for (f=0 ; f<lenPel ; f++) {
            if (listaPel[f].estado==ALTA && listaPel[f].director==listaDir[indice].id) {
                cuantas++;
            }
        }
        if (cuantas) {
            system("cls");
            printf("   6. Ver cu%cntas pel%cculas dirigi%c un director\n", 160, 161, 162);
            printf("\n\n         %s dirigi%c %d pel%cculas.\n", listaDir[indice].nombre, 162, cuantas, 161);
            pelicula_ListaHeader();
            for (f=0 ; f<lenPel ; f++) {
                if (listaPel[f].estado==ALTA && listaPel[f].director==listaDir[indice].id) {
                    pelicula_mostrarUnoConDirector(listaPel[f], listaDir,lenDir);
                }
            }
            pelicula_cierreLista();
        } else {
            printf("\n%s no dirigi%c ninguna pel%ccula.\n", listaDir[indice].nombre, 162, 161);
        }
    } else {
        printf("\nNo se encontr%c el ID %d\n" , 162, idDir);
    }
}

void pelicula_mostrarElQueMasDirigio(pelicula listaPel[], int lenPel, director listaDir[], int lenDir) {
    int cantidadDePeliculas[lenDir];
    short cantidadMaxima = SHRT_MIN;
    short f;
    short i;
    for (f=0 ; f<lenDir ; f++) {
        cantidadDePeliculas[f]=0;
    }
    for (f=0 ; f<lenDir ; f++) {
        if (listaDir[f].estado==ALTA) {
            for (i=0 ; i<lenPel ; i++) {
                if (listaDir[f].id==listaPel[i].director && listaPel[i].estado==ALTA) {
                    cantidadDePeliculas[f]++;
                }
            }
        }
    }
    for (f=0 ; f<lenDir ; f++) {
        if (cantidadDePeliculas[f]>=cantidadMaxima) {
            cantidadMaxima = cantidadDePeliculas[f];
        }
    }
    if (cantidadMaxima) {
        for (f=0 ; f<lenDir ; f++) {
            if (cantidadDePeliculas[f]==cantidadMaxima) {
                pelicula_ListaHeader();
                for (i=0 ; i<lenPel ; i++) {
                    if (listaPel[i].estado==ALTA && listaPel[i].director==listaDir[f].id) {
                        pelicula_mostrarUnoConDirector(listaPel[i], listaDir,lenDir);
                    }
                }
                pelicula_cierreLista();
            }
        }
    } else {
        printf("\nNadie dirigi%c nada.\n", 162);
    }
}

//////////////////////////////////////////////////////////////////

void pelicula_alta(pelicula  lista[],int limite, director listaDir[], int lenDir) {
    int id;
    int indice;
    int indiceDelDirector;

    if(limite > 0 && lista != NULL) {

        indice = pelicula_buscarLugarLibre(lista,limite);

        if(indice >= 0) {
            id = pelicula_siguienteId(lista,limite);

            printf("\n");
            getString(lista[indice].titulo, "Titulo:\t\t", TAM);
            primerasLetrasMayusculas(lista[indice].titulo);
            lista[indice].anio = getIntBetween(1900, 2018,"Anio:\t\t");
            getString(lista[indice].nacionalidad, "Nacionalidad:\t", TAM);
            primerasLetrasMayusculas(lista[indice].nacionalidad);
            director_mostrarListado(listaDir, lenDir);
            lista[indice].director = getInt("\nDirector (ID):\t");
            indiceDelDirector = director_buscarPorId(listaDir, lenDir, lista[indice].director);
            while (indiceDelDirector<0) {
                printf("\nEse director no se encuentra en el sistema.\n");
                return;
            }
            lista[indice].id = id;
            lista[indice].estado = ALTA;
        }
    }
}

void pelicula_baja(pelicula lista[] ,int limite, int id, director listaDirectores[], int lenDir) {
    short encontro = 0;
    limite--;


    for ( ; limite>=0 ; limite--) {
        if (lista[limite].estado==1 && id==lista[limite].id) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {
        system("cls");
        pelicula_mostrarUnoConHeader(lista[limite], listaDirectores, lenDir);

        if (pregunta("Esta seguro? S/N\t")) {
            lista[limite].estado = BAJA;
            printf("\n\nPelicula dada de baja\n");
        }
        printf("\n");

    } else {
        printf("\nNo se encontr%c el ID %d\n" , 162, id);
    }
}

void pelicula_borrarPeliculasPorDirector(pelicula arrayPeliculas[], int lenPel, int idDir) {
    short f;
    for (f=0; f<lenPel; f++){

        if (arrayPeliculas[f].director==idDir) {
            arrayPeliculas[f].estado = 0;
        }
    }
}

void pelicula_modificar(pelicula arrayPeliculas[], int lenPel, director arrayDirectores[], int lenDir) {
    short opcion;
    short valorCambiado = 0;
    int id;
    int indice;
    pelicula peliculaAux;

    system("cls");
    pelicula_mostrarListadoConDirectores(arrayPeliculas, lenPel, arrayDirectores, lenDir);
    id = getIntBetween(0,lenPel, "\nIngrese ID de la pelicula a modificar:\t");
    indice = pelicula_buscarPorId(arrayPeliculas, lenPel, id);

    if(indice>=0) {
        system("cls");
        pelicula_mostrarUnoConHeader(arrayPeliculas[indice], arrayDirectores, lenDir);
        peliculaAux = arrayPeliculas[indice];

        printf("\n1. Titulo\n");
        printf("2. A%co\n", 164);
        printf("3. Nacionalidad\n");
        printf("4. Director\n");
        printf("   ---------------------\n");
        printf("5. Atr%cs\n\n", 160);

        opcion = getShortBetween(1,5,"Ingrese opcion:\t");
        printf("\n");
        switch (opcion) {
            case 1 : { /*Titulo*/
                getString(arrayPeliculas[indice].titulo, "Ingrese nuevo titulo:\t", TAM);
                primerasLetrasMayusculas(arrayPeliculas[indice].titulo);
                valorCambiado = 1;
                break;
            }
            case 2 : { /*Año*/
                arrayPeliculas[indice].anio = getIntBetween(1900,2018, "Ingrese nuevo anio:\t");
                valorCambiado = 1;
                break;
            }
            case 3 : { /*Nacionalidad*/
                getString(arrayPeliculas[indice].nacionalidad, "Ingrese nuevo nacionalidad:\t", TAM);
                primerasLetrasMayusculas(arrayPeliculas[indice].nacionalidad);
                valorCambiado = 1;
                break;
            }
            case 4 : { /*Director*/
                director_mostrarListado(arrayDirectores, lenDir);
                arrayPeliculas[indice].director = getInt("\nIngrese nuevo director (ID):");
                valorCambiado = 1;
                break;
            }
            case 5 : { break; } /*Atrás*/
        }
        if (valorCambiado==1){
            if (valorCambiado && pregunta("Esta seguro? S/N\t")) {
                printf("\n");
                pelicula_mostrarUnoConHeader(arrayPeliculas[indice], arrayDirectores, lenDir);
            } else {
                printf("\n");
                arrayPeliculas[indice] = peliculaAux;
            }
        }
    } else {
        printf("\nNo se encontr%c el ID %d\n", 162, id);
    }
}

//////////////////////////////////////////////////////////////////

void pelicula_ordenarPorID(pelicula lista[], int len) {
    short f, i;
    pelicula peliculaAux;
    for (f=0 ; f<len-1 ; f++) {
        for (i=f+1 ; i<len ; i++) {
            if (lista[i].estado==ALTA && lista[f].id>lista[i].id) {
                peliculaAux = lista[f];
                lista[f] = lista[i];
                lista[i] = peliculaAux;
            }
        }
    }
}
