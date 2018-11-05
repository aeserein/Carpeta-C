#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void pausaYClear(void) {
    printf("\n    ");
    system("pause");
    system("cls");
}

unsigned short pregunta(char texto[50]) {
    char letra;
    do {
        printf("    %c%s" , 168, texto);
        letra = getche();
        letra = toupper(letra);
    } while (letra!='S' && letra!='N');

    return (letra=='S');
}

void renglon() {
    printf("\n");
}
