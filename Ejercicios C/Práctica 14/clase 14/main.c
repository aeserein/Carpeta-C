#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *pArchivo;

    pArchivo = fopen("saludo.txt", "w");

    fprintf(pArchivo, "Hola mundo");

    fclose(pArchivo);
    return 0;
}

/** fopen( (path al archivo), (modo) );
        Devuelve *FILE
        Modos:  w   -   write
                        Si no existe, lo crea
                        Si existe, lo sobreescribe con un archivo blanco
                r   -   read
                        Devuelve NULL si no encuentra el archivo
                        Devuelve NULL si no encuentra la carpeta
                wb  -   write Modo binario
                        Devuelve NULL si no encuentra archivo o carpeta
                rb  -   read Modo binario

 *  Un archivo se...
        1º Abre
        2º Usa
        3º Cierra

 *  Archivo de texto es .txt
    Archivo de bits puede ser cualquier cosa, pero se pone .bin o .dat

 *  fprintf(puntero al archivo, "texto"); para archivo de texto

 *  fwrite(puntero al dato que va a escribir,
           sizeof(dato),
           cantidad de ese dato,
           puntero al archivo); para archivo binario

 *  fread (puntero al dato donde guarda,
           sizeof(dato),
           cantidad de ese dato
           puntero al archivo); para leer archivo binario

 */
