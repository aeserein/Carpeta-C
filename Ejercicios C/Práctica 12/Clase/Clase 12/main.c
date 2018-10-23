#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char letra;
} estructura;

int main() {

    estructura unaEstructura;
    estructura *pEstructura;
    pEstructura = &unaEstructura;
    int x;

    unaEstructura.numero = 100;
    unaEstructura.letra = 'a';
    //x = (*pEstructura).numero;

    printf("X:\t%d\n", x);
    printf("N%cMERO:\t%d\n", 163, pEstructura->numero);
    printf("LETRA:\t%c\n", pEstructura->letra);

    return 0;
}
