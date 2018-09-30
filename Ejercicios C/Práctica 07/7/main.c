#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {
    char nombre[32];
    char apellido[32];
    char aux[1024];
    short f;
    short auxLength;
    char nombreCompleto[63];

    printf("Lee nombre y apellido.\n");
    printf("Devuelve 'Apellido, Nombre Nombre'.\n\n");

    printf("Ingrese nombre:\t");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>31 && strlen(aux)<2) {
        printf("Reingrese nombre:\t");
        fflush(stdin);
        gets(aux);
    }
    strcpy(nombre, aux);

    printf("Ingrese apellido:\t");
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>31 && strlen(aux)<2) {
        printf("Reingrese nombre:\t");
        fflush(stdin);
        gets(aux);
    }
    strcpy(apellido, aux);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    auxLength = strlen(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);
    for (f=1 ; f<auxLength ; f++) {
        if (nombreCompleto[f]==' ') {
            nombreCompleto[f+1] = toupper(nombreCompleto[f+1]);
        }
    }

    printf("\n");
    printf("%s", nombreCompleto);
    printf("\n");

    return 0;
}
