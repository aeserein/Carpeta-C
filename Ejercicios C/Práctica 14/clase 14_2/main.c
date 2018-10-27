#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int main() {

    FILE *pArchivo;
    char texto[TAM];

    pArchivo = fopen("../clase 14/saludo.txt", "r");

    if (pArchivo!=NULL) {
        fgets(texto, TAM, pArchivo);
        fclose(pArchivo);
        puts(texto);
    }

    return 0;
}
