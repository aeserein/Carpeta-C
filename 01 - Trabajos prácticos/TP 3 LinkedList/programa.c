#include "programa.h"

int programa(void) {

    int debug = -999;
    int option;
    int fileLoaded = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        menu();

        option = getIntBetween(1, 10, "    Ingrese opcion:\t");

        switch(option) {
            case 1 : { // Cargar desde el archivo data.csv (modo texto)
                if (!fileLoaded) {
                    debug = controller_loadFromText("data.csv", listaEmpleados);
                    fileLoaded = 1;
                    c_listaCargada(debug);
                    //printf("\nTEST - loadFromText: %d\n", debug);
                } else {
                    c_archivoYaCargado();
                }
                pausaYClear();
                break;
            }
            case 2 : { // Cargar desde el archivo data.bin (modo binario)
                if (!fileLoaded) {
                    debug = controller_loadFromBinary("data.bin", listaEmpleados);
                    c_listaCargada(debug);
                    fileLoaded = 1;
                    //printf("\nTEST - loadFromBinary: %d\n", debug);
                } else {
                    c_archivoYaCargado();
                }
                pausaYClear();
                break;
            }
            case 3 : { // Alta de empleado
                if (fileLoaded) {
                    debug = controller_addEmployee(listaEmpleados);
                    //printf("\nTEST - addEmployee: %d\n", debug);
                } else {
                    c_primeroCargueUnArchivo();
                    pausaYClear();
                }
                break;
            }
            case 4 : { // Modificar datos de empleado
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_editEmployee(listaEmpleados);
                } else {
                    c_noHayEmpleadosEnElSistema();
                    pausaYClear();
                }
                break;
            }
            case 5 : { // Baja de empleado
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_removeEmployee(listaEmpleados);
                    //printf("\nTEST - removeEmployee: %d\n", debug);
                } else {
                    c_noHayEmpleadosEnElSistema();
                    pausaYClear();
                }
                break;
            }
            case 6 : { // Listar empleados
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = ll_sort(listaEmpleados, sortByID, 1);
                    debug = controller_ListEmployee(listaEmpleados);
                    //printf("\nTEST - ListEmployee: %d\n", debug);
                } else {
                    c_noHayEmpleadosEnElSistema();
                }
                pausaYClear();
                break;
            }
            case 7 : { // Ordenar empleados
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_sortEmployee(listaEmpleados);
                    //printf("\nTEST - sortEmployee: %d\n", debug);
                } else {
                    c_noHayEmpleadosEnElSistema();
                    pausaYClear();
                }
                break;
            }
            case 8 : { // Guardar empleados en el archivo data.csv (modo texto)
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_saveAsText("data.csv", listaEmpleados);
                    //printf("\nTEST - saveAsText: %d\n", debug);
                    c_archivoGuardado();
                } else {
                    c_noHayEmpleadosEnElSistema();
                }
                pausaYClear();
                break;
            }
            case 9 : { // Guardar empleados en el archivo data.bin (modo binario)
                if ( !ll_isEmpty(listaEmpleados) ) {
                    debug = controller_saveAsBinary("data.bin", listaEmpleados);
                    //printf("\nTEST - saveAsBinary: %d\n", debug);
                    c_archivoGuardado();
                } else {
                    c_noHayEmpleadosEnElSistema();
                }
                pausaYClear();
                break;
            }
        }
    }while(option!=10);

    ll_deleteLinkedList(listaEmpleados);
    system("cls");
    return debug;
}
