#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265359

float sumarFloat(float *n1, float *n2) {
    return (*n1)+(*n2);
}

int sumarInt(int *n1, int *n2) {
    return *n1+*n2;
}

short sumarShort(short *n1, short *n2) {
    return *n1+*n2;
}

float restarFloat(float *n1, float *n2) {
    return *n1-*n2;
}

int restarInt(int *n1, int *n2) {
    return *n1-*n2;
}

short restarShort(short *n1, short *n2) {
    return *n1-*n2;
}

///////////////////////////////////////////////////////////////////////

float multiplicarFloat(float *n1, float *n2) {
    return (*n1)*(*n2);
}

int multiplicarInt(int *n1, int *n2) {
    return (*n1)*(*n2);
}

short multiplicarShort(short *n1, short *n2) {
    return (*n1)*(*n2);
}

float dividirFloat(float *n1, float *n2) {
    return (*n1)/(*n2);
}

float dividirInt(int *n1, int *n2) {
    return (float)(*n1)/(*n2);
}

float dividirShort(short *n1, short *n2) {
    return (float)(*n1)/(*n2);
}

///////////////////////////////////////////////////////////////////////

/*
double potencia(void *n, void *pow) {
    return pow((double)*n, (double)*pow);
}
*/
///////////////////////////////////////////////////////////////////////

long factorialDeFloat(float *n) {
    int numero = (int)*n;
    long resultado = 1;
    if (numero!=0) {
        int f;
        for (f=1 ; f<=numero ; f++) {
            resultado = resultado*f;
        }
    }
    return resultado;
}

long factorialDeInt(int *n) {
    int numero = *n;
    long resultado = 1;
    if (numero!=0) {
        int f;
        for (f=1 ; f<=numero ; f++) {
            resultado = resultado*f;
        }
    }
    return resultado;
}

///////////////////////////////////////////////////////////////////////

short tieneDecimalesEsteFloat(float *numero) {
    return ((*numero)-(int)(*numero)!=0);
}


int cuantosDecimalesTieneEsteFloat(float *numero) {
    float parteDecimal;
    short cDecimales = 0;
    parteDecimal = (*numero);
    while (parteDecimal!=0) {
        parteDecimal = parteDecimal*10;
        parteDecimal = parteDecimal - (int)parteDecimal;
        cDecimales++;
    }
    return cDecimales;
}

short esPrimoEsteInt(int *numero) {
    short esPrimo = 1;
    short f;
    for (f=2 ; f<(*numero)-1 ; f++) {
        if (*numero%f==0) {
            esPrimo = 0;
            break;
        }
    }
    return esPrimo;
}

///////////////////////////////////////////////////////////////////////

float superficieTrianguloInt(int *base, int *altura) {
    return (float)(*base) * (*altura) / 2;
}

float superficieTrianguloFloat(float *base, float *altura) {
    return (*base) * (*altura) / 2;
}
