#include "programa.h"

int programa(void) {

    int debug = 0;
    short opcion;
    short archivoCargado = 0;
    short sueldoCalculado = 0;
    float sueldoPromedio;
    LinkedList *listaEmpleados;

    listaEmpleados = ll_newLinkedList();

    do {
        printf("1 - Leer archivo de texto\n"
               "2 - Listar\n"
               "3 - Calcular sueldo\n"
               "4 - Ver empleados con sueldo\n"
               "5 - Guardar archivo de texto\n"
               "  -------------------------------\n"
               "6 - Salir\n\n");
        opcion = getShortBetween(1,6, "Ingrese opcion:\t");

        switch (opcion) {
            case 1 : {  /* Leer texto */
                if (!archivoCargado) {
                    controller_loadFromText("lista.csv", listaEmpleados);
                    archivoCargado = 1;
                    printf("\nLEIDO lista.csv\n");
                } else {
                    system("cls");
                    printf("\nArchivo ya cargado\n");
                }
                pausaYClear();
                break;
            }
            case 2 : {  /* Listar */
                if (!ll_isEmpty(listaEmpleados)) {
                    debug = ll_sort(listaEmpleados, sortByNombre, 1);
                    debug = controller_listeEmpleado(listaEmpleados);
                } else {
                    system("cls");
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 3 : {
                if (!ll_isEmpty(listaEmpleados)) {
                    debug = ll_map(listaEmpleados, calcularSueldo);
                    sueldoCalculado = 1;
                    printf("\nSueldos calculados\n");
                } else {
                    system("cls");
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 4 : {
                if (!ll_isEmpty(listaEmpleados) && sueldoCalculado) {
                    debug = ll_sort(listaEmpleados, sortByID, 1);
                    controller_listeEmpleadoConSueldos(listaEmpleados);
                } else {
                    system("cls");
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 5 : {
                if (!ll_isEmpty(listaEmpleados) && sueldoCalculado) {
                    sueldoPromedio = ll_averageValue(listaEmpleados, getSueldo);
                    LinkedList* listaAGuardar;
                    listaAGuardar = ll_filter_limite(listaEmpleados, filtrarLimite, sueldoPromedio, 1);

                    printf("Promedio: %f\n\nEmpleados guardados: ", sueldoPromedio);
                    debug = ll_sort(listaAGuardar, sortByID, 1);
                    controller_listeEmpleadoConSueldos(listaAGuardar);
                    controller_saveAsText("sueldos.csv", listaAGuardar);
                } else {
                    system("cls");
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
        }
    } while(opcion!=6);

    return debug;
}

/** NOTAS

120   -   21600
40    -   9600
80    -   28000
240

*/
