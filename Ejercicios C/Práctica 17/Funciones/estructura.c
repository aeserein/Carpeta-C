#include "estructura.h"

Estructura* estructura_new() {
    Estructura *puntero;
    puntero = (Estructura*)malloc(sizeof(Estructura));
    return puntero;
}

Estructura* estructura_newParametros(int *id, char* variableString, int *variableInt, float *variableFloat) {

    Estructura *puntero;
    puntero = (Estructura*)malloc(sizeof(Estructura));

    if (puntero!=NULL) {
        puntero->id = *id;
        strcpy(puntero->variableString, variableString);
        puntero->variableInt = *variableInt;
        puntero->variableFloat = *variableFloat;
    }
    return puntero;
}

int estructura_delete(Estructura *puntero) {
    int debug = 0;
    if (puntero!=NULL) {
        free(puntero);
        debug = 1;
    }
    return debug;
}

////////////////////////////////////////////////////////////////////////////////////

int estructura_setId(Estructura* this, int id) {
    int debug = 0;
    if (this!=NULL) {
        this->id = id;
        debug = 1;
    }
    return debug;
}

int estructura_getId(Estructura* this) {
    int id = -1;
    if (this!=NULL) {
        id = this->id;
    }
    return id;
}

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableString(Estructura* this, char* variableString) {
    int debug = 0;
    if (this!=NULL) {
        strcpy(this->variableString, variableString);
        debug = 1;
    }
    return debug;
}

char* estructura_getVariableString(Estructura* this) {
    if (this!=NULL) {
        return this->variableString;
    } else {
        return NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableInt(Estructura* this, int variableInt){
    int debug = 0;
    if (this!=NULL) {
        this->variableInt = variableInt;
        debug = 1;
    }
    return debug;
}

int estructura_getVariableInt(Estructura* this) {
    int variableInt = -1;
    if (this!=NULL) {
        variableInt = this->variableInt;
    }
    return variableInt;
}

/////////////////////////////////////////////////////////////////////////////////////

int estructura_setVariableFloat(Estructura* this, float variableFloat) {
    int debug = 0;
    if (this!=NULL) {
        this->variableFloat = variableFloat;
        debug = 1;
    }
    return debug;
}

float estructura_get(Estructura* this) {
    float variableFloat = -1;
    if (this!=NULL) {
        variableFloat = this->variableFloat;
    }
    return variableFloat;
}

/////////////////////////////////////////////////////////////////////////////////////

int estructura_print(Estructura *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf("   ID: %6.d\t", puntero->id);
        printf("STRING: %20.20s\t", puntero->variableString);
        printf("INT: %8.d\t", puntero->variableInt);
        printf("FLOAT: %7.2f\n", puntero->variableFloat);

        debug = 1;
    }
    return debug;
}

int estructura_printOne(Estructura *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        //list_header();
        printf("--------------------------------------------------------------\n");
        printf("   ID: %6.d\t", puntero->id);
        printf("STRING: %20.20s\t", puntero->variableString);
        printf("INT: %8.d\t", puntero->variableInt);
        printf("FLOAT: %7.2f\n", puntero->variableFloat);
        printf("--------------------------------------------------------------\n");
        //list_end();

        debug = 1;
    }
    return debug;
}

void estructura_printFromStack(int *id, char *vString, int *vInt, float *vFloat) {

    //list_header();
    printf("   ID: %6d\t", *id);
    printf("STRING: %20.20s\t", vString);
    printf("INT: %8d\t", *vInt);
    printf("FLOAT: %7.2f\n", *vFloat);
    //list_end();
}

int estructura_DEBUG_printMemory(Estructura *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf("   &:\t%p\t", &(puntero->id));
        printf("&:\t%p\t\t", &(puntero->variableString));
        printf("&:\t%p\t\t", &(puntero->variableInt));
        printf("&:\t%p\n\n", &(puntero->variableFloat));

        debug = 1;
    }
    return debug;
}

/////////////////////////////////////////////////////////////////////////////////////

void list_header() {
    renglon();
    printf("     _____________________________________________________________________\n"
           "    |         |                              |            |               |\n"
           "    |     ID  |                      Nombre  |     Horas  |      Salario  |\n"
           "    |_________|______________________________|____________|_______________|\n"
           "    |         |                              |            |               |\n");
}

void list_end() {
    printf("    |_________|______________________________|____________|_______________|\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////

int sortByID(void *e1, void *e2) {
    Estructura *Estructura1;
    Estructura1 = (Estructura*)e1;
    Estructura *Estructura2;
    Estructura2 = (Estructura*)e2;
    int r = 0;

    if ( Estructura1->id > Estructura2->id ) {
        r = 1;
    } else if ( Estructura1->id < Estructura2->id ) {
        r = -1;
    }
    return r;
}

int sortByString(void *e1, void *e2) {
    Estructura *Estructura1;
    Estructura1 = (Estructura*)e1;
    Estructura *Estructura2;
    Estructura2 = (Estructura*)e2;
    return ( stricmp(Estructura1->variableString, Estructura2->variableString) );
}

int sortByInt(void *e1, void *e2) {
    Estructura *Estructura1;
    Estructura1 = (Estructura*)e1;
    Estructura *Estructura2;
    Estructura2 = (Estructura*)e2;
    int r = 0;

    if ( Estructura1->variableInt > Estructura2->variableInt ) {
        r = 1;
    } else if ( Estructura1->variableInt < Estructura2->variableInt ) {
        r = -1;
    }
    return r;
}

int sortByFloat(void *e1, void *e2) {
    Estructura *Estructura1;
    Estructura1 = (Estructura*)e1;
    Estructura *Estructura2;
    Estructura2 = (Estructura*)e2;
    int r = 0;

    if ( Estructura1->variableFloat > Estructura2->variableFloat ) {
        r = 1;
    } else if ( Estructura1->variableFloat < Estructura2->variableFloat ) {
        r = -1;
    }
    return r;
}

int intMasDe10(void *elemento) {
    Estructura *vEstructura;
    vEstructura = (Estructura*)elemento;

    return (vEstructura->variableInt>10);
}

int filtrarPorLetra(void *elemento, char letra) {
    Estructura *vEstructura;
    vEstructura = (Estructura*)elemento;

    return (vEstructura->variableString[0]==letra);
}

int filtrarLimiteVariableInt(void *elemento, int limite) {
    Estructura *vEstructura;
    vEstructura = (Estructura*)elemento;
    int r = 0;

    if (vEstructura->variableInt > limite) {
        r = 1;
    } else if (vEstructura->variableInt < limite) {
        r = -1;
    }
    return r;
}
