#include <stdio.h>
#include <stdlib.h>
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
    char id[6], name[NOMBRE], hours[10], salary[20];
    int idAux;
    int hoursAux;
    int salaryAux;
    int count = 0;
    int debug = -999;

    pFile = fopen("data.csv", "r");

    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);
        //printf("STRINGS\tID: %s \tNOMBRE: %10s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);
        if (count==0) { //Salteo primer renglón
            count++;
            continue;
        }

        idAux = atoi(id);
        hoursAux = atoi(hours);
        salaryAux = atoi(salary);

        //printf("AUX\tID: %d \tNOMBRE: %10s\tHORAS: %d\tSALARIO: %d\n\n", idAux, name, hoursAux, salaryAux);

        Employee* employeeAux = employee_newParametros(&idAux, name, &hoursAux, &salaryAux);
        debug = ll_add(pArrayListEmployee, employeeAux);
        employeeAux = ll_get(pArrayListEmployee, count-1);
        employee_print(employeeAux);

        count++;
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
    FILE *pFile = NULL;
    char id[6], name[NOMBRE], hours[10], salary[20];
    int idAux;
    int hoursAux;
    int salaryAux;
    int count = 0;
    int debug = -999;
    Employee employeeAux;

    pFile = fopen("data.csv", "rb");

    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);
        printf("STRINGS\tID: %s \tNOMBRE: %10s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);
        if (count==0) { //salteo primer renglón
            count++;
            continue;
        }

        idAux = atoi(id);
        hoursAux = atoi(hours);
        salaryAux = atoi(salary);

        printf("AUX\tID: %d \tNOMBRE: %10s\tHORAS: %d\tSALARIO: %d\n", idAux, name, hoursAux, salaryAux);
        debug = employee_setId(&employeeAux, idAux);
        debug = employee_setNombre(&employeeAux, name);
        debug = employee_setHorasTrabajadas(&employeeAux, hoursAux);
        debug = employee_setSueldo(&employeeAux, salaryAux);

        /*
        debug = ll_add(pArrayListEmployee, &employeeAux);
        printf("TEST - ADD: %d\n", debug);
        */

        printf("STRUCT\tID: %d \tNOMBRE: %10s\tHORAS: %d\tSALARIO: %d\n\n", employeeAux.id, employeeAux.nombre, employeeAux.horasTrabajadas, employeeAux.sueldo);
        count++;
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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
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
    Employee *aux = NULL;
    int len = ll_len(pArrayListEmployee);
    int f;

    printf("LEN: %d\n", len);
    if(len>0) {

        for(f=0; f<len; f++) {

            aux = employee_new();
            aux = (Employee*)ll_get(pArrayListEmployee, f);
            if (aux!=NULL) {
                employee_print(aux);
            }
            free(aux);
        }
    }
    return len;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

