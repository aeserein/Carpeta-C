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
    while(strlen(aux)>len || strlen(aux)<=0) {
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
    }
    strcpy(vec, aux);
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
    short tiene = -1;
    int len = strlen(string);

    if (len>0) {
        tiene = 0;
        for (f=0 ; f<len ; f++) {
            if (!isdigit(string[f]) && string[f]!='.') {
                tiene = 1;
            }
        }
    }
    return tiene;
}
