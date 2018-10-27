#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *pArchivo;
    int x = 4;
    int y;

    pArchivo = fopen("archivo.bin", "wb");

    if (pArchivo!=NULL) {
        y =fwrite(&x,
                  sizeof(int),
                  1,
                  pArchivo);
        fclose(pArchivo);
        printf("Escribi%c archivo: %d\n\n", 162, y);
    }

    x = 5;
    printf("X antes de leer de archivo: %d\n\n", x);

    pArchivo = fopen("archivo.bin", "rb");
    if (pArchivo!=NULL) {
        fread(&x,
              sizeof(int),
              1,
              pArchivo);
        fclose(pArchivo);
        printf("X en archivo: %d", x);
    }

    printf("\n");
    return 0;
}
