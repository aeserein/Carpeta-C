#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265359

float sumarDosFloat(float n1, float n2) {
    return n1+n2;
}

int sumarDosInt(int n1, int n2) {
    return n1+n2;
}

short sumarDosShort(short n1, short n2) {
    return n1+n2;
}

///////////////////////////////////////////////////////////////////////

float restarDosFloat(float n1, float n2) {
    return n1-n2;
}

int restarDosInt(int n1, int n2) {
    return n1-n2;
}

short restarDosShort(short n1, short n2) {
    return n1-n2;
}

///////////////////////////////////////////////////////////////////////

float multiplicarDosFloat(float n1, float n2) {
    return n1*n2;
}

int multiplicarDosInt(int n1, int n2) {
    return n1*n2;
}

short multiplicarDosShort(short n1, short n2) {
    return n1*n2;
}

///////////////////////////////////////////////////////////////////////

float dividirDosFloat(float n1, float n2) {
    return n1/n2;
}

float dividirDosInt(int n1, int n2) {
    return (float)n1/n2;
}

///////////////////////////////////////////////////////////////////////

long factorialDeFloat(float n) {
    int numero = (int)n;
    long resultado = 1;
    if (numero!=0) {
        int f;
        for (f=1 ; f<=numero ; f++) {
            resultado = resultado*f;
        }
    }
    return resultado;
}

long factorialDeInt(int n) {
    long resultado = 1;
    if (n!=0) {
        int f;
        for (f=1 ; f<=n ; f++) {
            resultado = resultado*f;
        }
    }
    return resultado;
}

///////////////////////////////////////////////////////////////////////

short tieneDecimalesEsteFloat(float numero) {
    return (numero-(int)numero!=0);
}

///////////////////////////////////////////////////////////////////////

float superficieTrianguloInt(int base, int altura) {
    return (float)base*altura/2;
}

float superficieTrianguloFloat(float base, float altura) {
    return base*altura/2;
}
