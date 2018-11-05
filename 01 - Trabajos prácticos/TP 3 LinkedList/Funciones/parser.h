#ifndef parser_H_INCLUDED
#define parser_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../LinkedList.h"
#include "Employee.h"
#define NOMBRE 128

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif // parser_H_INCLUDED
