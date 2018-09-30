#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Lee un n%cmero. Devuelve si es par o impar.\n\n" , 163);
    int numero;

    printf("Ingrese un n%cmero:\t" , 163);
    scanf("%d" , &numero);

    printf("\n");
    if (numero%2==0) {
        printf("N%cmero par" , 163);
    } else  {
        printf("N%cmero impar" , 163);
    }

    printf("\n");
    return 0;
}
