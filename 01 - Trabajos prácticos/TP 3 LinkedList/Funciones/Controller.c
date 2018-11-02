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
    Employee employeeAux;

    Employee *puntero;
    Employee unEmpleado = {3,"TERCERO",33,3333};
    Employee otroEmpleado = {4,"CUARTO",44,4444};

    debug = ll_add(pArrayListEmployee, &unEmpleado);
    puntero = (Employee*)ll_get(pArrayListEmployee, 2);
    employee_print(puntero);

    debug = ll_add(pArrayListEmployee, &otroEmpleado);
    puntero = (Employee*)ll_get(pArrayListEmployee, 3);
    employee_print(puntero);

    /*
    pFile = fopen("data.csv", "r");


    while( !feof(pFile) ) {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);
        printf("STRINGS\tID: %s\tNOMBRE: %s\tHORAS: %s\tSALARIO: %s\n", id, name, hours, salary);
        if (count==0) { //salteo primer renglón
            count++;
            continue;
        }

        idAux = atoi(id);
        hoursAux = atoi(hours);
        salaryAux = atoi(salary);

        printf("AUX\tID: %d\tNOMBRE: %s\tHORAS: %d\tSALARIO: %d\n", idAux, name, hoursAux, salaryAux);
        debug = employee_setId(&employeeAux, idAux);
        printf("TEST - ID: %d\n", debug);

        debug = employee_setNombre(&employeeAux, name);
        printf("TEST - NOMBRE: %d\n", debug);

        debug = employee_setHorasTrabajadas(&employeeAux, hoursAux);
        printf("TEST - HORAS: %d\n", debug);

        debug = employee_setSueldo(&employeeAux, salaryAux);
        printf("TEST - SUELDO: %d\n", debug);

        debug = ll_add(pArrayListEmployee, &employeeAux);
        printf("TEST - ADD: %d\n", debug);

        printf("STRUCT\tID: %d\tNOMBRE: %s\tHORAS: %d\tSALARIO: %d\n", employeeAux.id, employeeAux.nombre, employeeAux.horasTrabajadas, employeeAux.sueldo);
        count++;
    }
    //employee_delete(employeeAux);
    fclose(pFile);
    */
    return count;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
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
    Employee *puntero;
    int len = ll_len(pArrayListEmployee);
    int f;

    printf("LEN: %d\n", len);
    if(len>0) {

        for(f=0; f<len; f++) {
            puntero = (Employee*)ll_get(pArrayListEmployee, f);
            if (puntero!=NULL) {
                employee_print(puntero);
            }
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

