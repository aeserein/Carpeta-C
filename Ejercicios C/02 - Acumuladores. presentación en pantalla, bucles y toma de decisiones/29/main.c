#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Imprime los primeros 100 m%cultiplos de 5, de 7, y de 5 y 7\n\n", 163);
    short f;

    printf("\tM%cultiplos de 5:\n", 163);
    for (f=1 ; f<=100 ; f++) {
        printf("%d  ", (int)(5*f));
    }
    printf("\n\n\tM%cultiplos de 7:\n", 163);
    for (f=1 ; f<=100 ; f++) {
        printf("%d  ", (int)(7*f));
    }
    printf("\n\n\tM%cultiplos de 5 y 7:\n", 163);
    for (f=1 ; f<=100 ; f++) {
        printf("%d  ", (int)(7*5*f));
    }

    printf("\n");
    return 0;
}
