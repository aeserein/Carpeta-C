#include "estructuraDirector.h"

int director_init( director listado[],int limite) {

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

void director_hardcode(director listado[]) {

    int id[5] = {0,1,2,3,4};
    char nombre[][TAM]= {"Director1","Director2","Director3","Director4","Director5"};
    int diaNac[5] = {11,12,13,14,15};
    int mesNac[5] = {1,2,3,4,5};
    int anioNac[5] = {1901,1902,1903,1904,1905};
    char nacionalidad[][TAM] = {"Argentina", "Paraguay", "Brasil", "Chile", "Bolivia"};

    int i;
    for(i=0; i<5; i++) {
        listado[i].id = id[i];
        strcpy(listado[i].nombre,nombre[i]);
        listado[i].diaNacimiento = diaNac[i];
        listado[i].mesNacimiento = mesNac[i];
        listado[i].anioNacimiento = anioNac[i];
        strcpy(listado[i].pais, nacionalidad[i]);
        listado[i].estado = ALTA;
    }
}

int director_estaVacioEsteArray(director lista[], int len) {
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

int director_buscarPorId(director lista[] ,int limite, int id) {
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

int director_siguienteId(director lista[],int limite) {
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

int director_buscarLugarLibre(director lista[],int limite) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(lista[i].estado == VACIO || lista[i].estado == BAJA) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

void director_ListaHeader() {
    printf("\n");
    printf("      __________________________________________________________________\n");
    director_listaRenglon();
    printf("     |  %5s |  %18s |  %11s |  %17s |\n" , "ID" , "Nombre" , "Fecha Nac.", "Pais");
    director_cierreLista();
    director_listaRenglon();
}

void director_listaRenglon() {
    printf("     |        |                     |              |                    |\n");
}

void director_cierreLista() {
    printf("     |________|_____________________|______________|____________________|\n");
}

void director_mostrarUno(director lista) {
     printf("     |  %5d |", lista.id);
     printf("  %18s |", lista.nombre);
     printf("   %.2hi/", lista.diaNacimiento);
     printf("%.2hi/", lista.mesNacimiento);
     printf("%hi |", lista.anioNacimiento);
     printf("  %17s |\n" , lista.pais);
}

void director_mostrarUnoConHeader(director lista) {
    director_ListaHeader();
    printf("     |  %5d |", lista.id);
    printf("  %18s |", lista.nombre);
    printf("   %.2hi/", lista.diaNacimiento);
    printf("%.2hi/", lista.mesNacimiento);
    printf("%hi |", lista.anioNacimiento);
    printf("  %17s |\n" , lista.pais);
    director_cierreLista();
}

void director_mostrarNombreDirector(director lista) {
     printf("  %14.14s |\n", lista.nombre);
}

void director_mostrarListado(director lista[],int limite) {
    int i;
    director_ordenarPorID(lista, limite);
    if(limite > 0 && lista != NULL) {

        director_ListaHeader();
        for(i=0; i<limite; i++) {

            if(lista[i].estado==ALTA) {
                director_mostrarUno(lista[i]);
            }
        }
        director_cierreLista();
    }
}

//////////////////////////////////////////////////////////////////

void director_alta(director lista[],int limite) {
    int id;
    int indice;
    short f;
    short encontro = 0;
    int indiceDirectorEncontrado;

    if(limite > 0 && lista != NULL) {
        indice = director_buscarLugarLibre(lista,limite);

        if(indice >= 0) {
            id = director_siguienteId(lista,limite);

            getString(lista[indice].nombre, "\nNombre:\t\t\t", TAM);
            primerasLetrasMayusculas(lista[indice].nombre);

            for (f=0 ; f<limite ; f++) {
                if (f==indice) { continue; }
                if ( stricmp(lista[indice].nombre , lista[f].nombre)==0) {
                    encontro = 1;
                    indiceDirectorEncontrado = f;
                }
            }
            if (!encontro) {
                lista[indice].diaNacimiento = getIntBetween(1,31, "Nacimiento - Dia:\t");
                lista[indice].mesNacimiento = getIntBetween(1,12, "Nacimiento - Mes:\t");
                lista[indice].anioNacimiento = getIntBetween(1900,2010, "Nacimiento - Anio:\t");
                getString(lista[indice].pais, "Pais de origen:\t\t" , TAM);
                primerasLetrasMayusculas(lista[indice].pais);
                lista[indice].id = id;
                lista[indice].estado = ALTA;
            } else {
                system("cls");
                printf("\nEse director ya se encuentra en el sistema.\n");
                director_mostrarUnoConHeader(lista[indiceDirectorEncontrado]);
            }
        }
    }
}

int director_baja(director lista[] ,int limite, int id) {
    short encontro = 0;
    int idDelDirectorBorrado = -1;
    limite--;

    for ( ; limite>=0 ; limite--) {
        if (lista[limite].estado==1 && id==lista[limite].id) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {
        system("cls");
        director_mostrarUnoConHeader(lista[limite]);

        if (pregunta("Esta seguro? S/N\t")) {
            idDelDirectorBorrado = lista[limite].id;
            lista[limite].estado = VACIO;
            strcpy(lista[limite].nombre,"");
            printf("\n\nDirector borrado\n");
        }

    } else {
        printf("\nNo se encontr%c el ID %d\n" , 162, id);
    }
    return idDelDirectorBorrado;
}

//////////////////////////////////////////////////////////////////

void director_ordenarPorID(director lista[], int len) {
    short f, i;
    director directorAux;
    for (f=0 ; f<len-1 ; f++) {
        for (i=f+1 ; i<len ; i++) {
            if (lista[i].estado==ALTA && lista[f].id>lista[i].id) {
                directorAux = lista[f];
                lista[f] = lista[i];
                lista[i] = directorAux;
            }
        }
    }
}
