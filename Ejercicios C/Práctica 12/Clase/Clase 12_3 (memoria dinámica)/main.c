#include <stdio.h>
#include <stdlib.h>
#define CANT 5
#define CANT_MAYOR 10

int main() {
    int *pInt;
    short f;
    pInt = (int*)malloc(sizeof(int)*CANT); //<-----(int*) para castear a puntero a int

    if (pInt!=NULL){
        *pInt = 9;
        printf("%d\n\n", *pInt);

        for (f=0 ; f<CANT ; f++) {
            printf("INDEX %d:   ", f, 163);
            scanf("%d", (pInt+f));
        }
        printf("\n");
        for (f=0 ; f<CANT ; f++) {
            printf("INDEX %d:   %d\n", f, *(pInt+f));
        }
    }
    pInt = (int*)realloc(pInt, sizeof(int)*(CANT+5));

    if (pInt!=NULL) {
        for (f=0 ; f+CANT<CANT+5 ; f++) {
            printf("INDEX %d:   ", f+CANT, 163);
            scanf("%d", (pInt+f+CANT));
        }
        printf("\n");
        for (f=0 ; f<CANT+5 ; f++) {
            printf("INDEX %d:   %d\n", f, *(pInt+f));
        }
    }

    return 0;
}

/** malloc()    Devuelve puntero a void.
                Puntero a void es una variable de cualquier cosa
                Como el objeto Object de Java

 *  Argumento es cantidad de memoria a reservar
                Se usa sizeof() de un tipo de dato (int, float, short, etc)
 *  Devuelve NULL si no encuentra lugar en la memoria
 *  Se pregunta si el puntero es distinto a NULL por las dudas de que no haya encontrado lugar en la memoria
 *  Se castea el puntero a void a puntero al tipo de dato
 *  pEntero = (int*)malloc(sizeof(int)); es igual a pInt = &variable;
                Con malloc guarda en el heap (memoria dinámica)
                Con el puntero a dirección de memoria guarda en el stack (memoria estática)
 *  Para crear un array pEntero = (int*)malloc(   sizeof(int)*CANT   ); donde CANT es la cantidad de "índices"
 *  realloc() busca un espacio en la variable para "realocar" un nuevo espacio en memoria
                Se usa para cambiar el tamaño del array
                Realloc se debería asignar a una variable distinta al puntero original
                porque, si no encuentra espacio, iguala todo a NULL
 *  free() libera memoria del heap
 */
