#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "estructura.h"

/** \brief  Retira informaci�n del archivo de texto y la coloca en nuevos empleados
 *
 * \param   pFile FILE*
 * \param   pArrayListEstructura LinkedList*
 * \return  int  -   Cantidad de empleados leidos
 */
int parser_eEmpleadoFromText(FILE* pFile , LinkedList* pArrayListEstructura);

/** \brief  Retira informaci�n del archivo binario y la coloca en nuevos empleados
 *
 * \param   pFile FILE*
 * \param   pArrayListEstructura LinkedList*
 * \return  int  -   Cantidad de empleados leidos
 */
int parser_eEmpleadoFromBinary(FILE* pFile , LinkedList* pArrayListEstructura);

#endif // parser_H_INCLUDED
