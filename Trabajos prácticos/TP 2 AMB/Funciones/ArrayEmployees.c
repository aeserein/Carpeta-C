#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int employee_init( employee listado[],int len) {

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

//////////////////////////////////////////////////////////////////

int employee_findEmployeeById(employee lista[] ,int limite, int id) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

            if(lista[i].isEmpty == FALSE && lista[i].id == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int employee_siguienteId(employee lista[],int limite) {
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -1;

        for(i=0; i<limite; i++) {

            if(lista[i].isEmpty == TRUE && lista[i].id>retorno) {
                    retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}

int employee_buscarLugarLibre(employee lista[],int limite) {
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL) {

        retorno = -2;

        for(i=0;i<limite;i++) {

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
     printf("\n");
     printf("%5d\t", oneEmployee.id);
     printf("%18s\t", oneEmployee.name);
     printf("%18s\t", oneEmployee.lastName);
     printf("%6.2f\t", oneEmployee.salary);
     printf("%4d" , oneEmployee.sector);
}

int employee_printEmployees(employee list[],int len) {
    int i;
    int retorno = -2;
    if(len > 0 && list != NULL) {
        retorno = -1;
        printf("%5s\t%18s\t%18s\t%6s\t%4s\n" , "ID" , "Nombre" , "Apellido" , "Salario" , "Sector");
        for(i=0; i<len; i++) {

            if(list[i].isEmpty==FALSE) {
                employee_printThisEmployee(list[i]);
                retorno = 0;
            }
        }
        printf("\n");
    }
    return retorno;
}

void employee_mostrarListadoConBorrados(employee lista[],int limite) {
    int i;
    if(limite > 0 && lista != NULL) {

        for(i=0; i<limite; i++) {

            if(lista[i].isEmpty==TRUE) {
                employee_printThisEmployee(lista[i]);
            } else {
                printf("\n[Vacio]");
            }
        }
    }
}

//////////////////////////////////////////////////////////////////


int addEmployee(employee list[],int len,int id,char name[],char lastName[],float salary,int sector) {
    int index;
    index = employee_buscarLugarLibre(list, len);

    list[index].id = id;
    list[index].isEmpty = FALSE;

    strcpy(list[index].name, name);
    strcpy(list[index].lastName, lastName);
    list[index].salary = salary;
    list[index].sector = sector;

    return -1;
}

/*
int getEmployeeValues(employee list[],int len) {
    int id;
    char name[NOMBRE];
    char lastName[NOMBRE];
    float salary;
    int sector;
    int indice;
    int retorno = -1;

    if(len > 0 && list != NULL) {

        indice = employee_buscarLugarLibre(list,len);
        retorno = 0;
        if(indice >= 0) {

            id = employee_siguienteId(list, len);
            printf("\n");
            getString(name, "Nombre:\t", NOMBRE);
            getString(lastName, "Apellido:\t", NOMBRE);
            salary = getFloat("Salario:\t");
            sector = getInt("Sector:\t");
            retorno = 1;
        }
    }

    addEmployee(list, len, id, name, lastName, salary, sector);
    return retorno;
} */

int getEmployeeValues(employee list[],int len) {
    int indice;
    int retorno = -2;

    if(len > 0 && list != NULL) {

        indice = employee_buscarLugarLibre(list,len);
        retorno = -1;
        if(indice >= 0) {

            list[indice].id = employee_buscarLugarLibre(list, len);
            list[indice].isEmpty = FALSE;
            printf("\n");
            getString(list[indice].name, "Nombre:\t", NOMBRE);
            getString(list[indice].lastName, "Apellido:\t", NOMBRE);
            list[indice].salary = getFloat("Salario:\t");
            list[indice].sector = getInt("Sector:\t");
            retorno = 0;
        }
    }

    return retorno;
}

void employee_removeEmployee(employee lista[] ,int limite, int id) {
    short encontro = 0;
    limite--;

    for ( ; limite>=0 ; limite--) {
        if (lista[limite].isEmpty==FALSE && id==lista[limite].id) {
            encontro = 1;
            break;
        }
    }
    if (encontro) {

        employee_printThisEmployee(lista[limite]);
        printf("\n");

        if (pregunta("Dar de baja?\t")) {
            lista[limite].isEmpty = TRUE;;
            printf("\n\nEmpleado dado de baja.\n");
        }

    } else {
        printf("\nNo se encontr%c el ID %d\n" , 162, id);
    }
}

void employee_modificacion(employee lista[] ,int limite, int id) {
    short encontro = 0;
    // Variable auxiliar de cambio
    char nameAux[NOMBRE];
    char nameOriginal[NOMBRE];
    // Variable auxiliar de cambio
    limite--;

    for ( ; limite>=0 ; limite--) {
        if (lista[limite].isEmpty==1 && id==lista[limite].id) {
            encontro = 1;
            break;
        }
    }

    if (encontro) {

        employee_printThisEmployee(lista[limite]);
        printf("\n");

        //Dato a modificar
        strcpy(nameAux, "[Nombre modificado]");
        strcpy(nameOriginal, lista[limite].name);
        strcpy(lista[limite].name, nameAux);
        //Dato a modificar

        employee_printThisEmployee(lista[limite]);

        if (pregunta("[Pregunta]?\t")) {
            printf("[Mensaje de afirmacion]");
        } else {
            strcpy(lista[limite].name, nameOriginal);
        }

    } else {
        printf("\n[No encontr%c]\n" , 162);
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
