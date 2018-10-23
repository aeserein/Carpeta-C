#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Recibe tres n%cmeros.\n", 163);
    printf("El primero y el %cltimo son los l%cmites de un intervalo.\n", 163, 161);
    printf("Devuelve si el del medio pertenece al intervalo.\n\n", 163);

    short f;
    int numeros[3];

    for (f=0 ; f<3 ; f++) {
        printf("N%cmero %hi:\t", 163, (f+1));
        scanf("%d", &numeros[f]);
    }
    printf("\n");
    for (f=0 ; f<3 ; f++) {
        printf("%d   \t", numeros[f]);
    }

    if ( (numeros[1]>=numeros[0] && numeros[1]<=numeros[2]) || (numeros[1]>=numeros[0] && numeros[1]<=numeros[2]) ) {
        printf("\nEl n%cmero del medio pertenece al intervalo.\n", 163);
    } else {
        printf("\nNo pertenece al intervalo.\n", 163);
    }
    return 0;
}
