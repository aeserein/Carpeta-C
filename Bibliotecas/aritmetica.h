#ifndef ARITMETICA_H_INCLUDED
#define ARITMETICA_H_INCLUDED

///////////////////////////////////////////////////////////////////////

float sumarFloat(float *n1, float *n2);

int sumarInt(int *n1, int *n2);

short sumarShort(short *n1, short *n2);

float restarFloat(float *n1, float *n2);

int restarInt(int *n1, int *n2);

short restarShort(short *n1, short *n2);

///////////////////////////////////////////////////////////////////////

float multiplicarFloat(float *n1, float *n2);

int multiplicarInt(int *n1, int *n2);

short multiplicarShort(short *n1, short *n2);

float dividirFloat(float *n1, float *n2);

float dividirInt(int *n1, int *n2);

float dividirShort(short *n1, short *n2);

///////////////////////////////////////////////////////////////////////

double potencia(void *n, void *pow);

///////////////////////////////////////////////////////////////////////

long factorialDeFloat(float *n);

long factorialDeInt(int *n);

///////////////////////////////////////////////////////////////////////

short tieneDecimalesEsteFloat(float *numero);

int cuantosDecimalesTieneEsteFloat(float *numero);

short esPrimoEsteInt(int *numero);

///////////////////////////////////////////////////////////////////////

float superficieTrianguloInt(int *base, int *altura);

float superficieTrianguloFloat(float *base, float *altura);

///////////////////////////////////////////////////////////////////////

#endif
