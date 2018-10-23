#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int employee_init (employee listado[],int len) {

    int retorno = -1;
    int i;
    if(len > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            listado[i].isEmpty = TRUE;
            listado[i].id= 0;
        }
    }
    return retorno;
}

int isThisEmpty(employee list[], int len) {
    int isIt = -1;
    int i;
    if(len > 0 && list != NULL) {
        isIt = TRUE;
        for(i=0; i<len; i++) {
            if (list[i].isEmpty==FALSE) {
                isIt = FALSE;
            }
        }
    }
    return isIt;
}

//////////////////////////////////////////////////////////////////

int employee_findEmployeeById(employee lista[] ,int limit, int id) {
    int retorno = -1;
    int i;
    if(limit > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limit;i++) {

            if(lista[i].isEmpty == FALSE && lista[i].id == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int employee_getNextID(employee lista[],int limit) {
    int retorno = -2;
    int i;
    if(limit > 0 && lista != NULL) {

        retorno = -1;

        for(i=0; i<limit; i++) {

            if(lista[i].isEmpty == TRUE && lista[i].id>retorno) {
                retorno=i+1;
            }
        }
    }
    return retorno;
}

int employee_getFreeSpace(employee lista[],int limit) {
    int retorno = -1;
    int i;
    if(limit > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limit;i++) {

            if(lista[i].isEmpty == TRUE) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

void employee_printThisEmployee(employee oneEmployee) {
     printf("  | %5d |", oneEmployee.id);
     printf("   %14.14s |", oneEmployee.name);
     printf("   %15.15s |", oneEmployee.lastName);
     printf("   $ %9.2f |", oneEmployee.salary);
     printf("   %7d |\n" , oneEmployee.sector);
}

void printSheetHeader() {
    printf("\n");
    printf("   __________________________________________________________________________\n");
    printSheetLine();
    printf("  | %5s |   %14s |    %14s |   %11s |   %7s |\n" , "ID" , "Nombre" , "Apellido" , "Salario" , "Sector");
    printSheetEnd();
    printSheetLine();
}

void printSheetEnd() {
    printf("  |_______|__________________|___________________|_______________|___________|\n");
}

void printSheetLine() {
    printf("  |       |                  |                   |               |           |\n");
}

int employee_printOneEmployeeWithHeader(employee oneEmployee) {
    printSheetHeader();
    employee_printThisEmployee(oneEmployee);
    printSheetEnd();
    return 0;
}

int employee_printEmployees(employee list[],int len) {
    int i;
    int retorno = -2;
    if(len > 0 && list != NULL) {
        retorno = -1;
        printSheetHeader();
        for(i=0; i<len; i++) {

            if(list[i].isEmpty==FALSE) {
                employee_printThisEmployee(list[i]);
                retorno = 0;
            }
        }
        printSheetEnd();
    }
    return retorno;
}

//////////////////////////////////////////////////////////////////

int addEmployee(employee list[],int len,int id,char name[],char lastName[],float salary,int sector) {
    int index;
    index = employee_getFreeSpace(list, len);

    list[index].id = id;
    list[index].isEmpty = FALSE;

    strcpy(list[index].name, name);
    strcpy(list[index].lastName, lastName);
    list[index].salary = salary;
    list[index].sector = sector;

    return -1;
}

int getEmployeeValues(employee list[],int len) {
    int id;
    char name[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    float salary;
    int sector;
    int retorno = -2;

    if(len > 0 && list != NULL) {

        id = employee_getNextID(list,len);
        retorno = -1;
        if(id >= 0) {

            getString(name, "\nNombre:\t\t", NAME_LENGTH);
            primerasLetrasMayusculas(name);
            getString(lastName, "Apellido:\t", NAME_LENGTH);
            primerasLetrasMayusculas(lastName);
            salary = getFloatBetween(0,999999,"Salario:\t");
            sector = getIntBetween(0,99999,"Sector:\t\t");
            retorno = 0;

            addEmployee(list, len, id, name, lastName, salary, sector);
        } else {
            printf("\nNo hay m%cs espacio en la plantilla.\n", 160);
        }
    }

    return retorno;
}

void employee_removeEmployee(employee lista[] ,int limit, int id) {
    short encontro = 0;
    limit--;

    for ( ; limit>=0 ; limit--) {
        if (lista[limit].isEmpty==FALSE && id==lista[limit].id) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {
        employee_printOneEmployeeWithHeader(lista[limit]);

        if (pregunta("Dar de baja? S/N\t")) {
            lista[limit].isEmpty = TRUE;;
            printf("\n\nEmpleado dado de baja.");
        }
    } else {
        printf("\nNo se encontr%c el ID %d." , 162, id);
    }
}

//////////////////////////////////////////////////////////////////

int sortEmployeesByLastName(employee list[], int len, int order) {
    short f, i;
    employee employeeAux;
    if (order==UP) {
        for (f=0 ; f<len-1 ; f++) {
            for (i=f+1 ; i<len ; i++) {
                if (list[i].isEmpty==FALSE && stricmp(list[f].lastName,list[i].lastName)==1) {
                    employeeAux = list[f];
                    list[f] = list[i];
                    list[i] = employeeAux;
                }
            }
        }
    } else {
        for (f=0 ; f<len-1 ; f++) {
            for (i=f+1 ; i<len ; i++) {
                if (list[i].isEmpty==FALSE && stricmp(list[f].lastName,list[i].lastName)==-1) {
                    employeeAux = list[f];
                    list[f] = list[i];
                    list[i] = employeeAux;
                }
            }
        }
    }

    return 0;
}

int sortEmployeesBySector(employee list[], int len, int order) {
    short f, i;
    employee employeeAux;
    if (order==UP) {
        for (f=0 ; f<len-1 ; f++) {
            for (i=f+1 ; i<len ; i++) {
                if (list[i].isEmpty==FALSE && list[f].sector>list[i].sector) {
                    employeeAux = list[f];
                    list[f] = list[i];
                    list[i] = employeeAux;
                }
            }
        }
    } else {
        for (f=0 ; f<len-1 ; f++) {
            for (i=f+1 ; i<len ; i++) {
                if (list[i].isEmpty==FALSE && list[f].sector<list[i].sector) {
                    employeeAux = list[f];
                    list[f] = list[i];
                    list[i] = employeeAux;
                }
            }
        }
    }

    return 0;
}
