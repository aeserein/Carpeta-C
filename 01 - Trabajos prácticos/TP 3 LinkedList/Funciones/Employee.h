#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(int *id, char* nombre, int *horasTrabajadas, int *salario);
int employee_delete(Employee *puntero);

/////////////////////////////////////////////////////////////////////////////////////

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

/////////////////////////////////////////////////////////////////////////////////////

int employee_print(Employee *puntero);
void employee_printFromStack(int *id, char *name, int *hours, int *salary);
int employee_DEBUG_printMemory(Employee *puntero);

#endif // employee_H_INCLUDED
