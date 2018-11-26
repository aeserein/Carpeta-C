#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "estructura.h"
#include "parser.h"
#include "ingresos.h"
#include "strings.h"
#include "flow.h"

/** \brief  Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEstructura);

/** \brief  Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
long controller_loadFromBinary(char* path , LinkedList* pArrayListEstructura);

/** \brief  Alta de empleados
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_addEstructura(LinkedList* pArrayListEstructura);

/** \brief  Modificar datos de empleado
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_editEstructura(LinkedList* pArrayListEstructura);

/** \brief  Baja de empleado
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_removeEstructura(LinkedList* pArrayListEstructura);

/** \brief  Listar empleados
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_listeEmpleado(LinkedList* pArrayListEstructura);

int controller_listeEmpleadoConSueldos(LinkedList* pArrayListEstructura);

/** \brief  Ordenar empleados
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_sortEstructura(LinkedList* pArrayListEstructura);

/** \brief  Filtrar empleados
 *
 * \param   pArrayEstructura LinkedList*
 * \return  int
 */
int controller_filterEstructura(LinkedList* pArrayEstructura);

/** \brief  Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEstructura);

/** \brief  Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param   path char*
 * \param   pArrayListEstructura LinkedList*
 * \return  int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEstructura);

////////////////////////////////////////////////////////////////////////////////////

/** \brief  Busca índice de un empleado de ID n
 *
 * \param   LinkedList  *pArrayListEstructura
 * \param   int     -   *id
 * \return  int     -   index
 */
int indexFromID(LinkedList *pArrayListEstructura, int *id);

/** \brief  Calcula el mínimo ID disponible posible
 *
 * \param   LinkedList *pArrayListEstructura
 * \return  int     -   Un ID libre
 */
int getAvailableID(LinkedList *pArrayListEstructura);

/** \brief  Pide nuevo nombre, pregunta por confirmación y reemplaza
 *
 * \param   Estructura *auxEstructura
 * \return  int     -   Debug
 */
 int edit_name(eEmpleado *auxEmpleado);

/** \brief  Pide nueva carga horaria, pregunta por confirmación y reemplaza
 *
 * \param   Estructura *auxEstructura
 * \return  int     -   Debug
 */
int edit_hours(eEmpleado *auxEmpleado);

/** \brief  Pide nuevo salario, pregunta por confirmación y reemplaza
 *
 * \param   Estructura *auxEstructura
 * \return  int     -   Debug
 */
int edit_salary(eEmpleado *auxEmpleado);

/** \brief  Muestra el empleado a modificar elegido por el usuario
 *          Pregunta qué campo quiere cambiar y llama a la función correspondiente
 *
 * \param   LinkedList *pArrayListEstructura
 * \param   int     -   *index
 * \return  int     -   Debug
 */
int editMenu(LinkedList *pArrayListEstructura, int *index);

/** \brief  Ordena dos empleados por ID
 *
 * \param   void *e1
 * \param   void *e2
 * \return  int -   1   - El primero es mayor
 *                  -1  - El segundo es mayor
 *                  0   - Son iguales
 */
int sortByID(void *e1, void *e2);

/** \brief  Ordena dos empleados por nombre
 *
 * \param   void *e1
 * \param   void *e2
 * \return  int -   1   - El primero es mayor
 *                  -1  - El segundo es mayor
 *                  0   - Empiezan con la misma letra
 */
int sortByName(void *e1, void *e2);

/** \brief  Ordena dos empleados por carga horaria
 *
 * \param   void *e1
 * \param   void *e2
 * \return  int -   1   - La primera es mayor
 *                  -1  - La segunda es mayor
 *                  0   - Son iguales
 */
int sortByHours(void *e1, void *e2);

/** \brief  Ordena dos empleados por salario
 *
 * \param   void *e1
 * \param   void *e2
 * \return  int -   1   - El primero es mayor
 *                  -1  - El segundo es mayor
 *                  0   - Son iguales
 */
int sortBySalario(void *e1, void *e2);

/** \brief  Pregunta por orden ascendente o descendiente
 *
 * \return  int     -   1   - Orden ascendente
 *                      0   - Orden descendiente
 *                      -1  - Usuario escogió volver
 */
int askForOrder();

#endif // CONTROLLER_H_INCLUDED
