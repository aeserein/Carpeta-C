#include <stdio.h>
#include <stdlib.h>
#include <D:\Alvaro\Trabajos\Programación\01 - Programación 1\Calculadora\funciones\funciones.c>

int main() {

    printf("CALCULADORA\n-----------------\n\n");
    unsigned short opcion;
    float n1;
    float n2;
    float resultado1;
    float resultado2;

    do {
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Factorial\n");
        printf("-----------------\n");
        printf("6. Salir\n\n");
        opcion = ingresarNumero();

        switch (opcion) {
            case 1 : {
                n1 = ingresarNumero();
                n2 = ingresarNumero();
                resultado1 = sumarDos(n1,n2);
                printf("\nSUMA:\t%.2f\n" , resultado1);
                break;
            }
            case 2 : {
                n1 = ingresarNumero();
                n2 = ingresarNumero();
                resultado1 = restarDos(n1,n2);
                printf("\nRESTA:\t%.2f\n" , resultado1);
                break;
            }
            case 3 : {
                n1 = ingresarNumero();
                n2 = ingresarNumero();
                resultado1 = multiplicarDos(n1,n2);
                printf("PRODUCTO:\t%.2f\n" , resultado1);
                break;
            }
            case 4 : {
                n1 = ingresarNumero();
                n2 = ingresarNumero();
                resultado1 = dividirDos(n1,n2);
                printf("\nDIVISI%cN:\t%.2f\n" , 224 , resultado1);
                break;
            }
            case 5 : {
                n1 = ingresarNumero();
                n2 = ingresarNumero();
                resultado1 = factorial(n1);
                resultado2 = factorial(n2);
                printf("\nFACTORIAL 1:\t%.2f\n" , resultado1);
                printf("\nFACTORIAL 2:\t%.2f\n" , resultado2);
                break;
            }
            case 6 : {
                break;
            }
            default : {
                printf("\nOpci%cn inv%clida\n" , 162 , 160);
            }
        }

        if (opcion!=6) {
            printf("\n");
            if (!continuar()) {
                printf("\n");
                return 0;
            }
            system("cls");
        }


    } while (opcion!=6);

    return 0;

}
