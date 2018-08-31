#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int main() {

    printf("Lee el radio de un c%crculo. Devuelve circunferencia y %crea.\n\n" , 161 , 160);

    int radio;
    float circunferencia; //perímetro
    float area;

    printf("Ingrese radio de un c%crculo:\t" , 161);
    scanf("%i" , &radio);
    while (radio<1) {
        printf("N%cmero no v%clido" , 163 , 160);
        scanf("%i" , &radio);
    }

    circunferencia = 2*radio*PI;
    area = PI*radio*radio;

    printf("\nCIRCUNFERENCIA:\t%f" , circunferencia);
    printf("\n%cREA:\t%f\n" , 182 , area);

    return 0;

}
