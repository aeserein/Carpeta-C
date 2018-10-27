#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int main() {

    FILE *pArchivo;
    char texto[TAM] = {"viejita"};
    char texto2[TAM];

    pArchivo = fopen("../clase 14/saludo.txt", "w");

    if (pArchivo!=NULL) {
        fprintf(pArchivo, "PRIMERA LINEA\nSEGUNDA LINEA\nTERCERA LINEA");

        fclose(pArchivo);

    }

    return 0;
}
