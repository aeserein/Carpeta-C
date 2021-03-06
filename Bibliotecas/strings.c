#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strings.h"

void getString(char *vec, const char *mensaje, int len) {
    char aux[len];
    printf("%s", mensaje);
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>len || strlen(aux)<0) {
        printf("Error. Intente nuevamente:\t");
        fflush(stdin);
        gets(aux);
    }
    strcpy(vec, aux);
}

char* getString_dinamico(const char* mensaje) {
    printf("%s", mensaje);

    char* pString = (char*)malloc(sizeof(char)*1024);
    scanf("%1023s",pString);

    int len = strlen(pString);
    pString = (char*)realloc(pString,sizeof(char)*(len+1));

    return pString;
}

void primerasLetrasMayusculas(char texto[]) {
    int auxLength;
    short f;
    auxLength = strlen(texto);
    strlwr(texto);
    texto[0] = toupper(texto[0]);
    for (f=1 ; f<auxLength-1 ; f++) {
        if (texto[f]==' ') {
            texto[f+1] = toupper(texto[f+1]);
        }
    }
}

void nombreYApellido(char nombreCompleto[], int len) {

    if (len%2==0) {
        len = (len/2) - 1;
    } else {
        len = len/2;
    }
    char nombre[len];
    char apellido[len];

    getString(nombre, "Ingrese nombre/s:", len);
    getString(apellido, "Ingrese apellido/s:\t", len);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    primerasLetrasMayusculas(nombreCompleto);

}

void ordenarDosStrings(char string1[], char string2[]) {
    /*
	short f;

	if (strlen(string1Aux)<=strlen(string2Aux)) {
		lenMin = strlen(string1Aux);
	} else {
		lenMin = strlen(string2Aux);
	}

	for (f=0 ; f<lenMin ; f++) {
		if (strcmp(string2Aux[f]<string1Aux[f]) {

			char aux[1024];

			strcpy(aux, string1);
			strcpy(string1, string2);
			strcpy(string2, aux);
			break;

		} else if (string2Aux[f]==string1Aux[f]) {

		} else {
			break;
		}
	}
	*/
}

void ordenarEstosStrings(char strings[][50], int columnas) {
	int f;
	int i;
	for (f=0 ; f<columnas-1 ; f++) {
		for (i=f+1 ; i<columnas ; i++) {
			ordenarDosStrings(strings[f], strings[i]);
		}
	}
}

short tieneLetrasEsteString(char string[]) {
    short f;

    for (f=0 ; f<strlen(string) ; f++) {
        if (!isdigit(string[f]) && string[f]!='.') {
            return 1;
        }
    }
    return 0;
}
