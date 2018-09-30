#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee un n%cmero. Devuelve si es positivo o negativo.\n\n" , 163);
    int numero;

    printf("Ingrese un n%cmero:\t" , 163);
    scanf("%d" , &numero);

    printf("\n");
    if (numero==0) {
        printf("El n%cmero es 0" , 163);
    } else if (numero>0) {
        printf("N%cmero positivo" , 163);
    } else {
        printf("N%cmero negativo" , 163);
    }

    printf("\n");
    return 0;
}
