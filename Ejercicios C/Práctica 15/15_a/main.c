#include <stdio.h>
#include <stdlib.h>

int main() {
    int vec[10] = {10,9,8,7,6,5,4,3,2,1};
    char aux[5];
    short f;
    FILE *pArchivo;
    pArchivo = fopen("array.txt", "w");

    for (f=0 ; f<10 ; f++) {
        sprintf(aux, "%d\n", vec[f]);
        fprintf(pArchivo, aux);
    }
    fclose(pArchivo);
    return 0;
}

/** *   txt a csv (comma separated value)

 */
