#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#define MENSAJES 65

float getFloat(char texto[MENSAJES]) {
    char num[12];
    float numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
    } while ( tieneLetrasEsteString(num) );
    numero = atof(num);
    return numero;
}

float getFloatBetween(float min, float max, char texto[MENSAJES]) {
    char num[12];
    float numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
        if ( !tieneLetrasEsteString(num) ) {
            numero = atof(num);
        } else {
            numero = min-1;
        }
    } while (numero<min || numero>max);

    return numero;
}

/////////////////////////////////////////////////////////////////

int getInt(char texto[MENSAJES]) {
    char num[12];
    int numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
    } while ( tieneLetrasEsteString(num) );
    numero = atoi(num);
    return numero;
}

int getIntBetween(int min, int max, char texto[MENSAJES]) {
    char num[12];
    int numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
        if ( !tieneLetrasEsteString(num) ) {
            numero = atoi(num);
        } else {
            numero = min-1;
        }
    } while (numero<min || numero>max);

    return numero;
}

/////////////////////////////////////////////////////////////////

short getShort(char texto[MENSAJES]) {
    char num[6];
    short numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
    } while ( tieneLetrasEsteString(num) );
    numero = (short)atoi(num);
    return numero;
}

short getShortBetween(short min, short max, char texto[MENSAJES]) {
    char num[6];
    short numero;

    do {
        printf("%s" , texto);
        fflush(stdin);
        gets(num);
        if ( !tieneLetrasEsteString(num) ) {
            numero = atoi(num);
        } else {
            numero = min-1;
        }
    } while (numero<min || numero>max);

    return numero;
}

/////////////////////////////////////////////////////////////////
