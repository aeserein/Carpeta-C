#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flow.h"

typedef struct {
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief  Crea empleado en memoria dinámica
 *          Devuelve puntero
 *
 * \return  Employee*
 */
Employee* employee_new();

/** \brief  Crea empleado en memoria dinámica con los datos completos
 *          Devuelve puntero a ese empleado
 *
 * \param   int*    -   ID
 * \param   char*   -   Nombre
 * \param   int*   -    Horas
 * \param   int*   -    Sueldo
 * \return  Employee*
 */
Employee* employee_newParametros(int *id, char* nombre, int *horasTrabajadas, int *salario);

/** \brief  Elimina empleado
 *
 * \param   Employee *puntero
 * \return  int     -   Debug
 */
int employee_delete(Employee *puntero);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Asigna valor al campo ID de un empleado
 *
 * \param   Employee*
 * \param   int     -   ID a asignar
 * \return  int     -   Debug   -   0 - Si no asignó
 *                                  1 - Si asignó
 */
int employee_setId(Employee* this, int id);

/** \brief  Devuelve ID de un empleado
 *
 * \param   Employee*
 * \return  int     -   ID
 */
int employee_getId(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Asigna valor al campo nombre de un empleado
 *
 * \param   Employee*
 * \param   char*     -   nombre a asignar
 * \return  int     -   Debug   -   0 - Si no asignó
 *                                  1 - Si asignó
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief  Devuelve nombre de un empleado
 *
 * \param   Employee*
 * \return  char*     -   Nombre
 */
char* employee_getNombre(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Asigna valor al campo horasTrabajadas de un empleado
 *
 * \param   Employee*
 * \param   int     -   ID a asignar
 * \return  int     -   Debug   -   0 - Si no asignó
 *                                  1 - Si asignó
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief  Devuelve horasTrabajadas de un empleado
 *
 * \param   Employee*
 * \return  int     -   Horas
 */
int employee_getHorasTrabajadas(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Asigna valor al campo sueldo de un empleado
 *
 * \param   Employee*
 * \param   int     -   sueldo a asignar
 * \return  int     -   Debug   -   0 - Si no asignó
 *                                  1 - Si asignó
 */
int employee_setSueldo(Employee* this, int sueldo);

/** \brief  Devuelve sueldo de un empleado
 *
 * \param   Employee*
 * \return  int     -   ID
 */
int employee_getSueldo(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Imprime un empleado de la lista
 *
 * \param   Employee *puntero
 * \return  int     -   Debug   -   0 - Si no pudo imprimir
 *                                  1 - Si pudo imprimir
 */
int employee_print(Employee *puntero);

/** \brief  Imprime un empleado de la lista con header
 *
 * \param   Employee *puntero
 * \return  int     -   Debug   -   0 - Si no pudo imprimir
 *                                  1 - Si pudo imprimir
 */
int employee_printOne(Employee *puntero);

/** \brief  Imprime un empleado de la lista con valores desde el stack
 *          Para mostrar un empleado con datos nuevos antes de modificar los valores verdaderos
 *
 * \param   Employee *puntero
 * \return  void
 */
void employee_printFromStack(int *id, char *name, int *hours, int *salary);

/** \brief  Imprime las direcciones de memoria de cada dato de un empleado
 *          Solo para debuguear
 *
 * \param   Employee *puntero
 * \return  int     -   Debug   -   0 - Si no pudo imprimir
 *                                  1 - Si pudo imprimir
 */
int employee_DEBUG_printMemory(Employee *puntero);

/////////////////////////////////////////////////////////////////////////////////////

/** \brief  Imprime cabecera de lista
 *
 * \return  void
 */
void list_header(void);

/** \brief  Imprime cierre de la lista
 *
 * \return  void
 */
void list_end(void);

#endif // employee_H_INCLUDED
