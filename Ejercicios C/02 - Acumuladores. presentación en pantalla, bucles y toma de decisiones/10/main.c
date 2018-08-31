#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Devuelve los n%cmeros impares de 0 a 100 y la cantidad.\n" , 163);
    int f;
    int cImpares = 0;

    for (f=0 ; f<101 ; f++) {
        if (f%2==1) {
            printf("%d " , f);
            cImpares++;
        }
    }

    printf("\n\nCANTIDAD DE IMPARES:\t%d\n" , cImpares);

    return 0;

}
