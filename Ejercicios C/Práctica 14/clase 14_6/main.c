#include <stdio.h>
#include <stdlib.h>
#define TAM 30

typedef struct {
    char nombre[TAM];
    int edad;
} persona;

int main() {
    FILE *pArchivo;
    persona unaPersona = {"Pepe el Mediocre", 20};
    persona personaLeidaDeArchivo;
    int y;
    long asd;

    pArchivo = fopen("persona.dat", "wb");
    if (pArchivo!=NULL) {
        y = fwrite(&unaPersona,
                   sizeof(persona),
                   1,
                   pArchivo);
        printf("Escribi%c archivo: %d\n\n", 162, y);
        fclose(pArchivo);
    }

    pArchivo = fopen ("persona.dat", "rb");
    asd = ftell(pArchivo);
    printf("%li", asd);
    if (pArchivo!=NULL) {
        fread(&personaLeidaDeArchivo,
              sizeof(persona),
              1,
              pArchivo);
        fclose(pArchivo);
        printf("NOMBRE: %s\n", personaLeidaDeArchivo.nombre);
        printf("EDAD: %d\n", personaLeidaDeArchivo.edad);
    }

    return 0;
}
