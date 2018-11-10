#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
    FILE *pFile = NULL;
    int count = 0;

    pFile = fopen(path, "r");
    if (pFile!=NULL) {
        count = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    fclose(pFile);

    return count;
}

long controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
    FILE *pFile = NULL;
    long count = 0;

    pFile = fopen(path, "rb");
    if (pFile!=NULL) {
        count = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    fclose(pFile);

    return count;
}

int controller_addEmployee(LinkedList* pArrayListEmployee) {
    int id, hours, salary;
    char name[NOMBRE];
    Employee *newEmployee = NULL;
    system("cls");

    c_altaDeEmpleado();
    id = getAvailableID(pArrayListEmployee);
    printf("                          ID:\t%d\n"
           "                          ________\n\n", id);
    getString(name, "                          Nombre:\t", NOMBRE);
    primerasLetrasMayusculas(name);
    hours = getIntBetween(1,99999, "                          Horas:\t");
    salary = getIntBetween(1,9999999, "                          Salario:\t");

    newEmployee = employee_newParametros(&id, name, &hours, &salary);
    ll_add(pArrayListEmployee, newEmployee);

    c_empleadoDadoDeAlta();
    getch();
    system("cls");
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee) {
    Employee *auxEmployee;
    int len = ll_len(pArrayListEmployee);
    int f;
    system("cls");
    //printf("LEN: %d\n", len);
    list_header();
    for(f=0; f<len; f++) {

        auxEmployee = (Employee*)ll_get(pArrayListEmployee, f);
        if (auxEmployee!=NULL) {
            employee_print(auxEmployee);
        }
    }
    list_end();
    return len;
}

int controller_editEmployee(LinkedList* pArrayListEmployee) {
    int debug;
    int id;
    int index;
    system("cls");

    renglon();
    debug = controller_ListEmployee(pArrayListEmployee);
    renglon();
    id = getInt("    Ingrese ID:\t");
    index = indexFromID(pArrayListEmployee, &id);

    if (index>=0) {
        editMenu(pArrayListEmployee, &index);
    } else {
        system("cls");
        c_noSeEncontroEmpleado();
        pausaYClear();
    }

    return debug;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee) {
    int debug;
    int id;
    int index;
    Employee *auxEmployee;
    system("cls");

    renglon();
    debug = controller_ListEmployee(pArrayListEmployee);
    renglon();
    id = getInt("    Ingrese ID:\t");
    index = indexFromID(pArrayListEmployee, &id);
    system("cls");

    if (index>=0) {
        auxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        if (auxEmployee!=NULL) {
            employee_printOne(auxEmployee);
            if ( pregunta("Dar de baja? S/N\t") ) {
                debug = ll_remove(pArrayListEmployee, index);
                c_empleadoDadoDeBaja();
            }
            getch();
            system("cls");
        }
    } else {
        c_noSeEncontroEmpleado();
        pausaYClear();
    }

    return debug;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee) {
    short option;
    int order;
    int debug = 0;
    system("cls");

    printSortMenu();
    option = getShortBetween(1, 5, "                     Ingrese opcion:\t");

    switch (option) {
        case 1 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByID, order);
                controller_ListEmployee(pArrayListEmployee);
                pausaYClear();
            }
            break;
        }
        case 2 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByName, order);
                controller_ListEmployee(pArrayListEmployee);
                pausaYClear();
            }
            break;
        }
        case 3 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByHours, order);
                controller_ListEmployee(pArrayListEmployee);
                pausaYClear();
            }
            break;
        }
        case 4 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortBySalario, order);
                controller_ListEmployee(pArrayListEmployee);
                pausaYClear();
            }
            break;
        }
    }
    system("cls");
    return debug;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee) {
    FILE *pFile;
    Employee *employeeAux;
    int size = ll_len(pArrayListEmployee);
    char aux[200];
    short f;

    pFile = fopen(path, "w");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            employeeAux = (Employee*)ll_get(pArrayListEmployee, f);
            sprintf(aux,
                    "%d,%s,%d,%d\n",
                    employeeAux->id, employeeAux->nombre, employeeAux->horasTrabajadas, employeeAux->sueldo);
            fprintf(pFile, aux);
        }
    }
    fclose(pFile);
    return size;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee) {
    FILE *pFile;
    Employee *employeeAux;
    int size = ll_len(pArrayListEmployee);
    short f;
    int count = 0;

    pFile = fopen(path, "wb");
    if (pFile!=NULL) {
        for (f=0 ; f<size ; f++) {
            employeeAux = ll_get(pArrayListEmployee, f);
            fwrite(employeeAux,
                   sizeof(Employee),
                   1,
                   pFile);
            count ++;
        }
    }
    fclose(pFile);
    return count;
}

////////////////////////////////////////////////////////////////////////////////////


int indexFromID(LinkedList *pArrayListEmployee, int *id) {
    Employee *auxEmployee;
    int len = ll_len(pArrayListEmployee);
    int f;
    int index = -1;

    //printf("LEN: %d\n", len);
    for(f=0; f<len; f++) {

        auxEmployee = (Employee*)ll_get(pArrayListEmployee, f);
        if (auxEmployee!=NULL && auxEmployee->id==*id) {
            index = f;
        }
    }
    return index;
}

int getAvailableID(LinkedList *pArrayListEmployee) {
    int newID = 0;
    Employee *employeeAux;
    int len = ll_len(pArrayListEmployee);
    int listOfIDs[len];
    short encontroLibre=0;
    short f;

    for (f=0 ; f<len ; f++) {
        employeeAux = ll_get(pArrayListEmployee, f);
        *(listOfIDs+f) = employeeAux->id;
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

int edit_name(Employee *auxEmployee) {
    char name[NOMBRE];
    int debug = 0;
    getString(name, "\n                     Nuevo nombre:\t", NOMBRE);
    primerasLetrasMayusculas(name);
    system("cls");
    employee_printFromStack(&(auxEmployee->id),
                            name,
                            &(auxEmployee->horasTrabajadas),
                            &(auxEmployee->sueldo) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        employee_setNombre(auxEmployee, name);
        employee_printOne(auxEmployee);
        c_nombreModificado();
        debug = 1;
        getch();
        system("cls");
    }
    return debug;
}

int edit_hours(Employee *auxEmployee) {
    int hours;
    int debug = 0;
    hours = getIntBetween(1,99999, "\n                     Nueva carga horaria:  ");
    system("cls");
    employee_printFromStack(&(auxEmployee->id),
                            auxEmployee->nombre,
                            &hours,
                            &(auxEmployee->sueldo) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        employee_setHorasTrabajadas(auxEmployee, hours);
        employee_printOne(auxEmployee);
        c_horasModificado();
        debug = 1;
        getch();
        system("cls");
    }
    return debug;
}

int edit_salary(Employee *auxEmployee) {
    int salary;
    int debug = 0;
    salary = getIntBetween(1, 9999999, "\n                     Nuevo salario:\t");
    system("cls");
    employee_printFromStack(&(auxEmployee->id),
                            auxEmployee->nombre,
                            &(auxEmployee->horasTrabajadas),
                            &salary);

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        debug = employee_setSueldo(auxEmployee, salary);
        employee_printOne(auxEmployee);
        c_salarioModificado();
        debug = 1;
        getch();
        system("cls");
    }
    return debug;
}

int editMenu(LinkedList *pArrayListEmployee, int *index) {
    Employee *auxEmployee;
    int debug = 0;
    short option;
    auxEmployee = (Employee*)ll_get(pArrayListEmployee, *index);

    if (auxEmployee!=NULL) {
        system("cls");
        employee_printOne(auxEmployee);
        printEditMenu();
        option = getShortBetween(1, 4, "                     Ingrese opcion:\t");

        switch (option) {
            case 1 : { /// Nombre
                debug = edit_name(auxEmployee);
                break;
            }
            case 2 : { /// Horas
                debug = edit_hours(auxEmployee);
                break;
            }
            case 3 : { /// Salario
                debug = edit_salary(auxEmployee);
                break;
            }
            case 4 : { /// Atrás
                system("cls");
            }
        }
    }
    return debug;
}

int sortByID(void *e1, void *e2) {
    Employee *employee1;
    employee1 = (Employee*)e1;
    Employee *employee2;
    employee2 = (Employee*)e2;
    int r = 0;

    if ( employee1->id > employee2->id ) {
        r = 1;
    } else if ( employee1->id < employee2->id ) {
        r = -1;
    }
    return r;
}

int sortByName(void *e1, void *e2) {
    Employee *employee1;
    employee1 = (Employee*)e1;
    Employee *employee2;
    employee2 = (Employee*)e2;
    return ( stricmp(employee1->nombre, employee2->nombre) );
}

int sortByHours(void *e1, void *e2) {
    Employee *employee1;
    employee1 = (Employee*)e1;
    Employee *employee2;
    employee2 = (Employee*)e2;
    int r = 0;

    if ( employee1->horasTrabajadas > employee2->horasTrabajadas ) {
        r = 1;
    } else if ( employee1->horasTrabajadas < employee2->horasTrabajadas ) {
        r = -1;
    }
    return r;
}

int sortBySalario(void *e1, void *e2) {
    Employee *employee1;
    employee1 = (Employee*)e1;
    Employee *employee2;
    employee2 = (Employee*)e2;
    int r = 0;

    if ( employee1->sueldo > employee2->sueldo ) {
        r = 1;
    } else if ( employee1->sueldo < employee2->sueldo ) {
        r = -1;
    }
    return r;
}

int askForOrder() {
    short option;

    system("cls");
    printOrderMenu();
    option = getShortBetween(1, 3, "                     Escoja orden:\t");
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

