#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresarString(char texto[], int cantidad) {
    char buffer[1024];
    printf("Ingresar %s:" , texto);
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>cantidad) {
        printf("Reingresar %s:\t");
        fflush(stdin);
        gets(buffer);
    }
}   //Pasar por puntero

void primerasLetrasMayusculas(char texto[], int cantidad) {
    auxLength = strlen(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);
    for (f=1 ; f<auxLength ; f++) {
        if (nombreCompleto[f]==' ') {
            nombreCompleto[f+1] = toupper(nombreCompleto[f+1]);
        }
    }
}
