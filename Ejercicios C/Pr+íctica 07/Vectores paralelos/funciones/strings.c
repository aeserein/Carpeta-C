#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIR 10

void ingresarString(char vector[], char mensaje[32], int len) {
    char aux[1024];
    printf("%s" , mensaje);
    fflush(stdin);
    gets(aux);
    while(strlen(aux)>len || strlen(aux)<0) {
        printf("Error. Intente nuevamente:\t");
        fflush(stdin);
        gets(aux);
    }
    strcpy(vector, aux);
}

void primerasLetrasMayusculas(char texto[]) {
    int auxLength;
    short f;
    auxLength = strlen(texto);
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

    ingresarString(nombre, "Ingrese nombre/s:", len);
    ingresarString(apellido, "Ingrese apellido/s:\t", len);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    primerasLetrasMayusculas(nombreCompleto);

}

void ordenarDosStrings(char string1[], char string2[]) {
	int lenMin;
	short f;

	char string1Aux[strlen(string1)+1];
	strcpy(string1Aux, string1);
	strlwr(string1Aux);

	char string2Aux[strlen(string2)+1];
	strcpy(string2Aux, string2);
	strlwr(string2Aux);

	if (strlen(string1Aux)<=strlen(string2Aux)) {
		lenMin = strlen(string1Aux);
	} else {
		lenMin = strlen(string2Aux);
	}

	for (f=0 ; f<lenMin ; f++) {
		if (string2Aux[f]<string1Aux[f]) {

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
}

short ordenarDosStrings_Bandera(char string1[], char string2[]) {
	int lenMin;
	short f;

	char string1Aux[strlen(string1)+1];
	strcpy(string1Aux, string1);
	strlwr(string1Aux);

	char string2Aux[strlen(string2)+1];
	strcpy(string2Aux, string2);
	strlwr(string2Aux);

	if (strlen(string1Aux)<=strlen(string2Aux)) {
		lenMin = strlen(string1Aux);
	} else {
		lenMin = strlen(string2Aux);
	}

	for (f=0 ; f<lenMin ; f++) {
		if (string2Aux[f]<string1Aux[f]) {

			char aux[1024];

			strcpy(aux, string1);
			strcpy(string1, string2);
			strcpy(string2, aux);
			return 1;

		} else if (string2Aux[f]==string1Aux[f]) {

		} else {
			break;
		}
	}
	return 0;
}

void ordenarEstosStrings(char strings[][61], int columnas) {
	int f;
	int i;
	for (f=0 ; f<columnas-1 ; f++) {
		for (i=f+1 ; i<columnas ; i++) {
			ordenarDosStrings(strings[f], strings[i]);
		}
	}
}
