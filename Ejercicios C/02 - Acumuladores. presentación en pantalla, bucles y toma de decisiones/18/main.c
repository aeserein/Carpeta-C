#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee 10 n%cmeros diferentes a 0. Suma positivos y multiplica negativos.\n\n" , 163);
    int numero;
    double sumaPositivos = 0;
    double productoNegativos = 1;
    int f;

    for(f=0 ; f<10 ; f++) {

        numero = 0;
        while (numero==0) {
            printf("N%cmero %d:\t" , 163 , f+1);
            scanf("%d" , &numero);
        }

        if (numero>0) {
            sumaPositivos += numero;
        } else {
            productoNegativos *= numero;
        }

    }

    printf("\nSUMA DE POSITIVOS:\t%g\n" , sumaPositivos);
    if (productoNegativos==1) {
        productoNegativos = 0;
    }
    printf("PRODUCTO DE NEGATIVOS:\t%g\n" , productoNegativos);


    return 0;

}
