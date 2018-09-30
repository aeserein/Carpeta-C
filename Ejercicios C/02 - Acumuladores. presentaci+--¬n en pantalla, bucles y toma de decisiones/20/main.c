#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Imprime los n%cmeros naturales desde 1 hasta el que ingresa el usuario.\n\n" , 163);
    int numero;
    int f;

    do {
        printf("Ingresar n%cmero:\t" , 163);
        scanf("%d" , &numero);
    } while (numero<1);

    for (f=1 ; f<=numero ; f++) {
        printf("%d\t" , f);
    }
    return 0;
}
