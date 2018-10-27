#ifndef PROGRAMA_H_INCLUDED
#define PROGRAMA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Funciones/ArrayEmployees.h"

/** \brief Prints main menu
 *
 * \param void
 * \return void
 */
void printMenu(void);

/** \brief  Prints menu that shows information of the employees in the system
 *          Is accessed from the main menu and goes back to it when finishing
 *
 * \param employee[]    Employees array
 * \param int           Length of the array
 * \return void
 *
 */
void informar(employee[], int);

/** \brief  Menu for showing sheets on the screen
 *
 * \param employee[]    Employees array
 * \param int           Length of the array
 * \return void
 */
void menuDeListado(employee[], int);

/** \brief  Shows salaries info
 *          Total, average and amount of employees above the average
 *
 * \param employee[]    Employees array
 * \param int           Length of the array
 * \return void
 */
void showSalaries(employee[], int);

/** \brief  Menu for modifying data for a specific employee
 *          Will ask what field the user wants to change
 *
 * \param employee[]    Employees array
 * \param int           Length of the array
 * \param int           Index of the employee to be modified
 * \return short        0 if nothing was changed
 *                      1 if the user modified a field
 */
short modifyData(employee[], int, int);

/** \brief  Main program.
 *
 * \param void  Receives nothing from main function
 * \return int  Variable used for debugging
 */
int mainProgramHere(void);


#endif // PROGRAMA_H_INCLUDED
