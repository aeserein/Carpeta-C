#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee 4 n%cmeros. Imprime el mayor.\n\n" , 163);
    int f;
    int numero;
    int max;

    for (f=0 ; f<4 ; f++) {

        printf("Ingresar un n%cmero:\t" , 163);
        scanf("%d" , &numero);

        if (f==0) {
            max = numero;
        } else if (numero>max) {
            max = numero;
        }

    }

    printf("\nMAX:\t%d\n" , max);
    return 0;

}
