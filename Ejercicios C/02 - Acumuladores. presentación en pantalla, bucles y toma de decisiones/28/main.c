#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Imprime los primos desde 0 hasta 100\n");
    short f, i;
    short bEsPrimo;
    for (f=2 ; f<=10000 ; f++) {
        bEsPrimo = 1;
        for(i=2 ; i<f ; i++) {
            if (f%i==0) {
                bEsPrimo=0;
                break;
            }
        }
        if (bEsPrimo) {
            printf("%hi\t", f);
        }
    }
    return 0;
}
