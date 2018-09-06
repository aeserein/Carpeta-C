#include <stdio.h>
#include <stdlib.h>
#define CANT 10

int main()
{
    printf("Guarda 10 n%cmeros en un vector y los muestra.\n\n" , 163);
    int numeros[CANT];
    int f;

    for (f=0 ; f<CANT ; f++) {
        printf("Ingresar n%cmero %d:\t" , 163 , f+1);
        scanf("%d" , &numeros[f]);
    }

    printf("\n");

    for (f=0 ; f<CANT ; f++) {
        printf("N%cmero %d:\t%d" , 163 , f+1 , numeros[f]);
        printf("\n");
    }
    return 0;
}
