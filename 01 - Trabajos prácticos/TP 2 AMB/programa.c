#include "programa.h"

void printMenu() {
    printf("    ** Base de datos - Empleados **\n\n");

    printf("1. Alta de empleado\n"
           "2. Modificar datos\n"
           "3. Dar empleado de baja\n"
           "4. Informar\n"
           "   -----------------------------\n"
           "5. Salir\n\n");
}

void informar(employee arrayEmployees[], int len) {
    short opcion;

    printf("1. Ver listado de empleados\n");
    printf("2. Ver total y promedio de salarios,\n   y empleados por encima del promedio\n");
    printf("   -------------------------------------\n");
    printf("3. Atr%cs\n\n", 160);

    opcion = getShortBetween(1,3,"Ingrese opcion:\t");
    switch (opcion) {
        case 1 : { /*Listado*/
            system("cls");
            menuDeListado(arrayEmployees, len);
            break;
        }
        case 2 : { /*Salarios*/
            showSalaries(arrayEmployees, len);
            break;
        }
        case 3 : { break; } /*Salir*/
    }
    pausaYClear();
}

void menuDeListado(employee arrayEmployees[], int len) {
    short opcion;
    int order;

    printf("1. Ordenar por apellido\n");
    printf("2. Ordenar por sector\n");
    printf("   ----------------------------------\n");
    printf("3. Atr%cs\n\n",160);

    opcion = getShortBetween(1,3,"Ingrese opcion:\t");
    order = getIntBetween(0,1,"\nSeleccione orden:\n0. Decreciente\n1. Creciente:\t");
    switch (opcion) {
        case 1 : { /*Por apellido*/
            system("cls");
            sortEmployeesByLastName(arrayEmployees, len, order);
            employee_printEmployees(arrayEmployees, len);
            break;
        }
        case 2 : { /*Por sector*/
            system("cls");
            sortEmployeesBySector(arrayEmployees, len, order);
            employee_printEmployees(arrayEmployees, len);
            break;
        }
        case 3 : { break; } /*Salir*/
    }
}

void showSalaries(employee arrayEmployees[], int len) {
    float totalSalaries = 0;
    int countSalaries = 0;
    float averageSalary;
    int aboveAverage = 0;

    short f;
    for (f=0 ; f<len ; f++) {
        if (arrayEmployees[f].isEmpty==FALSE) {
            totalSalaries += arrayEmployees[f].salary;
            countSalaries++;
        }
    }
    averageSalary = (float)totalSalaries/countSalaries;
    for (f=0 ; f<len ; f++) {
        if (arrayEmployees[f].isEmpty==FALSE && arrayEmployees[f].salary>averageSalary) {
            aboveAverage++;
        }
    }
    printf("\nTotal de salarios:\t%.2f\n" , totalSalaries);
    printf("Promedio de salarios:\t%.2f\n" , averageSalary);
    printf("Empleados por encima del promedio: %d\n" , aboveAverage);
}

short modifyData(employee arrayEmployees[], int len, int index) {
    short opcion;
    short valueChanged = 0;

    printf("\n1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n");
    printf("   -----------------\n");
    printf("5. Atr%cs\n\n", 160);

    opcion = getShortBetween(1,5,"Ingrese opcion:\t");
    printf("\n");
    switch (opcion) {
        case 1 : { /*Nombre*/
            getString(arrayEmployees[index].name, "Ingrese nuevo nombre:\t", NAME_LENGTH);
            primerasLetrasMayusculas(arrayEmployees[index].name);
            valueChanged = 1;
            break;
        }
        case 2 : { /*Apellido*/
            getString(arrayEmployees[index].lastName, "Ingrese nuevo apellido:\t", NAME_LENGTH);
            primerasLetrasMayusculas(arrayEmployees[index].lastName);
            valueChanged = 1;
            break;
        }
        case 3 : { /*Salario*/
            arrayEmployees[index].salary = getFloat("Ingrese nuevo salario:\t");
            valueChanged = 1;
            break;
        }
        case 4 : { /*Sector*/
            arrayEmployees[index].sector = getInt("Ingrese nuevo sector:");
            valueChanged = 1;
            break;
        }
        case 5 : { break; } /*Atrás*/
    }
    return valueChanged;
}

int mainProgramHere() {

    short opcion;
    int id;
    int index;
    int debug = 0;
    short valueChanged;

    employee arrayEmployees[AMMOUNT_EMPLOYEES];
    employee employeeAux;
    employee_init(arrayEmployees, AMMOUNT_EMPLOYEES);

    do {
        printMenu();
        opcion = getShortBetween(1, 5, "Ingrese opcion:\t");

        switch(opcion) {
            case 1 : { /*Alta*/
                getEmployeeValues(arrayEmployees, AMMOUNT_EMPLOYEES);
                pausaYClear();
                break;
            }
            case 2 : { /*Modificar*/
                if (isThisEmpty(arrayEmployees, AMMOUNT_EMPLOYEES)) {
                    printf("\nNo hay empleados en el sistema.\n");
                } else {
                    system("cls");
                    printf("\n    ** Modificar datos **\n");
                    debug = sortEmployeesByLastName(arrayEmployees, AMMOUNT_EMPLOYEES, UP);
                    debug = employee_printEmployees(arrayEmployees, AMMOUNT_EMPLOYEES);
                    id = getInt("\nIngrese ID del empleado:\t");
                    index = employee_findEmployeeById(arrayEmployees, AMMOUNT_EMPLOYEES, id);

                    if(index>=0) {

                        employee_printOneEmployeeWithHeader(arrayEmployees[index]);
                        employeeAux = arrayEmployees[index];

                        valueChanged = modifyData(arrayEmployees, AMMOUNT_EMPLOYEES, index);
                        if (valueChanged && pregunta("Esta seguro? S/N\t")) {
                            printf("\n");
                            employee_printOneEmployeeWithHeader(arrayEmployees[index]);
                        } else {
                            arrayEmployees[index] = employeeAux;
                        }
                    } else {
                        printf("\nNo se encontr%c el ID %d\n", 162, id);
                    }
                }
                pausaYClear();
                break;
            }
            case 3 : {
                if (isThisEmpty(arrayEmployees, AMMOUNT_EMPLOYEES)) {
                    printf("\nNo hay empleados en el sistema.\n");
                } else {
                    system("cls");
                    printf("\n    ** Dar empleados de baja **\n");
                    debug = employee_printEmployees(arrayEmployees, AMMOUNT_EMPLOYEES);
                    id = getInt("\nIngrese ID del empleado:\t");

                    employee_removeEmployee(arrayEmployees, AMMOUNT_EMPLOYEES, id);

                    printf("\n");
                }
                pausaYClear();
                break;
            }
            case 4 : {
                if (isThisEmpty(arrayEmployees, AMMOUNT_EMPLOYEES)) {
                    printf("\nNo hay empleados en el sistema.\n");
                    pausaYClear();
                } else {
                    system("cls");
                    informar(arrayEmployees, AMMOUNT_EMPLOYEES);
                }
                break;
            }
            case 5 : { break; } /*Salir del programa*/
        }
    } while (opcion!=5);

    return debug;
}
