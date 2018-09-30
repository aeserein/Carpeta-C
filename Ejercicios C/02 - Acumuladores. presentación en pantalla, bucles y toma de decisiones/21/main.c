#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Imprime m%cltiplos de 3 desde 0 hasta\nun n%cmero ingresado por el usuario\n\n", 163);

    int numero, f;

    printf("Ingresar n%cmero:\t" , 163);
    scanf("%d" , &numero);

    for (f=0 ; f<=numero ; f++) {
        if (f%3==0) {
            printf("%d   " , f);
        }
    }
    return 0;
}
