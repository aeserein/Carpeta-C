#include <stdio.h>
#include <stdlib.h>
#define TAM 50

int main() {

    FILE *pArchivo;
    char texto[3][TAM];
    int w=0;

    pArchivo = fopen("../clase 14/saludo.txt", "r");

    if (pArchivo!=NULL) {
        while (1) {
            if ( feof(pArchivo) ) {
                break;
            } else {
                printf("FEOF: %d  -  ", feof(pArchivo));
                printf("W:%d\n",w);
                fgets(texto[w], TAM, pArchivo);
                printf("%s", texto[w]);
                w++;
            }
        }
    }
    fclose(pArchivo);

    printf("\n--------------------------\n\n");

    for (w=0 ; w<3 ; w++) {
        printf("%s", texto[w]);
    }

    printf("\n");
    return 0;
}
