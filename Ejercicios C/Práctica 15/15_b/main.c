#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int guardarEnArchivo(const char nombreArchivo[], const char modo[], int *pAGuardar, int tamanho);
int guardarBinarioInt(int *pAGuardar, int tamanho, FILE *pArchivo);
int guardarTxTInt(int *pAGuardar, int tamanho, FILE *pArchivo);

int abrirArchivo(const char nombreArchivo[], const char modo[], int *pALeer, int tamanho);

int main() {
    int vec[10] = {18,9,8,7,6,5,789,3,2,1};
    int vec2[10];
    short f;
    int debug;

    debug = guardarEnArchivo("array.bin", "wb", vec, 10);

    debug = abrirArchivo("array.bin", "rb", vec2, 10);

    for (f=0 ; f<10 ; f++){
        printf("%d\n", *(vec2+f));
    }
    return debug;
}

int guardarEnArchivo(const char nombreArchivo[], const char modo[], int *pAGuardar, int tamanho) {
    int debug = 0;
    FILE *pArchivo;
    pArchivo = fopen(nombreArchivo, modo);

    if ( !strcmp(modo, "wb") ) {
        debug = guardarBinarioInt(pAGuardar, tamanho, pArchivo);
    } else if ( !strcmp(modo, "w") ) {
        debug = guardarTxTInt(pAGuardar, tamanho, pArchivo);
    }

    fclose(pArchivo);
    return debug;
}

int abrirArchivo(const char nombreArchivo[], const char modo[], int *pALeer, int tamanho) {
    FILE *pArchivo;
    short f;
    int debug = 0;
    pArchivo = fopen(nombreArchivo, modo);

    if ( !strcmp(modo, "wb") ) {
        debug =  (pAGuardar, tamanho, pArchivo);
    } else if ( !strcmp(modo, "w") ) {
        debug = guardarTxTInt(pAGuardar, tamanho, pArchivo);
    }

    for (f=0 ; f<tamanho ; f++) {
        debug = fread(pALeer+f,
                      sizeof(pALeer),
                      tamanho,
                      pArchivo);
    }
    fclose(pArchivo);
    return debug;
}

int guardarBinarioInt(int *pAGuardar, int tamanho, FILE *pArchivo) {
    short f;
    int debug = 0;
    for (f=0 ; f<tamanho ; f++) {
        debug = fwrite(pAGuardar+f,
                       sizeof(pAGuardar),
                       tamanho,
                       pArchivo);
    }
    return debug;
}

int guardarTxTInt(int *pAGuardar, int tamanho, FILE *pArchivo) {
    short f;
    int debug = 0;
    char aux[11];
    for (f=0 ; f<10 ; f++) {
        sprintf(aux, "%d\n", *(pAGuardar+f) );
        debug = fprintf(pArchivo, aux);
    }
    return debug;
}
