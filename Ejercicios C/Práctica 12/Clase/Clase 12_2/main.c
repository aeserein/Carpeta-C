#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char letra;
} estructura;

estructura* setearNumero(int x, char y);

int main() {
    /*
    estructura unaEstructura[2] = {{100,'c'},{200,'d'}};
    estructura *pEstructura;
    pEstructura = unaEstructura;
    short f;

    for (f=0 ; f<2 ; f++) {
        printf("N%cMERO:\t%d\n", 163, (pEstructura+f)->numero);
        printf("LETRA:\t%c\n\n", (pEstructura+f)->letra);
    }*/
    estructura *unPuntero;
    unPuntero = setearNumero(1,'S');
    printf("-----------------\nN%cMERO:\t%d\nLETRA:\t%c\n\n", 163, unPuntero->numero, unPuntero->letra);

    return 0;
}

estructura* setearNumero(int x, char y) {
    estructura unaEstructura;
    estructura *pEstructura;
    pEstructura = &unaEstructura;

    printf("%d, %c\n", x,y);
    printf("N%cMERO:\t%d\nLETRA:\t%c\n\n", 163, pEstructura->numero, pEstructura->letra);
    pEstructura->numero = x;
    pEstructura->letra = y;
    printf("N%cMERO:\t%d\nLETRA:\t%c\n\n", 163, pEstructura->numero, pEstructura->letra);

    return pEstructura;
}
