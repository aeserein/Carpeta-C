#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../LinkedList.h"
#include "Employee.h"
#define NOMBRE 128

/** \brief  Retira información del archivo de texto y la coloca en nuevos empleados
 *
 * \param   pFile FILE*
 * \param   pArrayListEmployee LinkedList*
 * \return  int  -   Cantidad de empleados leidos
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief  Retira información del archivo binario y la coloca en nuevos empleados
 *
 * \param   pFile FILE*
 * \param   pArrayListEmployee LinkedList*
 * \return  int  -   Cantidad de empleados leidos
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // parser_H_INCLUDED
