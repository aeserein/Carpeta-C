#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Devuelve los m%cltiplos de 6 de 0 a 100\n\n", 163); //no considero un 0 múltiplo de un número
    int f;

    for(f=1 ; f<100 ; f++) {
        if (f%6==0) {
            printf("%d " , f);
        }
    }

    printf("\n");
    return 0;

}
