#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee un n%cmero y acumula los que lo anteceden hasta 0.\n\n" , 163);
    int numero;
    int aNumero = 0;
    int f;

    printf("Ingresar un n%cmero:\t" , 163);
    scanf("%d" , &numero);
    for (f=0 ; f<numero ; f++) {
        aNumero += f;
    }

    printf("%d" , aNumero);
    return 0;

}
