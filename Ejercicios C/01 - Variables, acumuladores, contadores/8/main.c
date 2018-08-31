#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Calcula superficie de un tri%cngulo.\n\n" , 160);

    int base;
    int altura;
    float area;

    printf("Ingrese base:\t");
    scanf("%i" , &base);
    while (base<1) {
        printf("N%cmero inv%clido, ingrese nuevamente:\t" , 163 , 160);
        scanf("%i" , &base);
    }
    printf("\nIngrese altura:\t");
    scanf("%i" , &altura);
    while (altura<1) {
        printf("N%cmero inv%clido, ingrese nuevamente:\t" , 163 , 160);
        scanf("%i" , &altura);
    }

    area = (float)base*altura/2;
    printf("\nSUPERFICIE:\t%.2f\n" , area);

    return 0;
}
