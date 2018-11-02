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

    Employee unEmpleado = {1,"PRIMERO",11,1111};
    Employee otroEmpleado = {2,"SEGUNDO",22,2222};

    debug = ll_add(listaEmpleados, &unEmpleado);
    printf("TEST - ADD1: %d\n", debug);
    debug = ll_add(listaEmpleados, &otroEmpleado);
    printf("TEST - ADD2: %d\n", debug);

    do{
        menu();

        option = getIntBetween(1, 10, "Ingrese opcion:\t");

        switch(option) {
            case 1 : { /// Cargar desde el archivo data.csv (modo texto)
                debug = controller_loadFromText("data.csv", listaEmpleados);
                printf("TEST - loadFromText: %d\n", debug);
                pausaYClear();
                break;
            }
            case 2 : { /// Cargar desde el archivo data.csv (modo binario)

            }
            case 3 : { /// Alta de empleado
            }
            case 4 : { /// Modificar datos de empleado
            }
            case 5 : { /// Baja de empleado
            }
            case 6 : { /// Listar empleados
                debug = controller_ListEmployee(listaEmpleados);
                printf("TEST - ListEmployee: %d\n", debug);
                pausaYClear();
                break;
            }
            case 7 : { /// Ordenar empleados
            }
            case 8 : { /// Guardar empleados en el archivo data.csv (modo texto)
            }
            case 9 : { /// Guardar empleados en el archivo data.csv (modo binario)
            }
        }
    }while(option != 10);


    return debug;
}


/** Preguntas
    controller_loadFromText
            El empleado auxiliar hay que crearlo en memoria dinámica?
*/
