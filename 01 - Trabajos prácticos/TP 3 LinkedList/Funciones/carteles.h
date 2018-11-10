#ifndef CARTELES_H_INCLUDED
#define CARTELES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "flow.h"

/// \brief  Menús / Alertas para simular una interfaz

void menu(void);
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
void c_archivoYaCargado(void);
void c_archivoGuardado(void);
void printEditMenu(void);
void printSortMenu(void);
void printOrderMenu(void);

#endif // CARTELES_H_INCLUDED
