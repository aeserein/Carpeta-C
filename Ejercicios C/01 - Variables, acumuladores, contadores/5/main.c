#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    printf("Lee un n%cmero y saca el cuadrado. No acepta n%cmeros negativos.\n\n" , 163 , 163);
    int numero;
    double potencia;

    printf("Ingrese n%cmero:\t" , 163);
    scanf("%i" , &numero);
    while (numero<=0) {
        printf("\nERROR. El n%cmero debe ser mayor a cero.\t" , 163);
        scanf("%i" , &numero);
    }

    potencia = pow(numero , 2);
    printf("\nCUADRADO DE %i:\t%g\n" , numero , potencia);

    return 0;
}
