#include "parser.h"

int parser_EstructuraFromText(FILE* pFile , LinkedList* pArrayListEstructura) {

    char id[7], vString[NOMBRE], vInt[15], vFloat[25];
    int idAux;
    int vIntAux;
    float vFloatAux;
    int count = 0;

    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, vString, vInt, vFloat);
        //printf("STRINGS\tID: %s \tNOMBRE: %10s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);

        idAux = atoi(id);
        vIntAux = atoi(vInt);
        vFloatAux = atof(vFloat);
        //printf("AUX\tID: %d \tNOMBRE: %10s\tHORAS: %d\tSALARIO: %d\n\n", idAux, name, hoursAux, salaryAux);

        Estructura* aNewEstructura = estructura_newParametros(&idAux, vString, &vIntAux, &vFloatAux);

        ll_add(pArrayListEstructura, aNewEstructura);
        count++;
    }

    return count;
}

int parser_EstructuraFromBinary(FILE* pFile , LinkedList* pArrayListEstructura) {
    int count = 0;

    while(1) {

        Estructura* aNewEstructura = estructura_new();
        fread(aNewEstructura,
              sizeof(Estructura),
              1,
              pFile);
        if ( feof(pFile) ) {
            break;
        }
        ll_add(pArrayListEstructura, aNewEstructura);
        count++;
    }

    return count;
}
