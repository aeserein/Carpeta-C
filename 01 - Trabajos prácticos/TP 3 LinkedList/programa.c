#include "programa.h"

void menu() {
    printf("1. Cargar desde el archivo data.csv (modo texto)"
           "2. Cargar desde el archivo data.csv (modo binario)"
           "3. Alta de empleado"
           "4. Modificar datos de empleado"
           "5. Baja de empleado"
           "6. Listar empleados"
           "7. Ordenar empleados"
           "8. Guardar empleados en el archivo data.csv (modo texto)"
           "9. Guardar empleados en el archivo data.csv (modo binario)"
           "   --------------------------------------------------------------------------"
           "10. Salir");
}

int programa(void) {

    int debug;
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        menu();

        option = getIntBetween()

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);


    return debug;
}
