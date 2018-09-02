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

float factorial(float n) {
    float resultado;
    if (n==1) {
        return 1;
    } else {
        resultado = n*factorial(n-1);
    }
    return resultado;
}

float ingresarNumero(void) {
    float n;
    printf("Ingrese un n%cmero:\t" , 163);
    scanf("%f" , &n);
    return n;
}

void pausaYClear(void) {
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
