#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
    hours = getInt("                          Carga horaria:\t");
    salary = getInt("                          Salario:\t");

    newEmployee = employee_newParametros(&id, name, &hours, &salary);
    ll_add(pArrayListEmployee, newEmployee);

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {
    Employee *auxEmployee;
    int len = ll_len(pArrayListEmployee);
    int f;

    ll_sort(pArrayListEmployee, sortByID, 1);
    system("cls");
    //printf("LEN: %d\n", len);
    for(f=0; f<len; f++) {

        auxEmployee = (Employee*)ll_get(pArrayListEmployee, f);
        if (auxEmployee!=NULL) {
            employee_print(auxEmployee);
        }
    }
    return len;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee) {
    int debug;
    int id;
    int index;
    system("cls");

    renglon();
    debug = controller_ListEmployee(pArrayListEmployee);
    renglon();
    id = getInt("Ingrese ID:\t");
    index = indexFromID(pArrayListEmployee, &id);

    if (index>=0) {
        editMenu(pArrayListEmployee, index);
    } else {
        c_noSeEncontroEmpleado();
    }

    return debug;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee) {
    int debug;
    int id;
    int index;
    Employee *auxEmployee;
    system("cls");

    renglon();
    debug = controller_ListEmployee(pArrayListEmployee);
    renglon();
    id = getInt("Ingrese ID:\t");
    index = indexFromID(pArrayListEmployee, &id);

    if (index>=0) {
        auxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
        if (auxEmployee!=NULL) {
            system("cls");
            employee_print(auxEmployee);
            if ( pregunta("Dar de baja? S/N\t") ) {
                debug = ll_remove(pArrayListEmployee, index);
                c_empleadoDadoDeBaja();
            }
        }
    } else {
        c_noSeEncontroEmpleado();
    }

    return debug;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee) {
    short option;
    int order;
    int debug = 0;
    system("cls");

    printf("   Ordenar\n"
           "   ---------------\n"
           "1. Por ID\n"
           "2. Por nombre\n"
           "3. Por carga horaria\n"
           "4. Por salario\n"
           "   ---------------\n"
           "5. Atr%cs\n\n", 160);
    option = getShortBetween(1, 5, "Ingrese opcion:\t");

    switch (option) {
        case 1 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByID, order);
            }
            break;
        }
        case 2 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByName, order);
            }
            break;
        }
        case 3 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortByHours, order);
            }
            break;
        }
        case 4 : {
            order = askForOrder();
            if (order>=0) {
                debug = ll_sort(pArrayListEmployee, sortBySalario, order);
            }
            break;
        }
    }
    return debug;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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




    printf("Cantidad: %d", count);
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
    getString(name, "    Nuevo nombre:\t", NOMBRE);
    primerasLetrasMayusculas(name);
    employee_printFromStack(&(auxEmployee->id),
                            name,
                            &(auxEmployee->horasTrabajadas),
                            &(auxEmployee->sueldo) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        employee_setNombre(auxEmployee, name);
        employee_print(auxEmployee);
        c_nombreModificado();
        debug = 1;
    }
    return debug;
}

int edit_hours(Employee *auxEmployee) {
    int hours;
    int debug = 0;
    hours = getInt("Nueva carga horaria:  ");
    employee_printFromStack(&(auxEmployee->id),
                            auxEmployee->nombre,
                            &hours,
                            &(auxEmployee->sueldo) );

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        employee_setHorasTrabajadas(auxEmployee, hours);
        employee_print(auxEmployee);
        c_horasModificado();
        debug = 1;
    }
    return debug;
}

int edit_salary(Employee *auxEmployee) {
    int salary;
    int debug = 0;
    salary = getInt("Nuevo salario:\t");
    employee_printFromStack(&(auxEmployee->id),
                            auxEmployee->nombre,
                            &(auxEmployee->horasTrabajadas),
                            &salary);

    if ( pregunta("Esta seguro? S/N\t") ) {
        system("cls");
        debug = employee_setSueldo(auxEmployee, salary);
        employee_print(auxEmployee);
        c_salarioModificado();
        debug = 1;
    }
    return debug;
}

int editMenu(LinkedList *pArrayListEmployee, int index) {
    Employee *auxEmployee;
    int debug = 0;
    short option;
    auxEmployee = (Employee*)ll_get(pArrayListEmployee, index);

    if (auxEmployee!=NULL) {
        system("cls");
        employee_print(auxEmployee);
        printf("1. Nombre\n"
               "2. Horas\n"
               "3. Salario\n"
               "   --------------\n"
               "4. Atr%cs\n\n", 160);
        option = getShortBetween(1, 4, "Ingrese opcion:\t");

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

////////////////////////////////////////////////////////////////////////////////////

int askForOrder() {
    short option;

    system("cls");
    printf("   Orden\n\n"
           "   ------------------\n"
           "1. Ascendente\n"
           "2. Descendente\n"
           "   ------------------\n"
           "3. Atr%cs", 160);
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

void c_empleadoDadoDeBaja(){
    printf("\n                                    /");
    printf("\n _________________________         /");
    printf("\n|                         |       /");
    printf("\n|  Empleado dado de baja  |   %c  /", 92);
    printf("\n|_________________________|    %c/", 92);
}

void c_noSeEncontroEmpleado() {
    printf("\n\n");
    printf("\n ____________________________");
    printf("\n|                            |");
    printf("\n|  No se encontr%c empleado   |", 162);
    printf("\n|____________________________|");
}

void c_nombreModificado() {
    renglon();
    printf("                                  /\n");
    printf(" _______________________         /\n");
    printf("|                       |       /\n");
    printf("|   Nombre modificado   |   %c  /\n", 92);
    printf("|_______________________|    %c/", 92);
}

void c_horasModificado() {
    renglon();
    printf("                                         /\n");
    printf(" ______________________________         /\n");
    printf("|                              |       /\n");
    printf("|   Carga horaria modificada   |   %c  /\n", 92);
    printf("|______________________________|    %c/", 92);
}

void c_salarioModificado() {
    renglon();
    printf("                                   /\n");
    printf(" ________________________         /\n");
    printf("|                        |       /\n");
    printf("|   Salario modificado   |   %c  /\n", 92);
    printf("|________________________|    %c/", 92);
}

void c_altaDeEmpleado() {
    renglon(); renglon();
    printf("                           _____________________\n");
    printf("                          |                     |\n");
    printf("                          |  Alta de empleado   |\n");
    printf("                          |_____________________|\n\n\n");
}

void c_noHayEmpleadosEnElSistema() {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modifica  ");
    for (f=0 ; f<36 ; f++) {
        printf("%c", 178);
    }
    printf("                |\n"
           "    |    5. Baja de e|                                    |               |\n"
           "    |    6. Listar em|   No hay empleados en el sistema   |               |\n"
           "    |    7. Ordenar e|____________________________________|               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void c_primeroCargueUnArchivo() {
        short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Mod ");
    for (f=0 ; f<49 ; f++) {
        printf("%c", 178);
    }
    printf("         |\n"
           "    |    5. Baj|                                                 |        |\n"
           "    |    6. Lim|   No se puede calcular ID                       |        |\n"
           "    |    7. Ord|   Por favor, cargue la lista desde un archivo   |        |\n"
           "    |__________|_________________________________________________|________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n");
}

void c_listaCargada(amount) {
    short f;
    system("cls");
    renglon(); renglon();
    printf("     _____________________________________________________________________\n"
           "    |                                                                     |\n"
           "    |    1. Cargar desde el archivo data.csv (modo texto)                 |\n"
           "    |    2. Cargar desde el archivo data.bin (modo binario)               |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    3. Alta de empleado                                              |\n"
           "    |    4. Modificar  ");
    for (f=0 ; f<33 ; f++) {
        printf("%c", 178);
    }
    printf("                  |\n"
           "    |    5. Baja de em|                                 |                 |\n"
           "    |    6. Listar emp|   Archivo cargado               |                 |\n"
           "    |    7. Ordenar em|   Se encontraron %d empleados   |                 |\n"
           "    |_________________|_________________________________|_________________|\n"
           "    |                                                                     |\n"
           "    |    8. Guardar empleados en el archivo data.csv (modo texto)         |\n"
           "    |    9. Guardar empleados en el archivo data.bin (modo binario)       |\n"
           "    |_____________________________________________________________________|\n"
           "    |                                                                     |\n"
           "    |    10. Salir                                                        |\n"
           "    |_____________________________________________________________________|\n\n", amount);
}
