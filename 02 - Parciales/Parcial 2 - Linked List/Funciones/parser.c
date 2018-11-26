#include "parser.h"

int parser_eEmpleadoFromText(FILE* pFile , LinkedList* pArrayListEstructura) {

    char id[7], nombre[TAM], direccion[TAM], horas[5];
    int idAux, horasAux;

    int count = 0;

    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],   %[^,],   %[^,],  %[^\n]\n", id, nombre, direccion, horas);
        //printf("STRINGS\tID: %s \tTAM: %10s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);

        idAux = atoi(id);
        horasAux = atoi(horas);

        //printf("AUX\tID: %d \tTAM: %10s\tHORAS: %d\tSALARIO: %d\n\n", idAux, name, hoursAux, salaryAux);

        eEmpleado* newEmpleado = empleado_newParametros(&idAux, nombre, direccion, &horasAux);

        ll_add(pArrayListEstructura, newEmpleado);
        count++;
    }

    return count;
}
/*
int parser_eEmpleadoFromBinary(FILE* pFile , LinkedList* pArrayListEstructura) {
    int count = 0;

    while(1) {

        eEmpleado* newEmpleado = empleado_new();
        fread(newEmpleado,
              sizeof(eEmpleado),
              1,
              pFile);
        if ( feof(pFile) ) {
            break;
        }
        ll_add(pArrayListEstructura, newEmpleado);
        count++;
    }

    return count;
}
*/
