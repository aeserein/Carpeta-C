#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Devuelve los n%cmeros pares de 1 a 100.\n" , 163);
    int f;

    for (f=1 ; f<101 ; f++) {
        if (f%2==0) {
            printf("%d " , f);
        }
    }

    return 0;

}
