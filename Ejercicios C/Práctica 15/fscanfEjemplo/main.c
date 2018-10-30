#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE 50

typedef struct {
    short id;
    char nombre[NOMBRE];
    int edad;
    float billete;

} persona;

persona* nuevoArrayDePersonas(int cuantasPersonas);
persona* nuevaPersonaConValores(int *id, char nombre[], int *edad, float *billete);

int main() {
    char id[100], nombre[100], edad[100], plata[100];
    int idAux; char nombreAux[NOMBRE]; int edadAux; float billeteAux;
    persona *punteroPersona[10];
    int cont=0;
    short f;

    FILE * pFile;

    pFile = fopen ("MOCK_DATA.csv", "r");

    while( !feof(pFile) ) {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, edad, plata);
        printf("%s - %s, %s - %s\n", id, nombre, edad, plata);

        idAux = atoi(id);
        strcpy(nombreAux, nombre);
        edadAux = atoi(edad);
        billeteAux = atof(plata);

        if (cont==0) { //salteo primer renglón
            cont++;
            continue;
        }
        punteroPersona[cont-1] = nuevaPersonaConValores(&idAux, nombreAux, &edadAux, &billeteAux);
        cont++;
    }
    fclose(pFile);

    for (f=0 ; f<)



   return(0);
}

persona* nuevoArrayDePersonas(int cuantasPersonas) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona)*cuantasPersonas);
    return puntero;
}

persona* nuevaPersonaConValores(int *id, char nombre[NOMBRE], int *edad, float *billete) {
    persona *puntero;
    puntero = (persona*)malloc(sizeof(persona));
    if (puntero!=NULL) {
        puntero->id = *id;
        strcpy(puntero->nombre, nombre);
        puntero->edad = *edad;
        puntero->billete = *billete;
    }
    return puntero;
}
