#include "controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayeEmpleado) {
    FILE *pFile = NULL;
    int count = 0;

    pFile = fopen(path, "r");
    if (pFile!=NULL) {
        count = parser_eEmpleadoFromText(pFile, pArrayeEmpleado);
    }
    fclose(pFile);

    return count;
}

int controller_listeEmpleado(LinkedList* pArrayeEmpleado) {
    eEmpleado *auxeEmpleado;
    int len = ll_len(pArrayeEmpleado);
    int f;
    system("cls");

    list_headerSinHoras();
    for(f=0; f<len; f++) {

        auxeEmpleado = (eEmpleado*)ll_get(pArrayeEmpleado, f);
        if (auxeEmpleado!=NULL) {
            empleado_printSinHoras(auxeEmpleado);
        }
    }
    list_endSinHoras();
    return len;
}

int controller_listeEmpleadoConSueldos(LinkedList* pArrayeEmpleado) {
    eEmpleado *auxeEmpleado;
    int len = ll_len(pArrayeEmpleado);
    int f;
    system("cls");

    list_header();
    for(f=0; f<len; f++) {

        auxeEmpleado = (eEmpleado*)ll_get(pArrayeEmpleado, f);
        if (auxeEmpleado!=NULL) {
            empleado_print(auxeEmpleado);
        }
    }
    list_end();
    return len;
}

int controller_editeEmpleado(LinkedList* pArrayeEmpleado) {
    int debug;
    int id;
    int index;
    system("cls");

    renglon();
    ll_sort(pArrayeEmpleado, sortByID, 1);
    debug = controller_listeEmpleado(pArrayeEmpleado);
    renglon();
    id = getInt("Ingrese ID:\t");
    index = indexFromID(pArrayeEmpleado, &id);

    if (index>=0) {
        //editMenu(pArrayeEmpleado, &index);
    } else {
        system("cls");
        printf("NO SE ENCONTRO\n");
        pausaYClear();
    }

    return debug;
}

int controller_removeeEmpleado(LinkedList* pArrayeEmpleado) {
    int debug;
    int id;
    int index;
    eEmpleado *auxeEmpleado;
    system("cls");

    renglon();
    ll_sort(pArrayeEmpleado, sortByID, 1);
    debug = controller_listeEmpleado(pArrayeEmpleado);
    renglon();
    id = getInt("    Ingrese ID:\t");
    index = indexFromID(pArrayeEmpleado, &id);
    system("cls");

    if (index>=0) {
        auxeEmpleado = (eEmpleado*)ll_get(pArrayeEmpleado, index);
        if (auxeEmpleado!=NULL) {
            empleado_printOne(auxeEmpleado);
            if ( pregunta("Dar de baja? S/N\t") ) {
                debug = ll_remove(pArrayeEmpleado, index);
                printf("\nDADO DE BAJA\n");
            }
        }
    } else {
        printf("NO SE ENCONTRO\n");
        pausaYClear();
    }

    return debug;
}

int controller_saveAsText(char* path , LinkedList* pArrayeEmpleado) {
    FILE *pFile;
    eEmpleado *empleado;
    int size = ll_len(pArrayeEmpleado);
    char aux[200];
    short f;

    pFile = fopen(path, "w");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            empleado = (eEmpleado*)ll_get(pArrayeEmpleado, f);
            sprintf(aux,
                    "%d,%s,%s,%d,%d\n",
                    empleado->id, empleado->nombre, empleado->direccion, empleado->horas, empleado->sueldo);
            fprintf(pFile, aux);
        }
    }
    fclose(pFile);
    return size;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayeEmpleado) {
    FILE *pFile;
    eEmpleado *eEmpleadoAux;
    int size = ll_len(pArrayeEmpleado);
    short f;
    int count = 0;

    pFile = fopen(path, "wb");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            eEmpleadoAux = ll_get(pArrayeEmpleado, f);
            fwrite(eEmpleadoAux,
                   sizeof(eEmpleado),
                   1,
                   pFile);
            count++;
        }
    }
    fclose(pFile);
    return count;
}

////////////////////////////////////////////////////////////////////////////////////


int indexFromID(LinkedList *pArrayeEmpleado, int *id) {
    eEmpleado *auxeEmpleado;
    int len = ll_len(pArrayeEmpleado);
    int f;
    int index = -1;

    //printf("LEN: %d\n", len);
    for(f=0; f<len; f++) {

        auxeEmpleado = (eEmpleado*)ll_get(pArrayeEmpleado, f);
        if (auxeEmpleado!=NULL && auxeEmpleado->id==*id) {
            index = f;
        }
    }
    return index;
}

int getAvailableID(LinkedList *pArrayeEmpleado) {
    int newID = 0;
    eEmpleado *eEmpleadoAux;
    int len = ll_len(pArrayeEmpleado);
    int listOfIDs[len];
    short encontroLibre=0;
    short f;

    for (f=0 ; f<len ; f++) {
        eEmpleadoAux = ll_get(pArrayeEmpleado, f);
        *(listOfIDs+f) = eEmpleadoAux->id;
    }

    while (!encontroLibre) {
        newID++;
        encontroLibre = 1;
        for (f=0 ; f<len ; f++) {
            if (newID==*(listOfIDs+f)) {
                encontroLibre = 0;
            }
        }
    }
    return newID;
}
