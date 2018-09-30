#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee un n%cmero. Devuelve la cantidad de m%cltiplos de 3 desde 1 hasta ese n%cmero.\n\n" , 163 , 163 , 163);
    int numero;
    int cMultiplos = 0;

    printf("Ingresar n%cmero:\t" , 163);
    scanf("%d" , &numero);

    for ( ; numero>0 ; numero--) {
        if (numero%3==0) {
            cMultiplos++;
        }
    }

    printf("CANTIDAD DE M%cLTIPLOS:\t%d" , 233 , cMultiplos);
    return 0;
}
