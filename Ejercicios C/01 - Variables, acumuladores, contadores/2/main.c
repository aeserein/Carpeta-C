#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1;
    int n2;
    int suma;

    printf("Toma dos n%cmeros y los suma.\n\n" , 163);

    printf("N%cmero uno:\t" , 163);
    scanf("%i" , &n1);
    printf("N%cmero dos:\t" , 163);
    scanf("%i" , &n2);

    suma = n1+n2;
    printf("\nSUMA:\t%i\n" , suma);

    return 0;

}
