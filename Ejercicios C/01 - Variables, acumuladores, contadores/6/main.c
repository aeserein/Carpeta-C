#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee diez n%cmeros. Cuenta positivos y negativos.\n\n" , 163);

    int numero;
    int f;
    int cPositivos = 0;
    int cNegativos = 0;

    for (f=0 ; f<10 ; f++) {
        printf("N%cmero %i:\t" , 163 , f+1);
        scanf("%i" , &numero);

        if (numero<0) {
            cNegativos++;
        }
        if (numero>0) {
            cPositivos++;
        }
    }

    printf("\nCANTIDAD DE POSITIVOS:\t%i" , cPositivos);
    printf("\nCANTIDAD DE NEGATIVOS:\t%i\n" , cNegativos);

    return 0;

}
