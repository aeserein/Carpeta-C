#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


float sumarDos(float n1, float n2) {
    float resultado;
    resultado = n1+n2;
    return resultado;
}

float restarDos(float n1, float n2) {
    float resultado;
    resultado = n1-n2;
    return resultado;
}

float multiplicarDos(float n1, float n2) {
    float resultado;
    resultado = n1*n2;
    return resultado;
}

float dividirDos(float n1, float n2) {
    float resultado;
    resultado = n1/n2;
    return resultado;
}

long factorialDe(float n) {
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

float ingresarFloat(char texto[32]) {
    float n;
    printf("%s" , texto);
    scanf("%f" , &n);
    return n;
}

int ingresarInt(char texto[32]) {
    int n;
    printf("%s" , texto);
    scanf("%d" , &n);
    return n;
}

void pausaYClear(void) {
    printf("\n");
    system("pause");
    system("cls");
}

int continuar(void) {
    char letra;
    do {
        printf("%cContinuar? S/N\t\t" , 168);
        letra = getche();
        letra = toupper(letra);
    } while (letra!='S' && letra!='N');

    return (letra=='S');
}

void imprimirTituloCalculadora(void){
    printf("*****************\n");
    printf("*  CALCULADORA  *\n");
    printf("*****************\n\n");
}
