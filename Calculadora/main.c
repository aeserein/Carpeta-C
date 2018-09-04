/**************************************************************************
 *  Programa:   Calculadora
 *
 *  Objetivo:   Lee dos números
 *              Calcula suma, resta, multiplicación, division y factorial
 *
 *  Versión:    1.0 - 03/09/2018
 *  Autor:      Álvaro Enuel Serein
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {

    unsigned short opcion;
    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long factorial1;
    long factorial2;
    unsigned short bOperaciones = 0;    // Bandera para que rebote si no se ingresaron los operandos o fueron cambiados
    unsigned short bNumeroUno = 0;      // Bandera para declarar que float numeroUno está ingresado
    unsigned short bNumeroDos = 0;      // Bandera para declarar que float numeroDos está ingresado


    do {
        imprimirTituloCalculadora();
        printf("1. Ingresar primer operando");
        if (bNumeroUno == 1) {
            printf("\t> %.2f\n" , numeroUno);
        } else {
            printf("\n");
        }
        printf("2. Ingresar segundo operando");
        if (bNumeroDos == 1) {
            printf("\t> %.2f\n" , numeroDos);
        } else {
            printf("\n");
        }
        printf("3. Calcular operaciones");
        if (bOperaciones) {
            printf("\t\tx\n");
        } else {
            printf("\n");
        }
        printf("4. Mostrar resultados\n");
        printf("-----------------\n");
        printf("5. Salir\n\n");
        opcion = ingresarFloat("Elija opcion:\t\t"); // No sé cómo pasar string con caracteres especiales

        switch (opcion) {
            case 1 :{
                numeroUno = ingresarFloat("Ingrese numero uno:\t");
                bNumeroUno = 1;
                if (bOperaciones) {
                    bOperaciones = 0;
                }
                break;
            }
            case 2 : {
                numeroDos = ingresarFloat("Ingrese numero dos:\t");
                bNumeroDos = 1;
                if (bOperaciones) {
                    bOperaciones = 0;
                }
                break;
            }
            case 3 : {
                if (bNumeroUno && bNumeroDos) {
                    suma = sumarDos(numeroUno, numeroDos);
                    resta = restarDos(numeroUno, numeroDos);
                    multiplicacion = multiplicarDos(numeroUno, numeroDos);
                    if (numeroDos!=0) {
                        division = dividirDos(numeroUno, numeroDos);
                    }
                    factorial1 = factorialDe(numeroUno);
                    factorial2 = factorialDe(numeroDos);

                    bOperaciones = 1;
                    printf("\n%cResultados listos!\n" , 173);
                } else {
                    printf("\nPrimero ingrese dos n%cmeros.\n" , 163);
                }
                    break;
            }
            case 4 : {
                if (bOperaciones) {
                    printf("\nSUMA\t\t-  %.2f + %.2f:\t%.2f\n" , numeroUno, numeroDos, suma);
                    printf("RESTA\t\t-  %.2f - %.2f:\t%.2f\n" , numeroUno, numeroDos, resta);
                    printf("MULTIPLICACI%cN  -  %.2f * %.2f:\t%.2f\n" , 224 , numeroUno, numeroDos, multiplicacion);
                    if (numeroDos!=0) {
                        printf("DIVISI%cN\t-  %.2f / %.2f:\t%.2f\n" , 224 , numeroUno, numeroDos, division);
                    } else {
                        printf("DIVISI%cN\t-  %.2f / %.0f:\tError\n" , 224 , numeroUno, numeroDos);
                    }
                    if (numeroUno-(int)numeroUno==0) {
                        printf("FACTORIAL\t-  %.0f!:\t%li\n" , numeroUno, factorial1);
                    } else {
                        printf("FACTORIAL\t-  %.2f!: Error\n" , numeroUno);
                    }
                    if (numeroDos-(int)numeroDos==0) {
                        printf("FACTORIAL\t-  %.0f!:\t%li\n" , numeroDos, factorial2);
                    } else {
                        printf("FACTORIAL\t-  %.2f!: Error\n" , numeroDos);
                    }
                } else {
                    printf("\nCalcule los valores antes de verlos en pantalla.\n");
                }
                break;
            }
            case 5 : {
                break;
            }
            default : {
                printf("\nOpci%cn inv%clida\n" , 162 , 160);
            }

        }
        if (opcion!=5) {
            pausaYClear();
        }
    } while (opcion!=5);

    return 0;

}
