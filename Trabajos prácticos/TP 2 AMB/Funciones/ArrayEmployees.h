#ifndef ESTRUCTURAEMPLEADOS_H_INCLUDED
#define ESTRUCTURAEMPLEADOS_H_INCLUDED

#include "ingresos.h"
#include "strings.h"
#include "flow.h"
#define TAMANIO 10
#define TRUE 1
#define FALSE 0
#define BAJA -1
#define NOMBRE 51
#define CANT_EMPLEADOS 1000
#define UP 1
#define DOWN 0

typedef struct {
    int id;
    char name[NOMBRE];
    char lastName[NOMBRE];
    float salary;
    int sector;
    int isEmpty;
} employee;

/** \brief Sets all 'isEmpty' flags as TRUE (1)
 *
 * \param   list    employee    Pointer to array of employees
 * \param   len     int         Array length
 * \return  int     Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int employee_init(employee[],int len);

//////////////////////////////////////////////////////////////////

int employee_findEmployeeById(employee[] ,int limite, int id);
int employee_siguienteId(employee[] ,int limite);
int employee_buscarLugarLibre(employee listado[],int limite);

//////////////////////////////////////////////////////////////////

void employee_printThisEmployee(employee);
int employee_printEmployees(employee[] ,int);
void employee_mostrarListadoConBorrados(employee[] ,int);

//////////////////////////////////////////////////////////////////

int addEmployee(employee[],int,int,char[],char[],float,int);
int getEmployeeValues(employee[],int);
void employee_removeEmployee(employee[] ,int limite, int id);
void employee_modificacion(employee[] ,int limite, int id);

int sortEmployeesByLastName(employee[], int, int);
int sortEmployeesBySector(employee[], int, int);

#endif // ESTRUCTURAEMPLEADOS_H_INCLUDED
