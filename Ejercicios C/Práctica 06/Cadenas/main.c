#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIR 32

int main()
{
    char cadena[DIR] = "String";
    char cadena2[DIR];
    int cantidadDeCaracteres;
    int estado;
    cantidadDeCaracteres = strlen(cadena);

    printf("%s" , cadena);
    printf("\n");
    printf("Cantidad de caracteres:\t%d" , cantidadDeCaracteres);

    strcpy(cadena2 , "Gato"); //Primer argumento la cadena. Segundo argumento la asignación
    printf("\n\n");
    printf("%s" , cadena);

    estado = strcmp(cadena , cadena2);
    printf("\n");
    printf("¿Son iguales?\n");
    printf("-1 si el ascii de la segunda es m%cs grande\n" , 160);
    printf("0 si son iguales\n");
    printf("1 si el ascii de la primera es m%cs grande\n" , 160);
    printf("%d" , estado); // el -1, 0 o 1 sirve para ordenar o buscar entre strings

    estado = stricmp(cadena , cadena2); //Compara ignorando mayusculas y minúsculas
    printf("\n");
    printf("%d" , estado);

    printf("\n\n");
    printf("Ingresar string:\t");
    fflush(stdin);  //siempre antes de ingresar char o string
    gets(cadena);

    strupr(cadena);
    printf("\n%s" , cadena);

    strlwr(cadena);
    printf("\n\n");
    printf("%s" , cadena);

    strcat(cadena , cadena2);
    printf("\n\n");
    printf("%s" , cadena);

    return 0;
}

/** #include <string.h>
 *  Los strings terminan en '\0' para que el programa sepa hasta donde llega
 *  Necesito un slot reservado para el '\0' que termina el string
 *  fflush(stdin) antes de ingresar cualquier string
 *
 *  gets(nombre)                ->  Lee string
 *  strcpy(nombre , texto)      ->  String copy             ->  Asigna string a variable
 *  strncpy(nombre , texto , num) ->String copy modo seguro ->  Asigna string a variable en modo seguro
 *  strcat(nombre , texto)      ->  Concatenar strings
 *  strcmp(nombre , nombre)     ->  String compare          ->  Compara strings, case sensitive
 *  stricmp(nombre , nombre)    ->  Compara strings, ignora mayúsculas y minúsculas
 *  strupr(nombre)              ->  String upper            ->  Pasa a mayúsculas
 *  strlwr(nombre)              ->  String lower            ->  Pasa a minúsculas
 *  toupper(char)               ->  Solo un char            ->  Pasa a mayúsculas
 *  tolower(char)               ->  Solo un char            ->  Pasa a minúsculas
 *  atoi(nombre)                ->  Parse int
 *  isdigit(char)               ->  Trabaja char por char   ->  Devuelve un int
 *  isspace(char)               ->  Trabaja char por char   ->  Devuelve un int
 *  strlen(nombre)              ->  Devuelve tamaño del string
 */
