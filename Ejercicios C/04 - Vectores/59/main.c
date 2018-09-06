#include <stdio.h>
#include <stdlib.h>
#define CANT 20

int main() {

    printf("\n\n");
    int numero[CANT];
    int max;
    int iMax;
    int f;

    for (f=0 ; f<20 ; f++) {
        do {
        printf("Ingresar n%cmero %d:\t" , 163 , f+1);
        scanf("%d" , &numero[f]);
        } while (numero<0);

        if (f==0) {
            max = numero[f];
            iMax = f+1;
        } else if (numero[f]>max) {
            max = numero[f];
            iMax = f+1;
        }

    }
    printf("\n");
    printf("M%cXIMO:\t%d\n" , 181 , max);
    printf("En posici%cn %d.\n" , 162 , iMax);

    return 0;
}
