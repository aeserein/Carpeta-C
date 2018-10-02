#include "programa.h"

void imprimirMenu() {
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
    printf("3. Salir\n\n");

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
    printf("   -------------------------------------\n");
    printf("3. Salir\n\n");

    opcion = getShortBetween(1,3,"Ingrese opcion:\t");
    printf("\n");
    switch (opcion) {
        case 1 : { /*Por apellido*/
            order = getIntBetween(0,1,"Seleccione orden\n0. Decreciente\n1. Creciente:\t");
            sortEmployeesByLastName(arrayEmployees, len, order);
            employee_printEmployees(arrayEmployees, len);
            break;
        }
        case 2 : { /*Por sector*/
            order = getIntBetween(0,1,"Seleccione orden\n0. Decreciente\n1. Creciente:\t");
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
    printf("Total de salarios:\t%.2f\n" , totalSalaries);
    printf("Promedio de salarios:\t%.2f\n" , averageSalary);
    printf("Empleados por encima del promedio:\t%d\n" , aboveAverage);
}

short menuModificar(employee arrayEmployees[], int len, int index) {
    short opcion;
    short valueChanged = 0;

    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n");
    printf("   -------------------------------------\n");
    printf("5. Atr%cs\n\n", 160);

    opcion = getShortBetween(1,5,"Ingrese opcion:\t");
    printf("\n");
    switch (opcion) {
        case 1 : { /*Nombre*/
            getString(arrayEmployees[index].name, "Ingrese nuevo nombre:\t", NOMBRE);
            valueChanged = 1;
            break;
        }
        case 2 : { /*Apellido*/
            getString(arrayEmployees[index].lastName, "Ingrese nuevo apellido:\t", NOMBRE);
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

void programaPrincipal() {

    short opcion;
    int id;
    int debug;
    int index;
    short valueChanged;
    employee arrayEmployees[CANT_EMPLEADOS];
    employee_init(arrayEmployees, CANT_EMPLEADOS);

    do {
        imprimirMenu();
        opcion = getShortBetween(1, 5, "Ingrese opcion:\t");

        switch(opcion) {
            case 1 : { /*Alta*/
                getEmployeeValues(arrayEmployees, CANT_EMPLEADOS);
                pausaYClear();
                break;
            }
            case 2 : { /*Modificar*/
                system("cls");
                debug = employee_printEmployees(arrayEmployees, CANT_EMPLEADOS);
                id = getInt("Ingrese ID del empleado:\t");
                index = employee_findEmployeeById(arrayEmployees, CANT_EMPLEADOS, id);

                printf("%5s\t%18s\t%18s\t%6s\t%4s\n" , "ID" , "Nombre" , "Apellido" , "Salario" , "Sector");
                employee_printThisEmployee(arrayEmployees[index]);

                valueChanged = menuModificar(arrayEmployees, CANT_EMPLEADOS, index);
                if (valueChanged) {
                    employee_printThisEmployee(arrayEmployees[index]);
                }
                break;
            }
            case 3 : {
                system("cls");
                debug = employee_printEmployees(arrayEmployees, CANT_EMPLEADOS);
                id = getInt("Ingrese ID del empleado:\t");
                employee_removeEmployee(arrayEmployees, CANT_EMPLEADOS, id);
                break;
            }
            case 4 : {
                system("cls");
                informar(arrayEmployees, CANT_EMPLEADOS);
                break;
            }
            case 5 : { break; } /*Salir del programa*/
        }
    } while (opcion!=5);
}
