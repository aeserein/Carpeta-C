#include "estructura.h"

eEmpleado* empleado_new() {
    eEmpleado *puntero;
    puntero = (eEmpleado*)malloc(sizeof(eEmpleado));
    return puntero;
}

eEmpleado* empleado_newParametros(int *id, char* nombre, char* direccion, int *horas) {

    eEmpleado *puntero;
    puntero = (eEmpleado*)malloc(sizeof(eEmpleado));

    if (puntero!=NULL) {
        puntero->id = *id;
        strcpy(puntero->nombre, nombre);
        strcpy(puntero->direccion, direccion);
        puntero->horas = *horas;
        puntero->sueldo = -1;
    }
    return puntero;
}

int empleado_delete(eEmpleado *puntero) {
    int debug = 0;
    if (puntero!=NULL) {
        free(puntero);
        debug = 1;
    }
    return debug;
}

////////////////////////////////////////////////////////////////////////////////////

int empleado_setId(eEmpleado* this, int id) {
    int debug = 0;
    if (this!=NULL) {
        this->id = id;
        debug = 1;
    }
    return debug;
}

int empleado_getId(eEmpleado* this) {
    int id = -1;
    if (this!=NULL) {
        id = this->id;
    }
    return id;
}

/////////////////////////////////////////////////////////////////////////////////////

int empleado_setNombre(eEmpleado* this, char* nombre) {
    int debug = 0;
    if (this!=NULL) {
        strcpy(this->nombre, nombre);
        debug = 1;
    }
    return debug;
}

char* empleado_getNombre(eEmpleado* this) {
    if (this!=NULL) {
        return this->nombre;
    } else {
        return NULL;
    }
}

int empleado_setDireccion(eEmpleado* this, char* direccion) {
    int debug = 0;
    if (this!=NULL) {
        strcpy(this->direccion, direccion);
        debug = 1;
    }
    return debug;
}

char* empleado_getDireccion(eEmpleado* this) {
    if (this!=NULL) {
        return this->nombre;
    } else {
        return NULL;
    }
}

int empleado_setHoras(eEmpleado* this, int horas){
    int debug = 0;
    if (this!=NULL) {
        this->horas = horas;
        debug = 1;
    }
    return debug;
}

int empleado_getHoras(eEmpleado* this) {
    int variableInt = -1;
    if (this!=NULL) {
        variableInt = this->horas;
    }
    return variableInt;
}

int empleado_setSueldo(eEmpleado* this, int sueldo){
    int debug = 0;
    if (this!=NULL) {
        this->sueldo = sueldo;
        debug = 1;
    }
    return debug;
}

int empleado_getSueldo(eEmpleado* this) {
    int variableInt = -1;
    if (this!=NULL) {
        variableInt = this->sueldo;
    }
    return variableInt;
}

/////////////////////////////////////////////////////////////////////////////////////

int empleado_print(eEmpleado *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf(" |  %5d  |", puntero->id);
        printf("   %16.16s  |", puntero->nombre);
        printf("  %16.16s  |", puntero->direccion);
        printf("    %4d  |", puntero->horas);
        printf(" %7d  |\n", puntero->sueldo);

        debug = 1;
    }
    return debug;
}

int empleado_printSinHoras(eEmpleado *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf("    | %5.d   |", puntero->id);
        printf("        %20.20s   |", puntero->nombre);
        printf("   %20.20s   |\n", puntero->direccion);

        debug = 1;
    }
    return debug;
}

int empleado_printOne(eEmpleado *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        //list_header();
        printf("--------------------------------------------------------------\n");
        printf(" ID: %5d\t", puntero->id);
        printf("TAM: %15.15s\t", puntero->nombre);
        printf("DIRECCION: %15.15s\t", puntero->direccion);
        printf("HORAS: %5d\n", puntero->horas);
        printf("--------------------------------------------------------------\n");
        //list_end();

        debug = 1;
    }
    return debug;
}

void empleado_printFromStack(int *id, char *nombre, char *direccion, int *horas) {

    //list_header();
    printf(" ID: %5d\t", *id);
    printf("TAM: %15.15s\t", nombre);
    printf("DIRECCION: %15.15s\t", direccion);
    printf("HORAS: %5d\n", *horas);
    //list_end();
}

/////////////////////////////////////////////////////////////////////////////////////

void list_header() {
    renglon();
    printf("  __________________________________________________________________________\n"
           " |         |                     |                    |          |          |\n"
           " |     ID  |             Nombre  |         Direccion  |   Horas  |  Sueldo  |\n"
           " |_________|_____________________|____________________|__________|__________|\n"
           " |         |                     |                    |          |          |\n");
}

void list_end() {
    printf(" |_________|_____________________|____________________|__________|__________|\n\n");
}

void list_headerSinHoras() {
    renglon();
    printf("     ____________________________________________________________________\n"
           "    |         |                               |                          |\n"
           "    |     ID  |                      Nombre   |             Direcci%cn    |\n"
           "    |_________|_______________________________|__________________________|\n"
           "    |         |                               |                          |\n", 162);
}

void list_endSinHoras() {
    printf("    |_________|_______________________________|__________________________|\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////

int sortByID(void *e1, void *e2) {
    eEmpleado *eEmpleado1;
    eEmpleado1 = (eEmpleado*)e1;
    eEmpleado *eEmpleado2;
    eEmpleado2 = (eEmpleado*)e2;
    int r = 0;

    if ( eEmpleado1->id > eEmpleado2->id ) {
        r = 1;
    } else if ( eEmpleado1->id < eEmpleado2->id ) {
        r = -1;
    }
    return r;
}

int sortByNombre(void *e1, void *e2) {
    eEmpleado *eEmpleado1;
    eEmpleado1 = (eEmpleado*)e1;
    eEmpleado *eEmpleado2;
    eEmpleado2 = (eEmpleado*)e2;
    return ( stricmp(eEmpleado1->nombre, eEmpleado2->nombre) );
}

int filtrarLimite(void *elemento, float limite) {
    eEmpleado *empleado;
    int r = -2;

    if (elemento!=NULL) {
        empleado = (eEmpleado*)elemento;
        r = 0;

        if ((float)empleado->sueldo > limite) {
            r = 1;
        } else if ((float)empleado->sueldo < limite) {
            r = -1;
        }
    }
    return r;
}

void calcularSueldo(void *elemento) {

    eEmpleado *empleado;
    int sueldo=0, horas;
    empleado = (eEmpleado*)elemento;

    horas = empleado_getHoras(empleado);

    if (horas<80 || horas>240) {
        return -1;
    }

    if (horas<=120) {
        sueldo += (horas*180);
    } else if (horas<=160) {
        sueldo += (120*180);
        horas = horas-120;
        sueldo += (horas*240);
    } else {
        sueldo += (120*180);
        horas = horas-120;
        sueldo += (40*240);
        horas = horas-40;
        sueldo += (horas*350);
    }
    empleado_setSueldo(empleado, sueldo);
}

int getSueldo(void* elemento) {
    eEmpleado *empleado;
    int sueldo = -1;

    if (elemento!=NULL) {
        empleado = (eEmpleado*)elemento;
        sueldo = empleado_getSueldo(empleado);
    }
    return sueldo;
}
