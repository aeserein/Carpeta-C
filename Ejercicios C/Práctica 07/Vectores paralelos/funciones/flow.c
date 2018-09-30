#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void pausaYClear(void) {
    printf("\n");
    system("pause");
    system("cls");
}

unsigned short continuar(void) {
    char letra;
    do {
        printf("%cContinuar? S/N\t\t" , 168);
        letra = getche();
        letra = toupper(letra);
    } while (letra!='S' && letra!='N');

    return (letra=='S');
}

unsigned short siONo(void) {
    char letra;
    do {
        letra = getche();
        letra = toupper(letra);
    } while (letra!='S' && letra!='N');

    return (letra=='S');
}
