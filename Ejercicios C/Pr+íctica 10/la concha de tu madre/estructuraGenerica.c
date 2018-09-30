#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuraGenerica.h"
#include "ingresos.h"
#include "strings.h"
#include "flow.h"
#define TAMANIO 10
#define ALTA 1
#define VACIO 0
#define BAJA -1

int eGen_init( eGenerica listado[],int limite) {

    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= VACIO;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

int eGen_buscarPorId(eGenerica lista[] ,int limite, int id) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(lista[i].estado == ALTA && lista[i].idGenerica == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_siguienteId(eGenerica lista[],int limite) {
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -1;

        for(i=0; i<limite; i++) {

            if(lista[i].estado == ALTA && lista[i].idGenerica>retorno) {
                    retorno=lista[i].idGenerica;
            }
        }
    }
    return retorno+1;
}

int eGen_buscarLugarLibre(eGenerica lista[],int limite) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(lista[i].estado == VACIO) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

void eGen_mostrarUno(eGenerica lista) {
     printf("\n");
     printf("%s\t", lista.nombre);
     printf("%d\t", lista.idGenerica);
     printf("%d\n", lista.estado);
}

void eGen_mostrarListado(eGenerica lista[],int limite) {
    int i;
    if(limite > 0 && lista != NULL) {

        for(i=0; i<limite; i++) {

            if(lista[i].estado==ALTA) {
                eGen_mostrarUno(lista[i]);
            }
        }
    }
}

void eGen_mostrarListadoConBorrados(eGenerica lista[],int limite) {
    int i;
    if(limite > 0 && lista != NULL) {

        for(i=0; i<limite; i++) {

            if(lista[i].estado==ALTA) {
                eGen_mostrarUno(lista[i]);
            } else {
                printf("\n[VACIO]");
            }
        }
    }
}

//////////////////////////////////////////////////////////////////

void eGen_alta(eGenerica  lista[],int limite) {
    int id;
    int indice;

    if(limite > 0 && lista != NULL) {

        indice = eGen_buscarLugarLibre(lista,limite);

        if(indice >= 0) {
            id = eGen_siguienteId(lista,limite);

            getString(lista[indice].nombre, "[Mensaje aqui de string]", NOMBRE);
            lista[indice].idGenerica = id;
            lista[indice].estado = ALTA;
        }
    }
}

void eGen_baja(eGenerica lista[] ,int limite, int id) {
    short encontro = 0;
    limite--;

    for ( ; limite>=0 ; limite--) {
        if (lista[limite].estado==1 && id==lista[limite].idGenerica) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {

        eGen_mostrarUno(lista[limite]);
        printf("\n");

        if (pregunta("[Pregunta]?\t")) {
            lista[limite].estado = BAJA;
            printf("\n\n[Dado de baja]\n");
        }

    } else {
        printf("\n[No encontr%c]\n" , 162);
    }
}

void eGen_modificacion(eGenerica lista[] ,int limite, int id) {
    short encontro = 0;
    // Variable auxiliar de cambio
    char nombreAux[NOMBRE];
    char nombreOriginal[NOMBRE];
    // Variable auxiliar de cambio
    limite--;

    for ( ; limite>=0 ; limite--) {
        if (lista[limite].estado==1 && id==lista[limite].idGenerica) {
            encontro = 1;
            break;
        }
    }

    if (encontro) {

        eGen_mostrarUno(lista[limite]);
        printf("\n");

        //Dato a modificar
        strcpy(nombreAux, "[Nombre modificado]");
        strcpy(nombreOriginal, lista[limite].nombre);
        strcpy(lista[limite].nombre, nombreAux);
        //Dato a modificar

        eGen_mostrarUno(lista[limite]);

        if (pregunta("[Pregunta]?\t")) {
            printf("[Mensaje de afirmacion]");
        } else {
            strcpy(lista[limite].nombre, nombreOriginal);
        }

    } else {
        printf("\n[No encontr%c]\n" , 162);
    }
}

//////////////////////////////////////////////////////////////////


