#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("CALCULADORA\n-----------\n\n");
    int opcion;
    do {
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Ingrese una opción:\t");
        scanf("%d" , &opcion);
        printf("\n");

        switch (opcion) {
            case 1 : {
                // funcion sumar
                break;
            }
            case 2 : {
                // funcion restar
                break;
            }
            case 3 : {
                // funcion multiplicar
                break;
            }
            case 4 : {
                // funcion dividir
                break;
            }
            case 5 : {
                break; //si es 5 sale
            }
            default : {
                printf("Opci%cn inv%clida" , 162 , 160);
            }
        } // TODO ESTO EN UNA FUNCION

        system("pause");
        system("cls");

    } while (opcion!=5);

    return 0;

}
