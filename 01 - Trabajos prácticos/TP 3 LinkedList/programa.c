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
    /*
    Employee eUno = {1,"PRIMERO",11,1111};
    Employee eDos = {2,"SEGUNDO",22,2222};
    Employee eTres = {3,"TERCERO",33,3333};
    Employee eCuatro = {4,"CUARTO",44,4444};
    Employee eCinco = {5,"QUINTO",55,5555};

    debug = ll_add(listaEmpleados, &eUno);
    debug = ll_add(listaEmpleados, &eDos);
    debug = ll_add(listaEmpleados, &eTres);
    debug = ll_add(listaEmpleados, &eCuatro);
    debug = ll_add(listaEmpleados, &eCinco);
    */

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
                debug = controller_loadFromBinary("data.csv", listaEmpleados);
                printf("TEST - loadFromBinary: %d\n", debug);
                pausaYClear();
                break;
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
