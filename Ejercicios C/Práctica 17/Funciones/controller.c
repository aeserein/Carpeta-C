#include "controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayEstructura) {
    FILE *pFile = NULL;
    int count = 0;

    pFile = fopen(path, "r");
    if (pFile!=NULL) {
        count = parser_EstructuraFromText(pFile, pArrayEstructura);
    }
    fclose(pFile);

    return count;
}

long controller_loadFromBinary(char* path , LinkedList* pArrayEstructura) {
    FILE *pFile = NULL;
    long count = 0;

    pFile = fopen(path, "rb");
    if (pFile!=NULL) {
        count = parser_EstructuraFromBinary(pFile, pArrayEstructura);
    }
    fclose(pFile);

    return count;
}

int controller_addEstructura(LinkedList* pArrayEstructura) {
    int id, vInt;
    char vString[NOMBRE];
    float vFloat;
    Estructura *newEstructura = NULL;
    system("cls");

    printf("ALTA\n\n");
    id = getAvailableID(pArrayEstructura);
    printf("ID: %d\n", id);
    getString(vString, "STRING:\t", NOMBRE);
    primerasLetrasMayusculas(vString);
    vInt = getIntBetween(0,99999, "INT:\t");
    vFloat = getFloatBetween(0,9999999, "FLOAT:\t");

    newEstructura = estructura_newParametros(&id, vString, &vInt, &vFloat);
    ll_add(pArrayEstructura, newEstructura);

    ///c_empleadoDadoDeAlta();
    pausaYClear();
    system("cls");
    return 1;
}

int controller_listEstructura(LinkedList* pArrayEstructura) {
    Estructura *auxEstructura;
    int len = ll_len(pArrayEstructura);
    int f;
    system("cls");

    //list_header();
    renglon();
    for(f=0; f<len; f++) {

        auxEstructura = (Estructura*)ll_get(pArrayEstructura, f);
        if (auxEstructura!=NULL) {
            estructura_print(auxEstructura);
        }
    }
    //list_end();
    return len;
}

int controller_editEstructura(LinkedList* pArrayEstructura) {
    int debug;
    int id;
    int index;
    system("cls");

    renglon();
    ll_sort(pArrayEstructura, sortByID, 1);
    debug = controller_listEstructura(pArrayEstructura);
    renglon();
    id = getInt("Ingrese ID:\t");
    index = indexFromID(pArrayEstructura, &id);

    if (index>=0) {
        editMenu(pArrayEstructura, &index);
    } else {
        system("cls");
        printf("NO SE ENCONTRO\n");
        pausaYClear();
    }

    return debug;
}

int controller_removeEstructura(LinkedList* pArrayEstructura) {
    int debug;
    int id;
    int index;
    Estructura *auxEstructura;
    system("cls");

    renglon();
    ll_sort(pArrayEstructura, sortByID, 1);
    debug = controller_listEstructura(pArrayEstructura);
    renglon();
    id = getInt("    Ingrese ID:\t");
    index = indexFromID(pArrayEstructura, &id);
    system("cls");

    if (index>=0) {
        auxEstructura = (Estructura*)ll_get(pArrayEstructura, index);
        if (auxEstructura!=NULL) {
            estructura_printOne(auxEstructura);
            if ( pregunta("Dar de baja? S/N\t") ) {
                debug = ll_remove(pArrayEstructura, index);
                printf("DADO DE BAJA\n");
            }
        }
    } else {
        printf("NO SE ENCONTRO\n");
        pausaYClear();
    }

    return debug;
}

int controller_sortEstructura(LinkedList* pArrayEstructura) {
    short opcion;
    int order;
    int debug = 0;
    system("cls");

    printf("ORDENAR\n\n"
           "1 - Por ID\n"
           "2 - Por string\n"
           "3 - Por int\n"
           "4 - Por float\n"
           "  ------------------\n"
           "5 - Atr%cs\n\n", 160);
    opcion = getShortBetween(1, 5, "Ingrese opcion:\t");
    if (opcion!=5) {
        order = askForOrder();
    }
    switch (opcion) {
        case 1 : {
            if (order>=0) {
                debug = ll_sort(pArrayEstructura, sortByID, order);
                controller_listEstructura(pArrayEstructura);
                pausaYClear();
            }
            break;
        }
        case 2 : {
            if (order>=0) {
                debug = ll_sort(pArrayEstructura, sortByString, order);
                controller_listEstructura(pArrayEstructura);
                pausaYClear();
            }
            break;
        }
        case 3 : {
            if (order>=0) {
                debug = ll_sort(pArrayEstructura, sortByInt, order);
                controller_listEstructura(pArrayEstructura);
                pausaYClear();
            }
            break;
        }
        case 4 : {
            if (order>=0) {
                debug = ll_sort(pArrayEstructura, sortByFloat, order);
                controller_listEstructura(pArrayEstructura);
                pausaYClear();
            }
            break;
        }
    }
    system("cls");
    return debug;
}

int controller_filterEstructura(LinkedList* pArrayEstructura) {
    int debug;
    short opcion;
    LinkedList *listaTemp = NULL;
    system("cls");

    printf("FILTRAR\n\n"
           "1 - Int m%cs de 10\n"
           "2 - Por letra\n"
           "3 - Desde\n"
           "4 - Hasta\n"
           "5 - Los 5 ints m%cs grandes\n"
           "  -----------------\n"
           "6 - Atr%cs\n\n", 160, 160, 160);
    opcion = getShortBetween(1,6, "Ingrese opcion:\t");

    switch (opcion) {
        case 1 : {  /* Int >10 */
            listaTemp = ll_filter(pArrayEstructura, intMasDe10);
            break;
        }
        case 2 : {  /* Por letra */
            char letra;
            letra = getChar("Ingrese una letra:\t");
            letra = toupper(letra);
            listaTemp = ll_filter_letra(pArrayEstructura, filtrarPorLetra, letra);
            break;
        }
        case 3 : {  /* Desde */
            int limite = getInt("Desde:\t");
            listaTemp = ll_filter_limite(pArrayEstructura, filtrarLimiteVariableInt, limite, 1);
            break;
        }
        case 4 : {  /* Hasta */
            int limite = getInt("Hasta:\t");
            listaTemp = ll_filter_limite(pArrayEstructura, filtrarLimiteVariableInt, limite, 0);
            break;
        }
        case 5 : {  /* Los 5 más grandes */
            listaTemp = ll_filter_max(pArrayEstructura, sortByInt, 5, 1);
            break;
        }
        case 6 : {  /* Atrás */
            system("cls");
        }
    }
    if (opcion!=6) {
        if (!ll_isEmpty(listaTemp)) {
            debug = controller_listEstructura(listaTemp);
        } else {
            system("cls");
            printf("NO ENCONTRO\n");
        }
        pausaYClear();
    }
    debug = ll_deleteLinkedList(listaTemp);
    return debug;
}

int controller_saveAsText(char* path , LinkedList* pArrayEstructura) {
    FILE *pFile;
    Estructura *EstructuraAux;
    int size = ll_len(pArrayEstructura);
    char aux[200];
    short f;

    pFile = fopen(path, "w");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            EstructuraAux = (Estructura*)ll_get(pArrayEstructura, f);
            sprintf(aux,
                    "%d,%s,%d,%f\n",
                    EstructuraAux->id, EstructuraAux->variableString, EstructuraAux->variableInt, EstructuraAux->variableFloat);
            fprintf(pFile, aux);
        }
    }
    fclose(pFile);
    return size;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayEstructura) {
    FILE *pFile;
    Estructura *EstructuraAux;
    int size = ll_len(pArrayEstructura);
    short f;
    int count = 0;

    pFile = fopen(path, "wb");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            EstructuraAux = ll_get(pArrayEstructura, f);
            fwrite(EstructuraAux,
                   sizeof(Estructura),
                   1,
                   pFile);
            count++;
        }
    }
    fclose(pFile);
    return count;
}

////////////////////////////////////////////////////////////////////////////////////


int indexFromID(LinkedList *pArrayEstructura, int *id) {
    Estructura *auxEstructura;
    int len = ll_len(pArrayEstructura);
    int f;
    int index = -1;

    //printf("LEN: %d\n", len);
    for(f=0; f<len; f++) {

        auxEstructura = (Estructura*)ll_get(pArrayEstructura, f);
        if (auxEstructura!=NULL && auxEstructura->id==*id) {
            index = f;
        }
    }
    return index;
}

int getAvailableID(LinkedList *pArrayEstructura) {
    int newID = 0;
    Estructura *EstructuraAux;
    int len = ll_len(pArrayEstructura);
    int listOfIDs[len];
    short encontroLibre=0;
    short f;

    for (f=0 ; f<len ; f++) {
        EstructuraAux = ll_get(pArrayEstructura, f);
        *(listOfIDs+f) = EstructuraAux->id;
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

int edit_string(Estructura *auxEstructura) {
    int debug = 0;
    char string[NOMBRE];

    getString(string, "\nNUEVO STRING:\t", NOMBRE);
    primerasLetrasMayusculas(string);
    system("cls");
    estructura_printFromStack(&(auxEstructura->id),
                            string,
                            &(auxEstructura->variableInt),
                            &(auxEstructura->variableFloat) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        debug = estructura_setVariableString(auxEstructura, string);
        estructura_printOne(auxEstructura);
        printf("\nVARIABLE STRING MODIFICADA\n");
        pausaYClear();
    }
    return debug;
}

int edit_int(Estructura *auxEstructura) {
    int debug = 0;
    int vInt;

    vInt = getIntBetween(0,99999, "\nNUEVO INT:  ");
    system("cls");
    estructura_printFromStack(&(auxEstructura->id),
                            auxEstructura->variableString,
                            &vInt,
                            &(auxEstructura->variableFloat) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        debug = estructura_setVariableInt(auxEstructura, vInt);
        estructura_printOne(auxEstructura);
        printf("\nVARIABLE INT MODIFICADA\n");
        pausaYClear();
    }
    return debug;
}

int edit_float(Estructura *auxEstructura) {
    int debug = 0;
    float vFloat;

    vFloat = getFloatBetween(0, 9999999, "\nNUEVO FLOAT:\t");
    system("cls");
    estructura_printFromStack(&(auxEstructura->id),
                            auxEstructura->variableString,
                            &(auxEstructura->variableInt),
                            &vFloat);

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        debug = estructura_setVariableFloat(auxEstructura, vFloat);
        estructura_printOne(auxEstructura);
        printf("\nVARIABLE FLOAT MODIFICADA\n");
        pausaYClear();
    }
    return debug;
}

int editMenu(LinkedList *pArrayEstructura, int *index) {
    int debug = 0;
    Estructura *auxEstructura;

    short option;
    auxEstructura = (Estructura*)ll_get(pArrayEstructura, *index);

    if (auxEstructura!=NULL) {
        system("cls");
        estructura_printOne(auxEstructura);
        printf("MODIFICAR\n\n"
               "1 - String\n"
               "2 - Int\n"
               "3 - Float\n"
               "  --------------\n"
               "4 - Atr%cs\n\n", 160);
        option = getShortBetween(1, 4, "Ingrese opcion:\t");

        switch (option) {
            case 1 : {  /* String */
                debug = edit_string(auxEstructura);
                break;
            }
            case 2 : {  /* Int */
                debug = edit_int(auxEstructura);
                break;
            }
            case 3 : {  /* Float */
                debug = edit_float(auxEstructura);
                break;
            }
            case 4 : {  /* Atrás */
                system("cls");
            }
        }

    }
    return debug;
}

int askForOrder() {
    short option;

    system("cls");
    printf("ORDENAR\n\n"
           "1 - Orden ascendente\n"
           "2 - Orden descendente\n"
           "  ------------------------\n"
           "3 - Atr%cs\n\n", 160);
    option = getShortBetween(1, 3, "Escoja orden:\t");
    switch (option) {
        case 2 : {
            option = 0;
            break;
        }
        case 3 : {
            option = -1;
        }
    }
    return option;
}
