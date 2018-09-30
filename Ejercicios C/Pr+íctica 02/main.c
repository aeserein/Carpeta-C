#include <stdio.h>
#include <stdlib.h>

    /* Ejercicio 1
    Pedir 3 números
    Sin iterar sacar el número del medio.
    */

int main() {

    printf("Lee tres n%cmeros. Devuelve el valor del medio.\n\n" , 163);
    int n1;
    int n2;
    int n3;
    int medio;
    int min;
    int max;

    printf("N%cmero uno:\t" , 163);
    scanf("%d" , &n1);
    min = n1;
    max = n1;

    printf("N%cmero dos:\t" , 163);
    scanf("%d" , &n2);
    if (n2>max) {
        max = n2;
    } else {
        max = n1;
    }

    printf("N%cmero tres:\t" , 163);
    scanf("%d" , &n3);
    if (n3>max) {
        max = n3;
    } else {
        if (n3<min) {
            min = n3;
        }
    }

    printf("\n(Referencia)\nMAX: %i\nMIN:%i\n\n" , max , min);

    if (n1<max && n1>min) {
        medio = n1;
    } else if (n2<max && n2>min) {
        medio = n2;
    } else if (n3<max && n3>min) {
        medio = n3;
    } else {
        medio = 999;
    }

    if (medio == 999) {
        printf("MEDIO: No existe\n");
    } else {
        printf("MEDIO: %i\n" , medio);
    }


    return 0;

}
