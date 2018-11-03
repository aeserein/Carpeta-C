#include "Employee.h"

Employee* employee_new() {
    Employee *puntero;
    puntero = (Employee*)malloc(sizeof(Employee));
    return puntero;
}

Employee* employee_newParametros(int *id, char* nombre, int *horasTrabajadas, int *salario) {
    Employee *puntero;

    puntero = (Employee*)malloc(sizeof(Employee));

    if (puntero!=NULL) {
        puntero->id = *id;
        strcpy(puntero->nombre, nombre);
        puntero->horasTrabajadas = *horasTrabajadas;
        puntero->sueldo = *salario;
    }
    return puntero;
}

int employee_delete(Employee *puntero) {
    int debug = 0;
    if (puntero!=NULL) {
        free(puntero);
        debug = 1;
    }
    return debug;
}

/////////////////////////////////////////////////////////////////////////////////////

int employee_setId(Employee* this, int id) {
    int debug = 0;
    if (this!=NULL) {
        this->id = id;
        debug = 1;
    }
    return debug;
}

int employee_getId(Employee* this) {
    int id = -1;
    if (this!=NULL) {
        id = this->id;
    }
    return id;
}

/////////////////////////////////////////////////////////////////////////////////////

int employee_setNombre(Employee* this, char* nombre) {
    int debug = 0;
    if (this!=NULL) {
        strcpy(this->nombre, nombre);
        debug = 1;
    }
    return debug;
}

char* employee_getNombre(Employee* this) {
    if (this!=NULL) {
        return this->nombre;
    } else {
        return NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int debug = 0;
    if (this!=NULL) {
        this->horasTrabajadas = horasTrabajadas;
        debug = 1;
    }
    return debug;
}

int employee_getHorasTrabajadas(Employee* this) {
    int horasTrabajadas = -1;
    if (this!=NULL) {
        horasTrabajadas = this->horasTrabajadas;
    }
    return horasTrabajadas;
}

/////////////////////////////////////////////////////////////////////////////////////

int employee_setSueldo(Employee* this, int sueldo) {
    int debug = 0;
    if (this!=NULL) {
        this->sueldo = sueldo;
        debug = 1;
    }
    return debug;
}

int employee_getSueldo(Employee* this) {
    int sueldo = -1;
    if (this!=NULL) {
        sueldo = this->sueldo;
    }
    return sueldo;
}

/////////////////////////////////////////////////////////////////////////////////////

int employee_print(Employee *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf("   ID:\t%d\t", puntero->id);
        printf("NOMBRE:\t%.7s\t\t", puntero->nombre);
        printf("HORAS:\t%d\t\t", puntero->horasTrabajadas);
        printf("SUELDO:\t%d\n", puntero->sueldo);

        debug = 1;
    }
    return debug;
}

int employee_DEBUG_printMemory(Employee *puntero) {
    int debug = 0;
    if (puntero!=NULL) {

        printf("   &:\t%d\t", &(puntero->id));
        printf("&:\t%d\t\t", &(puntero->nombre));
        printf("&:\t%d\t\t", &(puntero->horasTrabajadas));
        printf("&:\t%d\n\n", &(puntero->sueldo));

        debug = 1;
    }
    return debug;
}
