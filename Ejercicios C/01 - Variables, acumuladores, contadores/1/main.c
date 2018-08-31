#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    float promedio;

    printf("Toma 5 n%cmeros. Devuelve promedio.\n\n" , 163);

    printf("N%cmero uno:\t" , 163);
    scanf("%d" , &n1);

    printf("N%cmero dos:\t" , 163);
    scanf("%d" , &n2);

    printf("N%cmero tres:\t" , 163);
    scanf("%d" , &n3);

    printf("N%cmero cuatro:\t" , 163);
    scanf("%d" , &n4);

    printf("N%cmero cinco:\t" , 163);
    scanf("%d" , &n5);

    promedio = (float)(n1+n2+n3+n4+n5) / 5;
    printf("\nPROMEDIO: %.2f\n" , promedio);

    return 0;

}
