#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "ingresos.h"
#include "strings.h"
#include "flow.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
long controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

////////////////////////////////////////////////////////////////////////////////////

int indexFromID(LinkedList *pArrayListEmployee, int *id);
int getAvailableID(LinkedList *pArrayListEmployee);
int edit_name(Employee *auxEmployee);
int edit_hours(Employee *auxEmployee);
int edit_salary(Employee *auxEmployee);
int editMenu(LinkedList *pArrayListEmployee, int index);
int sortByID(void *e1, void *e2);
int sortByName(void *e1, void *e2);
int sortByHours(void *e1, void *e2);
int sortBySalario(void *e1, void *e2);

////////////////////////////////////////////////////////////////////////////////////

int askForOrder();
void c_empleadoDadoDeBaja(void);
void c_noSeEncontroEmpleado(void);
void c_nombreModificado(void);
void c_horasModificado(void);
void c_salarioModificado(void);
void c_altaDeEmpleado(void);
void c_empleadoDadoDeAlta(void);
void c_noHayEmpleadosEnElSistema(void);
void c_primeroCargueUnArchivo(void);
void c_listaCargada(int amount);

void printEditMenu(void);

#endif // CONTROLLER_H_INCLUDED
