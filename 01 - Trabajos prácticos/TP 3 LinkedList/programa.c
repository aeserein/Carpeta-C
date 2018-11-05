#include "programa.h"

void menu() {
    printf("1. Cargar desde el archivo data.csv (modo texto)\n"
           "2. Cargar desde el archivo data.csv (modo binario)\n"
           "3. Alta de empleado\n"
           "4. Modificar datos de empleado\n"
           "5. Baja de empleado\n"
           "6. Listar empleados\n"
           "7. Ordenar empleados\n"
           "8. Guardar empleados en el archivo data.csv (modo texto)\n"
           "9. Guardar empleados en el archivo data.csv (modo binario)\n"
           "   --------------------------------------------------------------------------\n"
           "10. Salir\n\n");
}

int programa(void) {

    int debug = -999;
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        menu();

        option = getIntBetween(1, 10, "Ingrese opcion:\t");

        switch(option) {
            case 1 : { // Cargar desde el archivo data.csv (modo texto)
                debug = controller_loadFromText("data.csv", listaEmpleados);
                printf("\nTEST - loadFromText: %d\n", debug);
                pausaYClear();
                break;
            }
            case 2 : { // Cargar desde el archivo data.csv (modo binario)
                debug = controller_loadFromBinary("data.bin", listaEmpleados);
                printf("\nTEST - loadFromBinary: %d\n", debug);
                pausaYClear();
                break;
            }
            case 3 : { // Alta de empleado
                debug = controller_addEmployee(listaEmpleados);
                printf("\nTEST - addEmployee: %d\n", debug);
                pausaYClear();
                break;
            }
            case 4 : { // Modificar datos de empleado
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_editEmployee(listaEmpleados);
                } else {
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 5 : { // Baja de empleado
                debug = controller_removeEmployee(listaEmpleados);
                printf("\nTEST - removeEmployee: %d\n", debug);
                pausaYClear();
                break;
            }
            case 6 : { // Listar empleados
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_ListEmployee(listaEmpleados);
                } else {
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 7 : { // Ordenar empleados
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_sortEmployee(listaEmpleados);
                } else {
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 8 : { /// Guardar empleados en el archivo data.csv (modo texto)
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_saveAsText("data.csv", listaEmpleados);
                } else {
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
            case 9 : { /// Guardar empleados en el archivo data.csv (modo binario)
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_saveAsBinary("data.bin", listaEmpleados);
                    printf("\nTEST - saveAsBinary: %d\n", debug);

                } else {
                    printf("No hay empleados en el sistema\n");
                }
                pausaYClear();
                break;
            }
        }
    }while(option != 10);


    return debug;
}


/** Preguntas
    sort
        ¿Debo mostrar cuando ordeno?

    archivos
        ¿Dos versiones distintas o una versión sola y que se pise cada vez que guardo?

    int ll_clear(LinkedList* this);    ///Limpiar todos los slots
        ¿Para qué?

    int ll_indexOf(LinkedList* this, void* pElement);
        ¿Para qué, si el usuario me da el ID
        y yo tengo que sacar un índice a partir del ID y no a partir del elemento

    Empleado 0, "", 0, 0 desde binario

    Diferencia entre pop y remove

    Preguntar para qué son las funciones que faltan

    Preguntar si las funciones que parecen no tener uso son para el parcial y no para este trabajo
*/
