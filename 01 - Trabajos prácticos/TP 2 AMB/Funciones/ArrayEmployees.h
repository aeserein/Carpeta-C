#ifndef ESTRUCTURAEMPLEADOS_H_INCLUDED
#define ESTRUCTURAEMPLEADOS_H_INCLUDED

#include "ingresos.h"
#include "strings.h"
#include "flow.h"
#define TRUE 1
#define FALSE 0
#define BAJA -1
#define NAME_LENGTH 51
#define AMMOUNT_EMPLOYEES 1000
#define UP 1
#define DOWN 0

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    float salary;
    int sector;
    int isEmpty;
} employee;

/** \brief Sets all 'isEmpty' flags as TRUE (1)
 *
 *  \param   list    employee    Pointer to array of employees
 *  \param   len     int         Array length
 *  \return  int     Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int employee_init(employee[],int);


/** \brief  Returns wether the employee array is empty or not
 *
 * \param   employee[]  Employee array
 * \param   int         Length of the array
 * \return  int         1 = It is empty
 *                      0 = It's not
 */
int isThisEmpty(employee[], int);

//////////////////////////////////////////////////////////////////

/** \brief  Searchs for an employee by his/her unique ID
 *
 * \param   employee[]  Employee array
 * \param   limit int  Length of the array
 * \param   id int      ID of the employee the program is looking for
 * \return  int         It's index in the array
 */
int employee_findEmployeeById(employee[] ,int limit, int id);

/** \brief  Gets the first ID available in the array
 *
 *  \param  employee[]  Employee array
 *  \param  limit int  Length of the array
 *  \return int         The ID for the next employee
 */
int employee_getNextID(employee[] ,int limit);

/** \brief  Gets the index for the first available position in the array
 *
 *  \param  listado employee[]  Employee array
 *  \param  limit int          Length of the array
 *  \return int                 An available index
 */
int employee_getFreeSpace(employee listado[],int limit);

//////////////////////////////////////////////////////////////////

/** \brief  Prints a single employee
 *
 * \param   employee
 * \return void
 */
void employee_printThisEmployee(employee);

/** \brief  Prints the header for the employee sheet
 *
 *          Has to be called before showing
 *          any employee or list of employees on screen
 *
 *  \param void
 *  \return void
 */
void printSheetHeader(void);


/** \brief Prints the last line of the sheet
 *
 *          Has to be called after showing employees on the screen
 *
 *  \param void
 *  \return void
 *
 */
void printSheetEnd(void);

/** \brief  Prints an empty line in the sheet
 *
 *          Not recommended anywhere outside
 *          functions 'employee_printOneEmployeeWithHeader'
 *                and 'employee_printEmployees'
 *
 * \param void
 * \return void
 *
 */
void printSheetLine(void);

/** \brief  Prints only one employee in a sheet
 *
 * \param   employee
 * \return  int         0 - Only used to debug
 */
int employee_printOneEmployeeWithHeader(employee);

/** \brief Prints a sheet with all employees in the system
 *
 * \param employee[]    Employee array
 * \param int           Length of the array
 * \return int          0 - Only used to debug
 */
int employee_printEmployees(employee[] ,int);

//////////////////////////////////////////////////////////////////

/** \brief  Receives data for all fields in the employee structure
 *          Adds them to the main employee array
 *
 * \param employee[]    Employee array
 * \param int           Length of the array
 * \param int           ID of the employee
 * \param char[]        First name
 * \param char[]        Last name
 * \param float         Salary
 * \param int           Sector
 * \return int          -1 - Used only to debug
 */
int addEmployee(employee[],int,int,char[],char[],float,int);

/** \brief  Checks for free space in the array
 *          Gets data from the user
 *          Calls addEmployee to add them to the array
 *
 * \param employee[]    Employee array
 * \param int           Length of the array
 * \return int          -2, -1 or 0 - Used only to debug
 */
int getEmployeeValues(employee[],int);

/** \brief  Removes employee from the system
 *          Will ask the user to confirm
 *
 * \param employee[]    Employee array
 * \param limit int    Length of the array
 * \param id int        ID of the employee to remove
 * \return void
 */
void employee_removeEmployee(employee[] ,int limit, int id);

//////////////////////////////////////////////////////////////////

/** \brief  Sorts employee list by name in both increasing or decreasing order
 *          Does not show the employees on screen
 *
 * \param employee[]    Employee array
 * \param int           Length of the array
 * \param int           Order - 1 for increasing, 0 for decreasing
 * \return int          0 - Only used to debug
 */
int sortEmployeesByLastName(employee[], int, int);

/** \brief  Sorts employee list by sector in both increasing or decreasing order
 *          Does not show the employees on screen
 *
 * \param employee[]    Employee array
 * \param int           Length of the array
 * \param int           Order - 1 for increasing, 0 for decreasing
 * \return int          0 - Only used to debug
 */
int sortEmployeesBySector(employee[], int, int);

#endif // ESTRUCTURAEMPLEADOS_H_INCLUDED
