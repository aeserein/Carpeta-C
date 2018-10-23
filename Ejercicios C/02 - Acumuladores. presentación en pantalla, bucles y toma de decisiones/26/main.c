#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main() {
    printf("Pregunta por s%c o no, solo acepta respuestas 'S' y 'N'\n", 160);
    char respuesta;

    do {
        printf("\nS/N:\t");
        respuesta = getch();
        respuesta = toupper(respuesta);
    } while (respuesta!='S' && respuesta!='N');

    printf("\n\n%d\n", (respuesta=='S'));
    return 0;
}
